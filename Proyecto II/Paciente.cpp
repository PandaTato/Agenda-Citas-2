#include "Paciente.h"

Paciente::Paciente() : Persona(){}

Paciente::Paciente(string ID, string nom, string ape, string tel, string cor, Fecha * fec): Persona(ID, nom, ape, tel,cor, fec){}

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
		<< "#      Correo      | " << correo << endl
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
	salida << correo << '\t';
	nacimiento->guardar(salida);
}


Paciente * Paciente::leer(ifstream & entrada)
{
	string id, nom, ape, cor, tel;
	Fecha* fec;


	getline(entrada, id, '\t');
	getline(entrada, nom, '\t');
	getline(entrada, ape, '\t');
	getline(entrada, tel, '\t');
	getline(entrada, cor, '\t');

	fec = Fecha::leer(entrada);

	return new Paciente(id, nom, ape, tel, cor, fec);
}