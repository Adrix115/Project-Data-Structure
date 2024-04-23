#include "Archivero.h"

using namespace std;

Archivero::Archivero(const string& filename) : m_nombreArchivo(filename) {}

string Archivero::leer() {
    string comando = "type " + m_nombreArchivo;
    FILE* pipe = _popen(comando.c_str(), "r");
    if (!pipe) {
        cerr << "Error." << endl;
        return "";
    }
    char buffer[128];
    string resultado = "";
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        resultado += buffer;
    }
    _pclose(pipe);
    return resultado;
}

string* Archivero::leerVector() {
    string comando = "type " + m_nombreArchivo;
    FILE* pipe = _popen(comando.c_str(), "r");
    if (!pipe) {
        cerr << "Error." << endl;
        return nullptr;
    }
    char buffer[128];
    string* resultado = new string[100];
    int i = 0;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr && i < 100) {
        resultado[i] = buffer;
        i++;
    }
    _pclose(pipe);
    return resultado;
}

void Archivero::escribir(const string& contenido) {
    string comando = "echo " + contenido + " >> " + m_nombreArchivo;
    system(comando.c_str());
}

void Archivero::sobreescribir(const string& contenido) {
    string comando = "echo " + contenido + " > " + m_nombreArchivo;
    system(comando.c_str());
}
void Archivero::sobreescribir2(const string& contenido) {
    // Primero, borra el contenido existente del archivo
    string comando = "echo. > " + m_nombreArchivo;
    system(comando.c_str());

    // Divide el contenido en líneas
    size_t pos = 0;
    size_t next_pos = 0;
    string linea;

    // Escribe cada línea en el archivo
    while ((next_pos = contenido.find('\n', pos)) != string::npos) {
        linea = contenido.substr(pos, next_pos - pos);
        comando = "echo " + linea + " >> " + m_nombreArchivo;
        system(comando.c_str());
        pos = next_pos + 1;
    }

    // Escribe la última línea en el archivo
    linea = contenido.substr(pos);
    comando = "echo " + linea + " >> " + m_nombreArchivo;
    system(comando.c_str());
}
