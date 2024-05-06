﻿#pragma once
#include "TxRegistraUsu.h"
#include "MenuProp.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de RegU
	/// </summary>
	public ref class RegProp : public System::Windows::Forms::Form
	{
	public:
		RegProp(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		bool mostra1 = false;
		String^ tipusSelected = "Propietari";
		private: System::Windows::Forms::Label^ PassLong;
		private: System::Windows::Forms::Label^ DiffPasswd;
		private: System::Windows::Forms::Label^ label9;
		private: System::Windows::Forms::TextBox^ descripcio;
		private: System::Windows::Forms::Label^ tipusLabel;
		private: System::Windows::Forms::RadioButton^ radioPropietariButton;
		private: System::Windows::Forms::RadioButton^ radioClinicaButton;


	public:

	public:
		bool mostra2 = false;


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~RegProp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ mail;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::MaskedTextBox^ phone;
	private: System::Windows::Forms::MaskedTextBox^ date;
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::TextBox^ passwd1;
	private: System::Windows::Forms::TextBox^ passwd2;
	private: System::Windows::Forms::Button^ valid_button;
	private: System::Windows::Forms::Button^ reg_button;
	private: System::Windows::Forms::Button^ show1;
	private: System::Windows::Forms::Button^ show2;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mail = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->phone = (gcnew System::Windows::Forms::MaskedTextBox());
			this->date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->passwd1 = (gcnew System::Windows::Forms::TextBox());
			this->passwd2 = (gcnew System::Windows::Forms::TextBox());
			this->valid_button = (gcnew System::Windows::Forms::Button());
			this->reg_button = (gcnew System::Windows::Forms::Button());
			this->show1 = (gcnew System::Windows::Forms::Button());
			this->show2 = (gcnew System::Windows::Forms::Button());
			this->PassLong = (gcnew System::Windows::Forms::Label());
			this->DiffPasswd = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->descripcio = (gcnew System::Windows::Forms::TextBox());
			this->tipusLabel = (gcnew System::Windows::Forms::Label());
			this->radioPropietariButton = (gcnew System::Windows::Forms::RadioButton());
			this->radioClinicaButton = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 25);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(236, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Registrar-se";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(27, 98);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 36);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nom Complert";
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(37, 143);
			this->name->Margin = System::Windows::Forms::Padding(4);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(360, 22);
			this->name->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(27, 222);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(246, 36);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Correu Electronic";
			// 
			// mail
			// 
			this->mail->Location = System::Drawing::Point(37, 266);
			this->mail->Margin = System::Windows::Forms::Padding(4);
			this->mail->Name = L"mail";
			this->mail->Size = System::Drawing::Size(360, 22);
			this->mail->TabIndex = 5;
			this->mail->TextChanged += gcnew System::EventHandler(this, &RegProp::mail_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(27, 345);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 36);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Telefon";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(27, 533);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(224, 36);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Data Naixement";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(933, 98);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(190, 36);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(933, 222);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(183, 36);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Contrasenya";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(933, 345);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(316, 36);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Verifica la contrasenya";
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(37, 389);
			this->phone->Margin = System::Windows::Forms::Padding(4);
			this->phone->Mask = L"+00 000 000 000";
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(360, 22);
			this->phone->TabIndex = 20;
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(37, 577);
			this->date->Margin = System::Windows::Forms::Padding(4);
			this->date->Mask = L"00/00/0000";
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(360, 22);
			this->date->TabIndex = 21;
			this->date->ValidatingType = System::DateTime::typeid;
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(941, 143);
			this->username->Margin = System::Windows::Forms::Padding(4);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(475, 22);
			this->username->TabIndex = 22;
			// 
			// passwd1
			// 
			this->passwd1->Location = System::Drawing::Point(941, 266);
			this->passwd1->Margin = System::Windows::Forms::Padding(4);
			this->passwd1->Name = L"passwd1";
			this->passwd1->Size = System::Drawing::Size(475, 22);
			this->passwd1->TabIndex = 23;
			this->passwd1->UseSystemPasswordChar = true;
			// 
			// passwd2
			// 
			this->passwd2->Location = System::Drawing::Point(941, 389);
			this->passwd2->Margin = System::Windows::Forms::Padding(4);
			this->passwd2->Name = L"passwd2";
			this->passwd2->Size = System::Drawing::Size(475, 22);
			this->passwd2->TabIndex = 24;
			this->passwd2->UseSystemPasswordChar = true;
			// 
			// valid_button
			// 
			this->valid_button->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->valid_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->valid_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->valid_button->Location = System::Drawing::Point(35, 649);
			this->valid_button->Margin = System::Windows::Forms::Padding(4);
			this->valid_button->Name = L"valid_button";
			this->valid_button->Size = System::Drawing::Size(364, 80);
			this->valid_button->TabIndex = 25;
			this->valid_button->Text = L"VALIDAR INFORMACIO";
			this->valid_button->UseVisualStyleBackColor = false;
			this->valid_button->Click += gcnew System::EventHandler(this, &RegProp::valid_button_Click);
			// 
			// reg_button
			// 
			this->reg_button->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->reg_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->reg_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reg_button->Location = System::Drawing::Point(941, 597);
			this->reg_button->Margin = System::Windows::Forms::Padding(4);
			this->reg_button->Name = L"reg_button";
			this->reg_button->Size = System::Drawing::Size(476, 80);
			this->reg_button->TabIndex = 26;
			this->reg_button->Text = L"REGISTRAR-SE";
			this->reg_button->UseVisualStyleBackColor = false;
			this->reg_button->Visible = false;
			this->reg_button->Click += gcnew System::EventHandler(this, &RegProp::reg_button_Click);
			// 
			// show1
			// 
			this->show1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->show1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->show1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->show1->Location = System::Drawing::Point(1425, 266);
			this->show1->Margin = System::Windows::Forms::Padding(4);
			this->show1->Name = L"show1";
			this->show1->Size = System::Drawing::Size(91, 25);
			this->show1->TabIndex = 27;
			this->show1->Text = L"mostrar";
			this->show1->UseVisualStyleBackColor = false;
			// 
			// show2
			// 
			this->show2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->show2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->show2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->show2->Location = System::Drawing::Point(1425, 389);
			this->show2->Margin = System::Windows::Forms::Padding(4);
			this->show2->Name = L"show2";
			this->show2->Size = System::Drawing::Size(91, 25);
			this->show2->TabIndex = 28;
			this->show2->Text = L"mostrar";
			this->show2->UseVisualStyleBackColor = false;
			// 
			// PassLong
			// 
			this->PassLong->AutoSize = true;
			this->PassLong->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PassLong->ForeColor = System::Drawing::Color::Red;
			this->PassLong->Location = System::Drawing::Point(899, 624);
			this->PassLong->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PassLong->Name = L"PassLong";
			this->PassLong->Size = System::Drawing::Size(407, 25);
			this->PassLong->TabIndex = 29;
			this->PassLong->Text = L"La contrasenya ha de tenir 6 caracters o mes!";
			this->PassLong->Visible = false;
			// 
			// DiffPasswd
			// 
			this->DiffPasswd->AutoSize = true;
			this->DiffPasswd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DiffPasswd->ForeColor = System::Drawing::Color::Red;
			this->DiffPasswd->Location = System::Drawing::Point(964, 624);
			this->DiffPasswd->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DiffPasswd->Name = L"DiffPasswd";
			this->DiffPasswd->Size = System::Drawing::Size(302, 25);
			this->DiffPasswd->TabIndex = 30;
			this->DiffPasswd->Text = L"La contrasenyes no coincideixen!";
			this->DiffPasswd->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(933, 468);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(155, 36);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Descripcio";
			// 
			// descripcio
			// 
			this->descripcio->Location = System::Drawing::Point(941, 512);
			this->descripcio->Margin = System::Windows::Forms::Padding(4);
			this->descripcio->Name = L"descripcio";
			this->descripcio->Size = System::Drawing::Size(475, 22);
			this->descripcio->TabIndex = 32;
			// 
			// tipusLabel
			// 
			this->tipusLabel->AutoSize = true;
			this->tipusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tipusLabel->Location = System::Drawing::Point(27, 442);
			this->tipusLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->tipusLabel->Name = L"tipusLabel";
			this->tipusLabel->Size = System::Drawing::Size(207, 36);
			this->tipusLabel->TabIndex = 33;
			this->tipusLabel->Text = L"Tipus d\'Usuari";
			// 
			// radioPropietariButton
			// 
			this->radioPropietariButton->AutoSize = true;
			this->radioPropietariButton->Checked = true;
			this->radioPropietariButton->Location = System::Drawing::Point(37, 487);
			this->radioPropietariButton->Margin = System::Windows::Forms::Padding(4);
			this->radioPropietariButton->Name = L"radioPropietariButton";
			this->radioPropietariButton->Size = System::Drawing::Size(86, 20);
			this->radioPropietariButton->TabIndex = 34;
			this->radioPropietariButton->TabStop = true;
			this->radioPropietariButton->Text = L"Propietari";
			this->radioPropietariButton->UseVisualStyleBackColor = true;
			// 
			// radioClinicaButton
			// 
			this->radioClinicaButton->AutoSize = true;
			this->radioClinicaButton->Location = System::Drawing::Point(188, 487);
			this->radioClinicaButton->Margin = System::Windows::Forms::Padding(4);
			this->radioClinicaButton->Name = L"radioClinicaButton";
			this->radioClinicaButton->Size = System::Drawing::Size(68, 20);
			this->radioClinicaButton->TabIndex = 35;
			this->radioClinicaButton->Text = L"Clinica";
			this->radioClinicaButton->UseVisualStyleBackColor = true;
			this->radioClinicaButton->CheckedChanged += gcnew System::EventHandler(this, &RegProp::radioClinicaButton_CheckedChanged);
			// 
			// RegProp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1579, 814);
			this->Controls->Add(this->radioClinicaButton);
			this->Controls->Add(this->radioPropietariButton);
			this->Controls->Add(this->tipusLabel);
			this->Controls->Add(this->descripcio);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->DiffPasswd);
			this->Controls->Add(this->PassLong);
			this->Controls->Add(this->show2);
			this->Controls->Add(this->show1);
			this->Controls->Add(this->reg_button);
			this->Controls->Add(this->valid_button);
			this->Controls->Add(this->passwd2);
			this->Controls->Add(this->passwd1);
			this->Controls->Add(this->username);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->mail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"RegProp";
			this->Text = L"RegistrarUsuari";
			this->Load += gcnew System::EventHandler(this, &RegProp::RegProp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void valid_button_Click(System::Object^ sender, System::EventArgs^ e) {

		//Valida si el nombre de usuario esta disponible
		bool usernameValid = true;
		System::String^ usernameText = username->Text;
		//Tratar el username para validar

		System::String^ passwd1text = passwd1->Text;
		System::String^ passwd2text = passwd2->Text;

		if (usernameValid && (passwd1->Text == passwd2->Text)) {

			if (passwd1->Text->Length < 6) {

				PassLong->Visible = true;

			}
			else {

				DiffPasswd->Visible = false;
				PassLong->Visible = false;
				reg_button->Visible = true;

			}

		}
		else {

			DiffPasswd->Visible = true;

		}

	}
	private: System::Void reg_button_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			String^ usernameS = username->Text;
			String^ nomComplertS = name->Text;
			String^ contrasenyaS = passwd1->Text;
			String^ telefonS = phone->Text;
			String^ tipusS = tipusSelected;
			String^ correuElectronicS = mail->Text;
			String^ dataNaixementS = date->Text;
			String^ descripcioS = descripcio->Text;


			TxRegistraUsu regUsu;
			regUsu.crear(usernameS, contrasenyaS, nomComplertS, telefonS, tipusS, correuElectronicS, descripcioS, dataNaixementS);
			regUsu.executar();

			PetSalut::MenuProp^ menuProp = gcnew PetSalut::MenuProp();

			this->Visible = false;
			this->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error pantalla usuari: " + ex->Message);
		}

	}
	private: System::Void radioClinicaButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radioClinicaButton->Checked) {
			this->label5->Visible = false;
			this->date->Visible = false;
			this->radioPropietariButton->Checked = false;
			this->tipusSelected = "Clinica";
		}
		else {
			this->label5->Visible = true;
			this->date->Visible = true;
			this->radioPropietariButton->Checked = true;
			this->tipusSelected = "Propietari";
		}
	}
	private: System::Void RegProp_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void mail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}