#include "Empresa.h"

Empresa::Empresa(string a)
{
	nombre = a;
}

Empresa::~Empresa()
{
}

string Empresa::setNombre() { return nombre; }

void Empresa::getNombre(string pNombre) { this->nombre = pNombre; }

void Empresa::guardar(ofstream&)
{
}

Empresa * Empresa::leer(ifstream&)
{
	return new Empresa("");
}
