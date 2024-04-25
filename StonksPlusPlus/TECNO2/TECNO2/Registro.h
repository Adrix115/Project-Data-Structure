#pragma once
#include <string>
using namespace std;
class Registro
{
public:
	string fecha;
	string tipo;
	string descripcion;
	Registro();
	Registro(string f, string t, string d);
	~Registro();

};

