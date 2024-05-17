#pragma once

using namespace System;
using namespace System::IO;

ref class ArchiveSaver {
private:
    String^ direccion;          // Direcci�n del archivo
    FileStream^ fileStream;     // Flujo de archivo
    StreamWriter^ streamWriter; // Escritor de flujo de archivo
    StreamReader^ streamReader; // Lector de flujo de archivo

public:
    // Constructor
    ArchiveSaver(String^ filePath);

    // Destructor
    ~ArchiveSaver();

    // M�todo para abrir el archivo
    void Open();

    // M�todo para escribir en el archivo (a�adir al final)
    void Write(String^ data);

    // M�todo para leer del archivo
    String^ Read();

    // M�todo para limpiar el archivo
    void CleanFile();

    // M�todo para leer y separar contenido en un array usando un separador
    array<String^>^ ReadArrayString(String^ separator);
};
