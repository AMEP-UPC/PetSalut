#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label8;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panelConfirmacion;
	private: System::Windows::Forms::Label^ labelConfirmacion;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonCerrarConfirmacion;

	private: System::Void exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que también oculta todos los controles dentro de él
		this->panel1->Visible = false;
	}
	private: System::Void nobutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que también oculta todos los controles dentro de él
		this->panel1->Visible = false;
	}
	private: System::Void exitbuttonconfirmation_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que también oculta todos los controles dentro de él
		this->panel2->Visible = false;
		this->panel1->Visible = false;
	}
	private: System::Void deletebutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que también oculta todos los controles dentro de él
		this->panel2->Visible = true;
	}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelConfirmacion = (gcnew System::Windows::Forms::Panel());
			this->labelConfirmacion = (gcnew System::Windows::Forms::Label());
			this->buttonCerrarConfirmacion = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(176, 37);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 26);
			this->label8->TabIndex = 15;
			this->label8->Text = L"MY PETS";
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(162, 8);
			this->label6->MaximumSize = System::Drawing::Size(255, 255);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(140, 29);
			this->label6->TabIndex = 14;
			this->label6->Text = L"PETSALUT";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(117, 119);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(627, 326);
			this->panel1->TabIndex = 13;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::LightGray;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(3, 72);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(619, 181);
			this->panel2->TabIndex = 16;
			this->panel2->Visible = false;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(551, 141);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(53, 21);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Close";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::exitbuttonconfirmation_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(253, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 22);
			this->label2->TabIndex = 11;
			this->label2->Text = L"DELETE PET";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(214, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 22);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Your pet has been deleted.";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(603, 7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(19, 21);
			this->button3->TabIndex = 13;
			this->button3->Text = L"X";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::exitbutton_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(161, 140);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 67);
			this->button2->TabIndex = 12;
			this->button2->Text = L"NO";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::nobutton_Click);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(257, 37);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(132, 22);
			this->label7->TabIndex = 11;
			this->label7->Text = L"DELETE PET";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(358, 140);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 67);
			this->button1->TabIndex = 10;
			this->button1->Text = L"DELETE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::deletebutton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(182, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Are you SURE you want to DELETE\?";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// panelConfirmacion
			// 
			this->panelConfirmacion->Location = System::Drawing::Point(0, 0);
			this->panelConfirmacion->Name = L"panelConfirmacion";
			this->panelConfirmacion->Size = System::Drawing::Size(200, 100);
			this->panelConfirmacion->TabIndex = 0;
			// 
			// labelConfirmacion
			// 
			this->labelConfirmacion->Location = System::Drawing::Point(0, 0);
			this->labelConfirmacion->Name = L"labelConfirmacion";
			this->labelConfirmacion->Size = System::Drawing::Size(100, 23);
			this->labelConfirmacion->TabIndex = 0;
			// 
			// buttonCerrarConfirmacion
			// 
			this->buttonCerrarConfirmacion->Location = System::Drawing::Point(0, 0);
			this->buttonCerrarConfirmacion->Name = L"buttonCerrarConfirmacion";
			this->buttonCerrarConfirmacion->Size = System::Drawing::Size(75, 23);
			this->buttonCerrarConfirmacion->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(876, 596);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
