#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create the main window and run it
    Proyecto2024::MyForm^ form = gcnew Proyecto2024::MyForm();
    Application::Run(form);
    return 0;
}
