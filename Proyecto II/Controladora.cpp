#include "Controladora.h"

Controladora::Controladora() { empresa = NULL; }
Controladora::Controladora(Empresa * ptrEmpresa){	this->empresa = ptrEmpresa;}

Controladora::~Controladora(){	delete empresa;}

Empresa * Controladora::getEmpresa(){	return empresa;}

void Controladora::setEmpresa(Empresa * ptrEmpresa){	this->empresa = ptrEmpresa;}

void Controladora::controlador()
{
	string Ruta = "../Empresa.txt";

	ifstream entrada;
	entrada.open(Ruta.c_str());
	empresa = Empresa::leer(entrada);
	entrada.close();

	int opcion;

	do
	{
		opcion = controlMenu();
	} while (opcion != 6);

	ofstream salida;
	salida.open(Ruta.c_str());
	empresa->guardar(salida);
	salida.close();
}

int Controladora::controlMenu()
{
	int opciones = Interfaz::menu();

	switch (opciones)
	{
	case 1:
	{
		int opcionMFactura;
		do
		{
			opcionMFactura = controlMFactura();
		} while (opcionMFactura != 6);
		break;
	}
	case 2:
	{
		int opcionMPaciente;
		do
		{
			opcionMPaciente = controlMPaciente();
		} while (opcionMPaciente != 6);
		break;
	}
	case 3:
	{
		int opcionMDoctor;
		do
		{
			opcionMDoctor = controlMDoctor();
		} while (opcionMDoctor != 6);
		break;
	}
	case 4:
	{
		int opcionMCita;
		do
		{
			opcionMCita = controlMCita();
		} while (opcionMCita != 6);
		break;
	}
	case 5:
	{
		int opcionMAgenda;
		do
		{
			opcionMAgenda = controlMAgenda();
		} while (opcionMAgenda != 3);
		break;
	}
	case 6: Interfaz::salir(); break;

	default: Interfaz::defaul(); break;
	}

	return opciones;
}


int Controladora::controlMFactura()
{
	int opccionMMR = Interfaz::MMFactura();

	switch (opccionMMR)
	{
	case 1: Interfaz::MMFingresar(empresa); break;
	case 2: Interfaz::MMFanular(empresa); break;
	case 3: Interfaz::MMFmostrarid(empresa); break;
	case 4: Interfaz::MMFmostrartodos(empresa); break;
	case 5: system("cls"); break;
	}

	return opccionMMR;
}
int Controladora::controlMPaciente()
{
	int opccionMMP = Interfaz::MMPaciente();

	switch (opccionMMP)
	{
	case 1: Interfaz::MMPingresar(empresa); break;
	case 2: Interfaz::MMPmodificar(empresa); break;
	case 3: Interfaz::MMPeliminar(empresa); break;
	case 4: Interfaz::MMPmostrarid(empresa); break;
	/*case 4: Interfaz::MMPmostrarPersona(empresa); break;*/
	case 5: Interfaz::MMPmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMP;
}
int Controladora::controlMDoctor()
{
	int opccionMMD = Interfaz::MMDoctor();

	switch (opccionMMD)
	{
	case 1: Interfaz::MMDingresar(empresa); break;
	case 2: Interfaz::MMDmodificar(empresa); break;
	case 3: Interfaz::MMDeliminar(empresa); break;
	case 4: Interfaz::MMDmostrarid(empresa); break;
	case 5: Interfaz::MMDmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMD;
}
int Controladora::controlMCita()
{

	int opccionMMC = Interfaz::MMCita();

	switch (opccionMMC)
	{
	case 1: Interfaz::MMCIingresar(empresa); break;
	case 2: Interfaz::MMCImodificar(empresa); break;
	case 3: Interfaz::MMCIeliminar(empresa); break;
	case 4: Interfaz::MMCImostrarid(empresa); break;
	//case 5: Interfaz::MMFCImostrarPersona(empresa); break;
	case 5: Interfaz::MMCImostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMC;
}
int Controladora::controlMAgenda()
{
	int opccionMMA = Interfaz::MMAgenda();

	switch (opccionMMA)
	{
	case 1: Interfaz::MMFAmostrarFecha(empresa); break;
	case 2: Interfaz::MMFAmostrarHoy(empresa); break;
	case 3: system("cls"); break;
	}
	return opccionMMA;
}
