#pragma once
#include <thread>
#include <chrono>
#include "Lista.h"
#include <string>

namespace Proyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Lista* lista;
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnAnadir;
	private: System::Windows::Forms::TextBox^ txtNumber;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnAnadir = (gcnew System::Windows::Forms::Button());
			this->txtNumber = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(76, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(392, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Base para sistema de mátricula";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(393, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cerrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 111);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(395, 20);
			this->textBox1->TabIndex = 4;
			// 
			// btnAnadir
			// 
			this->btnAnadir->Location = System::Drawing::Point(73, 149);
			this->btnAnadir->Name = L"btnAnadir";
			this->btnAnadir->Size = System::Drawing::Size(97, 23);
			this->btnAnadir->TabIndex = 6;
			this->btnAnadir->Text = L"añadir";
			this->btnAnadir->UseVisualStyleBackColor = true;
			this->btnAnadir->Click += gcnew System::EventHandler(this, &MyForm::btnAnadir_Click);
			// 
			// txtNumber
			// 
			this->txtNumber->Location = System::Drawing::Point(195, 149);
			this->txtNumber->Name = L"txtNumber";
			this->txtNumber->Size = System::Drawing::Size(29, 20);
			this->txtNumber->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 321);
			this->Controls->Add(this->txtNumber);
			this->Controls->Add(this->btnAnadir);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// set textbox
		this->textBox1->Text="Bye!";
		// set button state
		this->button1->Enabled = false;

		std::this_thread::sleep_for(std::chrono::seconds(3));
		Close();
	}
	private: System::Void btnAnadir_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lista == NULL) {
			lista = new Lista();
		}
		int value = Convert::ToInt32(this->txtNumber->Text);
		lista->insertEnd(value);
		this->txtNumber->Text = "";
		std::string result = lista->toString();
		this->textBox1->Text = gcnew String(result.c_str());
	}
};

	
}
