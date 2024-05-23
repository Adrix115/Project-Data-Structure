#include "Registro.h"

// Constructor por defecto
Registro::Registro() : id(++contadorId), fecha(""), doctor(""), especialidad(""), descripcion(""), visible(true) {}

// Constructor con par�metros
Registro::Registro(String^ f, String^ d, String^ e, String^ de) : id(++contadorId), fecha(f), doctor(d), especialidad(e), descripcion(de), visible(true) {}

// M�todo ToString
String^ Registro::ToString(String^ separador) {
    return id.ToString() + separador + fecha + separador + doctor + separador + especialidad + separador + descripcion;
}
