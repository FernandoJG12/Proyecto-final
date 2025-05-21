#include "ConsultarGemini.h"

using json = nlohmann::json;

// Callback para libcurl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

std::string consultarGemini(const std::string& pregunta) {
    std::string apiKey = "API_KEY";
  
    std::string question = "Responde de manera concisa y resumida:" + pregunta;

    string modelName = "gemini-2.0-flash";  

    json requestData = {
        {"contents", {
            {
                {"parts", {
                    {{"text", question}}
                }}
            }
        }}
    };

    string requestBody = requestData.dump();

    CURL* curl = curl_easy_init();
    if (curl) {
        string readBuffer;
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        string url = "https://generativelanguage.googleapis.com/v1beta/models/" +
            modelName + ":generateContent?key=" + apiKey;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestBody.length());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json response = json::parse(readBuffer);

                if (response.contains("error")) {
                    cerr << "Error de la API: " << response["error"]["message"] << endl;
                }
                else if (response.contains("candidates") && !response["candidates"].empty()) {
                    string reply = response["candidates"][0]["content"]["parts"][0]["text"];
                    reply.erase(remove(reply.begin(), reply.end(), '\n'), reply.end());
                    return reply;
                }
                else {
                    cerr << "Respuesta inesperada de la API:\n" << response.dump(2) << endl;
                }
            }
            catch (const json::exception& e) {
                cerr << "Error al parsear JSON: " << e.what() << endl;
                cerr << "Contenido recibido: " << readBuffer << endl;
            }
        }
        else {
            cerr << "Error en la solicitud CURL: " << curl_easy_strerror(res) << endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    else {
        cerr << "Error al inicializar CURL." << endl;
    }

    return 0;
}