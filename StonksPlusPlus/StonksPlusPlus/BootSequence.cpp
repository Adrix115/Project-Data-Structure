//EN TODO ESTE CODIGO, POR SI ALGUIEN QUE LO LEA QUIERA ENTENDER, DEJARE COMENTARIOS QUE LO EXPLIQUEN AL LADO, SI NO LES GUSTA ME DICEN Y ME ENCARGO DE QUITARLOS :D
#include "BootSequence.h"
#include <conio.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Aqui hay un handle que nos permite enviar salidas del tipo STD al windous
CONSOLE_SCREEN_BUFFER_INFO csbi;//este dato puede acceder al info de la pantalla del computador creado por microsoft

void BootSequence::FirstBoot() {  //Hola amiwos, esta parte ocupamos HANDLES, son punteros pero para el API de Windows, nos dan acceso a distintas cosas de windows, el sonido, el cmd, etc
    //Aqui primero nos encargamos de crear el tamano de la consola de comandos de Windows para que abra con un tamano y color tambien predetermninado
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    int ancho = 785; // Ancho deseado
    int alto = 570;  // Alto deseado
    MoveWindow(console, r.left, r.top, ancho, alto, TRUE);
    /*Aqui creamos un Thread/hilo, osea secuencia de instrucciones que se ejecutan en paralelo reutilizando espacios de memorias, para que la musica se oya mientras pasan cosas*/

    HANDLE hThread = CreateThread(NULL, 0, MainTheme, NULL, 0, NULL); //CreateThread(LpThreadAtributtes, dwStacksize, LpStartAdress, LpParametters, dwcreationflags, lpThreadID) :1. privacidad predeterminada, 2. sin tamano especifico, 3.la funcion que usamos 3. no se le pasa argumentos a la funcion en paralelo, 4.no se espera nada para ejecutar la funcion 5. El hilo no tiene un identificador, no nos importa quien sea, solo que se ejecute ...por ahora
    SetThreadPriority(hThread, THREAD_PRIORITY_ABOVE_NORMAL);
}

void BootSequence::colorbackground(int col, int bor) {
    system("cls");
     //Un cursor, que nospermite ubicar al caracter en una posiicon de la pantalla
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; 
    cout << "\x1b[48;5;" << col << "m";
     string line(width, ' '); //creamos una linea llena de espacios en blanco, para usando  el ANSI anterior tener solo un contorno del color deseado
    for (int h = 0; h < height/2; h++) {cout << line << endl<<line<<endl;} //lo imprimimos con un bucle sencillo
    //AHORA PARA EL MARGEN superior e inferior
     string line2(width, static_cast<char>(223));
     string line3(width, static_cast<char>(220));
    short posy = height-1;
    pos = { 0, 0 };  SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << bor << ";38;5;" << bor << "m"; cout << line2;
    pos = { 0, posy};  SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << bor << ";38;5;" << bor << "m"; cout << line3;
    //PARA LOS MARGENES LATERALES
    pos = { 0,0 };   SetConsoleCursorPosition(hConsole, pos); for (int h = 0; h < height / 2;h++) { cout << "\x1b[48;5;" << bor << "m"; cout << " " << endl << " "<<endl; }
    for (int h = 0; h < height-1; h++) { pos = { short(width - 1), short(h) }; SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << bor << "m"; cout << " " << endl; }
    pos = { 10,20 }; SetConsoleCursorPosition(hConsole, pos);

}
DWORD WINAPI BootSequence::MainTheme(LPVOID longpointer) {
    while (1 != 0) {
        Beep(660, 75);  // E5
        Sleep(112);
        Beep(660, 75);  // E5
        Sleep(225);
        Beep(660, 75);  // E5
        Sleep(225);
        Beep(510, 75);  // C5
        Sleep(75);
        Beep(660, 75);  // E5
        Sleep(225);
        Beep(770, 75);  // G5
        Sleep(412);
        Beep(380, 75);  // E4
        Sleep(431);
        Beep(510, 75);  // C5
        Sleep(337);
        Beep(380, 75);  // E4
        Sleep(300);
        Beep(320, 75);  // D4
        Sleep(375);
        Beep(440, 75);  // A4
        Sleep(225);
        Beep(480, 60);  // A#4/Bb4
        Sleep(247);
        Beep(450, 75);  // A4
        Sleep(112);
        Beep(430, 75);  // G#4/Ab4
        Sleep(225);
        Beep(380, 75);  // E4
        Sleep(150);
        Beep(660, 60);  // E5
        Sleep(150);
        Beep(760, 37);  // F#5
        Sleep(112);
        Beep(860, 75);  // G#5
        Sleep(225);
        Beep(700, 60);  // F5
        Sleep(112);
        Beep(760, 37);  // F#5
        Sleep(262);
        Beep(660, 60);  // E5
        Sleep(225);
        Beep(520, 60);  // C#5/Db5
        Sleep(112);
        Beep(580, 60);  // D5
        Sleep(112);
        Beep(480, 60);  // B4
        Sleep(112);
        Beep(500, 75);  // C5
        Sleep(225);
        Beep(760, 75);  // F#5
        Sleep(112);
        Beep(720, 75);  // F5
        Sleep(112);
        Beep(680, 75);  // E5
        Sleep(112);
        Beep(620, 150); // D#5/Eb5
        Sleep(150);
        Beep(650, 150); // E5
        Sleep(300);
        Beep(380, 75);  // E4
        Sleep(112);
        Beep(430, 75);  // G#4/Ab4
        Sleep(112);
        Beep(500, 75);  // C5
        Sleep(112);
        Beep(430, 75);  // G#4/Ab4
        Sleep(112);
        Beep(500, 75);  // C5
        Sleep(112);
        Beep(570, 150); // D5
        Sleep(300);
    }
    return 0;

}

