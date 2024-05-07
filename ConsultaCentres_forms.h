#pragma once
#include <string>
#include <iostream>
#include "PassarellaClinica.h"
#include "TxConsultarCentres.h"
#include "PassarellaCentre.h"
#include "CercadoraCentre.h"
#include "Ordinador.h"
#include "Delete_Mascota_forms.h"
#include "Crea_Mascota_forms.h"
#include "CercadoraClinica.h"

namespace PetSalut {
	using namespace std;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultaCentre_forms
	/// </summary>
	public ref class ConsultaCentres_forms : public System::Windows::Forms::Form
	{
	public:
		ConsultaCentres_forms(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ConsultaCentres_forms()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ petsaludlabel;
	private: System::Windows::Forms::Label^ mypetslabel;
	private: System::Windows::Forms::ComboBox^ centreList;


	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ eliminabutton;
	private: System::Windows::Forms::Button^ registrarcentrebutton;





	private: System::Windows::Forms::Panel^ descriptionPannel;


	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verifica si hay al menos un elemento seleccionado en el ComboBox
		if (centreList->SelectedIndex != -1) {
			// Si hay un elemento seleccionado, muestra el panel de descripción
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();
			// Obtén la mascota seleccionada del ComboBox
			String^ centreSeleccionat = centreList->SelectedItem->ToString();

			// Extrae el chip de la mascota seleccionada (asumiendo que el chip está entre paréntesis)
			int indiceParentesisAbierto = centreSeleccionat->IndexOf('(');
			int indiceParentesisCerrado = centreSeleccionat->IndexOf(')');
			String^ numero_IDmas = centreSeleccionat->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			//int chip = Int32::Parse(numero_IDmas);

			// Utiliza el chip para buscar y obtener más información de la mascota
			CercadoraCentre^ cercadora = gcnew CercadoraCentre();
			PassarellaCentre^ centre = cercadora->cercaCentre(numero_IDmas);

			// Muestra la información de la mascota en el panel de descripción
			// Por ejemplo, podrías mostrar el chip, el nombre, la fecha de nacimiento, etc.
			// Aquí se muestra el chip, nombre, fecha de nacimiento, descripción, propietario y tipo
			Label^ labelID = gcnew Label();
			labelID->Text = "Numero_ID: " + centre->Numero_ID;
			labelID->Location = Point(10, 10); // Establece la posición del label dentro del panel
			labelID->AutoSize = true;
			descriptionPannel->Controls->Add(labelID);

			Label^ labelNombre = gcnew Label();
			labelNombre->Text = "Nom: " + centre->Nom;
			labelNombre->Location = Point(10, labelID->Bottom + 5);
			labelNombre->AutoSize = true;
			descriptionPannel->Controls->Add(labelNombre);

			Label^ labelTelefon = gcnew Label();
			labelTelefon->Text = "Telefon" + centre->Telefon;
			labelTelefon->Location = Point(10, labelNombre->Bottom + 5); // Establece la posición del label debajo del anterior
			labelTelefon->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto
			descriptionPannel->Controls->Add(labelTelefon);

			Label^ labelClinica = gcnew Label();
			labelClinica->Text = "Clinica: " + centre->Clinica;
			labelClinica->MaximumSize = System::Drawing::Size(descriptionPannel->Width - 10, 0);
			labelClinica->Location = Point(10, labelTelefon->Bottom + 5); // Establece la posición del label debajo del anterior
			labelClinica->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto
			descriptionPannel->Controls->Add(labelClinica);

		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error o realiza alguna otra acción según tus necesidades
			MessageBox::Show("Por favor, selecciona una mascota antes de consultar.");
		}
	}
	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {


		//Usar aqui la variable ordenador para obtener el passarela propietari

		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();

		PassarellaClinica^ clinica = CercadoraClinica::cercaClinica(usuari->getUsername());

		TxConsultarCentres^ consultaCentres = TxConsultarCentres::crear(clinica);
		vector<String> centres = consultaCentres->obteResultat();
		// Limpiar el ComboBox
		centreList->Items->Clear();
		CercadoraCentre^ cercadora = gcnew CercadoraCentre();
		// Llenar el ComboBox con los identificadores de mascotas
		for (int i = 0; i < centres.size(); ++i) {

			PassarellaCentre^ centre = cercadora->cercaCentre(centres[i]);

			String^ numero_ID = centre->Numero_ID;
			String^ nombre = centre->Nom;

			// Concatenar el chip y el nombre y agregarlos a la lista
			String^ infoMascota = nombre + " (" + numero_ID + ")";
			centreList->Items->Add(infoMascota);
		}



	}


	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::Elimina_Mascota_forms^ elimMasc = gcnew PetSalut::Elimina_Mascota_forms();

		this->Visible = false;

		elimMasc->ShowDialog();

		this->Visible = true;

	}

