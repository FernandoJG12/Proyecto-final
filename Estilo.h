#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;


class Estilo {
public:
	enum Color {
        BLACK = 0,
        DARK_BLUE = 1,
        DARK_GREEN = 2,
        DARK_CYAN = 3,
        DARK_RED = 4,
        DARK_MAGENTA = 5,
        DARK_YELLOW = 6,
        LIGHT_GRAY = 7,
        DARK_GRAY = 8,
        BLUE = 9,
        GREEN = 10,
        CYAN = 11,
        RED = 12,
        MAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
	};

    
    static void ColorText(Color text, Color fondo);
    static void PosCursor(int x, int y);
    static void ColorBG(Color fondo);
    static void CentrarText(const string& mensaje, int y, Color text, Color fondo);
    static void ConsoleSize(int& ancho, int& alto);
    static void LimpiarPantalla();
};