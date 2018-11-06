#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "Empresa.h"
#include "Interfaz.h"

class Controladora
{
private:
	Empresa* empresa;

public:
	Controladora();
	Controladora(Empresa*);
	~Controladora();

	Empresa* getEmpresa();

	void setEmpresa(Empresa*);

	void controlador();

	//controles menus del menu principal
	int controlMP();
	int controlMR();
	int controlMM();

	//controles menus del menu mantenimiento
	int controlMMReservas();
	int controlMMRutas();
	int controlMMClientes();
	int controlMMPilotos();
	int controlMMVendedores();
	int controlMMAviones();
	int controlMMMotores();
	int controlMMEmpresa();
};

#endif // !CONTROLADORA_H
