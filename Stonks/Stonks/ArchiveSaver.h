#pragma once

using namespace System;
using namespace System::IO;

ref class ArchiveSaver {
private:
    String^ direccion;          // Dirección del archivo
    FileStream^ fileStream;     // Flujo de archivo
    StreamWriter^ streamWriter; // Escritor de flujo de archivo
    StreamReader^ streamReader; // Lector de flujo de archivo

public:
    // Constructor
    ArchiveSaver(String^ filePath);

    // Destructor
    ~ArchiveSaver();

    // Método para abrir el archivo
    void Open();

    // Método para escribir en el archivo (añadir al final)
    void Write(String^ data);

    // Método para leer del archivo
    String^ Read();

    // Método para limpiar el archivo
    void CleanFile();

    // Método para leer y separar contenido en un array usando un separador
    array<String^>^ ReadArrayString(String^ separator);
};
