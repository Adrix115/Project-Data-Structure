#pragma once //USERS CONTROL MANEJA LOS USUARIOS, ES EL ADMIN
#include "Users.h" //tipo de dato
#include "Wrote.h" //estetica
class UsersControl
{	private:
	Users Admin;
	Wrote text;
	public:
		UsersControl();
		void setadminname();
		void getadmindata();
		void changeadminpass();
		void showallusers(int tam, Users users[]);
		//void modifyuser();	
		//void deleteuser();
		//void createuser();
};

