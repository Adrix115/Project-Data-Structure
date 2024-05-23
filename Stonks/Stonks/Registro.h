#pragma once
using namespace System;
using namespace System::IO;

public ref class Registro
{
public:
    static int contadorId;
    int id;
    String^ fecha;
    String^ doctor;
    String^ especialidad;
    String^ descripcion;
    bool visible;

    Registro();
    Registro(String^ f, String^ d, String^ e, String^ de);
    String^ ToString(String^ separador);
};
