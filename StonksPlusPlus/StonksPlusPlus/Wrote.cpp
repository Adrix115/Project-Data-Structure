#include "Wrote.h"

Wrote::Wrote() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
Wrote::~Wrote() {}

void Wrote::write(string text) {
	int tempX=pos.X;
cout<< "\x1b[48;5;" << 211 << ";38;5;" << 211 << "m";
cout << "\x1b[38;5;"<<colour<<"m" << endl;
if (pos.X==(width/2)) pos.X-= short( text.size()/2);
else if (pos.X>(width/2)) pos.X -= short(text.size());
else { pos.X = pos.X; }
SetConsoleCursorPosition(hConsole, pos);
pos.Y += 1; pos.X = tempX;
cout << text;

}

void Wrote::newl(int n) {
	short tempx = pos.X;
	for (int i = 0; i < n; i++) cout << endl;
	pos.Y += n; pos.X = tempx; SetConsoleCursorPosition(hConsole, pos);
}

void Wrote::changecolor(int n) {
	colour = n;
}

void Wrote::changealignedment(string a) {
	if (a == "center") { pos.X = (width/2); }
	else if (a == "left") { pos.X = 3; }
	else if (a == "right") { pos.X = width-3; }
	SetConsoleCursorPosition(hConsole, pos);
}

void Wrote::reset() {
	pos = { 3, 2 }; SetConsoleCursorPosition(hConsole, pos);

}