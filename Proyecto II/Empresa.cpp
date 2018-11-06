#include "Empresa.h"

Empresa::Empresa(string a)
{
	nombre = a;
	cits = new Lista<Cita>();
	ag = new Agenda(cits);
	pa = new Lista<Paciente>();
	doc = new Lista<Doctor>();
	fac = new Lista<Factura>();
}

Empresa::~Empresa()
{
}

string Empresa::getId()
{
	return nombre;
}

Lista<Cita>* Empresa::getCitas()
{
	return cits;
}

Agenda * Empresa::getAgenda()
{
	return ag;
}

Lista<Paciente>* Empresa::getPacientes()
{
	return pa;
}

Lista<Doctor>* Empresa::getDoctores()
{
	return doc;
}

Lista<Factura>* Empresa::getFacturas()
{
	return fac;
}
