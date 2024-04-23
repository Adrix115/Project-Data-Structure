#include "UsersClient.h"

UsersClient::UsersClient() {
	CounterPost = 0;
}
void UsersClient::normalpost() {
	string full; int i;
	getline(cin, full);
	int parrafos = full.size() / 50; //50 caracteres por fila de texto ya que son post, no articulos 
	if (full.size() > 250) { system("cls");  cout << "PAGUE POR LA MEMBRESIA PREMIUM PARA TENER ACCESO A MAS CARACTERES "; system("pause"); }
	for ( i = 0; i < parrafos; i++) {
		parrafo[i] = full.substr(i * 50, 50); //Recorre del mucho  texto, cada 50 caracteres
		post += parrafo[i]+ "\n";
	}
}
void UsersClient::premiumpost() {
	string full; int i;
	getline(cin, full);
	int parrafos = full.size() / 50; //50 caracteres por fila de texto ya que son post, no articulos 
	for (i = 0; i < parrafos; i++) {
		parrafo[i] = full.substr(i * 50, 50); //Recorre del mucho  texto, cada 50 caracteres
		post += parrafo[i] + "\n";
	}
}
