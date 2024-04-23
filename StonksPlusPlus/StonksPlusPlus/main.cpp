#include <iostream>
#include <conio.h>
#define MAX 1000
//CON CLASE
#include "BootSequence.h"
#include "Wrote.h"
#include "Archivero.h"
#include "UsersControl.h"
#include "UserInvitado.h"
void menumaternal(BootSequence draw, Wrote text);
void menuadministrativo(BootSequence draw, Wrote text);
void rellenarstruct(string lineascondatos[]);

using namespace std;

Users users[MAX]; int tam;
UserInvitado loginsingup;
Users actualuser;
Archivero infodeusuarios("\"usuarios.txt\""); /// 
Archivero usuariosregistrados("\"tamuser.txt\""); /// 


int main() {
    ///SECUENCIA DE ARRANQUE INICIAL
    BootSequence draw;    HWND consoleWindow = GetConsoleWindow();
    draw.FirstBoot();    draw.colorbackground(23, 255);   draw.LogoUpsa(29, 255);    Sleep(2000);
	draw.colorbackground(62, 255);    draw.LogoStonks(60, 211);    Sleep(2000);
    system("cls"); system("pause");
    draw.colorbackground(211, 255);
    Wrote text; int  opc; char opp; bool first=true;
    string paso1 = usuariosregistrados.leer();  int paso2 = stof(paso1); tam = int(paso2);
    string* lineas = infodeusuarios.leerVector();
    string lineascondatos[MAX];
    for (int i = 0; i < tam; i++) {   lineascondatos[i] = lineas[i]; }
    delete[] lineas;
    rellenarstruct(lineascondatos);

    string txt;
    do{
    text.reset(); text. write("Stonks ++ Copyright 2024");
        text.changealignedment("center"); text.write("<INSERTAR AQUI NOMBRE DE PROGRAMA PARA MADRES...MAMADORES?>");
        text.changealignedment("right"); text.write(". . . . . .");
        text.newl(5);//Endline
        text.changealignedment("left"); text.write("Pulse en su teclado una de las siguientes opciones:");
        text.write("Justo ahora no hacen lo que deberia xd, 1 lleva a un proto login");
        text.newl(1);
        text.changealignedment("center"); text.write("1. Log in"); text.write("2. Sing up"); text.write("0. Salir"); 
    while (true) {
        try {    opp = _getch(); opc = int(opp);   if (!isdigit(opc) || (opp!='0' && opp!='1'&& opp!='2')) { throw invalid_argument(""); }; break; }
        catch (const invalid_argument& e) { if (first==true)      text.write("INCORRECTO, PULSA UN NUMERO VALIDO");   first = false;}}
    opc -= 48;
    
    switch (opc) {
    case 0: cout << "Cerrando la aplicacion";
        break;
    case 1: {bool saveuser = 1; do {
             text.reset(); draw.colorbackground(211, 255);
             actualuser = loginsingup.login(users, tam, saveuser);
    } while (saveuser==0); 
    ///AHORA, SI SALIO DE LA VERIFICACION, PODEMOS MANDAR AL USUARIO A ALGUN LUGAR
    if (actualuser.username == "kinfantas") menuadministrativo(draw, text);
    else menumaternal(draw, text);

    }
          
          break;
    case 2: {
        text.reset();        users[tam].userType = 0;   users[tam].userID = tam + 1;
        draw.colorbackground(211, 255);
        text.write("Stonks ++ Copyright 2024"); text.changealignedment("center");        text.write("SING UP"); text.newl(1);
        users[tam] = loginsingup.singup();
        text.reset(); draw.colorbackground(211, 255);        text.write("SE REGISTRO EL NUEVO USUARIO CON EXITO, INICIE SESION"); _getch();
        text.reset(); draw.colorbackground(211, 255);
        // guarda cuantos usuarios hay, :D
        usuariosregistrados.sobreescribir(to_string(tam+1));
        // guardar info de los usuarios
        string userInfo = to_string(users[tam].userID) + "/ /"  + users[tam].username + "/ /"  + users[tam].password + "/ /"  + users[tam].email + "/ /" + to_string(users[tam].userType) + "/ /";
        infodeusuarios.escribir(userInfo);    tam++;    break;
    }
    }
    } while (opc != 0);
          return 0;
    }


void menumaternal(BootSequence draw, Wrote text) {
    text.reset(); draw.colorbackground(211, 255);
    text.write("Stonks ++ Copyright 2024"); 
    text.changealignedment("center"); text.write("MENU MATERNAL???");
    text.changealignedment("left"); text.write("1.   Conversar en el foro");
    text.write("2.  Recordatorios");
    text.write("3.  Registro de Citas Medicas");
    text.write("4.  Seguimineto del bebe");
    _getch();

}
void menuadministrativo(BootSequence draw, Wrote text) {
    text.reset(); draw.colorbackground(211, 255);
    text.write("Stonks ++ Copyright 2024");
    text.changealignedment("center"); text.write("MENU MATERNAL???");
    text.changealignedment("left"); text.write("1. gestionar tipos de usuarios");
    text.write("2.Agregar informacion");
    text.write("3. Gestionar consultas");
    text.write("4. Gestionar Grupos de pollo");
    text.write("5. Gestionar eventos");
    _getch();
}

 void rellenarstruct(string lineascondatos[]) {
    for (int i = 0; i <= tam; i++) {
        string linea = lineascondatos[i];
        size_t pos = 0;
        string token;
        int counter = 0;

        while ((pos = linea.find("/ /")) != string::npos) {
            token = linea.substr(0, pos);
            switch (counter) {
            case 0: users[i].userID = stoi(token); break;
            case 1: users[i].username = token; break;
            case 2: users[i].password = token; break;
            case 3: users[i].email = token; break;
            case 4: users[i].userType = stoi(token); break;
            }
            linea.erase(0, pos + 3);
            counter++;
        };
    }
}