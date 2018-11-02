#ifndef EMPRESA_H
#define EMPRESA_H

#include "Agenda.h"
#include "Cita.h"

class Empresa {
public:
	Empresa(string);
	~Empresa();
private:
	string nombre;
};


#endif // !EMPRESA_H