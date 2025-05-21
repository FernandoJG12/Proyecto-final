#include "GetMensaje.h"
#include "ConexionMySql.h"
#include "Estilo.h"
#include "ConfTexto.h"
#include "ConsultarChatgpt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

int Desplazamiento = 0;
const int mensajesMaximos = 10;


//Funcion para obtener una respuesta tomando tres formas de conseguirla: un txt, una base de datos y como ultima opcion ChatGPT
string obtenerRespuesta(const string& pregunta) {
	try {
		string preguntaNormalizada = normalizarTexto(pregunta); //Normaliza la pregunta que ingresa el usuario para eliminar signos y demas
		vector<string> palabrasClave = ObPalabrasClave(preguntaNormalizada); //Obtiene palabras clave de la pregunta ya normalizada

		string respuestaDB = BaseDatos(preguntaNormalizada);
		if (respuestaDB != "No encontre respuesta" &&
			respuestaDB != "Error en la consulta a la base de datos" &&
			respuestaDB != "Error al conectar con la base de datos") {
			return respuestaDB + " (Base de datos)";
		}

		int mejorPuntaje = 0;
		string mejorRespuesta = "No encontre respuesta";

		ifstream archivo("conocimiento.txt", ios::in);
		if (!archivo) {
			cerr << "Error: No se pudo abrir el archivo conocimiento.txt" << endl;
			return consultarChatGPT(preguntaNormalizada);
		}

		map<string, string> Pregunta_Respuesta;
		string linea;

		while (getline(archivo, linea)) {
			size_t separador = linea.find('|');
			if (separador != string::npos) {
				string pregunta = normalizarTexto(linea.substr(0, separador));
				string respuesta = linea.substr(separador + 1);
				Pregunta_Respuesta[pregunta] = respuesta;
			}
		}
		archivo.close();

		for (auto& par : Pregunta_Respuesta) {
			string Almacen = par.first;
			int puntaje = 0;

			for (const string& palabra : palabrasClave) {
				if (Almacen.find(palabra) != string::npos) {
					puntaje++;
				}
			}
			if (puntaje > mejorPuntaje) {
				mejorPuntaje = puntaje;
				mejorRespuesta = par.second;
			}
		}

		if (mejorRespuesta != "No encontre respuesta") {
			return mejorRespuesta + " (txt)";
		}
		if (Pregunta_Respuesta.find(preguntaNormalizada) == Pregunta_Respuesta.end()) {
			agregarConocimiento(pregunta, consultarChatGPT(preguntaNormalizada));
		}
		return consultarChatGPT(preguntaNormalizada) + "(ChatGPT)";
		
	}
	catch (const exception& e) {
		cerr << "Error en obtenerRespuesta: " << e.what() << endl;
		return "Ocurrió un error al procesar tu pregunta";
	}
	catch (...) {
		cerr << "Error desconocido en obtenerRespuesta" << endl;
		return "Ocurrió un error inesperado";
	}
}

void mostrarMensaje(const Mensaje& mensaje, int& linea) {
	int ancho, alto;
	Estilo::ConsoleSize(ancho, alto);
	int anchoMax = ancho - 15;

	string textoCompleto = mensaje.deUsuario ? "Usuario: " + mensaje.texto : "Bot: " + mensaje.texto;

	vector<string> lineas;
	string textoActual = textoCompleto;

	while (textoActual.length() > anchoMax) {
		int posCorte = anchoMax;
		while (posCorte > 0 && textoActual[posCorte] != ' ') {
			posCorte--;
		}

		if (posCorte == 0) {
			posCorte = anchoMax;
		}

		lineas.push_back(textoActual.substr(0, posCorte));
		textoActual = textoActual.substr(posCorte + 1);
	}

	if (!textoActual.empty()) {
		lineas.push_back(textoActual);
	}

	for (const auto& lineaTexto : lineas) {
		if (mensaje.deUsuario) {
			fstream log("log.txt", ios::app);
			log << lineaTexto <<endl;
			log.close();

			int posX = max(5, ancho - static_cast<int>(lineaTexto.length()) - 5);

			Estilo::PosCursor(posX, linea + 5);
			Estilo::ColorText(Estilo::BLACK, Estilo::GREEN);
		}
		else {
			Estilo::PosCursor(5, linea + 5);
			Estilo::ColorText(Estilo::BLACK, Estilo::GREEN);
		}
		cout << lineaTexto;
		linea++;

		if (linea >= alto - 5) {
			break;
		}
	}
}

void interfaz(const vector<Mensaje>& historial) {
	Estilo::LimpiarPantalla();

	Estilo::ColorBG(Estilo::DARK_GRAY);
	Estilo::ColorText(Estilo::BLACK, Estilo::DARK_GRAY);                                                              
	int ancho, alto;
	Estilo::ConsoleSize(alto, ancho);
	_setmode(_fileno(stdout), _O_U16TEXT); // Modo Unicode
	std::wcout << LR"( 
			    █████╗ ███╗   ██╗██╗███╗   ███╗███████╗██████╗  ██████╗ ████████╗
			   ██╔══██╗████╗  ██║██║████╗ ████║██╔════╝██╔══██╗██╔═══██╗╚══██╔══╝
			   ███████║██╔██╗ ██║██║██╔████╔██║█████╗  ██████╔╝██║   ██║   ██║   
			   ██╔══██║██║╚██╗██║██║██║╚██╔╝██║██╔══╝  ██╔══██╗██║   ██║   ██║   
			   ██║  ██║██║ ╚████║██║██║ ╚═╝ ██║███████╗██████╔╝╚██████╔╝   ██║   
			   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝     ╚═╝╚══════╝╚═════╝  ╚═════╝    ╚═╝   
    )" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	int temp = ancho;
	ancho = alto;
	alto = temp;

	int espacioDisponible = alto - 5;

	if (historial.size() > mensajesMaximos) {
		Desplazamiento = max(0, (int)historial.size() - mensajesMaximos);
	}
	else {
		Desplazamiento = 0;
	}

	int lineaActual = 3;

	for (size_t i = Desplazamiento; i < historial.size(); i++) {
		if (lineaActual >= alto - 5) {
			break;
		}

		mostrarMensaje(historial[i], lineaActual);
		lineaActual++;
	}

	Estilo::PosCursor(2, alto - 3);
	Estilo::ColorText(Estilo::BLACK, Estilo::DARK_GRAY);
	cout << "Tu mensaje: ";
	Estilo::PosCursor(14, alto - 3);
}

void agregarConocimiento(const string& pregunta, const string& respuesta){
	ofstream archivo("conocimiento.txt", ios::app);
	if (archivo.is_open()) {
		archivo << endl << string(pregunta) << "|" << string(respuesta);
		archivo.close();
	}
	else {
		cerr << "No se pudo abrir el archivo";
	}
}