void BootSequence::LogoUpsa(int col, int bor) {
    char block =(219);
    char shadedBlock =(178);
    string line1 = string(2, block) + "\t    " + block + shadedBlock + "\t"    + string(8, block) + shadedBlock + "       " + string(9, block) + shadedBlock+"        " + string(8, block) + shadedBlock + "\n";
    string line2 = string(2, block) + "\t    " + block + string(1, shadedBlock) + "\t"    + string(2, block) + "\t" + block + shadedBlock + "      " + string(2, block)+ "\t         " + string(2, block) + "       " + block + shadedBlock;
    string line3 = string(2, block) + "\t    " + block + string(1, shadedBlock) + "\t"+ string(8, block) + shadedBlock + "\t" + string(8, block) + shadedBlock+ "        "+ string(10, block) + shadedBlock+"\n";
    string line4 = string(2, block) + "\t    " + block + string(1, shadedBlock) + "\t"+ string(2, block)  +"\t\t       " + string(2, block)  +shadedBlock+"       "+ string(2, block) + "       " + block + shadedBlock;
    string line5 = string(11, block) + string(1, shadedBlock) + "   " + string(2, block)+ "\t       " + string(9, block) + shadedBlock+"        " + string(2, block)+ "       " + block + shadedBlock;
    cout << "\x1b[48;5;" << col << ";38;5;" << 29 << "m";
    pos = { short(width / 7),short(height / 8) }; 
    for (int i = 0; i < ((height / 2) - (height / 8)); i++){ pos.Y++; SetConsoleCursorPosition(hConsole, pos); cout << string(68,block) << endl; }
    pos = { short(width / 7),short(height / 8) };     SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << string(68, block); for (int h = 0; h < 12; h++) { pos.Y++; SetConsoleCursorPosition(hConsole, pos); cout << block << endl; }
    pos = { short(width / 7),short(height / 2) };     SetConsoleCursorPosition(hConsole, pos); cout << string(68, block); pos.Y = (height / 8)-1; for (int h = 0; h < 12; h++) { pos.X = (68 + (width / 7)); pos.Y++; SetConsoleCursorPosition(hConsole, pos); cout << block << endl; }
    pos = { short(width / 5.5),short(height / 4) };
    
    SetConsoleCursorPosition(hConsole, pos);
            cout << "\x1b[48;5;" << 29 << ";38;5;" << bor << "m";
            cout << line1; pos = { short(pos.X),short(pos.Y+1)}; SetConsoleCursorPosition(hConsole, pos);
            cout << line2; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
            cout << line2; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
            cout << line3; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
            cout << line4; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
            cout << line4; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
            cout << line5; pos = { short(pos.X),short(pos.Y + 1) }; SetConsoleCursorPosition(hConsole, pos);
}

