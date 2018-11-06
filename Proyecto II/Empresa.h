#ifndef EMPRESA_H
#define EMPRESA_H

#include "Agenda.h"
#include "Cita.h"

class Empresa 
{
public:
	Empresa(string);
	~Empresa();
private:
	string nombre;

	string setNombre();
	void getNombre(string);

	void guardar(ofstream&);
	static Empresa* leer(ifstream&);
};

#endif // !EMPRESA_H