#include "Recordatorio.h"
Recordatorio::Recordatorio() {

}
Recordatorio::Recordatorio(string n, string d, string f, bool c) {
	this->nombre = n;
	this->descripcion = d;
	this->fecha = f;
	this->completado = c;
}
Recordatorio::~Recordatorio() {

}