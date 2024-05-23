#pragma once

#include "Nodo.h"
#include <fstream>

using namespace System;
using namespace System::IO;

public ref class ArchiveSaver {
public:
    String^ direccion;
    Nodo^ inicio;
    Nodo^ fin;

    void Cargar();
    void Guardar();

    ArchiveSaver(String^ filePath);
    ~ArchiveSaver();

    // Métodos para Usuario
    void Alta(Usuario^ user);
    void Baja(int id);
    void Modificar(Usuario^ user, int id);
    void Consultar(int id);
    void Listar();

    // Métodos para Recordatorio
    void AltaRecordatorio(Recordatorio^ recordatorio);
    void BajaRecordatorio(int id);
    void ModificarRecordatorio(Recordatorio^ recordatorio, int id);
    void ConsultarRecordatorio(int id);
    void ListarRecordatorios();

    // Métodos para Seguimiento
    void AltaSeguimiento(Seguimiento^ seguimiento);
    void BajaSeguimiento(int id);
    void ModificarSeguimiento(Seguimiento^ seguimiento, int id);
    void ConsultarSeguimiento(int id);
    void ListarSeguimientos();

    // Métodos para Registro
    void AltaRegistro(Registro^ registro);
    void BajaRegistro(int id);
    void ModificarRegistro(Registro^ registro, int id);
    void ConsultarRegistro(int id);
    void ListarRegistros();
};
