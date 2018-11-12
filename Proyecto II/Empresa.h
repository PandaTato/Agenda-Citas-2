#ifndef EMPRESA_H
#define EMPRESA_H

#include "Agenda.h"
#include "Cita.h"
#include "Factura.h"

class Empresa 
{
public:
	Empresa(string);
	Empresa(string, Lista<Cita>*, Lista<Paciente>*, Lista<Doctor>*, Lista<Factura>*);
	~Empresa();

    void setNombre(	string );
	void setAgenda(Agenda *);

	void setCitas(Lista<Cita>*);
	void setPacientes(Lista<Paciente>* );
	void setDoctores(Lista<Doctor>* );
	void setFacturas(Lista<Factura>* );


	void getNombre(string);
	Agenda *getAgenda();

	Lista<Cita>* getCitas();
	Lista<Paciente>* getPacientes();
	Lista<Doctor>* getDoctores();
	Lista<Factura>* getFacturas();

	void guardar(ofstream&);
	static Empresa* leer(ifstream&);

private:
	string nombre;

	Lista<Cita>* cita;
	Agenda *agenda;
	Lista<Paciente>* paciente;
	Lista<Doctor>* doctor;
	Lista<Factura>* factura;
};

#endif // !EMPRESA_H