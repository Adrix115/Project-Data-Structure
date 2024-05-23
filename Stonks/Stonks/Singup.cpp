#include "Singup.h"
#include "Main.h"

System::Void Stonks::Singup::B_Login_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = this->TB_Username->Text;
    String^ password = this->TB_Password->Text;
    String^ email = this->TB_Email->Text;

    // Crear una instancia de Usuario con la informaci�n del formulario
    Usuario^ newUser = gcnew Usuario(0, username, email, password); // ID se asignar� luego

    // Crear una instancia de ArchiveSaver y a�adir el nuevo usuario
    ArchiveSaver^ saver = gcnew ArchiveSaver("users.txt");
    saver->Alta(newUser);

    this->Hide();
    Main^ mainForm = gcnew Main();
    mainForm->Show();
}