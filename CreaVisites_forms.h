#pragma once
#pragma once
#include <random>
#include <string>
#include <iostream>
#include "PassarellaPropietari.h"
#include "TxConsultarMascotes.h"
#include "PassarellaMascota.h"
#include "CercadoraMascota.h"
#include "Ordinador.h"
#include "Delete_Mascota_forms.h"
#include "Crea_Mascota_forms.h"
#include "CercadoraPropietari.h"
#include "CercadoraCentre.h"
#include "PassarellaCentre.h"
#include "PassarellaEsdeveniments.h"
#include "PassarellaVisites.h"
#include "TxCrearVisita.h"
#include "TxCrearValoracio.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CreaVisites_forms
	/// </summary>
	public ref class CreaVisites_forms : public System::Windows::Forms::Form
	{
	public:
		CreaVisites_forms(void)
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
		~CreaVisites_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	private: System::Windows::Forms::Panel^ PanelVisita;
	private: System::Windows::Forms::Label^ admasclabel;
	private: System::Windows::Forms::ComboBox^ petsList;

	private: System::Windows::Forms::Label^ MascotaLabel;
	private: System::Windows::Forms::ComboBox^ HoursBox;

	private: System::Windows::Forms::Label^ adhoralabel;

	private: System::Windows::Forms::Label^ adCentrelabel;


	private: System::Windows::Forms::Label^ adMotiuLabel;


	private: System::Windows::Forms::Label^ titlelabel;


	private: System::Windows::Forms::Label^ CentreLabel;


	private: System::Windows::Forms::DateTimePicker^ DiaBox;




	private: System::Windows::Forms::Label^ nomLabel;
	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::Label^ HoraLabel;



	private: System::Windows::Forms::ComboBox^ CentresBox;
	private: System::Windows::Forms::Button^ guardarbutton;
	private: System::Windows::Forms::Label^ addatalabel;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ NomBox;

	private: System::Void fillCentres(System::Object^ sender, System::EventArgs^ e) {
		// Limpiar los ítems del ComboBox antes de llenarlo nuevamente
		CentresBox->Items->Clear();

		// Crear instancia de la buscadora de centros
		CercadoraCentre^ cercadora = gcnew CercadoraCentre();

		// Obtener la lista de todos los centros
		List<PassarellaCentre^>^ totsCentres = cercadora->CercatotsCentres();

		// Llenar el ComboBox con los objetos PassarellaCentre^
		for (int i = 0; i < totsCentres->Count; ++i) {
			PassarellaCentre^ centre = totsCentres[i];
			CentresBox->Items->Add(centre);
		}
	}



	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
		PassarellaPropietari^ propietari = CercadoraPropietari::cercaPropietari(usuari->getUsername());
		TxConsultarMascotes^ consultaMascotas = TxConsultarMascotes::crear(propietari);
		vector<int> mascotas = consultaMascotas->obteResultat();

		// Limpiar el ComboBox
		petsList->Items->Clear();

		CercadoraMascota^ cercadora = gcnew CercadoraMascota();

		// Llenar el ComboBox con objetos PassarellaMascota^
		for (int i = 0; i < mascotas.size(); ++i) {
			PassarellaMascota^ mascota = cercadora->cercaMascota(mascotas[i]);
			petsList->Items->Add(mascota); // Agregar el objeto mascota al ComboBox
		}
	}


	private: System::Void FillTimeComboBox(System::Object^ sender, System::EventArgs^ e) {
		System::TimeSpan startTime(9, 0, 0); // 9:00 AM
		// Hora de finalización
		System::TimeSpan endTime(21, 0, 0); // 9:00 PM
		// Intervalo de 30 minutos
		System::TimeSpan interval(0, 30, 0); // 30 minutos

		for (System::TimeSpan time = startTime; time <= endTime; time = time.Add(interval))
		{
			// Convertir el TimeSpan a una cadena en formato "hh:mm"
			String^ timeString = time.Hours.ToString("D2") + ":" + time.Minutes.ToString("D2");
			HoursBox->Items->Add(timeString);
		}

		// Establecer el primer elemento como seleccionado por defecto
		if (HoursBox->Items->Count > 0)
		{
			HoursBox->SelectedIndex = 0;
		}
	}
	private: System::Void guardarbutton_click(System::Object^ sender, System::EventArgs^ e) {
	
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		if (String::IsNullOrWhiteSpace(this->NomBox->Text)) {
			this->addatalabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->HoursBox->Text)) {
			this->adhoralabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->DiaBox->Text)) {
			this->addatalabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->petsList->Text)) {
			this->admasclabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->CentresBox->Text)) {
			this->adCentrelabel->Visible = true;
		}
		else {

			Ordinador^ ord = Ordinador::getInstance();
			PassarellaUsuari^ usuari = ord->obteUsuari();
			PassarellaMascota^ mascotaSeleccionada = safe_cast<PassarellaMascota^>(petsList->SelectedItem);
			int chipMascota = mascotaSeleccionada->Chip;
			PassarellaCentre^ centroSeleccionado = safe_cast<PassarellaCentre^>(CentresBox->SelectedItem);
			int numeroIDCentro = centroSeleccionado->Numero_ID;
			//AQUI NECESITO PASAR EN PETSLIST EL CHIP DEL PET SELECTED
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(1, 100000);
			int random_num = distrib(gen);
			TxCrearVisita^ nuevaVisita = TxCrearVisita::crear(this->NomBox->Text->ToString(), random_num,this->DiaBox->Value , this->HoursBox->Text->ToString(), usuari->getUsername(), chipMascota, numeroIDCentro);
			nuevaVisita->ejecutar();
			TxCrearValoracio^ novavaloracio = TxCrearValoracio::crear(numeroIDCentro, Convert::ToInt32(this->IDBox->Text), usuari->getUsername(), 0);
			novavaloracio->ejecutar();
			this->Close();

		}
	}
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PanelVisita = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->addatalabel = (gcnew System::Windows::Forms::Label());
			this->guardarbutton = (gcnew System::Windows::Forms::Button());
			this->NomBox = (gcnew System::Windows::Forms::TextBox());
			this->CentresBox = (gcnew System::Windows::Forms::ComboBox());
			this->admasclabel = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->MascotaLabel = (gcnew System::Windows::Forms::Label());
			this->HoursBox = (gcnew System::Windows::Forms::ComboBox());
			this->adhoralabel = (gcnew System::Windows::Forms::Label());
			this->adCentrelabel = (gcnew System::Windows::Forms::Label());
			this->adMotiuLabel = (gcnew System::Windows::Forms::Label());
			this->titlelabel = (gcnew System::Windows::Forms::Label());
			this->CentreLabel = (gcnew System::Windows::Forms::Label());
			this->DiaBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->nomLabel = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->HoraLabel = (gcnew System::Windows::Forms::Label());
			this->PanelVisita->SuspendLayout();
			this->SuspendLayout();
			// 
			// PanelVisita
			// 
			this->PanelVisita->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PanelVisita->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->PanelVisita->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PanelVisita->Controls->Add(this->button1);
			this->PanelVisita->Controls->Add(this->addatalabel);
			this->PanelVisita->Controls->Add(this->guardarbutton);
			this->PanelVisita->Controls->Add(this->NomBox);
			this->PanelVisita->Controls->Add(this->CentresBox);
			this->PanelVisita->Controls->Add(this->admasclabel);
			this->PanelVisita->Controls->Add(this->petsList);
			this->PanelVisita->Controls->Add(this->MascotaLabel);
			this->PanelVisita->Controls->Add(this->HoursBox);
			this->PanelVisita->Controls->Add(this->adhoralabel);
			this->PanelVisita->Controls->Add(this->adCentrelabel);
			this->PanelVisita->Controls->Add(this->adMotiuLabel);
			this->PanelVisita->Controls->Add(this->titlelabel);
			this->PanelVisita->Controls->Add(this->CentreLabel);
			this->PanelVisita->Controls->Add(this->DiaBox);
			this->PanelVisita->Controls->Add(this->nomLabel);
			this->PanelVisita->Controls->Add(this->dataLabel);
			this->PanelVisita->Controls->Add(this->HoraLabel);
			this->PanelVisita->Location = System::Drawing::Point(39, 41);
			this->PanelVisita->Name = L"PanelVisita";
			this->PanelVisita->Size = System::Drawing::Size(1109, 585);
			this->PanelVisita->TabIndex = 29;
			this->PanelVisita->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CreaVisites_forms::PanelVisita_Paint);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(839, 524);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 46);
			this->button1->TabIndex = 36;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreaVisites_forms::button1_Click);
			// 
			// addatalabel
			// 
			this->addatalabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addatalabel->AutoSize = true;
			this->addatalabel->ForeColor = System::Drawing::Color::Brown;
			this->addatalabel->Location = System::Drawing::Point(860, 267);
			this->addatalabel->Name = L"addatalabel";
			this->addatalabel->Size = System::Drawing::Size(82, 13);
			this->addatalabel->TabIndex = 35;
			this->addatalabel->Text = L"Required Field *";
			this->addatalabel->Visible = false;
			// 
			// guardarbutton
			// 
			this->guardarbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->guardarbutton->Location = System::Drawing::Point(965, 524);
			this->guardarbutton->Name = L"guardarbutton";
			this->guardarbutton->Size = System::Drawing::Size(120, 46);
			this->guardarbutton->TabIndex = 34;
			this->guardarbutton->Text = L"Guardar";
			this->guardarbutton->UseVisualStyleBackColor = true;
			this->guardarbutton->Click += gcnew System::EventHandler(this, &CreaVisites_forms::guardarbutton_click);
			// 
			// NomBox
			// 
			this->NomBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->NomBox->Location = System::Drawing::Point(122, 131);
			this->NomBox->Name = L"NomBox";
			this->NomBox->Size = System::Drawing::Size(732, 20);
			this->NomBox->TabIndex = 33;
			// 
			// CentresBox
			// 
			this->CentresBox->FormattingEnabled = true;
			this->CentresBox->Location = System::Drawing::Point(122, 416);
			this->CentresBox->Name = L"CentresBox";
			this->CentresBox->Size = System::Drawing::Size(732, 21);
			this->CentresBox->TabIndex = 32;
			this->CentresBox->Click += gcnew System::EventHandler(this, &CreaVisites_forms::fillCentres);
			// 
			// admasclabel
			// 
			this->admasclabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->admasclabel->AutoSize = true;
			this->admasclabel->ForeColor = System::Drawing::Color::Brown;
			this->admasclabel->Location = System::Drawing::Point(860, 345);
			this->admasclabel->Name = L"admasclabel";
			this->admasclabel->Size = System::Drawing::Size(82, 13);
			this->admasclabel->TabIndex = 31;
			this->admasclabel->Text = L"Required Field *";
			this->admasclabel->Visible = false;
			// 
			// petsList
			// 
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(122, 342);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(732, 21);
			this->petsList->TabIndex = 30;
			this->petsList->Click += gcnew System::EventHandler(this, &CreaVisites_forms::fillPets);
			// 
			// MascotaLabel
			// 
			this->MascotaLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->MascotaLabel->AutoSize = true;
			this->MascotaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MascotaLabel->Location = System::Drawing::Point(118, 319);
			this->MascotaLabel->Name = L"MascotaLabel";
			this->MascotaLabel->Size = System::Drawing::Size(70, 20);
			this->MascotaLabel->TabIndex = 28;
			this->MascotaLabel->Text = L"Mascota";
			// 
			// HoursBox
			// 
			this->HoursBox->FormattingEnabled = true;
			this->HoursBox->Location = System::Drawing::Point(122, 264);
			this->HoursBox->Name = L"HoursBox";
			this->HoursBox->Size = System::Drawing::Size(732, 21);
			this->HoursBox->TabIndex = 27;
			this->HoursBox->Click += gcnew System::EventHandler(this, &CreaVisites_forms::FillTimeComboBox);
			// 
			// adhoralabel
			// 
			this->adhoralabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->adhoralabel->AutoSize = true;
			this->adhoralabel->ForeColor = System::Drawing::Color::Brown;
			this->adhoralabel->Location = System::Drawing::Point(860, 203);
			this->adhoralabel->Name = L"adhoralabel";
			this->adhoralabel->Size = System::Drawing::Size(82, 13);
			this->adhoralabel->TabIndex = 25;
			this->adhoralabel->Text = L"Required Field *";
			this->adhoralabel->Visible = false;
			// 
			// adCentrelabel
			// 
			this->adCentrelabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->adCentrelabel->AutoSize = true;
			this->adCentrelabel->ForeColor = System::Drawing::Color::Brown;
			this->adCentrelabel->Location = System::Drawing::Point(860, 419);
			this->adCentrelabel->Name = L"adCentrelabel";
			this->adCentrelabel->Size = System::Drawing::Size(82, 13);
			this->adCentrelabel->TabIndex = 24;
			this->adCentrelabel->Text = L"Required Field *";
			this->adCentrelabel->Visible = false;
			// 
			// adMotiuLabel
			// 
			this->adMotiuLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->adMotiuLabel->AutoSize = true;
			this->adMotiuLabel->ForeColor = System::Drawing::Color::Brown;
			this->adMotiuLabel->Location = System::Drawing::Point(860, 134);
			this->adMotiuLabel->Name = L"adMotiuLabel";
			this->adMotiuLabel->Size = System::Drawing::Size(82, 13);
			this->adMotiuLabel->TabIndex = 22;
			this->adMotiuLabel->Text = L"Required Field *";
			this->adMotiuLabel->Visible = false;
			// 
			// titlelabel
			// 
			this->titlelabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->titlelabel->AutoSize = true;
			this->titlelabel->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->titlelabel->Location = System::Drawing::Point(525, 33);
			this->titlelabel->Name = L"titlelabel";
			this->titlelabel->Size = System::Drawing::Size(128, 22);
			this->titlelabel->TabIndex = 11;
			this->titlelabel->Text = L"NOVA VISITA";
			// 
			// CentreLabel
			// 
			this->CentreLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->CentreLabel->AutoSize = true;
			this->CentreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->CentreLabel->Location = System::Drawing::Point(118, 393);
			this->CentreLabel->Name = L"CentreLabel";
			this->CentreLabel->Size = System::Drawing::Size(57, 20);
			this->CentreLabel->TabIndex = 9;
			this->CentreLabel->Text = L"Centre";
			// 
			// DiaBox
			// 
			this->DiaBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DiaBox->Location = System::Drawing::Point(122, 197);
			this->DiaBox->Name = L"DiaBox";
			this->DiaBox->Size = System::Drawing::Size(732, 20);
			this->DiaBox->TabIndex = 2;
			// 
			// nomLabel
			// 
			this->nomLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->nomLabel->AutoSize = true;
			this->nomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->nomLabel->Location = System::Drawing::Point(118, 108);
			this->nomLabel->Name = L"nomLabel";
			this->nomLabel->Size = System::Drawing::Size(48, 20);
			this->nomLabel->TabIndex = 3;
			this->nomLabel->Text = L"Motiu";
			// 
			// dataLabel
			// 
			this->dataLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataLabel->AutoSize = true;
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->dataLabel->Location = System::Drawing::Point(118, 174);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(44, 20);
			this->dataLabel->TabIndex = 4;
			this->dataLabel->Text = L"Data";
			// 
			// HoraLabel
			// 
			this->HoraLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->HoraLabel->AutoSize = true;
			this->HoraLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->HoraLabel->Location = System::Drawing::Point(118, 241);
			this->HoraLabel->Name = L"HoraLabel";
			this->HoraLabel->Size = System::Drawing::Size(44, 20);
			this->HoraLabel->TabIndex = 5;
			this->HoraLabel->Text = L"Hora";
			// 
			// CreaVisites_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->PanelVisita);
			this->Name = L"CreaVisites_forms";
			this->Text = L"CreaVisites_forms";
			this->PanelVisita->ResumeLayout(false);
			this->PanelVisita->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void chipLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void cumpleLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tipusLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void descripcioLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PanelVisita_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
