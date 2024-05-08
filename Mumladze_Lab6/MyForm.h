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
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	

	public:
		MyForm(void);
	protected:
		~MyForm();


	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ actionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openDataBaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createNodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readNodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ updateNodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteNodeToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ISBN;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Author;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PageCount;
	private: System::Windows::Forms::ToolStripMenuItem^ errorCodesToolStripMenuItem;

	protected:
	
	
	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->actionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDataBaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createNodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readNodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateNodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteNodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ISBN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Author = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PageCount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errorCodesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->actionsToolStripMenuItem,
					this->errorCodesToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(684, 27);
			this->menuStrip->TabIndex = 0;
			// 
			// actionsToolStripMenuItem
			// 
			this->actionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openDataBaseToolStripMenuItem,
					this->createNodeToolStripMenuItem, this->readNodeToolStripMenuItem, this->updateNodeToolStripMenuItem, this->deleteNodeToolStripMenuItem
			});
			this->actionsToolStripMenuItem->Name = L"actionsToolStripMenuItem";
			this->actionsToolStripMenuItem->Size = System::Drawing::Size(86, 23);
			this->actionsToolStripMenuItem->Text = L"Операции";
			// 
			// openDataBaseToolStripMenuItem
			// 
			this->openDataBaseToolStripMenuItem->Name = L"openDataBaseToolStripMenuItem";
			this->openDataBaseToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->openDataBaseToolStripMenuItem->Text = L"Открыть базу данных";
			this->openDataBaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenDataBaseToolStripMenuItem_Click);
			// 
			// createNodeToolStripMenuItem
			// 
			this->createNodeToolStripMenuItem->Name = L"createNodeToolStripMenuItem";
			this->createNodeToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->createNodeToolStripMenuItem->Text = L"Создать запись";
			this->createNodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::CreateNodeToolStripMenuItem_Click);
			// 
			// readNodeToolStripMenuItem
			// 
			this->readNodeToolStripMenuItem->Name = L"readNodeToolStripMenuItem";
			this->readNodeToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->readNodeToolStripMenuItem->Text = L"Прочитать записи";
			this->readNodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ReadNodeToolStripMenuItem_Click);
			// 
			// updateNodeToolStripMenuItem
			// 
			this->updateNodeToolStripMenuItem->Name = L"updateNodeToolStripMenuItem";
			this->updateNodeToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->updateNodeToolStripMenuItem->Text = L"Обновить запись";
			this->updateNodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::UpdateNodeToolStripMenuItem_Click);
			// 
			// deleteNodeToolStripMenuItem
			// 
			this->deleteNodeToolStripMenuItem->Name = L"deleteNodeToolStripMenuItem";
			this->deleteNodeToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->deleteNodeToolStripMenuItem->Text = L"Удалить запись";
			this->deleteNodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::DeleteNodeToolStripMenuItem_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->ISBN,
					this->Date, this->Title, this->Author, this->PageCount
			});
			this->dataGridView->Location = System::Drawing::Point(20, 40);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->Size = System::Drawing::Size(645, 350);
			this->dataGridView->TabIndex = 1;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// ISBN
			// 
			this->ISBN->HeaderText = L"ISBN Книги";
			this->ISBN->Name = L"ISBN";
			this->ISBN->ReadOnly = true;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Дата публикации";
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			// 
			// Title
			// 
			this->Title->HeaderText = L"Заголовок книги";
			this->Title->Name = L"Title";
			this->Title->ReadOnly = true;
			// 
			// Author
			// 
			this->Author->HeaderText = L"Автор(ы) книги";
			this->Author->Name = L"Author";
			this->Author->ReadOnly = true;
			// 
			// PageCount
			// 
			this->PageCount->HeaderText = L"Число страниц";
			this->PageCount->Name = L"PageCount";
			this->PageCount->ReadOnly = true;
			// 
			// errorCodesToolStripMenuItem
			// 
			this->errorCodesToolStripMenuItem->Name = L"errorCodesToolStripMenuItem";
			this->errorCodesToolStripMenuItem->Size = System::Drawing::Size(109, 23);
			this->errorCodesToolStripMenuItem->Text = L"Коды ошибок";
			this->errorCodesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ErrorCodesToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 411);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"Работа с базой данных Access";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: AccessDB^ dataBase;
	
	private: System::Void ErrorCodesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OpenDataBaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateNodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ReadNodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void UpdateNodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteNodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	

	};
}
