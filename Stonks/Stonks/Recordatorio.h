#pragma once
using namespace System;

public ref class Recordatorio {
public:
    static int ID = 0;
    String^ nombre;
    String^ descripcion;
    String^ fecha;
    bool completado;

    Recordatorio(String^ nombre, String^ descripcion, String^ fecha, bool completado) {
        this->ID = ID++;
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->completado = completado;
    }

    String^ ToString(String^ separator) {
        return ID + separator + nombre + separator + descripcion + separator + fecha + separator + completado.ToString();
    }
};
