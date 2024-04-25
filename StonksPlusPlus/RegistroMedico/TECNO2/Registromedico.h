#pragma once
#include "NodoReg.h"
#include "Wrote.h"
#include "Users.h"
class Registromedico
{
private:
	NodoReg* inicio;
	NodoReg* final;
	Wrote w;
	Users usuario;
public:
	Registromedico();
	~Registromedico();
	void agregarcita();
	void vercitas();
	void buscarcita();
	bool esFechaValida(string &fecha);
};

