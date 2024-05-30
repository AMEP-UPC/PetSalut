#pragma once
#pragma once
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
#include "CreaVisites_forms.h"
#include "EliminaVisita_forms.h"
#include "TxModificarValoracio.h"


namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultaVistes_forms
	/// </summary>
	public ref class ConsultaVistes_forms : public System::Windows::Forms::Form
	{
	public:
		ConsultaVistes_forms(void)
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
		~ConsultaVistes_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ registrarbutton;
	private: System::Windows::Forms::Button^ eliminabutton;
	private: System::Windows::Forms::Label^ visitesLabel;

	private: System::Windows::Forms::Label^ petsaludlabel;
	private: System::Windows::Forms::Label^ mascotalabel;
	private: System::Windows::Forms::ComboBox^ visitaList;
	private: System::Windows::Forms::Label^ visitaLabel;
	private: System::Windows::Forms::Panel^ descriptionPannel;
	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ valorarButton;
	private: System::Windows::Forms::ComboBox^ petsList;
	private: System::Windows::Forms::Panel^ hiddenPanel; // Panel oculto
	private: System::Windows::Forms::Button^ showHideButton; // Botón para mostrar/ocultar el panel
	private: System::Windows::Forms::Label^ trackBarLabel;
	private: System::Windows::Forms::Label^ valorartext;
	private: System::Windows::Forms::Button^ notaguardarButton;


	private: System::Windows::Forms::TrackBar^ trackBar;

	//	private: System::Windows::Forms::Button^ consultar;
	protected:

	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {


		//Usar aqui la variable ordenador para obtener el passarela propietari
		petsList->Items->Clear();
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
	private: System::Void visitalist_click(System::Object^ sender, System::EventArgs^ e) {
		visitaList->Items->Clear();
		if (petsList->SelectedIndex == -1) return;

		// Obtener el identificador de la mascota seleccionada
		String^ selectedPet = petsList->SelectedItem->ToString();
		int chipMascota = Int32::Parse(selectedPet->Split('(')[1]->Replace(")", "")->Trim());

		// Buscar la mascota por su chip usando la CercadoraMascota
		CercadoraMascota^ cercadora = gcnew CercadoraMascota();
		PassarellaMascota^ mascota = cercadora->cercaMascota(chipMascota);

		if (mascota == nullptr) {
			MessageBox::Show("No se pudo encontrar la mascota seleccionada.");
			return;
		}

		// Consultar las visitas de la mascota seleccionada
		TxConsultarVisites^ consultaVisites = TxConsultarVisites::crear(mascota);
		vector<int> visitesIDs = consultaVisites->obteResultat();
		// Limpiar el ComboBox de visitas
		visitaList->Items->Clear();

		CercadoraEsdeveniments^ cercadorEsdeveniments = gcnew CercadoraEsdeveniments();

		// Llenar el ComboBox de visitas y buscar nombre de eventos
		for (int i = 0; i < visitesIDs.size(); ++i) {
			PassarellaEsdeveniments^ esdeveniment = cercadorEsdeveniments->cercaEsdeveniment(visitesIDs[i]);

			int id = esdeveniment->Numeroid;
			String^ nomEsdeveniment = esdeveniment->Nom;
			String^ infoVisita = nomEsdeveniment + " (" + id.ToString() + ")";
			visitaList->Items->Add(infoVisita);

		}
	}

	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::EliminaVisita_forms^ elimVisita = gcnew PetSalut::EliminaVisita_forms();

		this->Visible = false;

		elimVisita->ShowDialog();

		this->Close();

	}

	private: System::Void registrarbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::CreaVisites_forms^ creaVisita = gcnew PetSalut::CreaVisites_forms();

		this->Visible = false;

		creaVisita->ShowDialog();

		this->Visible = true;

	}
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (visitaList->SelectedIndex != -1) {
			// Si hay un elemento seleccionado, muestra el panel de descripción
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();

			// Obtén el evento seleccionado del ComboBox
			String^ esdevenimentSeleccionado = visitaList->SelectedItem->ToString();

			// Extrae el numero_id del evento seleccionado (asumiendo que el ID está entre paréntesis)
			int indiceParentesisAbierto = esdevenimentSeleccionado->IndexOf('(');
			int indiceParentesisCerrado = esdevenimentSeleccionado->IndexOf(')');
			String^ idString = esdevenimentSeleccionado->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int numeroid = Int32::Parse(idString);

			// Utiliza el numeroid para buscar y obtener más información del evento y visita
			CercadoraEsdeveniments^ cercadora = gcnew CercadoraEsdeveniments();
			PassarellaEsdeveniments^ esdeveniment = cercadora->cercaEsdeveniment(numeroid);
			CercadoraVisita^ cercadorav = gcnew CercadoraVisita();
			PassarellaVisites^ visita = cercadorav->cercaVisita(numeroid);
			CercadoraMascota^ buscadorMascotas = gcnew CercadoraMascota();
			PassarellaMascota^ mascota = buscadorMascotas->cercaMascota(visita->Mascota);

			CercadoraCentre^ buscadorCentros = gcnew CercadoraCentre();
			PassarellaCentre^ centre = buscadorCentros->cercaCentre(visita->Centre);

			// Muestra la información del evento en el panel de descripción
			Label^ labelNumeroID = gcnew Label();
			labelNumeroID->Text = "Número de Visita: " + esdeveniment->Numeroid.ToString();
			labelNumeroID->Location = Point(10, 10);
			labelNumeroID->AutoSize = true;
			descriptionPannel->Controls->Add(labelNumeroID);

			Label^ labelNombre = gcnew Label();
			labelNombre->Text = "Motiu: " + esdeveniment->Nom;
			labelNombre->Location = Point(10, labelNumeroID->Bottom + 5);
			labelNombre->AutoSize = true;
			descriptionPannel->Controls->Add(labelNombre);

			Label^ labelFecha = gcnew Label();
			labelFecha->Text = "Data: " + esdeveniment->Data.ToString("dd/MM/yyyy");
			labelFecha->Location = Point(10, labelNombre->Bottom + 5);
			labelFecha->AutoSize = true;
			descriptionPannel->Controls->Add(labelFecha);

			Label^ labelHora = gcnew Label();
			labelHora->Text = "Hora: " + esdeveniment->Hora;
			labelHora->Location = Point(10, labelFecha->Bottom + 5);
			labelHora->AutoSize = true;
			descriptionPannel->Controls->Add(labelHora);

			Label^ labelMascota = gcnew Label();
			labelMascota->Text = "Mascota: " + mascota->Nom;
			labelMascota->Location = Point(10, labelHora->Bottom + 5);
			labelMascota->AutoSize = true;
			descriptionPannel->Controls->Add(labelMascota);

			Label^ labelCentre = gcnew Label();
			labelCentre->Text = "Centre: " + centre->Nom;
			labelCentre->Location = Point(10, labelMascota->Bottom + 5);
			labelCentre->AutoSize = true;
			descriptionPannel->Controls->Add(labelCentre);

			Label^ labelUbicacio = gcnew Label();
			labelUbicacio->Text = "Ubicació: " + centre->Ubicacio;
			labelUbicacio->Location = Point(10, labelCentre->Bottom + 5);
			labelUbicacio->AutoSize = true;
			descriptionPannel->Controls->Add(labelUbicacio);

			    this->valorarButton->Visible = true;

		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error
			MessageBox::Show("Por favor, selecciona un evento antes de consultar.");
		}
	}
	private: System::Void trackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
			   // Obtiene el valor actual del TrackBar
			   int valorSeleccionado = trackBar->Value;

			   // Actualiza el texto de la Label con el valor seleccionado
			   trackBarLabel->Text = "Nota: " + valorSeleccionado.ToString();
	}
		
	private: System::Void exitbutton_click(System::Object^ sender, System::EventArgs^ e) {
		this->hiddenPanel->Visible = false;

	}
	private: System::Void valorarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->hiddenPanel->Visible = true;

	}
	private: System::Void notaguardarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ esdevenimentSeleccionado = visitaList->SelectedItem->ToString();

		// Extrae el numero_id del evento seleccionado (asumiendo que el ID está entre paréntesis)
		int indiceParentesisAbierto = esdevenimentSeleccionado->IndexOf('(');
		int indiceParentesisCerrado = esdevenimentSeleccionado->IndexOf(')');
		String^ idString = esdevenimentSeleccionado->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
		int numeroid = Int32::Parse(idString);
		CercadoraVisita^ cercadorav = gcnew CercadoraVisita();
		PassarellaVisites^ visita = cercadorav->cercaVisita(numeroid);
		int numeroidcentre = visita->Centre;
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
		TxModificarValoracio^ valoracioModificada = TxModificarValoracio::prepara(numeroidcentre, numeroid, usuari->getUsername(), trackBar->Value);
		try {
			valoracioModificada->executa();
		}
		catch (Exception^ ex) {
			throw gcnew Exception("No s'ha pogut modificar l'item");

		}
		this->hiddenPanel->Visible = false;
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
			this->registrarbutton = (gcnew System::Windows::Forms::Button());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->visitesLabel = (gcnew System::Windows::Forms::Label());
			this->petsaludlabel = (gcnew System::Windows::Forms::Label());
			this->mascotalabel = (gcnew System::Windows::Forms::Label());
			this->visitaList = (gcnew System::Windows::Forms::ComboBox());
			this->visitaLabel = (gcnew System::Windows::Forms::Label());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->hiddenPanel = (gcnew System::Windows::Forms::Panel());
			this->valorartext = (gcnew System::Windows::Forms::Label());
			this->trackBarLabel = (gcnew System::Windows::Forms::Label());
			this->showHideButton = (gcnew System::Windows::Forms::Button());
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->valorarButton = (gcnew System::Windows::Forms::Button());
			this->notaguardarButton = (gcnew System::Windows::Forms::Button());
			this->hiddenPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// registrarbutton
			// 
			this->registrarbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->registrarbutton->Location = System::Drawing::Point(462, 297);
			this->registrarbutton->Name = L"registrarbutton";
			this->registrarbutton->Size = System::Drawing::Size(135, 35);
			this->registrarbutton->TabIndex = 8;
			this->registrarbutton->Text = L"REGISTRAR VISITA";
			this->registrarbutton->UseVisualStyleBackColor = false;
			this->registrarbutton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::registrarbutton_Click);
			// 
			// eliminabutton
			// 
			this->eliminabutton->BackColor = System::Drawing::Color::Red;
			this->eliminabutton->Location = System::Drawing::Point(462, 355);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(135, 35);
			this->eliminabutton->TabIndex = 9;
			this->eliminabutton->Text = L"ELIMINAR VISITA";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::eliminabutton_click);
			// 
			// petsList
			// 
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(176, 121);
			this->petsList->Margin = System::Windows::Forms::Padding(2);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(200, 21);
			this->petsList->TabIndex = 3;
			this->petsList->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::fillPets);
			// 
			// visitesLabel
			// 
			this->visitesLabel->AutoSize = true;
			this->visitesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->visitesLabel->Location = System::Drawing::Point(224, 64);
			this->visitesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->visitesLabel->Name = L"visitesLabel";
			this->visitesLabel->Size = System::Drawing::Size(157, 39);
			this->visitesLabel->TabIndex = 11;
			this->visitesLabel->Text = L"VISITES";
			this->visitesLabel->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::visitesLabel_Click);
			// 
			// petsaludlabel
			// 
			this->petsaludlabel->AutoSize = true;
			this->petsaludlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->petsaludlabel->Location = System::Drawing::Point(193, 9);
			this->petsaludlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->petsaludlabel->Name = L"petsaludlabel";
			this->petsaludlabel->Size = System::Drawing::Size(235, 46);
			this->petsaludlabel->TabIndex = 10;
			this->petsaludlabel->Text = L"PETSALUT";
			// 
			// mascotalabel
			// 
			this->mascotalabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mascotalabel->AutoSize = true;
			this->mascotalabel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mascotalabel->Location = System::Drawing::Point(96, 118);
			this->mascotalabel->Name = L"mascotalabel";
			this->mascotalabel->Size = System::Drawing::Size(75, 22);
			this->mascotalabel->TabIndex = 17;
			this->mascotalabel->Text = L"Mascota:";
			// 
			// visitaList
			// 
			this->visitaList->FormattingEnabled = true;
			this->visitaList->Location = System::Drawing::Point(100, 153);
			this->visitaList->Name = L"visitaList";
			this->visitaList->Size = System::Drawing::Size(348, 21);
			this->visitaList->TabIndex = 18;
			this->visitaList->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::visitalist_click);
			// 
			// visitaLabel
			// 
			this->visitaLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->visitaLabel->AutoSize = true;
			this->visitaLabel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->visitaLabel->Location = System::Drawing::Point(37, 150);
			this->visitaLabel->Name = L"visitaLabel";
			this->visitaLabel->Size = System::Drawing::Size(57, 22);
			this->visitaLabel->TabIndex = 19;
			this->visitaLabel->Text = L"Visita:";
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionPannel->Location = System::Drawing::Point(32, 191);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(425, 199);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			this->descriptionPannel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConsultaVistes_forms::descriptionPannel_Paint);
			// 
			// hiddenPanel
			// 
			this->hiddenPanel->BackColor = System::Drawing::Color::Gray;
			this->hiddenPanel->Controls->Add(this->notaguardarButton);
			this->hiddenPanel->Controls->Add(this->valorartext);
			this->hiddenPanel->Controls->Add(this->trackBarLabel);
			this->hiddenPanel->Controls->Add(this->showHideButton);
			this->hiddenPanel->Controls->Add(this->trackBar);
			this->hiddenPanel->Location = System::Drawing::Point(32, 191);
			this->hiddenPanel->Name = L"hiddenPanel";
			this->hiddenPanel->Size = System::Drawing::Size(424, 199);
			this->hiddenPanel->TabIndex = 21;
			this->hiddenPanel->Visible = false;
			// 
			// valorartext
			// 
			this->valorartext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->valorartext->AutoSize = true;
			this->valorartext->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->valorartext->Location = System::Drawing::Point(127, 13);
			this->valorartext->Name = L"valorartext";
			this->valorartext->Size = System::Drawing::Size(171, 22);
			this->valorartext->TabIndex = 21;
			this->valorartext->Text = L"Com valores la visita\?";
			// 
			// trackBarLabel
			// 
			this->trackBarLabel->AutoSize = true;
			this->trackBarLabel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->trackBarLabel->Location = System::Drawing::Point(72, 62);
			this->trackBarLabel->Name = L"trackBarLabel";
			this->trackBarLabel->Size = System::Drawing::Size(62, 22);
			this->trackBarLabel->TabIndex = 0;
			this->trackBarLabel->Text = L"Nota: 0";
			// 
			// showHideButton
			// 
			this->showHideButton->BackColor = System::Drawing::Color::Transparent;
			this->showHideButton->Location = System::Drawing::Point(389, 9);
			this->showHideButton->Name = L"showHideButton";
			this->showHideButton->Size = System::Drawing::Size(27, 26);
			this->showHideButton->TabIndex = 22;
			this->showHideButton->Text = L"X";
			this->showHideButton->UseVisualStyleBackColor = false;
			this->showHideButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::exitbutton_click);
			// 
			// trackBar
			// 
			this->trackBar->Location = System::Drawing::Point(112, 76);
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(198, 45);
			this->trackBar->TabIndex = 1;
			this->trackBar->Scroll += gcnew System::EventHandler(this, &ConsultaVistes_forms::trackBar_Scroll);
			// 
			// consultar
			// 
			this->consultar->Location = System::Drawing::Point(392, 121);
			this->consultar->Margin = System::Windows::Forms::Padding(2);
			this->consultar->Name = L"consultar";
			this->consultar->Size = System::Drawing::Size(56, 19);
			this->consultar->TabIndex = 5;
			this->consultar->Text = L"consultar";
			this->consultar->UseVisualStyleBackColor = true;
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::consultar_Click);
			// 
			// valorarButton
			// 
			this->valorarButton->Location = System::Drawing::Point(462, 153);
			this->valorarButton->Name = L"valorarButton";
			this->valorarButton->Size = System::Drawing::Size(135, 23);
			this->valorarButton->TabIndex = 20;
			this->valorarButton->Text = L"VALORAR VISITA";
			this->valorarButton->UseVisualStyleBackColor = true;
			this->valorarButton->Visible = false;
			this->valorarButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::valorarButton_Click);
			// 
			// notaguardarButton
			// 
			this->notaguardarButton->Location = System::Drawing::Point(271, 152);
			this->notaguardarButton->Name = L"notaguardarButton";
			this->notaguardarButton->Size = System::Drawing::Size(145, 35);
			this->notaguardarButton->TabIndex = 22;
			this->notaguardarButton->Text = L"GUARDAR";
			this->notaguardarButton->UseVisualStyleBackColor = true;
			this->notaguardarButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::notaguardarButton_Click);
			// 
			// ConsultaVistes_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 409);
			this->Controls->Add(this->hiddenPanel);
			this->Controls->Add(this->valorarButton);
			this->Controls->Add(this->consultar);
			this->Controls->Add(this->descriptionPannel);
			this->Controls->Add(this->visitaLabel);
			this->Controls->Add(this->visitaList);
			this->Controls->Add(this->mascotalabel);
			this->Controls->Add(this->visitesLabel);
			this->Controls->Add(this->petsaludlabel);
			this->Controls->Add(this->petsList);
			this->Controls->Add(this->eliminabutton);
			this->Controls->Add(this->registrarbutton);
			this->Name = L"ConsultaVistes_forms";
			this->Text = L"ConsultaVistes_forms";
			this->hiddenPanel->ResumeLayout(false);
			this->hiddenPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void visitesLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void descriptionPannel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
