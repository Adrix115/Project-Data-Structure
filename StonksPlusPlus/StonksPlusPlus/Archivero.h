#pragma once

#define ARCHIVERO_H
#include <iostream>
#include <string>
using namespace std;
class Archivero
{private:
    string m_nombreArchivo;
 public:
    Archivero(const string& filename);
    string leer();
    string* leerVector();
    void escribir(const string& contenido);
    void sobreescribir(const string& contenido);
    void sobreescribir2(const string& contenido);
};