	private: System::Void registrarbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::Crea_Mascota_forms^ creaMasc = gcnew PetSalut::Crea_Mascota_forms();

		this->Visible = false;

		creaMasc->ShowDialog();

		this->Visible = true;

	}
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->petsaludlabel = (gcnew System::Windows::Forms::Label());
			this->mypetslabel = (gcnew System::Windows::Forms::Label());
			this->centreList = (gcnew System::Windows::Forms::ComboBox());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->registrarcentrebutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// petsaludlabel
			// 
			this->petsaludlabel->AutoSize = true;
			this->petsaludlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->petsaludlabel->Location = System::Drawing::Point(268, 7);
			this->petsaludlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->petsaludlabel->Name = L"petsaludlabel";
			this->petsaludlabel->Size = System::Drawing::Size(235, 46);
			this->petsaludlabel->TabIndex = 1;
			this->petsaludlabel->Text = L"PETSALUT";
			this->petsaludlabel->Click += gcnew System::EventHandler(this, &ConsultaCentres_forms::label1_Click);
			// 
			// mypetslabel
			// 
			this->mypetslabel->AutoSize = true;
			this->mypetslabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mypetslabel->Location = System::Drawing::Point(289, 53);
			this->mypetslabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mypetslabel->Name = L"mypetslabel";
			this->mypetslabel->Size = System::Drawing::Size(200, 39);
			this->mypetslabel->TabIndex = 2;
			this->mypetslabel->Text = L"My Centers";
			// 
			// centreList
			// 
			this->centreList->FormattingEnabled = true;
			this->centreList->Location = System::Drawing::Point(262, 136);
			this->centreList->Margin = System::Windows::Forms::Padding(2);
			this->centreList->Name = L"centreList";
			this->centreList->Size = System::Drawing::Size(200, 21);
			this->centreList->TabIndex = 3;
			this->centreList->Click += gcnew System::EventHandler(this, &ConsultaCentres_forms::fillPets);
			// 
			// consultar
			// 
			this->consultar->Location = System::Drawing::Point(476, 136);
			this->consultar->Margin = System::Windows::Forms::Padding(2);
			this->consultar->Name = L"consultar";
			this->consultar->Size = System::Drawing::Size(56, 19);
			this->consultar->TabIndex = 4;
			this->consultar->Text = L"consultar";
			this->consultar->UseVisualStyleBackColor = true;
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaCentres_forms::consultar_Click);
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionPannel->Location = System::Drawing::Point(181, 180);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(384, 197);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			this->descriptionPannel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConsultaCentres_forms::panel1_Paint);
			// 
			// eliminabutton
			// 
			this->eliminabutton->BackColor = System::Drawing::Color::Red;
			this->eliminabutton->Location = System::Drawing::Point(623, 331);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(135, 35);
			this->eliminabutton->TabIndex = 6;
			this->eliminabutton->Text = L"ELIMINAR Centre";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaCentres_forms::eliminabutton_click);
			// 
			// registrarcentrebutton
			// 
			this->registrarcentrebutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->registrarcentrebutton->Location = System::Drawing::Point(623, 277);
			this->registrarcentrebutton->Name = L"registrarcentrebutton";
			this->registrarcentrebutton->Size = System::Drawing::Size(135, 35);
			this->registrarcentrebutton->TabIndex = 7;
			this->registrarcentrebutton->Text = L"REGISTRAR Centre";
			this->registrarcentrebutton->UseVisualStyleBackColor = false;
			this->registrarcentrebutton->Click += gcnew System::EventHandler(this, &ConsultaCentres_forms::registrarbutton_Click);
			// 
			// ConsultaCentre_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 404);
			this->Controls->Add(this->registrarcentrebutton);
			this->Controls->Add(this->eliminabutton);
			this->Controls->Add(this->descriptionPannel);
			this->Controls->Add(this->consultar);
			this->Controls->Add(this->centreList);
			this->Controls->Add(this->mypetslabel);
			this->Controls->Add(this->petsaludlabel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConsultaCentre_forms";
			this->Text = L"ConsultaCentre_forms";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	};
}
