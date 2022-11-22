#pragma once
#include <msclr/marshal_cppstd.h>
#include "AVL_tree.h"

namespace ADLab31 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataBase = new AVL_tree("DB.bin");
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Button^ doButton;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ idBox;
		System::Windows::Forms::TextBox^ nameBox;
		System::Windows::Forms::TextBox^ surnameBox;
		System::Windows::Forms::TextBox^ resultBox;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::RadioButton^ insertButton;
		System::Windows::Forms::RadioButton^ deleteButton;
		System::Windows::Forms::RadioButton^ selectButton;
		System::Windows::Forms::RadioButton^ updateButton;
		AVL_tree* dataBase;
		System::Windows::Forms::RadioButton^ generateButton;
		System::Windows::Forms::TextBox^ genAmountBox;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Button^ dropButton;

		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->doButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->idBox = (gcnew System::Windows::Forms::TextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->surnameBox = (gcnew System::Windows::Forms::TextBox());
			this->resultBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->generateButton = (gcnew System::Windows::Forms::RadioButton());
			this->insertButton = (gcnew System::Windows::Forms::RadioButton());
			this->deleteButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectButton = (gcnew System::Windows::Forms::RadioButton());
			this->updateButton = (gcnew System::Windows::Forms::RadioButton());
			this->genAmountBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dropButton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// doButton
			// 
			this->doButton->Location = System::Drawing::Point(338, 285);
			this->doButton->Name = L"doButton";
			this->doButton->Size = System::Drawing::Size(256, 101);
			this->doButton->TabIndex = 4;
			this->doButton->Text = L"DO";
			this->doButton->UseVisualStyleBackColor = true;
			this->doButton->Click += gcnew System::EventHandler(this, &MyForm::doButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(172, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"ID";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(148, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Name";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(128, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Surname";
			// 
			// idBox
			// 
			this->idBox->Location = System::Drawing::Point(208, 50);
			this->idBox->Name = L"idBox";
			this->idBox->Size = System::Drawing::Size(308, 22);
			this->idBox->TabIndex = 11;
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(208, 119);
			this->nameBox->Name = L"nameBox";
			this->nameBox->ReadOnly = true;
			this->nameBox->Size = System::Drawing::Size(308, 22);
			this->nameBox->TabIndex = 12;
			this->nameBox->Text = L" ";
			// 
			// surnameBox
			// 
			this->surnameBox->Location = System::Drawing::Point(208, 185);
			this->surnameBox->Name = L"surnameBox";
			this->surnameBox->ReadOnly = true;
			this->surnameBox->Size = System::Drawing::Size(308, 22);
			this->surnameBox->TabIndex = 13;
			this->surnameBox->Text = L" ";
			// 
			// resultBox
			// 
			this->resultBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->resultBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->resultBox->Location = System::Drawing::Point(531, 22);
			this->resultBox->Multiline = true;
			this->resultBox->Name = L"resultBox";
			this->resultBox->ReadOnly = true;
			this->resultBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->resultBox->Size = System::Drawing::Size(361, 223);
			this->resultBox->TabIndex = 18;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->generateButton);
			this->panel1->Controls->Add(this->insertButton);
			this->panel1->Controls->Add(this->deleteButton);
			this->panel1->Controls->Add(this->selectButton);
			this->panel1->Controls->Add(this->updateButton);
			this->panel1->Location = System::Drawing::Point(1, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(118, 216);
			this->panel1->TabIndex = 19;
			// 
			// generateButton
			// 
			this->generateButton->AutoSize = true;
			this->generateButton->Location = System::Drawing::Point(7, 163);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(105, 38);
			this->generateButton->TabIndex = 4;
			this->generateButton->TabStop = true;
			this->generateButton->Text = L"GENERATE\r\nTEST DB";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::generateButton_CheckedChanged);
			// 
			// insertButton
			// 
			this->insertButton->AutoSize = true;
			this->insertButton->Location = System::Drawing::Point(7, 127);
			this->insertButton->Name = L"insertButton";
			this->insertButton->Size = System::Drawing::Size(79, 21);
			this->insertButton->TabIndex = 3;
			this->insertButton->TabStop = true;
			this->insertButton->Text = L"INSERT";
			this->insertButton->UseVisualStyleBackColor = true;
			// 
			// deleteButton
			// 
			this->deleteButton->AutoSize = true;
			this->deleteButton->Location = System::Drawing::Point(7, 89);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(83, 21);
			this->deleteButton->TabIndex = 2;
			this->deleteButton->TabStop = true;
			this->deleteButton->Text = L"DELETE";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::deleteButton_CheckedChanged);
			// 
			// selectButton
			// 
			this->selectButton->AutoSize = true;
			this->selectButton->Checked = true;
			this->selectButton->Location = System::Drawing::Point(7, 13);
			this->selectButton->Name = L"selectButton";
			this->selectButton->Size = System::Drawing::Size(82, 21);
			this->selectButton->TabIndex = 1;
			this->selectButton->TabStop = true;
			this->selectButton->Text = L"SELECT";
			this->selectButton->UseVisualStyleBackColor = true;
			this->selectButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::selectButton_CheckedChanged);
			// 
			// updateButton
			// 
			this->updateButton->AutoSize = true;
			this->updateButton->Location = System::Drawing::Point(7, 49);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(85, 21);
			this->updateButton->TabIndex = 0;
			this->updateButton->TabStop = true;
			this->updateButton->Text = L"UPDATE";
			this->updateButton->UseVisualStyleBackColor = true;
			// 
			// genAmountBox
			// 
			this->genAmountBox->Location = System::Drawing::Point(11, 272);
			this->genAmountBox->Name = L"genAmountBox";
			this->genAmountBox->Size = System::Drawing::Size(100, 22);
			this->genAmountBox->TabIndex = 20;
			this->genAmountBox->Text = L"0";
			this->genAmountBox->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 252);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 17);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Amount of rows";
			this->label4->Visible = false;
			// 
			// dropButton
			// 
			this->dropButton->Location = System::Drawing::Point(725, 316);
			this->dropButton->Name = L"dropButton";
			this->dropButton->Size = System::Drawing::Size(115, 38);
			this->dropButton->TabIndex = 22;
			this->dropButton->Text = L"Drop DB";
			this->dropButton->UseVisualStyleBackColor = true;
			this->dropButton->Click += gcnew System::EventHandler(this, &MyForm::dropButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(918, 417);
			this->Controls->Add(this->dropButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->genAmountBox);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->surnameBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->idBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->doButton);
			this->MaximumSize = System::Drawing::Size(936, 464);
			this->Name = L"MyForm";
			this->Text = L"Control panel";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void doButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectButton->Checked)
			{
				if (inputCheck())
				{
					int compares = 0;
					Info selectInfo = dataBase->select(int::Parse(idBox->Text), compares);
					if (!(selectInfo == Info()))
					{
						resultBox->Text += "ID: " + idBox->Text + "\r\n"
							+ "Surname: " + gcnew String(selectInfo.surname.data()) + "\r\n" +
							"Name: " + gcnew String(selectInfo.name.data()) + "\r\n" +
							"Amount of compares: " + Convert::ToString(compares) + "\r\n\r\n";
					}
					else
						MessageBox::Show("Didn`t find row with such primary key\r\nAmount of compares: "
							+ Convert::ToString(compares), "Error");
				}
				else
				{
					MessageBox::Show("Incorrect input", "Error");
				}
			}
			else if (insertButton->Checked)
			{
				if (inputCheck())
				{
					bool result = dataBase->insert(int::Parse(idBox->Text),
						Info(msclr::interop::marshal_as<std::string>(nameBox->Text),
							msclr::interop::marshal_as<std::string>(surnameBox->Text)));
					if (result)
						MessageBox::Show("Inserted the row", "Done");
					else
						MessageBox::Show("Row with an equal primary key has been already created", "Error");
				}
				else
				{
					MessageBox::Show("Incorrect input", "Error");
				}
			}
			else if (updateButton->Checked)
			{
				if (inputCheck())
				{
					bool result = dataBase->update(int::Parse(idBox->Text),
						Info(msclr::interop::marshal_as<std::string>(nameBox->Text),
							msclr::interop::marshal_as<std::string>(surnameBox->Text)));
					if (result)
					{
						resultBox->Text += "Updated:\r\nID: " + idBox->Text + "\r\n"
							+ "Surname: " + surnameBox->Text + "\r\n" +
							"Name: " + nameBox->Text + "\r\n\r\n";
					}
					else
					{
						MessageBox::Show("Didn`t find row with such primary key. Didn`t update", "Error");
					}
				}
				else
				{
					MessageBox::Show("Incorrect input", "Error");
				}
			}
			else if (deleteButton->Checked)
			{
				if (inputCheck())
				{
					bool result = dataBase->erase(int::Parse(idBox->Text));
					if (result)
						resultBox->Text += "Deleted: " + idBox->Text + "\r\n\r\n";
					else
					{
						MessageBox::Show("Didn`t find row with such primary key. Didn`t delete", "Error");
					}
				}
				else
				{
					MessageBox::Show("Incorrect input", "Error");
				}
			}
			else if (generateButton->Checked)
			{
				if (dataBase->isNotEmpty())
					MessageBox::Show("There are already created rows. Delete them before generate test rows", "Error");
				else
				{
					std::string checkGenAmount = msclr::interop::marshal_as<std::string>(genAmountBox->Text);
					bool validate = !(checkGenAmount.find_first_not_of("0123456789") != std::string::npos ||
						stoi(checkGenAmount) == 0);
					if (validate)
					{
						int rowsAmount = int::Parse(genAmountBox->Text);
						for (int i = 0; i < rowsAmount; i++)
						{
							dataBase->insert(i, Info("Name" + std::to_string(i), "Surname" + std::to_string(i)));
						}
						MessageBox::Show("Created rows with test data (NameN, SurnameN)", "Done");
					}
					else
					{
						MessageBox::Show("Incorrect input", "Error");
					}
				}
			}
		}

		System::Void selectButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			changeAccessibility(selectButton);
		}

		System::Void deleteButton_CheckedChanged(Object^ sender, EventArgs^ e) {
			changeAccessibility(deleteButton);
		}

		System::Void generateButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			genAmountBox->Text = "0";
			genAmountBox->Visible = !genAmountBox->Visible;
			label4->Visible = !label4->Visible;
			changeAccessibility(generateButton);
		}

		System::Void changeAccessibility(RadioButton^ button)
		{
			if (button->Checked)
			{
				nameBox->Text = " ";
				nameBox->ReadOnly = true;
				surnameBox->Text = " ";
				surnameBox->ReadOnly = true;
				if (button->Name == "generateButton")
				{
					idBox->Text = "";
					idBox->ReadOnly = true;
				}
			}
			else
			{
				nameBox->ReadOnly = false;
				surnameBox->ReadOnly = false;
				nameBox->Text = "";
				surnameBox->Text = "";
				if (button->Name == "generateButton")
				{
					idBox->Text = "";
					idBox->ReadOnly = false;
				}
			}
		}

		System::Boolean inputCheck() {
			std::string checkId = msclr::interop::marshal_as<std::string>(idBox->Text);
			if (System::String::IsNullOrEmpty(idBox->Text) ||
				System::String::IsNullOrEmpty(nameBox->Text) ||
				System::String::IsNullOrEmpty(surnameBox->Text))
				return false;
			if (checkId.find_first_not_of("0123456789") != std::string::npos)
				return false;
			return true;
		}

		System::Void dropButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (dataBase->isNotEmpty())
			{
				auto choice = MessageBox::Show("Are you sure?", "Drop DB", MessageBoxButtons::YesNo);
				if (choice == System::Windows::Forms::DialogResult::Yes)
				{
					dataBase->~AVL_tree();
					resultBox->Text += "Dropped DB\r\n\r\n";
				}
			}
			else
			{
				MessageBox::Show("Database is empty", "Error");
			}
		}

		System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) 
		{
			dataBase->serialize("DB.bin");
			dataBase->~AVL_tree();
		}
	};
}
