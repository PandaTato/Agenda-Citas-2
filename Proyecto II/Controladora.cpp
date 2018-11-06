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
	} while (opcion != 3);

	ofstream salida;
	salida.open(Ruta.c_str());
	empresa->guardar(salida);
	salida.close();
}

int Controladora::controlMenu()
{
	int opcion = Interfaz::menu();

	switch (opcion)
	{
	case 1:
	{
		int opcionMM;
		do
		{
			opcion = controlMFactura();
		} while (opcion != 6);
		break;
	}
	case 2:
	{
		int opcionMPaciente;
		do
		{
			opcion = controlMPaciente();
		} while (opcion != 6);
		break;
	}
	case 3:
	{
		int opcionMM;
		do
		{
			opcion = controlMDoctor();
		} while (opcion != 6);
		break;
	}
	case 4:
	{
		int opcionMCita;
		do
		{
			opcion = controlMPaciente();
		} while (opcion != 7);
		break;
	}
	case 5:
	{
		int opcionMAgenda;
		do
		{
			opcion = controlMAgenda();
		} while (opcion != 3);
		break;
	}
	case 6: Interfaz::salir(); break;

	default: Interfaz::defaul(); break;
	}

	return opcion;
}


int Controladora::controlMFactura()
{
	int opccionMMR = Interfaz::MMFactura();

	switch (opccionMMR)
	{
	case 1: Interfaz::MMFingresar(empresa); break;
	case 2: Interfaz::MMFanular(empresa); break;
	case 3: Interfaz::MMFmostrarid(empresa); break;
	case 4: Interfaz::MMFmostrarPersona(empresa); break;
	case 5: Interfaz::MMFmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMR;
}
int Controladora::controlMPaciente()
{
	int opccionMMRu = Interfaz::MMPaciente();

	switch (opccionMMRu)
	{
	case 1: Interfaz::MMPingresar(empresa); break;
	case 2: Interfaz::MMPeliminar(empresa); break;
	case 3: Interfaz::MMPmostrarid(empresa); break;
	case 4: Interfaz::MMPmostrarPersona(empresa); break;
	case 5: Interfaz::MMPmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMRu;
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

	int opccionMMP = Interfaz::MMCita();

	switch (opccionMMP)
	{
	case 1: Interfaz::MMCIingresar(empresa); break;
	case 2: Interfaz::MMCImodificar(empresa); break;
	case 3: Interfaz::MMCIeliminar(empresa); break;
	case 4: Interfaz::MMCImostrarid(empresa); break;
	case 5: Interfaz::MMFCImostrarPersona(empresa); break;
	case 6: Interfaz::MMCImostrartodos(empresa); break;
	case 7: system("cls"); break;
	}

	return opccionMMP;
}
int Controladora::controlMAgenda()
{
	int opccionMMV = Interfaz::MMAgenda();

	switch (opccionMMV)
	{
	case 1: Interfaz::MMFAmostrarFecha(empresa); break;
	case 2: Interfaz::MMFAmostrarHoy(empresa); break;
	case 3: system("cls"); break;
	}
	return opccionMMV;
}
