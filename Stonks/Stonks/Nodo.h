#pragma once

#include "Usuario.h"
#include "Recordatorio.h"
#include "Seguimiento.h"
#include "Registro.h"

public ref class Nodo {

public:
    Usuario^ usuario;
    Recordatorio^ recordatorio;
    Seguimiento^ seguimiento;
    Registro^ registro;
    Nodo^ siguiente;

    Nodo(Usuario^ u) : usuario(u), siguiente(nullptr) {}
    Nodo(Recordatorio^ r) : recordatorio(r), siguiente(nullptr) {}
    Nodo(Registro^ r) : registro(r), siguiente(nullptr) {}
    Nodo(Seguimiento^ s) : seguimiento(s), siguiente(nullptr) {}
};