void BootSequence::LogoStonks(int col, int bor) {

    char block = static_cast<char>(219); // Block character
    char shadedBlock = static_cast<char>(178); // Shaded block character
    COORD pos = { short(-9+width / 5.5), short(height / 4) };
    SetConsoleCursorPosition(hConsole, pos);
    cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << "    " + string(2, block) + shadedBlock + "   \t"; pos.Y++;    SetConsoleCursorPosition(hConsole, pos);
    cout << string(10,block)+string(2, shadedBlock)  +"     \t"; pos.Y++;    SetConsoleCursorPosition(hConsole, pos);
    cout << string(2, block) + string(1, shadedBlock) + " "+ string(2, block) + shadedBlock + "  ";  cout << " \x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << "    " << string(8, block) + shadedBlock /*T*/ +"    "+string(8, block)+shadedBlock + /*O*/ "    " + string(2, block) + "     " + block + shadedBlock +/*N*/"    " + string(2, block) + "     " + block + shadedBlock /*K*/; pos.Y++;
    SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << string(2, block) + string(1, shadedBlock) + " " + string(2, block) + shadedBlock + "  ";  cout << "\x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << "         " << string(1, block) + shadedBlock /*T*/ + "       " + string(2, block) + "     " + string(1, block) + shadedBlock +/*O*/ "    " + string(3, block) + "    " + block + shadedBlock +/*N*/"    " + string(2, block) + "    " + block + shadedBlock /*K*/+"       ";  cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << block + string(1, shadedBlock) + "       " + block + shadedBlock; pos.Y++;
    cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";    SetConsoleCursorPosition(hConsole, pos);
    cout << string(10, block) + string(2, shadedBlock) + "      ";  cout << "\x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << string(1, block) + shadedBlock /*T*/ + "       " + string(2, block) + "     " + string(1, block) + shadedBlock +/*O*/ "    " + string(2, block) + " "+block+"   " + block + shadedBlock +/*N*/"    " + string(2, block) + "   " + block + shadedBlock /*K*/ + "        ";  cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << block + string(1, shadedBlock) + "       " + block + shadedBlock; pos.Y++;
    SetConsoleCursorPosition(hConsole, pos);   cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << "    "+string(2, block)+shadedBlock+" "+string(2, block) + string(2, shadedBlock) + "      ";  cout << "\x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << string(1, block) + shadedBlock /*T*/ + "       " + string(2, block) + "     " + string(1, block) + shadedBlock +/*O*/ "    " + string(2, block) + "  " + block + "  " + block + shadedBlock +/*N*/"    " + string(4, block) + "" + block + shadedBlock /*K*/ + "      ";  cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << string(7,block) + string(1, shadedBlock) + " " + string(7, block) + shadedBlock; pos.Y++;
    SetConsoleCursorPosition(hConsole, pos);    cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << "    " + string(2, block) + shadedBlock + " " + string(2, block) + string(2, shadedBlock) + "      ";  cout << "\x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << string(1, block) + shadedBlock /*T*/ + "       " + string(2, block) + "     " + string(1, block) + shadedBlock +/*O*/ "    " + string(2, block) + "   " + block + " " + block + shadedBlock +/*N*/"    " + string(2, block) + "    " + block + shadedBlock /*K*/ + "       ";  cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << string(1, block) + string(1, shadedBlock) + "       " + string(1, block) + shadedBlock; pos.Y++;
    SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << string(10, block)  + string(2, shadedBlock) + "      ";  cout << "\x1b[48;5;" << col << ";38;5;" << 34 << "m"; /*Yelou*/ cout << string(1, block) + shadedBlock /*T*/ + "       " + string(8, block) + shadedBlock +/*O*/ "    " + string(2, block) + "    " + block + "" + block + shadedBlock +/*N*/"    " + string(2, block) + "    " + block + shadedBlock /*K*/ + "       ";  cout << "\x1b[48;5;" << col << ";38;5;" << 15 << "m"; cout << string(1, block) + string(1, shadedBlock) + "       " + string(1, block) + shadedBlock; pos.Y++;
    SetConsoleCursorPosition(hConsole, pos); cout << "\x1b[48;5;" << col << ";38;5;" << 220 << "m";
    cout << "    " + string(2, block) + shadedBlock + "   \t"; pos.Y++;    SetConsoleCursorPosition(hConsole, pos);
}

