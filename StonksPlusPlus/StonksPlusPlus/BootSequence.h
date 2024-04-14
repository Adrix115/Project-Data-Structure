#pragma once
#include <iostream>
#include <windows.h> //Nos da el acceso a la consola de comandos y al API de winrdows =D Siu!
using namespace std;
/*oh, she is sweet but she is a psycho, a little bit psycho */
//Si algo es static porque pertenece a la funcion en si, no a algun objeto, lo usa FirsBoot

class BootSequence
{private:
	int colour;
	int width; //ancho de la consola del windous
	int height; //alto de la consola dle windousss
	COORD pos;
public:
	void FirstBoot();
	void LogoUpsa(int col, int bor);
	void LogoStonks(int col, int bor);
	void colorbackground(int col, int bor);      
	static 	DWORD WINAPI MainTheme(LPVOID longpointer); //le enviamos nulos y devuelve 0 asi que es casi un void pero winrdows nos obliga a ponerlo asi JASJDSAJ
};

