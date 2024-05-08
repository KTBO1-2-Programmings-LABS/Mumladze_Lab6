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

}
Void MyForm::UpdateNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}
Void MyForm::DeleteNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}

