#ifndef Hora_H
#define Hora_H

#pragma warning(disable:4996)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

#include "Utiles.h"

using namespace std;

class Hora
{
private:
	int hora;
	int minutos;

	time_t now = time(NULL);
	struct tm nowLocal = *localtime(&now);

public:
	Hora();
	Hora(int, int);
	~Hora();

	void setHora(int);
	void setMinutos(int);

	int getHora();
	int getMinutos();

	bool esMenor(Hora*);

	string toString();

	static bool validarHora(int, int);

	void guardar(ofstream&);
	static Hora* leer(ifstream&);
};

#endif /*Hora_H*/
