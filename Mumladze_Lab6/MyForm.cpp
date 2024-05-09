#include "MyForm.h"
#include "AccessDB.h"
#include "GetData.h"

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
		"3 - таблица Books не соответствует формату программы\n4 - ошибка чтения БД\n" + 
		"5 - ошибка создания записи в БД\n6 - ошибка обновления записи в БД");
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
	GetData^ getDataForm = gcnew GetData(nullptr);
	if (getDataForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		BookNode^ node = getDataForm->GetDataFromBox();
		ErrorsDB status = this->dataBase->Create(node);
		if (status == DB_OK) {
			this->dataGridView->Rows->Add(node->ID, node->ISBN, node->title,
				node->author, node->date, node->pageCount);
		}
		else {
			MessageBox::Show("Ошибка код " + (static_cast<int>(status)).ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

Void MyForm::ReadNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
	this->dataGridView->Rows->Clear();
	List<BookNode^>^ bookList = this->dataBase->Read();
	if (bookList) {
		for each (BookNode^ node in bookList) {
			this->dataGridView->Rows->Add(node->ID, node->ISBN, node->title, 
				node->author, node->date, node->pageCount);
		}
	}
	else {
		ErrorsDB status = DB_READ_ERROR;
		MessageBox::Show("Ошибка код " + (static_cast<int>(status)).ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Void MyForm::UpdateNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
	if (dataGridView->SelectedRows->Count != 1) {
		MessageBox::Show("Пожалуйста, выберите одну строку для обновления", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	DataGridViewRow^ selectedRow = dataGridView->SelectedRows[0];
	BookNode^ node = gcnew BookNode();
	node->ID = Convert::ToInt32(selectedRow->Cells["ID"]->Value);
	node->ISBN = Convert::ToString(selectedRow->Cells["ISBN"]->Value);
	node->title = Convert::ToString(selectedRow->Cells["Title"]->Value);
	node->author = Convert::ToString(selectedRow->Cells["Author"]->Value);
	node->date = Convert::ToDateTime(selectedRow->Cells["Date"]->Value);
	node->pageCount = Convert::ToInt32(selectedRow->Cells["PageCount"]->Value);

	GetData^ getDataForm = gcnew GetData(node);
	if (getDataForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		BookNode^ updatedNode = getDataForm->GetDataFromBox();
		ErrorsDB status = this->dataBase->Update(updatedNode);
		if (status == DB_OK) {
			for each (DataGridViewRow ^ row in this->dataGridView->Rows) {
				if (Convert::ToInt32(row->Cells["ID"]->Value) == updatedNode->ID) {
					row->Cells["ISBN"]->Value = updatedNode->ISBN;
					row->Cells["Title"]->Value = updatedNode->title;
					row->Cells["Author"]->Value = updatedNode->author;
					row->Cells["Date"]->Value = updatedNode->date->ToString("d");
					row->Cells["PageCount"]->Value = updatedNode->pageCount;
					break;
				}
			}
		}
		else {
			MessageBox::Show("Ошибка код " + (static_cast<int>(status)).ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

Void MyForm::DeleteNodeToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {

}

