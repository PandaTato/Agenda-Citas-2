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
	int controlMenu();

	//controles menus del menu mantenimiento
	int controlMFactura();
	int controlMPaciente();
	int controlMDoctor();
	int controlMCita();
	int controlMAgenda();
};

#endif // !CONTROLADORA_H
