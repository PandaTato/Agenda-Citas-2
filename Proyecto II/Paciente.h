#ifndef Paciente_H
#define Paciente_H

#include "Persona.h"

using namespace std;

class Paciente : public Persona
{
public:
	Paciente();
	Paciente(string, string, string, string, string, Fecha*);
	~Paciente();

	//to string
	virtual string toString();

	//guardar, leer
	void guardar(ofstream&);
	static Paciente* leer(ifstream&);
};

#endif /*Paciente_H*/