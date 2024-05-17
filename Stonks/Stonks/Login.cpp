#include "Main.h"
#include "Login.h"
#include "Singup.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

Void Stonks::Login::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Ocultar el ormulario actual
	this->Hide();
	// Mostrar Singup
	Main^ singupForm = gcnew Main(); singupForm->Show();
}