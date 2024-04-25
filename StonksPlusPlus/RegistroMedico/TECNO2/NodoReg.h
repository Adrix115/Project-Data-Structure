#pragma once
#include "Registro.h"
class NodoReg
{
public:
	NodoReg* sig;
	Registro dato;
	NodoReg() {}
	~NodoReg();
};

