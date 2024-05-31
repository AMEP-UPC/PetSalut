#pragma once
#include "TxConsultaUsu.h"
#include "ModCli.h"
#include "ConsultaCentresForm.h"

namespace PetSalut {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InfoCli
	/// </summary>
	public ref class InfoCli : public System::Windows::Forms::Form
	{
	public:
		InfoCli(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//

			try {

				TxConsultaUsu conU;
				conU.crear();
				conU.executar();

				TxConsultaUsu::Resultat res = conU.obteResultat();

				this->nameLabel->Text = res.nom;
				this->mailLabel->Text = res.correu;
				this->phoneLabel->Text = res.telefon;
				this->usernameLabel->Text = res.username;
				this->passwordLabel->Text = res.contrasenya;
				this->descripcio->Text = res.descripcio;

			}

			catch (Exception^ ex)
			{
				MessageBox::Show("Error: " + ex->Message);
			}

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~InfoCli()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label9;
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ mailLabel;
	private: System::Windows::Forms::Label^ phoneLabel;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Label^ descripcio;
	private: System::Windows::Forms::Button^ Accepta_Tanca;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


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
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->mailLabel = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->descripcio = (gcnew System::Windows::Forms::Label());
			this->Accepta_Tanca = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(708, 284);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(172, 33);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Descripcio";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(28, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(279, 33);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Correu Electronic";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(708, 184);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(203, 33);
			this->label7->TabIndex = 41;
			this->label7->Text = L"Contrasenya";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(708, 84);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(212, 33);
			this->label6->TabIndex = 40;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(28, 284);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 33);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Telefon";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(28, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(231, 33);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Nom Complert";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(445, 51);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Informacio Clinica";
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->nameLabel->Location = System::Drawing::Point(29, 117);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(182, 30);
			this->nameLabel->TabIndex = 47;
			this->nameLabel->Text = L"Nombre aqui";
			// 
			// mailLabel
			// 
			this->mailLabel->AutoSize = true;
			this->mailLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mailLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->mailLabel->Location = System::Drawing::Point(29, 217);
			this->mailLabel->Name = L"mailLabel";
			this->mailLabel->Size = System::Drawing::Size(172, 30);
			this->mailLabel->TabIndex = 48;
			this->mailLabel->Text = L"Correo Aqui";
			// 
			// phoneLabel
			// 
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->phoneLabel->Location = System::Drawing::Point(29, 317);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(164, 30);
			this->phoneLabel->TabIndex = 49;
			this->phoneLabel->Text = L"phone Aqui";
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->usernameLabel->Location = System::Drawing::Point(709, 117);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(214, 30);
			this->usernameLabel->TabIndex = 51;
			this->usernameLabel->Text = L"username Aqui";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->passwordLabel->Location = System::Drawing::Point(709, 217);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(246, 30);
			this->passwordLabel->TabIndex = 52;
			this->passwordLabel->Text = L"contrasenya Aqui";
			// 
			// descripcio
			// 
			this->descripcio->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descripcio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->descripcio->Location = System::Drawing::Point(709, 317);
			this->descripcio->Name = L"descripcio";
			this->descripcio->Size = System::Drawing::Size(449, 130);
			this->descripcio->TabIndex = 53;
			this->descripcio->Text = L"descripcio Aqui";
			// 
			// Accepta_Tanca
			// 
			this->Accepta_Tanca->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Accepta_Tanca->Location = System::Drawing::Point(714, 543);
			this->Accepta_Tanca->Margin = System::Windows::Forms::Padding(2);
			this->Accepta_Tanca->Name = L"Accepta_Tanca";
			this->Accepta_Tanca->Size = System::Drawing::Size(209, 79);
			this->Accepta_Tanca->TabIndex = 54;
			this->Accepta_Tanca->Text = L"Mostrar Centres";
			this->Accepta_Tanca->UseVisualStyleBackColor = true;
			this->Accepta_Tanca->Click += gcnew System::EventHandler(this, &InfoCli::Accepta_Tanca_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(927, 543);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 79);
			this->button1->TabIndex = 55;
			this->button1->Text = L"Modificar Informacio";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &InfoCli::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(34, 543);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(215, 79);
			this->button2->TabIndex = 56;
			this->button2->Text = L"Tornar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &InfoCli::button2_Click);
			// 
			// InfoCli
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Accepta_Tanca);
			this->Controls->Add(this->descripcio);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->mailLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"InfoCli";
			this->Text = L"InfoCli";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ModCli^ modCli = gcnew PetSalut::ModCli();

		this->Visible = false;

		modCli->ShowDialog();

		this->Close();

	}
	private: System::Void Accepta_Tanca_Click(System::Object^ sender, System::EventArgs^ e) {
		PetSalut::ConsultaCentresForm^ consMasc = gcnew PetSalut::ConsultaCentresForm();

		this->Visible = false;

		consMasc->ShowDialog();

		this->Visible = true;
	}
};
}