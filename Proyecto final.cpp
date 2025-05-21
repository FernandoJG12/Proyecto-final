#include <iostream>
#include <string>
#include <vector>
#include "Estilo.h"
#include "GetMensaje.h"
#include "ConfTexto.h"
#include "ConexionMySql.h"
#include "ConsultarChatgpt.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "es_ES.UTF-8");
	Estilo::ColorBG(Estilo::DARK_GRAY);
	Estilo::LimpiarPantalla();
	
	vector<Mensaje> historial;
	string entradaUsuario;


	interfaz(historial);

	while (true) {

		int ancho, alto;
		Estilo::ConsoleSize(alto, ancho);
		int temp = ancho;
		ancho = alto;
		alto = temp;

		Estilo::PosCursor(14, alto -3);
		Estilo::ColorText(Estilo::WHITE, Estilo::DARK_GRAY);

		getline(cin, entradaUsuario);

		if (entradaUsuario == "salir" || entradaUsuario == "Salir" || entradaUsuario == "SALIR") {
			Estilo::ColorText(Estilo::BLACK, Estilo::CYAN);
			cout << "\nEspero haya sido de ayuda. Adios";
			Estilo::ColorText(Estilo::BLACK, Estilo::DARK_GRAY);
			break;
		}
		

		if (entradaUsuario.empty()) {
			continue;
		}

		Mensaje msgUsuario;
		msgUsuario.texto = entradaUsuario;
		msgUsuario.deUsuario = true;
		historial.push_back(msgUsuario);

		string respuestaBot = obtenerRespuesta(entradaUsuario);

		Mensaje msgBot;
		msgBot.texto = respuestaBot;
		msgBot.deUsuario = false;
		historial.push_back(msgBot);

		interfaz(historial);
	}

	return 0;
}
