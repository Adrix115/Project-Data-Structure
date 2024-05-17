#include "Singup.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

Void Stonks::Singup::B_Login_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username = this->TB_Username->Text;
	String^ password = this->TB_Password->Text;
	String^ email = this->TB_Email->Text;

	// Formatear la información para almacenar en el archivo
	String^ userInfo = username + "-()-" + password + "-()-" + email;

	// Crear una instancia de ArchiveSaver y escribir los datos
	ArchiveSaver^ saver = gcnew ArchiveSaver("users.txt");
	saver->Write(userInfo);
}
