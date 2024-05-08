#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;

enum ErrorsDB {
	DB_OK = 0,
	DB_CANNOT_CONNECT = 1,
	DB_WRONG_TABLES = 2,
	DB_WRONG_COLUMNS = 3,
	DB_READ_ERROR = 4,
};

ref class AccessDB {

private:
	OleDbConnection^ dbConnect;

public:
	ErrorsDB OpenDB(String^ path);
	ErrorsDB CheckDB();
	Void CloseDB();


	OleDbDataReader^ Read();
};