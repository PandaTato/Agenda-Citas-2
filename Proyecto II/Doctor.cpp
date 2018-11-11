#include "Doctor.h"

Doctor::Doctor() : Persona() {}
Doctor::Doctor(string ID, string nom, string ape, string tel): Persona(ID, nom, ape, tel) {}

Doctor::~Doctor() {}

string Doctor::toString()
{
	stringstream r;

	r
		<< "#----------------------------------------------#" << endl
		<< "#                    Doctor                    #" << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Cedula      | " << id << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Nombre      | " << nombre << endl
		<< "#----------------------------------------------#" << endl
		<< "#     Apellidos    | " << apellido << endl
		<< "#----------------------------------------------#" << endl
		<< "#     Telefono     | " << telefono << endl
		<< "#----------------------------------------------#" << endl;

	return r.str();
}

void Doctor::guardar(ofstream & salida)
{
	salida << id << '\t';
	salida << nombre << '\t';
	salida << apellido << '\t';
	salida << telefono << '\t';
}

Doctor * Doctor::leer(ifstream & entrada)
{
	string id, nom, ape, tel;


	getline(entrada, id, '\t');
	getline(entrada, nom, '\t');
	getline(entrada, ape, '\t');
	getline(entrada, tel, '\t');


	return new Doctor(id, nom, ape, tel);
}