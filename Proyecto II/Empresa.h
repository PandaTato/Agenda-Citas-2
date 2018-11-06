#ifndef EMPRESA_H
#define EMPRESA_H

#include "Agenda.h"
#include "Cita.h"
#include "Factura.h"

class Empresa 
{
public:
	Empresa(string);
	~Empresa();

	string setNombre();

	void getNombre(string);
	string getId();
	Lista<Cita>* getCitas();
	Agenda *getAgenda();
	Lista<Paciente>* getPacientes();
	Lista<Doctor>* getDoctores();
	Lista<Factura>* getFacturas();

	void guardar(ofstream&);
	static Empresa* leer(ifstream&);

private:
	string nombre;

	Lista<Cita>* cits;
	Agenda *ag;
	Lista<Paciente>* pa;
	Lista<Doctor>* doc;
	Lista<Factura>* fac;
};

#endif // !EMPRESA_H