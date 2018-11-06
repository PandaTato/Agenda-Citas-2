#include "Paciente.h"

Paciente::Paciente() : Persona(){}

Paciente::Paciente(string ID, string nom, string ape, string tel, Fecha * fec): Persona(ID, nom, ape, tel, fec){}

Paciente::~Paciente(){}

string Paciente::toString()
{
	stringstream r;

	r
		<< "#----------------------------------------------#" << endl
		<< "#                   Paciente                    #" << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Cedula      | " << id << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Nombre      | " << nombre << endl
		<< "#----------------------------------------------#" << endl
		<< "#     Apellidos    | " << apellido << endl
		<< "#----------------------------------------------#" << endl
		<< "#     Telefono     | " << telefono << endl
		<< "#----------------------------------------------#" << endl
		<< "# Fecha Nacimiento | " << nacimiento->getAnnio() << " / " << nacimiento->getMes() << " / " << nacimiento->getDia() << endl
		<< "#----------------------------------------------#" << endl;

	return r.str();
}

void Paciente::guardar(ofstream & salida)

{
	salida << id << '\t';
	salida << nombre << '\t';
	salida << apellido << '\t';
	salida << telefono << '\t';
	nacimiento->guardar(salida);
}


Paciente * Paciente::leer(ifstream & entrada)
{
	string id, nom, ape, tel;
	Fecha* fec;


	getline(entrada, id, '\t');
	getline(entrada, nom, '\t');
	getline(entrada, ape, '\t');
	getline(entrada, tel, '\t');

	fec = Fecha::leer(entrada);

	return new Paciente(id, nom, ape, tel, fec);
}