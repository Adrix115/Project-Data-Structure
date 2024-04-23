#include "UsersDocs.h"
void UsersDocs::addcredenciales() {
	cout << "Ingresar ano del credencial: "; cin >> cred[nrodecred].ano;
	cout << "Ingresar instucion que valida: "; cin >> cred[nrodecred].institucion;
	cout << "Ingresar descripcion del credencial: "; cin >> cred[nrodecred].descripcion;
	nrodecred++;
}

void UsersDocs::article() {
	string full; int i;
	getline(cin, full);
	int parrafos = full.size() / 50; //50 caracteres por fila de texto ya que son post, no articulos 
	for (i = 0; i < parrafos; i++) {
		parrafo[i] = full.substr(i * 50, 50); //Recorre del mucho  texto, cada 50 caracteres
		articulo += parrafo[i] + "\n";
	}
}

void UsersDocs::showcredenciales() {
	for (int i = 0; i < nrodecred; i++) {
	
		cout << "CREDENCIAL " << i + 1 << endl;
		cout << "Emitida el " << cred[i].ano << " y validada por: " << cred[i].institucion<<endl;
		cout << "		" << cred[i].descripcion << endl << endl;
	}
}