#include "Cita.h"

int codigo = 0;

Cita::Cita()
{
	this->id = codigo++;

	this->doctor = NULL;
	this->paciente = NULL;
	this->fecha = NULL;
	this->hora = NULL;
}
Cita::Cita(Doctor * pDoctor, Paciente * pPaciente, Fecha * pFecha, Hora * pHora)
{
	this->id = codigo++;

	this->doctor = pDoctor;
	this->paciente = pPaciente;
	this->fecha = pFecha;
	this->hora = pHora;
}
Cita::Cita(string pID, Doctor * pDoctor, Paciente * pPaciente, Fecha * pFecha, Hora * pHora)
{
	this->id = pID;

	this->doctor = pDoctor;
	this->paciente = pPaciente;
	this->fecha = pFecha;
	this->hora = pHora;
}

Cita::~Cita(){}

string Cita::getId(){	return id;}
Doctor * Cita::getDoctor(){	return doctor;}
Paciente * Cita::getPaciente() { return paciente; }
Fecha * Cita::getFecha() { return fecha; }
Hora * Cita::getHora() { return hora; }

void Cita::setId(string pID) { this->id = pID; }
void Cita::setDoctor(Doctor * pDoctor) { this->doctor = pDoctor; }
void Cita::setPaciente(Paciente * pPaciente) { this->paciente = pPaciente; }
void Cita::setFecha(Fecha * pFecha) { this->fecha = pFecha; }
void Cita::setHora(Hora * pHora) { this->hora = pHora; }

string Cita::toString()
{
	stringstream r;

	r
		<< "#----------------------------------------------#" << endl
		<< "#                     Cita                     #" << endl
		<< "#----------------------------------------------#" << endl
		<< "#        ID        | " << id << endl
		<< "#----------------------------------------------#" << endl
		<< "#                    Doctor                    #" << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Nombre      | " << doctor->getNombre() << endl
		<< "#     Apellido     | " << doctor->getApellido() << endl
		<< "#----------------------------------------------#" << endl
		<< "#                   Paciente                   #" << endl
		<< "#----------------------------------------------#" << endl
		<< "#      Nombre      | " << paciente->getNombre() << endl
		<< "#     Apellido     | " << paciente->getApellido() << endl
		<< "#----------------------------------------------#" << endl
		<< "#       Fecha      | " << fecha->getAnnio() << " / " << fecha->getMes() << " / " << fecha->getDia() << endl
		<< "#----------------------------------------------#" << endl
		<< "#       Hora       | " << hora->getHora() << " : " << hora->getMinutos() << endl
		<< "#----------------------------------------------#" << endl;

	return r.str();
}

ostream & operator<<(ostream & out, Cita* e)
{
	out
		<< "Id: " << e->id << "\t" << e->fecha->getDia() << "/" << e->fecha->getMes() << "/" << e->fecha->getAnnio()
		<< "\t" << e->paciente->getNombre() << " " << e->paciente->getApellido()
		<< "\t" << e->paciente->getID() << endl
		<< "                                 *--------*                           " << endl;

	return out;
}

void Cita::guardar(ofstream & salida)
{
	salida << id << '\n';
	
	this->doctor->guardar(salida);
	this->paciente->guardar(salida);
	this->fecha->guardar(salida);
	this->hora->guardar(salida);
}

Cita * Cita::leer(ifstream & entrada)
{
	string id;

	getline(entrada, id, '\n');
	Doctor* pDoctor = Doctor::leer(entrada);
	Paciente* pPaciente = Paciente::leer(entrada);
	Fecha* pFecha = Fecha::leer(entrada);
	Hora* pHora = Hora::leer(entrada);

	return new Cita(id, pDoctor, pPaciente, pFecha, pHora);
}
