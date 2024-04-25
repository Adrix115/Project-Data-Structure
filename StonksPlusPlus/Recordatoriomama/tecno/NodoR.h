#pragma once
#include "Recordatorio.h"
class NodoR
{
public:
	Recordatorio dato;
	NodoR* sig;
	NodoR();
	~NodoR();
};

