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

	string getId();
	Lista<Cita>* getCitas();
	Agenda *getAgenda();
	Lista<Paciente>* getPacientes();
	Lista<Doctor>* getDoctores();
	Lista<Factura>* getFacturas();
private:
	string nombre;
<<<<<<< HEAD

	string setNombre();
	void getNombre(string);

	void guardar(ofstream&);
	static Empresa* leer(ifstream&);
};
=======
	Lista<Cita>* cits;
	Agenda *ag;
	Lista<Paciente>* pa;
	Lista<Doctor>* doc;
	Lista<Factura>* fac;

};

	
>>>>>>> f70ecea79873695b79ff1fcc32f6a11d3aa7191f

#endif // !EMPRESA_H