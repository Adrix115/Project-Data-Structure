#include "Main.h"
#include "Login.h"
#include "Singup.h"
#include "ArchiveSaver.h"

System::Void Stonks::Login::B_Login_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = this->TB_Username->Text;
    String^ password = this->TB_Password->Text;

    // Crear una instancia de ArchiveSaver para cargar los usuarios
    ArchiveSaver^ saver = gcnew ArchiveSaver("users.txt");
    Nodo^ aux = saver->inicio;


    bool encontrado = false;
    Usuario^ userActual = nullptr;

    while (aux != nullptr) {
        if (aux->usuario != nullptr && aux->usuario->Username == username && aux->usuario->Password == password && aux->usuario->Visible) {
            encontrado = true;
            userActual = aux->usuario;
            break;
        }
        aux = aux->siguiente;
    }

    if (encontrado) {
        // Guardar la información del usuario actual en UserActual.txt
        FileStream^ fileStream = nullptr;
        StreamWriter^ writer = nullptr;

        try {
            fileStream = gcnew FileStream("UserActual.txt", FileMode::Create);
            writer = gcnew StreamWriter(fileStream);

            writer->WriteLine(userActual->ID);
            writer->WriteLine(userActual->Username);
            writer->WriteLine(userActual->Email);
            writer->WriteLine(userActual->Password);
            writer->WriteLine(userActual->Visible);
        }
        finally {
            if (writer != nullptr) {
                writer->Close();
            }
            if (fileStream != nullptr) {
                fileStream->Close();
            }
        }

        MessageBox::Show("EXITO!", "BIENVENIDO", MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->Hide();
        // Assuming Main form is another form you want to show after successful login
        Main^ mainForm = gcnew Main();
        mainForm->Show();
    }
    else {
        MessageBox::Show("USO INCORRECTO", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
