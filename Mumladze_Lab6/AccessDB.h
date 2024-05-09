#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System::Collections::Generic;

enum ErrorsDB {
	DB_OK = 0,
	DB_CANNOT_CONNECT = 1,
	DB_WRONG_TABLES = 2,
	DB_WRONG_COLUMNS = 3,
	DB_READ_ERROR = 4,
	DB_CREATE_ERROR = 5,
	DB_UPDATE_ERROR = 6,
	DB_DELETE_ERROR = 7
};

ref struct BookNode {
	Int32 ID;
	String^ ISBN;
	DateTime^ date;
	String^ title;
	String^ author;
	Int32 pageCount;
};

ref class AccessDB {
private:
	OleDbConnection^ dbConnect;

public:
	ErrorsDB OpenDB(String^ path);
	ErrorsDB CheckDB();
	Void CloseDB();

	ErrorsDB Create(BookNode^ node);
	List<BookNode^>^ Read();
	ErrorsDB Update(BookNode^ node);
	ErrorsDB Delete(Int32 ID);
};