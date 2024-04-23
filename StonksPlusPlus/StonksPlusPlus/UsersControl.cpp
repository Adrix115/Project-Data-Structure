#include "UsersControl.h"
UsersControl::UsersControl() { Admin.username = "kinfantas"; Admin.password = "empresa"; }
void UsersControl::setadminname() {
	string a;  text.reset(); text.changealignedment("center"); text.write("Ingresa el nuevo nombre");
	getline(cin, a); Admin.username = a;
}
void UsersControl::getadmindata() {
	text.reset(); text.changealignedment("center");
	text.write("Username: "); text.write(Admin.username); text.newl(1);
	text.write("email: "); text.write(Admin.email); text.newl(1);
	text.write("pass: "); text.write(Admin.password); text.newl(1);
	
}
void UsersControl::changeadminpass(){
	string a;  text.reset(); text.changealignedment("center"); text.write("Ingresa el nuevo password");
	getline(cin, a); Admin.password = a;
}


void UsersControl::showallusers(int tam, Users users[]) {
	system("cls");
	text.reset(); text.changealignedment("center");
	for (int i = 0; i < tam; i++) { 
		text.write("USUARIO "); text.write(to_string(i)); text.newl(1);
		text.write("Username: "); text.write(users[i].username); text.newl(1);
		text.write("Email: "); text.write(users[i].email); text.newl(1);
		text.write("Password: "); text.write(users[i].password); text.newl(1);
		text.write("ID: "); text.write(to_string(users[i].userID)); text.newl(1);
		text.write("PREMIUM (1), NORMAL (0): "); text.write(to_string(users[i].userType)); text.newl(2);
	}
}
