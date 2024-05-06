#pragma once
#include <string>
#include <iostream>
#include "PassarellaPropietari.h"
#include "TxConsultarMascotes.h"
#include "PassarellaMascota.h"
#include "CercadoraMascota.h"
#include "Ordinador.h"
#include "Delete_Mascota_forms.h"
#include "CercadoraPropietari.h"

namespace PetSalut {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultaMascota_forms
	/// </summary>
	public ref class ConsultaMascota_forms : public System::Windows::Forms::Form
	{
	public:
		ConsultaMascota_forms(void)
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
		~ConsultaMascota_forms()
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
	private: System::Windows::Forms::ComboBox^ petsList;

	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ eliminabutton;



	private: System::Windows::Forms::Panel^ descriptionPannel;

	
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verifica si hay al menos un elemento seleccionado en el ComboBox
		if (petsList->SelectedIndex != -1) {
			// Si hay un elemento seleccionado, muestra el panel de descripci�n
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();
			// Obt�n la mascota seleccionada del ComboBox
			String^ mascotaSeleccionada = petsList->SelectedItem->ToString();

			// Extrae el chip de la mascota seleccionada (asumiendo que el chip est� entre par�ntesis)
			int indiceParentesisAbierto = mascotaSeleccionada->IndexOf('(');
			int indiceParentesisCerrado = mascotaSeleccionada->IndexOf(')');
			String^ chipString = mascotaSeleccionada->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int chip = Int32::Parse(chipString);

			// Utiliza el chip para buscar y obtener m�s informaci�n de la mascota
			CercadoraMascota^ cercadora = gcnew CercadoraMascota();
			PassarellaMascota^ mascota = cercadora->cercaMascota(chip);

			// Muestra la informaci�n de la mascota en el panel de descripci�n
			// Por ejemplo, podr�as mostrar el chip, el nombre, la fecha de nacimiento, etc.
			// Aqu� se muestra el chip, nombre, fecha de nacimiento, descripci�n, propietario y tipo
			Label^ labelChip = gcnew Label();
			labelChip->Text = "Chip: " + mascota->Chip;
			labelChip->Location = Point(10, 10); // Establece la posici�n del label dentro del panel
			labelChip->AutoSize = true;
			descriptionPannel->Controls->Add(labelChip);

			Label^ labelNombre = gcnew Label();
			labelNombre->Text = "Nombre: " + mascota->Nom;
			labelNombre->Location = Point(10, labelChip->Bottom + 5);
			labelNombre->AutoSize = true;
			descriptionPannel->Controls->Add(labelNombre);

			Label^ labelFechaNacimiento = gcnew Label();
			labelFechaNacimiento->Text = "Fecha de Nacimiento: " + mascota->DataNaixament.ToString();
			labelFechaNacimiento->Location = Point(10, labelNombre->Bottom + 5); // Establece la posici�n del label debajo del anterior
			labelFechaNacimiento->AutoSize = true; // Ajusta autom�ticamente el tama�o del label al texto
			descriptionPannel->Controls->Add(labelFechaNacimiento);

			Label^ labelDescripcion = gcnew Label();
			labelDescripcion->Text = "Descripci�n: " + mascota->Descripcio;
			labelDescripcion->MaximumSize = System::Drawing::Size(descriptionPannel->Width - 10, 0);
			labelDescripcion->Location = Point(10, labelFechaNacimiento->Bottom + 5); // Establece la posici�n del label debajo del anterior
			labelDescripcion->AutoSize = true; // Ajusta autom�ticamente el tama�o del label al texto
			descriptionPannel->Controls->Add(labelDescripcion);

			Label^ labelPropietario = gcnew Label();
			labelPropietario->Text = "Propietario: " + mascota->Propietari;
			labelPropietario->Location = Point(10, labelDescripcion->Bottom + 5); // Establece la posici�n del label debajo del anterior
			labelPropietario->AutoSize = true; // Ajusta autom�ticamente el tama�o del label al texto
			descriptionPannel->Controls->Add(labelPropietario);

			Label^ labelTipo = gcnew Label();
			labelTipo->Text = "Tipo: " + mascota->Tipus;
			labelTipo->Location = Point(10, labelPropietario->Bottom + 5); // Establece la posici�n del label debajo del anterior
			descriptionPannel->Controls->Add(labelTipo);

			// A�ade m�s labels con la informaci�n que quieras mostrar
		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error o realiza alguna otra acci�n seg�n tus necesidades
			MessageBox::Show("Por favor, selecciona una mascota antes de consultar.");
		}
	}
	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {
	

		//Usar aqui la variable ordenador para obtener el passarela propietari

		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
	
		PassarellaPropietari^ propietari = CercadoraPropietari::cercaPropietari(usuari->getUsername());
		
		TxConsultarMascotes^ consultaMascotas = TxConsultarMascotes::crear(propietari);
		vector<int> mascotas = consultaMascotas->obteResultat();
		// Limpiar el ComboBox
		petsList->Items->Clear();
		CercadoraMascota^ cercadora = gcnew CercadoraMascota();
		// Llenar el ComboBox con los identificadores de mascotas
		for (int i = 0; i < mascotas.size(); ++i) {
			
			PassarellaMascota^ mascota = cercadora->cercaMascota(mascotas[i]);

			int chip = mascota->Chip;
			String^ nombre = mascota->Nom;

			// Concatenar el chip y el nombre y agregarlos a la lista
			String^ infoMascota = nombre + " (" + chip.ToString() + ")";
			petsList->Items->Add(infoMascota);
		}
		


	}


	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {
		
		PetSalut::Elimina_Mascota_forms^ elimMasc = gcnew PetSalut::Elimina_Mascota_forms();

		this->Visible = false;

		elimMasc -> ShowDialog();

		this->Visible = true;

	}
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->petsaludlabel = (gcnew System::Windows::Forms::Label());
			this->mypetslabel = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// petsaludlabel
			// 
			this->petsaludlabel->AutoSize = true;
			this->petsaludlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->petsaludlabel->Location = System::Drawing::Point(254, 7);
			this->petsaludlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->petsaludlabel->Name = L"petsaludlabel";
			this->petsaludlabel->Size = System::Drawing::Size(235, 46);
			this->petsaludlabel->TabIndex = 1;
			this->petsaludlabel->Text = L"PETSALUT";
			this->petsaludlabel->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::label1_Click);
			// 
			// mypetslabel
			// 
			this->mypetslabel->AutoSize = true;
			this->mypetslabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mypetslabel->Location = System::Drawing::Point(292, 54);
			this->mypetslabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mypetslabel->Name = L"mypetslabel";
			this->mypetslabel->Size = System::Drawing::Size(142, 39);
			this->mypetslabel->TabIndex = 2;
			this->mypetslabel->Text = L"My pets";
			// 
			// petsList
			// 
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(262, 136);
			this->petsList->Margin = System::Windows::Forms::Padding(2);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(200, 21);
			this->petsList->TabIndex = 3;
			this->petsList->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::fillPets);
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
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::consultar_Click);
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionPannel->Location = System::Drawing::Point(215, 170);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(384, 197);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			this->descriptionPannel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConsultaMascota_forms::panel1_Paint);
			// 
			// eliminabutton
			// 
			this->eliminabutton->BackColor = System::Drawing::Color::Red;
			this->eliminabutton->Location = System::Drawing::Point(623, 331);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(135, 35);
			this->eliminabutton->TabIndex = 6;
			this->eliminabutton->Text = L"ELIMINAR MASCOTA";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::eliminabutton_click);
			// 
			// ConsultaMascota_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 404);
			this->Controls->Add(this->eliminabutton);
			this->Controls->Add(this->descriptionPannel);
			this->Controls->Add(this->consultar);
			this->Controls->Add(this->petsList);
			this->Controls->Add(this->mypetslabel);
			this->Controls->Add(this->petsaludlabel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConsultaMascota_forms";
			this->Text = L"ConsultaMascota_forms";
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
