#include "Agenda.h"

Agenda::Agenda() { citas = NULL; }
Agenda::Agenda(Lista<Cita>* pCitas) { this->citas = pCitas; }
Agenda::Agenda(Agenda* pAgenda) { this->citas = pAgenda->getCitas(); }

Agenda::~Agenda(){}

Lista<Cita>* Agenda::getCitas() { return citas; }

void Agenda::setCitas(Lista<Cita>* pCitas){ this->citas = pCitas; }

string Agenda::toString()
{	
	stringstream r;

	r << citas->toString();

	return r.str();
}

void Agenda::guardar(ofstream & salida) { citas->guardar(salida); }

Agenda* Agenda::leer(ifstream & entrada)
{
	Lista<Cita>* ptrLista = Lista<Cita>::leer(entrada);

	return new Agenda(ptrLista);
}
