#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class Wrote
{
private:
	string text;
	int colour = 15; //Color del texto en un ANSI 256 Bits, vean la tabla anexa, empieza con blanco como color por defecto
	COORD pos = { 3,2 }; //Coordenadas posicion, empieza alineado a la izquierda por defecto
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Manejador necesario para complementar las coordenadas
	int width, height; //Lo mismo, si, ahora que lo pienso la posicion demanda mucho
public:
	Wrote();
	~Wrote();
	void write(string txt);
	void newl(int n);
	void changecolor(int n);
	void changealignedment(string a);
	void reset();


};