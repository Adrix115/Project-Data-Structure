#pragma once
using namespace System;

public ref class Seguimiento {
public:
    static int contadorId = 0;
    String^ fecha;
    String^ descripcion;
    bool visible;

    Seguimiento(String^ fecha, String^ descripcion) {
        this->contadorId = contadorId++;
        this->fecha = fecha;
        this->descripcion = descripcion;
        this->visible = true;
    }

    String^ ToString(String^ separator) {
        return contadorId + separator + fecha + separator + descripcion + separator + visible.ToString();
    }
};
