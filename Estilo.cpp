#include "Estilo.h"


void Estilo::ColorText(Color text, Color fondo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (fondo << 4) | text);
}

void Estilo::LimpiarPantalla() {
	system("cls");
}

void Estilo::PosCursor(int x, int y) {
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Estilo::ConsoleSize(int& ancho, int& alto) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Estilo::ColorBG(Color fondo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if(!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	WORD currentTextColor = csbi.wAttributes & 0x0F;
	WORD newAttributes = (fondo << 4) | currentTextColor;

	COORD startcoord = { 0,0 };
	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	FillConsoleOutputAttribute(
		hConsole,
		newAttributes,
		consoleSize,
		startcoord,
		&written
	);
	SetConsoleTextAttribute(hConsole, newAttributes);
	PosCursor(0, 0);
	system("cls");
}

void Estilo::CentrarText(const string& mensaje, int y, Color textColor, Color bgColor) {
	int ancho, alto;
	Estilo::ConsoleSize(ancho, alto);
	int x = (ancho - mensaje.length()) / 2;
	PosCursor(x, y);
	ColorText(textColor, bgColor);
	cout << mensaje;
}

