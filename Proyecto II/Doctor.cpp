#include "Doctor.h"

Doctor::Doctor() : Persona() {}
Doctor::Doctor(string ID, string nom, string ape, string tel, string cor, Fecha * fec) : Persona(ID, nom, ape, tel, cor, fec) {}

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
		<< "#----------------------------------------------#" << endl
		<< "#      Correo      | " << correo << endl
		<< "#----------------------------------------------#" << endl
		<< "# Fecha Nacimiento | " << nacimiento->getAnnio() << " / " << nacimiento->getMes() << " / " << nacimiento->getDia() << endl
		<< "#----------------------------------------------#" << endl;

	return r.str();
}

void Doctor::guardar(ofstream & salida)

{
	salida << id << '\t';
	salida << nombre << '\t';
	salida << apellido << '\t';
	salida << telefono << '\t';
	salida << correo << '\t';
	nacimiento->guardar(salida);
}


Doctor * Doctor::leer(ifstream & entrada)
{
	string id, nom, ape, cor, tel;
	Fecha* fec;


	getline(entrada, id, '\t');
	getline(entrada, nom, '\t');
	getline(entrada, ape, '\t');
	getline(entrada, tel, '\t');
	getline(entrada, cor, '\t');

	fec = Fecha::leer(entrada);

	return new Doctor(id, nom, ape, tel, cor, fec);
}