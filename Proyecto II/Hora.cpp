#include "Hora.h"

Hora::Hora()
{
	hora = nowLocal.tm_hour;
	minutos = nowLocal.tm_min;
}
Hora::Hora(int h, int m) 
{
	hora = h;
	minutos = m;
}

Hora::~Hora() {}

void Hora::setHora(int h) { hora = h; }
void Hora::setMinutos(int m){	minutos = m;}

int Hora::getHora() { return hora; }
int Hora::getMinutos(){	return minutos;}

bool Hora::esMenor(Hora * hor)
{
	int h = hor->getHora();
	int m = hor->getMinutos();

	if (hora <= h)
		if (minutos <= m)
			return true;

	return false;
}

string Hora::toString() 
{
	stringstream s;
	s << "La hora es : " << hora << ":" << minutos << endl;
	return s.str();
}

bool Hora::validarHora(int h, int m)
{
	if (h < 25 && h >= 0 && m < 60 && m >= 0)
		return true;
	else
		return false;
}

void Hora::guardar(ofstream & salida)
{
	salida << hora << '\t';
	salida << minutos << '\n';
}

Hora * Hora::leer(ifstream & entrada)
{
	string h, m;

	getline(entrada, h, '\t');
	getline(entrada, m, '\n');

	int hora, min;

	hora = convertirInt(h);
	min = convertirInt(m);

	return new Hora(hora, min);
}
