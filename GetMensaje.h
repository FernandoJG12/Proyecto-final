#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Mensaje {
	string texto;
	bool deUsuario;
};

void mostrarMensaje(const Mensaje& mensaje, int& linea);
string obtenerRespuesta(const string& pregunta);
void interfaz(const vector<Mensaje>& historial);
void agregarConocimiento(const string& pregunta, const string& respuesta);

