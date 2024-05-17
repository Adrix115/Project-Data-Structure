#pragma once

namespace Stonks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent(); //constructor principal
			int width = (Screen::PrimaryScreen->Bounds.Width) / 1.8; int height = (Screen::PrimaryScreen->Bounds.Height) / 1.5; //Tamano formulario relativo al pxieles del PC del usuario, si lo hicieramos con un tamano fijo, como diferentes usuarios tienen diferentes resoluciones de pantalla, variaria
			this->Size = System::Drawing::Size(width, height);
		}

	protected:
		~Main()
		{	if (components)	{	delete components;	}	}
		System::Windows::Forms::Button^ B_login; System::Windows::Forms::Button^ B_Singup;
		System::Windows::Forms::Label^ label1;	System::Windows::Forms::PictureBox^ LogoProject;

		// Los componentes(las herramientas graficas) se almacenan en e lmetodo container
		System::ComponentModel::Container^ components;
		//FUNCION DE POSICION Y TAMANO AJUSTABLE
		System::Void Main_Resize(System::Object^ sender, System::EventArgs^ e) {
			int formWidth = this->ClientSize.Width;	int formHeight = this->ClientSize.Height; float porcen = 1 * (formWidth / 30);
			///Tamano relativo a la pantalla
			label1->Font = (gcnew System::Drawing::Font(L"Bodoni MT", porcen * 1.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			B_Singup->Size = System::Drawing::Size(formWidth / 5, formHeight / 10);
			B_login->Size = System::Drawing::Size(formWidth / 5, formHeight / 10);
			LogoProject->Size = System::Drawing::Size(formWidth / 2.8, formHeight / 2);
			//posicion relativa a la pantalla
			label1->Location = System::Drawing::Point(formWidth / 2 - label1->Width / 2, formHeight / 1.8);
			B_Singup->Location = System::Drawing::Point(formWidth / 2 - B_Singup->Width / 2, formHeight / 1.45);
			B_login->Location = System::Drawing::Point(formWidth / 2 - B_login->Width / 2, formHeight / 1.2);
			LogoProject->Location = System::Drawing::Point(formWidth / 2 - LogoProject->Width / 2, formHeight / 40);
			B_Singup->Font = (gcnew System::Drawing::Font(L"Bodoni MT", (porcen * 0.7) * 1.0F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			B_login->Font = (gcnew System::Drawing::Font(L"Bodoni MT", (porcen * 0.7) * 1.0F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->B_login = (gcnew System::Windows::Forms::Button());
			this->B_Singup = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LogoProject = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoProject))->BeginInit();
			this->SuspendLayout();
			// 
			// COSAS SOBRANTES PARA UTILIZAR EL DISENADOR, ELIMINAR AL EXPORTAR EL PROYECTO
			// 
			this->B_login->Location = System::Drawing::Point(291, 301);
			this->B_login->Size = System::Drawing::Size(133, 42);
			this->B_Singup->Location = System::Drawing::Point(291, 367);
			this->B_Singup->Size = System::Drawing::Size(133, 42);
			this->label1->Location = System::Drawing::Point(239, 253);
			this->label1->Size = System::Drawing::Size(249, 13);
			this->LogoProject->Size = System::Drawing::Size(292, 146);
			this->LogoProject->Location = System::Drawing::Point(219, 75);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->ClientSize = System::Drawing::Size(731, 456);
			
			// B_login
			// 
			this->B_login->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->B_login->Name = L"B_login";
			this->B_login->TabIndex = 0;
			this->B_login->Text = L"Log In";
			this->B_login->Click += gcnew System::EventHandler(this, &Main::B_login_Click);
			this->B_login->UseVisualStyleBackColor = false;
			// 
			// B_Singup
			this->B_Singup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->B_Singup->Name = L"B_Singup";
			this->B_Singup->TabIndex = 1;
			this->B_Singup->Text = L"Sing Up";
			this->B_Singup->UseVisualStyleBackColor = false;
			this->B_Singup->Click += gcnew System::EventHandler(this, &Main::B_Singup_Click);
			// 
			// label1
			this->label1->AutoSize = true;
			this->label1->Name = L"label1";
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Text = L"Porfavor seleccione una de las siguientes opciones";
			// 
			// LogoProject
			this->LogoProject->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LogoProject->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoProject.Image")));
			this->LogoProject->Name = L"LogoProject";
			this->LogoProject->SizeMode = PictureBoxSizeMode::StretchImage;
			this->LogoProject->TabStop = false;
			// 
			// Main
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->Controls->Add(this->LogoProject);	this->Controls->Add(this->label1);
			this->Controls->Add(this->B_Singup);	this->Controls->Add(this->B_login);
			this->Name = L"Main";	this->Text = L"Main";
			this->Resize += gcnew System::EventHandler(this, &Main::Main_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoProject))->EndInit();
			this->ResumeLayout(false);	this->PerformLayout();
		}
#pragma endregion

		Void B_Singup_Click(System::Object^ sender, System::EventArgs^ e);
		Void B_login_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
