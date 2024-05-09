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
    ErrorsDB status = DB_OK;
	try {
        this->dbConnect->Open();
        DataTable^ schemaTable = dbConnect->GetSchema("Tables", gcnew array<String^> {nullptr, nullptr, nullptr, "TABLE"});
        if (schemaTable->Rows->Count == 1) {
            DataRow^ table = schemaTable->Rows[0];
            if (table["TABLE_NAME"]->ToString() == "Books") {
                DataTable^ columns = dbConnect->GetSchema("Columns", gcnew array<String^> {nullptr, nullptr, "Books", nullptr});
                bool hasID = false, hasISBN = false, hasPublishingDate = false, hasTitle = false, hasAuthor = false, hasPageCount = false;
                for each (DataRow ^ col in columns->Rows) {
                    String^ columnName = col["COLUMN_NAME"]->ToString();
                    String^ dataType = col["DATA_TYPE"]->ToString();

                    if (columnName == "ID" && dataType == "3")
                        hasID = true;
                    else if (columnName == "ISBN" && dataType == "130")
                        hasISBN = true;
                    else if (columnName == "Title" && dataType == "130")
                        hasTitle = true;
                    else if (columnName == "Author" && dataType == "130")
                        hasAuthor = true;
                    else if (columnName == "PublishingDate" && dataType == "7")
                        hasPublishingDate = true;
                    else if (columnName == "PageCount" && dataType == "3")
                        hasPageCount = true;
                    else {
                        status = DB_WRONG_COLUMNS;
                        break;
                    }
                }
                if (!(hasID && hasISBN && hasPublishingDate && hasTitle && hasAuthor && hasPageCount))
                    status = DB_WRONG_COLUMNS;
                else
                    status = DB_OK;
            }
            else 
                status = DB_WRONG_TABLES;
        }
        else 
            status = DB_WRONG_TABLES;
    }
	catch (Exception^ e) {
		status = DB_CANNOT_CONNECT;
	}
    finally {
        if (this->dbConnect->State == ConnectionState::Open)
            this->dbConnect->Close();
    }
    return status;
}

Void AccessDB::CloseDB() {
    delete this->dbConnect;
    this->dbConnect = nullptr;
}



ErrorsDB AccessDB::Create(BookNode^ node) {
    ErrorsDB status = DB_OK;
    try {
        this->dbConnect->Open();
        String^ query = "INSERT INTO Books (ISBN, Title, Author, PublishingDate, PageCount) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ command = gcnew OleDbCommand(query, this->dbConnect);
        command->Parameters->AddWithValue("?", node->ISBN);
        command->Parameters->AddWithValue("?", node->title);
        command->Parameters->AddWithValue("?", node->author);
        command->Parameters->AddWithValue("?", node->date);
        command->Parameters->AddWithValue("?", node->pageCount);
        command->ExecuteNonQuery();
        status = DB_OK;
    }
    catch (Exception^ e) {
        status = DB_CREATE_ERROR;
    }
    finally {
        if (this->dbConnect->State == ConnectionState::Open)
            this->dbConnect->Close();
    }
    return status;
}

List<BookNode^>^ AccessDB::Read() {
    String^ query = "SELECT * FROM Books";
    OleDbCommand^ command = gcnew OleDbCommand(query, this->dbConnect);
    List<BookNode^>^ bookList = gcnew List<BookNode^>();
    
    try {
        this->dbConnect->Open();
        OleDbDataReader^ reader = command->ExecuteReader();
        while (reader->Read()) {
            BookNode^ book = gcnew BookNode();
            book->ID = Convert::ToInt32(reader["ID"]);
            book->ISBN = reader["ISBN"]->ToString();
            book->date = static_cast<DateTime^>(reader["PublishingDate"]);
            book->title = reader["Title"]->ToString();
            book->author = reader["Author"]->ToString();
            book->pageCount = Convert::ToInt32(reader["PageCount"]);
            bookList->Add(book);
        }
    }
    catch (Exception^ e) {
        this->dbConnect->Close();
        return nullptr;
    }
    finally {
        if (this->dbConnect->State == ConnectionState::Open)
            this->dbConnect->Close();
    }
    return bookList;
}

ErrorsDB AccessDB::Update(BookNode^ node) {
    ErrorsDB status = DB_OK;
    try {
        this->dbConnect->Open();
        String^ query = "UPDATE Books SET ISBN = ?, PublishingDate = ?, Title = ?, Author = ?, PageCount = ? WHERE ID = ?";
        OleDbCommand^ command = gcnew OleDbCommand(query, this->dbConnect);
        command->Parameters->AddWithValue("?", node->ISBN);
        command->Parameters->AddWithValue("?", node->date);
        command->Parameters->AddWithValue("?", node->title);
        command->Parameters->AddWithValue("?", node->author);
        command->Parameters->AddWithValue("?", node->pageCount);
        command->Parameters->AddWithValue("?", node->ID);
        command->ExecuteNonQuery();
        status = DB_OK;
    }
    catch (Exception^ e) {
        status = DB_UPDATE_ERROR;
    }
    finally {
        if (this->dbConnect->State == ConnectionState::Open)
            this->dbConnect->Close();
    }
    return status;
}

ErrorsDB AccessDB::Delete(Int32 ID) {
    ErrorsDB status = DB_OK;
    try {
        this->dbConnect->Open();
        String^ query = "DELETE FROM Books WHERE ID = ?";
        OleDbCommand^ command = gcnew OleDbCommand(query, this->dbConnect);
        command->Parameters->AddWithValue("?", ID);
        command->ExecuteNonQuery();
        status = DB_OK;
    }
    catch (Exception^ e) {
        status = DB_DELETE_ERROR;
    }
    finally {
        if (this->dbConnect->State == ConnectionState::Open)
            this->dbConnect->Close();
    }
    return status;
}
