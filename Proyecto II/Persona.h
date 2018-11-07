#ifndef Persona_H
#define Persona_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Fecha.h"

using namespace std;

class Persona
{
protected:
	string id;
	string nombre;
	string apellido;
	string telefono;

public:
	Persona();
	Persona(string, string, string,string);
	~Persona();

	//gets
	virtual string getID();
	virtual string getNombre();
	virtual string getApellido();
	virtual string getTelefono();

	//sets
	virtual void setID(string);
	virtual void setNombre(string);
	virtual void setApellido(string);
	virtual void setTelefono(string);

	//to string
	virtual string toString() = 0;

	//guardar, leer
	virtual void guardar(ofstream&);
	static Persona* leer(ifstream&);
};

#endif /* Persona_H */
