#include <iostream>
#include "BootSequence.h"
#include <conio.h>
#include "Wrote.h"

void menumaternal(BootSequence draw, Wrote text);
void menuadministrativo(BootSequence draw, Wrote text);
struct usuario {
    int ID;
    string username;
    bool clase; //administrativo, usuario normal, usuario premium
};
usuario user;
using namespace std;

int main() {
    ///SECUENCIA DE ARRANQUE INICIAL
    BootSequence draw;    HWND consoleWindow = GetConsoleWindow();
    draw.FirstBoot();    draw.colorbackground(23, 255);   draw.LogoUpsa(29, 255);    Sleep(2000);
	draw.colorbackground(62, 255);    draw.LogoStonks(60, 211);    Sleep(2000);
    system("cls"); system("pause");
    draw.colorbackground(211, 255);
    ///AQUI EMPIEZA DE LLENO EL PROGRAMA
    Wrote text; int  opc; char opp; bool first=true;
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
    
    
    switch (opc) {
    case 48: { }
          break;
    case 49: { do {
        text.reset(); draw.colorbackground(211, 255);
        text.write("Stonks ++ Copyright 2024");
        text.write("INGRESAR EL NOMBRE DE USAURIO: (pongan infantazzz para normal y infangod para admin)"); text.newl(1);
        cin >> user.username;
        if (user.username == "infantazz") { menumaternal(draw, text); }
        else if (user.username == "infangod") {
            menuadministrativo(draw, text);
        }
    } while (user.username != "infantazz" || user.username != "infangod"); }
          break;
    case 50: { }
          break;
    }
    return 0;
}

void menumaternal(BootSequence draw, Wrote text) {
    text.reset(); draw.colorbackground(211, 255);
    text.write("Stonks ++ Copyright 2024"); 
    text.changealignedment("center"); text.write("MENU MATERNAL???");
    text.changealignedment("left"); text.write("1. Conversar en el foro");
    text.write("2.Recordatorios");
    text.write("3. Registro de Citas Medicas");
    text.write("4. Seguimineto del bebe");
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