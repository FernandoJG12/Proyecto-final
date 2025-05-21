#include "ConfTexto.h"
#include <sstream>
#include <cctype>

//Funcion para normalizar el texto
string normalizarTexto(const string& texto) {
	string normalizado;

	for (size_t i = 0; i < texto.size(); i++) {
		unsigned char c = texto[i];

		switch (c) {
		case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
			normalizado += 'a'; break;
		case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
			normalizado += 'e'; break;
		case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
			normalizado += 'i'; break;
		case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
			normalizado += 'o'; break;
		case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
			normalizado += 'u'; break;
		case '�': case '�':
			normalizado += 'n'; break;
		default:
			if (isalpha(c)) {
				normalizado += static_cast<char>(tolower(c));
			}
			else if (c == ' ') {
				normalizado += ' ';
			}
		}
	}
	return normalizado;
}

//Funcion para obtener palabras clave
vector<string> ObPalabrasClave(const string& texto) {
	vector<string> palabras;
	istringstream iss(texto);
	string palabra;
	while (iss >> palabra) {
		if (palabra.size() > 7) {
			palabras.push_back(palabra);
		}
	}
	return palabras;
}