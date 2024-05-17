#pragma once

namespace Stonks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)		{			InitializeComponent();	}

	protected:
		~Login()
		{			if (components)	{			delete components;	}	}
	System::Windows::Forms::Button^ B_Login;
	System::Windows::Forms::TextBox^ TB_Password;
	System::Windows::Forms::TextBox^ TB_Username;
	System::Windows::Forms::Label^ L_Login;
	System::Windows::Forms::Label^ L_Username;
	System::Windows::Forms::Label^ L_Password;

	void LoginForm_FormClosed(Object^ sender, FormClosedEventArgs^ e) {
		Application::Exit();	}


	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->B_Login = (gcnew System::Windows::Forms::Button());
			this->TB_Password = (gcnew System::Windows::Forms::TextBox());
			this->TB_Username = (gcnew System::Windows::Forms::TextBox());
			this->L_Login = (gcnew System::Windows::Forms::Label());
			this->L_Username = (gcnew System::Windows::Forms::Label());
			this->L_Password = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// B_Login
			// 
			this->B_Login->Location = System::Drawing::Point(286, 303);
			this->B_Login->Name = L"B_Login";
			this->B_Login->Size = System::Drawing::Size(116, 46);
			this->B_Login->TabIndex = 0;
			this->B_Login->Text = L"Iniciar Sesion";
			this->B_Login->UseVisualStyleBackColor = true;
			this->B_Login->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// TB_Password
			// 
			this->TB_Password->Location = System::Drawing::Point(266, 245);
			this->TB_Password->Name = L"TB_Password";
			this->TB_Password->Size = System::Drawing::Size(160, 20);
			this->TB_Password->TabIndex = 1;
			// 
			// TB_Username
			// 
			this->TB_Username->Location = System::Drawing::Point(266, 172);
			this->TB_Username->Name = L"TB_Username";
			this->TB_Username->Size = System::Drawing::Size(160, 20);
			this->TB_Username->TabIndex = 2;
			// 
			// L_Login
			// 
			this->L_Login->AutoSize = true;
			this->L_Login->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold));
			this->L_Login->Location = System::Drawing::Point(274, 66);
			this->L_Login->Name = L"L_Login";
			this->L_Login->Size = System::Drawing::Size(141, 42);
			this->L_Login->TabIndex = 3;
			this->L_Login->Text = L"LOGIN";
			// 
			// L_Username
			// 
			this->L_Username->AutoSize = true;
			this->L_Username->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Username->Location = System::Drawing::Point(296, 128);
			this->L_Username->Name = L"L_Username";
			this->L_Username->Size = System::Drawing::Size(100, 24);
			this->L_Username->TabIndex = 4;
			this->L_Username->Text = L"Username";
			// 
			// L_Password
			// 
			this->L_Password->AutoSize = true;
			this->L_Password->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_Password->Location = System::Drawing::Point(298, 208);
			this->L_Password->Name = L"L_Password";
			this->L_Password->Size = System::Drawing::Size(96, 24);
			this->L_Password->TabIndex = 5;
			this->L_Password->Text = L"Password";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->ClientSize = System::Drawing::Size(676, 400);
			this->Controls->Add(this->L_Password);
			this->Controls->Add(this->L_Username);
			this->Controls->Add(this->L_Login);
			this->Controls->Add(this->TB_Username);
			this->Controls->Add(this->TB_Password);
			this->Controls->Add(this->B_Login);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	 System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	 Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
