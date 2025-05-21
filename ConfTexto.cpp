#include "ConfTexto.h"
#include <sstream>
#include <cctype>

//Funcion para normalizar el texto
string normalizarTexto(const string& texto) {
	string normalizado;

	for (size_t i = 0; i < texto.size(); i++) {
		unsigned char c = texto[i];

		switch (c) {
		case 'á': case 'Á': case 'à': case 'À': case 'â': case 'Â': case 'ä': case 'Ä':
			normalizado += 'a'; break;
		case 'é': case 'É': case 'è': case 'È': case 'ê': case 'Ê': case 'ë': case 'Ë':
			normalizado += 'e'; break;
		case 'í': case 'Í': case 'ì': case 'Ì': case 'î': case 'Î': case 'ï': case 'Ï':
			normalizado += 'i'; break;
		case 'ó': case 'Ó': case 'ò': case 'Ò': case 'ô': case 'Ô': case 'ö': case 'Ö':
			normalizado += 'o'; break;
		case 'ú': case 'Ú': case 'ù': case 'Ù': case 'û': case 'Û': case 'ü': case 'Ü':
			normalizado += 'u'; break;
		case 'ñ': case 'Ñ':
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