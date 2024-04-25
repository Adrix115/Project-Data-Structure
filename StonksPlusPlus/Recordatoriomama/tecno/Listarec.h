#pragma once
#include "NodoR.h"
#include "Wrote.h"
#include "Users.h"
class Listarec
{
private:
	NodoR* inicio;
	NodoR* final;
	Wrote w;
	Users usuario;
public:
	Listarec();
	~Listarec();
	void set_usuario(Users usuario);
	void nuevorecordatorio();
	void mostrarrecordatorios();
	void modificarrecordatorios();
	void eliminarrecdordatorio();
	void marcarcompletado();
	bool esFechaValida(string& fecha);
	void priorizar();

};

