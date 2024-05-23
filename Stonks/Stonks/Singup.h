#pragma once
#include "ArchiveSaver.h"


namespace Stonks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Singup : public System::Windows::Forms::Form
	{	public:
		Singup(void)	{		InitializeComponent();	}

	protected:
		~Singup()	{	if (components)	{		delete components;	}	}
	System::Windows::Forms::Button^ B_Login;
	System::Windows::Forms::Label^ L_Singup;
	System::Windows::Forms::TextBox^ TB_Username;
	System::Windows::Forms::TextBox^ TB_Password;
	System::Windows::Forms::TextBox^ TB_Email;
	System::Windows::Forms::Label^ L_Username;
	System::Windows::Forms::Label^ L_Password;
	System::Windows::Forms::Label^ L_Email;
	System::ComponentModel::Container ^components;

	void SignupForm_FormClosed(Object^ sender, FormClosedEventArgs^ e) {
		Application::Exit();}

	// Función de redimensionamiento ajustable para el formulario de registro
	System::Void Singup_Resize(System::Object^ sender, System::EventArgs^ e) {
		int formWidth = this->ClientSize.Width;
		int formHeight = this->ClientSize.Height;
		float porcen = 1 * (formWidth / 30);		float baseFontSize = porcen * 0.8F;
		TB_Username->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize*0.6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		TB_Email->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize * 0.6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		TB_Password->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize * 0.6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->FormClosed += gcnew FormClosedEventHandler(this, &Singup::SignupForm_FormClosed);

		// Ajustar el tamaño de los controles
		this->TB_Username->Size = System::Drawing::Size(formWidth / 4, formHeight / 5);
		this->B_Login->Size = System::Drawing::Size(formWidth / 6, formHeight / 9);
		this->TB_Password->Size = System::Drawing::Size(formWidth / 4, formHeight / 20);
		this->L_Singup->Size = System::Drawing::Size(formWidth / 4, formHeight / 20);
		this->TB_Email->Size = System::Drawing::Size(formWidth / 4, formHeight / 20);

		// Ajustar la ubicación de los controles
		this->L_Singup->Location = System::Drawing::Point(formWidth / 2.6, formHeight / 12);
		this->TB_Username->Location = System::Drawing::Point(formWidth / 2 - TB_Username->Width / 2, formHeight / 3.18);
		this->L_Username->Location = System::Drawing::Point(formWidth / 2.43, formHeight / 4.5);
		this->TB_Password->Location = System::Drawing::Point(formWidth / 2 - TB_Password->Width / 2, formHeight / 2.1);
		this->L_Password->Location = System::Drawing::Point(formWidth / 2.38, formHeight / 2.62);
		this->TB_Email->Location = System::Drawing::Point(formWidth / 2 - TB_Email->Width / 2, formHeight / 1.6);
		this->L_Email->Location = System::Drawing::Point(formWidth / 2.25 , formHeight / 1.852);
		this->B_Login->Location = System::Drawing::Point(formWidth / 2 - B_Login->Width / 2, formHeight /1.25);

		// Ajustar el tamaño de las fuentes en base al tamaño del formulario
		this->L_Singup->Font = (gcnew System::Drawing::Font(L"Times New Roman", porcen * 1.15F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point));
		this->B_Login->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point));
		this->L_Username->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point));
		this->L_Password->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point));
		this->L_Email->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point));
		B_Login->Font = (gcnew System::Drawing::Font(L"Times New Roman", baseFontSize*0.7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));

	}



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)	{
			this->B_Login = (gcnew System::Windows::Forms::Button());
			this->L_Singup = (gcnew System::Windows::Forms::Label());
			this->TB_Username = (gcnew System::Windows::Forms::TextBox());
			this->TB_Password = (gcnew System::Windows::Forms::TextBox());
			this->TB_Email = (gcnew System::Windows::Forms::TextBox());
			this->L_Username = (gcnew System::Windows::Forms::Label());
			this->L_Password = (gcnew System::Windows::Forms::Label());
			this->L_Email = (gcnew System::Windows::Forms::Label());
			this->FormClosed += gcnew FormClosedEventHandler(this, &Singup::SignupForm_FormClosed);
			this->SuspendLayout();
			// B_Login
			// 
			this->B_Login->Name = L"B_Login";
			this->B_Login->TabIndex = 0;
			this->B_Login->Text = L"Registrar";
			this->B_Login->UseVisualStyleBackColor = true;
			this->B_Login->Click += gcnew System::EventHandler(this, &Singup::B_Login_Click);
			// L_Singup
			// 
			this->L_Singup->AutoSize = true;
			this->L_Singup->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Singup->Name = L"L_Singup";
			this->L_Singup->TabIndex = 1;
			this->L_Singup->Text = L"SING UP";
			// TB_Username
			// 
			this->TB_Username->Name = L"TB_Username";
			this->TB_Username->TabIndex = 2;
			// TB_Password
			// 
			this->TB_Password->Name = L"TB_Password";
			this->TB_Password->TabIndex = 3;
			// TB_Email
			// 
			this->TB_Email->Name = L"TB_Email";
			this->TB_Email->TabIndex = 4;
			// L_Username
			// 
			this->L_Username->AutoSize = true;
			this->L_Username->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Username->Name = L"L_Username";
			this->L_Username->Text = L"Username";
			// L_Password
			// 
			this->L_Password->AutoSize = true;
			this->L_Password->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Password->Name = L"L_Password";
			this->L_Password->Text = L"Password";
			// L_Email
			// 
			this->L_Email->AutoSize = true;
			this->L_Email->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Email->Name = L"L_Email";
			this->L_Email->Text = L"Email";
			// IGNORAR ESTO, SOLO ES PARA EL DISENADOR
			// 
			this->TB_Username->Size = System::Drawing::Size(170, 20);
			this->L_Singup->Size = System::Drawing::Size(167, 42);
			this->B_Login->Size = System::Drawing::Size(119, 47);
			this->B_Login->Location = System::Drawing::Point(266, 314);
			this->L_Singup->Location = System::Drawing::Point(247, 51);
			this->TB_Username->Location = System::Drawing::Point(243, 154);
			this->TB_Password->Location = System::Drawing::Point(243, 210);
			this->TB_Password->Size = System::Drawing::Size(170, 20);
			this->TB_Email->Location = System::Drawing::Point(243, 264);
			this->TB_Email->Size = System::Drawing::Size(170, 20);
			this->L_Username->Location = System::Drawing::Point(283, 117);
			this->L_Username->Size = System::Drawing::Size(100, 24);
			this->L_Password->Location = System::Drawing::Point(285, 177);
			this->L_Password->Size = System::Drawing::Size(96, 24);
			this->L_Email->Location = System::Drawing::Point(300, 237);
			this->L_Email->Size = System::Drawing::Size(62, 24);
			// Singup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->ClientSize = System::Drawing::Size(654, 391);
			this->Controls->Add(this->L_Email);
			this->Controls->Add(this->L_Password);
			this->Controls->Add(this->L_Username);
			this->Controls->Add(this->TB_Email);
			this->Controls->Add(this->TB_Password);
			this->Controls->Add(this->TB_Username);
			this->Controls->Add(this->L_Singup);
			this->Controls->Add(this->B_Login);
			this->Name = L"Singup";
			this->Text = L"Singup";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->Resize += gcnew System::EventHandler(this, &Singup::Singup_Resize);
		}
#pragma endregion
	 System::Void B_Login_Click(System::Object^ sender, System::EventArgs^ e);
	 

};
}
