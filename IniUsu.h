﻿#pragma once
#include "TxIniciSessio.h"
#include "MenuProp.h"
#include "MenuCli.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniUsu
	/// </summary>
	public ref class IniUsu : public System::Windows::Forms::Form
	{
	public:
		IniUsu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~IniUsu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 24));
			this->label1->Location = System::Drawing::Point(427, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 44);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Iniciar Sessio";
			this->label1->Click += gcnew System::EventHandler(this, &IniUsu::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 11));
			this->textBox1->Location = System::Drawing::Point(414, 235);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(307, 26);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 11));
			this->textBox2->Location = System::Drawing::Point(414, 325);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(307, 26);
			this->textBox2->TabIndex = 2;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->label2->Location = System::Drawing::Point(483, 280);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(159, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Contrasenya";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->label3->Location = System::Drawing::Point(483, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 26);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Nom d\'usuari";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18));
			this->button1->Location = System::Drawing::Point(414, 394);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(307, 81);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Iniciar Sessio";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IniUsu::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->button2->Location = System::Drawing::Point(725, 325);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 26);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Mostrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &IniUsu::button2_Click);
			// 
			// IniUsu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"IniUsu";
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &IniUsu::IniUsu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			String^ username = textBox1->Text;
			String^ contrasenya = textBox2->Text;

			TxIniciSessio iniS;

			iniS.crear(username, contrasenya);
			iniS.executar();

			PassarellaUsuari^ usu = CercadoraUsuari::cercaUsuari(username);
			String^ tip = usu->getTipus();

			if (tip == "propietari") {

				PetSalut::MenuProp^ menuProp = gcnew PetSalut::MenuProp();

				this->Visible = false;

				menuProp->ShowDialog();

				this->Visible = true;
			}
			else {
				PetSalut::MenuCli^ menuCli = gcnew PetSalut::MenuCli();

				this->Visible = false;

				menuCli->ShowDialog();

				this->Visible = true;
			}

			this->Close();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message);
		}

	}
	private: System::Void IniUsu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	this->textBox2->UseSystemPasswordChar = !this->textBox2->UseSystemPasswordChar;


}
};
}