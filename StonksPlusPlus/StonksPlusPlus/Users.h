#pragma once
#include <string>
#include "wrote.h"
#include <iostream>
using namespace std;
class Users
{public:
	bool userType; //0: normal, 1: premium ////Esto es conveniente porque asi desde el menu administrativo cambiar usuario de premium a normal es solo escribir un valor
	int userID; //A cada usuario se le asigna un numero segun el orden en el que se haya creado, esto para manejarnos de forma mas sencilla...y ayudar si queremos mostra
	string username, password, email; ///3 strings que bueno, son necesarios para un tipo de foro que quieren crear
};

