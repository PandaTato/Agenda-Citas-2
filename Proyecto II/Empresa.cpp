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

<<<<<<< HEAD
string Empresa::setNombre() { return nombre; }

void Empresa::getNombre(string pNombre) { this->nombre = pNombre; }

void Empresa::guardar(ofstream&)
{
}

Empresa * Empresa::leer(ifstream&)
{
	return new Empresa("");
=======
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
>>>>>>> f70ecea79873695b79ff1fcc32f6a11d3aa7191f
}
