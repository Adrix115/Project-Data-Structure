#pragma once
#include "UsersClient.h"
struct credenciales {
	int ano;
	string institucion;
	string descripcion;
};

class UsersDocs : public UsersClient  
{
	private:
		string articulo;
		int ArticleCounter;
		credenciales cred[1000];
		int nrodecred;
	public:
		UsersDocs() { userType = 1; nrodecred = 0; } //siempre es premium un doc
		void addcredenciales();
		void article();
		void showcredenciales();
};

