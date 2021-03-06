#ifndef Fecha_H
#define Fecha_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>

#include "Utiles.h"

#pragma warning(disable:4996)

using namespace std;

class Fecha
{
private:
	int annio;
	int mes;
	int dia;
	int day;

	time_t now = time(NULL);
	struct tm nowLocal = *localtime(&now);

public:
	Fecha();
	Fecha(int, int, int);
	Fecha(int, int, int, int);
	~Fecha();

	int getAnnio();
	int getMes();
	int getDia();
	int getDay();

	string getMesPal(int);

	void setAnnio(int);
	void setMes(int);
	void setDia(int);
	void setDay(int);

	string toString();

	static bool validarFecha(int, int, int);
	bool esMenor(Fecha*);
	static Fecha* validarFechaC(int, int, int);


	void guardar(ofstream&);
	static Fecha* leer(ifstream&);
};

#endif /*Fecha_H*/