#include "Main.h"
#include "Login.h"
#include "Singup.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Stonks::Main form;
	Application::Run(% form);
}

Void Stonks::Main::B_Singup_Click(System::Object^ sender, System::EventArgs^ e) {
	// Ocultar el formulario actual
	this->Hide();
	// Mostrar Singup
	Singup^ singupForm = gcnew Singup(); 
	singupForm->Show();
}

Void Stonks::Main::B_login_Click(System::Object^ sender, System::EventArgs^ e) {
	// Ocultar el formulario actual
	this->Hide();
	// Mostrar Singup
	Login^ loginForm = gcnew Login(); 
	loginForm->Show();
}