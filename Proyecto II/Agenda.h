#ifndef AGENDA_H
#define AGENDA_H

#include "Cita.h"
#include "Lista.h"

class Agenda
{
private:
	Lista<Cita>* citas;
public:
	Agenda(Lista<Cita>*);
	Agenda(Agenda*);
	
	~Agenda();

	Lista<Cita>* getCitas();

	void setCitas(Lista<Cita>*);

	string toString();

	string obtenerAgenda(Doctor*,Fecha*);
	
};

#endif // !AGENDA_H

