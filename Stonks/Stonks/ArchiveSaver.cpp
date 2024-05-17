#include "ArchiveSaver.h"

// Constructor
ArchiveSaver::ArchiveSaver(String^ filePath) : direccion(filePath) {
    Open();  // Abrir el archivo autom�ticamente al crear la instancia
}

// Destructor
ArchiveSaver::~ArchiveSaver() {
    if (fileStream != nullptr)
        fileStream->Close();
}

// M�todo para abrir el archivo
void ArchiveSaver::Open() {
    if (!File::Exists(direccion)) {
        fileStream = File::Create(direccion);
    }
    else {
        fileStream = File::Open(direccion, FileMode::OpenOrCreate, FileAccess::ReadWrite);
    }
    streamWriter = gcnew StreamWriter(fileStream);
    streamReader = gcnew StreamReader(fileStream);
}

// M�todo para escribir en el archivo (a�adir al final)
void ArchiveSaver::Write(String^ data) {
    fileStream->Seek(0, SeekOrigin::End);  // Mover al final del archivo
    streamWriter->WriteLine(data);         // Escribir en una nueva l�nea
    streamWriter->Flush();                 // Asegurarse de que se escribe en el archivo
}

// M�todo para leer del archivo
String^ ArchiveSaver::Read() {
    fileStream->Seek(0, SeekOrigin::Begin);  // Volver al inicio del archivo
    return streamReader->ReadToEnd();
}

// M�todo para limpiar el archivo
void ArchiveSaver::CleanFile() {
    fileStream->SetLength(0);  // Establecer la longitud del archivo a 0, borrando su contenido
    streamWriter->Flush();     // Asegurarse de que los cambios se aplican
}

// M�todo para leer y separar contenido en un array usando un separador
array<String^>^ ArchiveSaver::ReadArrayString(String^ separator) {
    String^ content = Read();                        // Leer todo el contenido del archivo
    array<String^>^ splitContent = content->Split(gcnew array<String^> { separator }, StringSplitOptions::None);
    return splitContent;                             // Retornar el contenido separado en un array
}
