#include "MyForm.h"
#include "AccessDB.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace MumladzeLab6;
using namespace System::Data::OleDb;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault;
	Application::EnableVisualStyles;
	
	MyForm app;
	Application::Run(% app);
}



MyForm::MyForm(void) {
	InitializeComponent();
	this->dataBase = gcnew AccessDB();
}
MyForm::~MyForm() {
	if (components) {
		delete components;
	}
}



Void MyForm::ErrorCodesToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
	String^ str = gcnew String("1 - невозможно соединиться с БД\n2 - БД не соответствует формату программы\n" + 
		"3 - таблица Books не соответствует формату программы");
	MessageBox::Show(str, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

Void MyForm::OpenDataBaseToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Access Database files (*.accdb)|*.accdb";
	String^ pathFile;

	if (openFileDialog->ShowDialog() == Forms::DialogResult::OK) {
		pathFile = openFileDialog->FileName;
		ErrorsDB status = this->dataBase->OpenDB(pathFile);
		if (status != DB_OK) {
			MessageBox::Show("Ошибка код " + (static_cast<int>(status)).ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->dataBase->CloseDB();
		}
	}
	else {
		MessageBox::Show("Внимание: вы не выбрали базу данных. Для работы с БД необходимо ее открыть.", "Ошибка открытия БД", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	
}

Void MyForm::CreateNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}

Void MyForm::ReadNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
	OleDbDataReader^ reader = this->dataBase->Read();
	if (reader) {
		while (reader->Read()) {
			this->dataGridView->Rows->Add(reader["ID"], reader["ISBN"], reader["Title"], 
				reader["Author"], reader["PublishingDate"], reader["PageCount"]);
		}
	}
	else {
		ErrorsDB status = DB_READ_ERROR;
		MessageBox::Show("Ошибка код " + (static_cast<int>(status)).ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Void MyForm::UpdateNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}

Void MyForm::DeleteNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}

