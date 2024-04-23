#pragma once
#include "Users.h"
class UserInvitado
{//Users nos brinda los atributos de userType, userID, username, password, email
private: 
	Users usuario;
	Wrote text;
public:
	Users login(Users users[], int tam, bool &bucle);
	Users singup();
};

