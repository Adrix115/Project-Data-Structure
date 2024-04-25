#pragma once
#include <iostream>
#include <string>
using namespace std;
class Recordatorio
{
public:
	string nombre;
	string descripcion;
	string fecha;
	bool completado;
	Recordatorio();
	Recordatorio(string n, string d, string f, bool c);
	~Recordatorio();

};

