#include "AccessDB.h"

ErrorsDB AccessDB::OpenDB(String^ path) {
    try {
        String^ configString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + path + ";";
        this->dbConnect = gcnew OleDbConnection(configString);
        return CheckDB();
    }
    catch (Exception^ e) {
        return DB_CANNOT_CONNECT;
    }
}

ErrorsDB AccessDB::CheckDB() {
	try {
        this->dbConnect->Open();
        DataTable^ schemaTable = dbConnect->GetSchema("Tables");
        for each (DataRow^ row in schemaTable->Rows) {
            if (row["TABLE_NAME"]->ToString() == "Books") {
                DataTable^ columns = dbConnect->GetSchema("Columns", gcnew array<String^>{nullptr, nullptr, "Books", nullptr});
                bool hasID = false, hasISBN = false, hasPublishingDate = false, hasTitle = false, hasAuthor = false, hasPageCount = false;
                for each (DataRow ^ col in columns->Rows) {
                    String^ columnName = col["COLUMN_NAME"]->ToString();
                    String^ dataType = col["DATA_TYPE"]->ToString();

                    if (columnName == "ID" && dataType == "3") hasID = true;
                    else if (columnName == "ISBN" && dataType == "130") hasISBN = true;
                    else if (columnName == "Title" && dataType == "130") hasTitle = true;
                    else if (columnName == "Author" && dataType == "130") hasAuthor = true;
                    else if (columnName == "PublishingDate" && dataType == "7") hasPublishingDate = true;
                    else if (columnName == "PageCount" && dataType == "3") hasPageCount = true;
                    else {
                        this->dbConnect->Close();
                        return DB_WRONG_COLUMNS;
                    }
                }
                if (!(hasID && hasISBN && hasPublishingDate && hasTitle && hasAuthor && hasPageCount)) {
                    return DB_WRONG_COLUMNS;
                }
                return DB_OK;
            }
            else {
                return DB_WRONG_TABLES;
            }
        }
        dbConnect->Close();
    }
	catch (Exception^ e) {
		return DB_CANNOT_CONNECT;
	}
}

Void AccessDB::CloseDB() {
    delete this->dbConnect;
    this->dbConnect = nullptr;
}



ErrorsDB AccessDB::Create(BookNode^ node) {
    try {
        String^ query = "INSERT INTO Books (ISBN, Title, Author, PublishingDate, PageCount) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ command = gcnew OleDbCommand(query, dbConnect);
        command->Parameters->AddWithValue("?", node->ISBN);
        command->Parameters->AddWithValue("?", node->title);
        command->Parameters->AddWithValue("?", node->author);
        command->Parameters->AddWithValue("?", node->date);
        command->Parameters->AddWithValue("?", node->pageCount);
        command->ExecuteNonQuery();
        return DB_OK;
    }
    catch (Exception^ e) {
        return DB_CREATE_ERROR;
    }
}

OleDbDataReader^ AccessDB::Read() {
    String^ query = "SELECT * FROM Books";
    OleDbCommand^ command = gcnew OleDbCommand(query, this->dbConnect);
    OleDbDataReader^ reader = command->ExecuteReader();
    if (reader->HasRows) {
        return reader;
    }
    else {
        return nullptr;
    }
}

