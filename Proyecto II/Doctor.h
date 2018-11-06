#ifndef Doctor_H
#define Doctor_H

#include "Persona.h"

using namespace std;

class Doctor : public Persona
{
public:
	Doctor();
	Doctor(string, string, string, string, Fecha*);
	~Doctor();

	//to string
	virtual string toString();

	//guardar, leer
	void guardar(ofstream&);
	static Doctor* leer(ifstream&);
};

#endif /*Doctor_H*/