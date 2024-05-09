#pragma once

#include "AccessDB.h"

namespace MumladzeLab6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GetData
	/// </summary>
	public ref class GetData : public System::Windows::Forms::Form {
	
	
	public:
		GetData(BookNode^ node);
	protected:
		~GetData();


	private: System::Windows::Forms::MaskedTextBox^ boxISBN;
	private: System::Windows::Forms::Label^ labelISBN;
	private: System::Windows::Forms::TextBox^ boxTitle;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TextBox^ boxAuthor;
	private: System::Windows::Forms::Label^ labelAuthor;
	private: System::Windows::Forms::MaskedTextBox^ boxDate;
	private: System::Windows::Forms::Label^ labelDate;
	private: System::Windows::Forms::TextBox^ boxPages;
	private: System::Windows::Forms::Label^ labelPages;
	private: System::Windows::Forms::Button^ buttonSave;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->boxISBN = (gcnew System::Windows::Forms::MaskedTextBox());
			this->labelISBN = (gcnew System::Windows::Forms::Label());
			this->boxTitle = (gcnew System::Windows::Forms::TextBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->boxAuthor = (gcnew System::Windows::Forms::TextBox());
			this->labelAuthor = (gcnew System::Windows::Forms::Label());
			this->boxDate = (gcnew System::Windows::Forms::MaskedTextBox());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->boxPages = (gcnew System::Windows::Forms::TextBox());
			this->labelPages = (gcnew System::Windows::Forms::Label());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// boxISBN
			// 
			this->boxISBN->Location = System::Drawing::Point(12, 12);
			this->boxISBN->Mask = L"000-0-00000-000-0";
			this->boxISBN->Name = L"boxISBN";
			this->boxISBN->Size = System::Drawing::Size(115, 20);
			this->boxISBN->TabIndex = 2;
			// 
			// labelISBN
			// 
			this->labelISBN->AutoSize = true;
			this->labelISBN->Location = System::Drawing::Point(12, 35);
			this->labelISBN->Name = L"labelISBN";
			this->labelISBN->Size = System::Drawing::Size(32, 13);
			this->labelISBN->TabIndex = 3;
			this->labelISBN->Text = L"ISBN";
			// 
			// boxTitle
			// 
			this->boxTitle->Location = System::Drawing::Point(12, 56);
			this->boxTitle->Name = L"boxTitle";
			this->boxTitle->Size = System::Drawing::Size(219, 20);
			this->boxTitle->TabIndex = 4;
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Location = System::Drawing::Point(12, 79);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(89, 13);
			this->labelTitle->TabIndex = 5;
			this->labelTitle->Text = L"Название книги";
			// 
			// boxAuthor
			// 
			this->boxAuthor->Location = System::Drawing::Point(12, 100);
			this->boxAuthor->Name = L"boxAuthor";
			this->boxAuthor->Size = System::Drawing::Size(219, 20);
			this->boxAuthor->TabIndex = 6;
			// 
			// labelAuthor
			// 
			this->labelAuthor->AutoSize = true;
			this->labelAuthor->Location = System::Drawing::Point(12, 123);
			this->labelAuthor->Name = L"labelAuthor";
			this->labelAuthor->Size = System::Drawing::Size(51, 13);
			this->labelAuthor->TabIndex = 7;
			this->labelAuthor->Text = L"Автор(ы)";
			// 
			// boxDate
			// 
			this->boxDate->Location = System::Drawing::Point(12, 144);
			this->boxDate->Mask = L"00/00/0000";
			this->boxDate->Name = L"boxDate";
			this->boxDate->Size = System::Drawing::Size(100, 20);
			this->boxDate->TabIndex = 8;
			this->boxDate->ValidatingType = System::DateTime::typeid;
			// 
			// labelDate
			// 
			this->labelDate->AutoSize = true;
			this->labelDate->Location = System::Drawing::Point(12, 167);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(95, 13);
			this->labelDate->TabIndex = 9;
			this->labelDate->Text = L"Дата публикации";
			// 
			// boxPages
			// 
			this->boxPages->Location = System::Drawing::Point(12, 188);
			this->boxPages->Name = L"boxPages";
			this->boxPages->Size = System::Drawing::Size(100, 20);
			this->boxPages->TabIndex = 10;
			this->boxPages->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GetData::BoxPages_KeyPress);
			// 
			// labelPages
			// 
			this->labelPages->AutoSize = true;
			this->labelPages->Location = System::Drawing::Point(12, 211);
			this->labelPages->Name = L"labelPages";
			this->labelPages->Size = System::Drawing::Size(83, 13);
			this->labelPages->TabIndex = 11;
			this->labelPages->Text = L"Число страниц";
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(137, 158);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(85, 39);
			this->buttonSave->TabIndex = 12;
			this->buttonSave->Text = L"Сохранить значения";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &GetData::ButtonSave_Click);
			// 
			// GetData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(244, 236);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->labelPages);
			this->Controls->Add(this->boxPages);
			this->Controls->Add(this->labelDate);
			this->Controls->Add(this->boxDate);
			this->Controls->Add(this->labelAuthor);
			this->Controls->Add(this->boxAuthor);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->boxTitle);
			this->Controls->Add(this->labelISBN);
			this->Controls->Add(this->boxISBN);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"GetData";
			this->Text = L"NewWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Int32 ID = -1;
	private: System::Void BoxPages_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void ButtonSave_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Boolean IsAnyFieldUncorrect();
	public: BookNode^ GetDataFromBox();
		
	};
}
