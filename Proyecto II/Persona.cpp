#include "Persona.h"

Persona::Persona()
{
	this->id = "";
	this->nombre = "";
	this->apellido = "";
	this->telefono = "";
}
Persona::Persona(string ID, string nom, string ape, string tel, Fecha* nac)
{
	this->id = ID;
	this->nombre = nom;
	this->apellido = ape;
	this->telefono = tel;
	this->nacimiento = nac;
}

Persona::~Persona(){}

string Persona::getID() { return string(id); }
string Persona::getNombre() { return string(nombre); }
string Persona::getApellido(){	return string(apellido);}
string Persona::getTelefono(){	return string(telefono);}
Fecha * Persona::getNacimiento() {	return nacimiento;}

void Persona::setID(string ID){	id = ID;}
void Persona::setNombre(string nom){ this->nombre = nom;}
void Persona::setApellido(string ape){ this->apellido = ape;}
void Persona::setTelefono(string tel){ this->telefono = tel;}
void Persona::getNacimiento(Fecha * nac) { this->nacimiento = nac; }
void Persona::guardar(ofstream &){}

Persona * Persona::leer(ifstream &) { return nullptr; }