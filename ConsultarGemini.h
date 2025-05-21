#pragma once
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <locale.h>  //soporte de caracteres especiales
#include <iostream>

std::string consultarGemini(const std::string& pregunta); //Funcion de consulta a Gemini