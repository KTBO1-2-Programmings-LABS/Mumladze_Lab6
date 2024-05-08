#include "GetData.h"

using namespace MumladzeLab6;

GetData::GetData(BookNode^ node) {
	InitializeComponent();
	if (node != nullptr) {
		this->boxISBN->Text = node->ISBN;
		this->boxTitle->Text = node->title;
		this->boxAuthor->Text = node->author;
		this->boxDate->Text = node->date->ToString();
		this->boxPages->Text = node->pageCount.ToString();
		this->Text = "Изменить";
	}
	else {
		this->Text = "Создать";
	}
}

GetData::~GetData() {
	if (components) {
		delete components;
	}
}

Void GetData::BoxPages_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
	if ('0' <= e->KeyChar && e->KeyChar <= '9') {
		e->Handled = false;
	}
	else {
		e->Handled = true;
	}
}

Void GetData::ButtonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->IsAnyFieldUncorrect()) {
		MessageBox::Show("Найдено некорректное поле, перепроверьте ввод", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

Boolean GetData::IsAnyFieldUncorrect() {
	if (this->boxISBN->Text->Length != 17)
		return true;
	if (String::IsNullOrWhiteSpace(this->boxTitle->Text))
		return true;
	if (String::IsNullOrWhiteSpace(this->boxAuthor->Text))
		return true;
	DateTime temp_date;
	if (!DateTime::TryParse(this->boxDate->Text, temp_date))
		return true;
	Int32 temp_int;
	if (String::IsNullOrWhiteSpace(this->boxPages->Text))
		return true;

	return false;
}

BookNode^ GetData::GetDataFromBox() {
	BookNode^ node = gcnew BookNode();
	node->ISBN = this->boxISBN->Text;
	node->title = this->boxTitle->Text;
	node->author = this->boxAuthor->Text;
	node->date = DateTime::Parse(this->boxDate->Text);
	node->pageCount = Int32::Parse(this->boxPages->Text);
	return node;
}