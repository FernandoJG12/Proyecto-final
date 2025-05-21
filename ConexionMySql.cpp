#include "ConexionMySql.h"

string BaseDatos(const string& pregunta){  
	try {
		Driver* driver;
		Connection* con;

		driver = get_driver_instance();

		//Conexion a la base de datos
		con = driver->connect("tcp://127.0.0.1:3307", "root", "123456"); 

		//Selecciona la base de datos 
		con->setSchema("chatbot_anime");

		//Bucle para mantener la conexion
		while (true) {
			//Verifica si la pregunta esta vacia
			if (!pregunta.empty()) {
				PreparedStatement* pstmt;
				pstmt = con->prepareStatement(
					//Consulta que busca la respuesta en la base de datos
					"SELECT respuesta FROM conocimiento WHERE pregunta LIKE CONCAT('%',?,'%') LIMIT 1"
				);
				pstmt->setString(1, pregunta);

				ResultSet* res = pstmt->executeQuery();

				if (res->next()) {
					return  res->getString("respuesta") ;
				}
				else {
					return "No encontre respuesta";
				}
				delete res;
				delete pstmt;
			}
		}
	}
	//Manejo de exceociones SQL
	catch (SQLException& e) {
		cout << "Error SQL: " << e.what() << endl;
		cout << "Código MySQL: " << e.getErrorCode() << endl;
		cout << "SQLState: " << e.getSQLState() << endl;
	}
	return 0;
}







