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
		opcion = controlMP();
	} while (opcion != 3);

	ofstream salida;
	salida.open(Ruta.c_str());
	empresa->guardar(salida);
	salida.close();
}

int Controladora::controlMP()
{
	int opcion = Interfaz::menu();

	switch (opcion)
	{
	case 1:
	{
		int opcionMM;
		do
		{
			opcion = controlMR();
		} while (opcion != 2);
		break;
	}
	case 2:
	{
		int opcionMM;
		do
		{
			opcion = controlMM();
		} while (opcion != 9);
		break;
	}
	case 3: Interfaz::salir(); break;

	default: Interfaz::defaul(); break;
	}

	return opcion;
}
int Controladora::controlMR()
{
	int opcionMR = Interfaz::MReserva();

	switch (opcionMR)
	{
	case 1: Interfaz::MRreserva(empresa); break;
	case 2: system("cls"); break;
	}

	return opcionMR;
}
int Controladora::controlMM()
{
	int opcionMM2 = Interfaz::mantenimiento();

	switch (opcionMM2)
	{
	case 1:
	{
		int opcionMMR;
		do
		{
			opcionMMR = controlMMReservas();
		} while (opcionMMR != 6);
		break;
	}
	case 2:
	{
		int opcionMMRu;
		do
		{
			opcionMMRu = controlMMRutas();
		} while (opcionMMRu != 6);
		break;
	}
	case 3:
	{
		int opcionMMC;
		do
		{
			opcionMMC = controlMMClientes();
		} while (opcionMMC != 6);
		break;
	}
	case 4:
	{
		int opcionMMP;
		do
		{
			opcionMMP = controlMMPilotos();
		} while (opcionMMP != 6);
		break;
	}
	case 5:
	{
		int opcionMMV;
		do
		{
			opcionMMV = controlMMVendedores();
		} while (opcionMMV != 6);
		break;
	}
	case 6:
	{
		int opcionMMA;
		do
		{
			opcionMMA = controlMMAviones();
		} while (opcionMMA != 6);
		break;
	}
	case 7:
	{
		int opcionMMM;
		do
		{
			opcionMMM = controlMMMotores();
		} while (opcionMMM != 6);
		break;
	}
	case 8:
	{
		int opcionMME;
		do
		{
			opcionMME = controlMMEmpresa();
		} while (opcionMME != 6);
		break;
	}
	case 9: system("cls"); break;
	}

	return opcionMM2;
}

int Controladora::controlMMReservas()
{
	int opccionMMR = Interfaz::MMReservas();

	switch (opccionMMR)
	{
	case 1: Interfaz::MMRingresar(empresa); break;
	case 2: Interfaz::MMRmodificar(empresa); break;
	case 3: Interfaz::MMReliminar(empresa); break;
	case 4: Interfaz::MMRmostrarid(empresa); break;
	case 5: Interfaz::MMRmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMR;
}

int Controladora::controlMMRutas()
{
	int opccionMMRu = Interfaz::MMRutas();

	switch (opccionMMRu)
	{
	case 1: Interfaz::MMRUingresar(empresa); break;
	case 2: Interfaz::MMRUmodificar(empresa); break;
	case 3: Interfaz::MMRUeliminar(empresa); break;
	case 4: Interfaz::MMRUmostrarid(empresa); break;
	case 5: Interfaz::MMRUmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMRu;
}

int Controladora::controlMMClientes()
{
	int opccionMMC = Interfaz::MMClientes();

	switch (opccionMMC)
	{
	case 1: Interfaz::MMCingresar(empresa); break;
	case 2: Interfaz::MMCmodificar(empresa); break;
	case 3: Interfaz::MMCeliminar(empresa); break;
	case 4: Interfaz::MMCmostrarid(empresa); break;
	case 5: Interfaz::MMCmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMC;
}

int Controladora::controlMMPilotos()
{

	int opccionMMP = Interfaz::MMPilotos();

	switch (opccionMMP)
	{
	case 1: Interfaz::MMPingresar(empresa); break;
	case 2: Interfaz::MMPmodificar(empresa); break;
	case 3: Interfaz::MMPeliminar(empresa); break;
	case 4: Interfaz::MMPmostrarid(empresa); break;
	case 5: Interfaz::MMPmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMP;
}

int Controladora::controlMMVendedores()
{
	int opccionMMV = Interfaz::MMVendedores();

	switch (opccionMMV)
	{
	case 1: Interfaz::MMVingresar(empresa); break;
	case 2: Interfaz::MMVmodificar(empresa); break;
	case 3: Interfaz::MMVeliminar(empresa); break;
	case 4: Interfaz::MMVmostrarid(empresa); break;
	case 5: Interfaz::MMVmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMV;
}

int Controladora::controlMMAviones()
{
	int opccionMMA = Interfaz::MMAviones();

	switch (opccionMMA)
	{
	case 1: Interfaz::MMAingresar(empresa); break;
	case 2: Interfaz::MMAmodificar(empresa); break;
	case 3: Interfaz::MMAeliminar(empresa); break;
	case 4: Interfaz::MMAmostrarid(empresa); break;
	case 5: Interfaz::MMAmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMA;
}

int Controladora::controlMMMotores()
{
	int opccionMMM = Interfaz::MMMotores();

	switch (opccionMMM)
	{
	case 1: Interfaz::MMMingresar(empresa); break;
	case 2: Interfaz::MMMmodificar(empresa); break;
	case 3: Interfaz::MMMeliminar(empresa); break;
	case 4: Interfaz::MMMmostrarid(empresa); break;
	case 5: Interfaz::MMMmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMMM;
}

int Controladora::controlMMEmpresa()
{
	int opccionMME = Interfaz::MMEmpresa();

	switch (opccionMME)
	{
	case 1: Interfaz::MMEingresar(empresa); break;
	case 2: Interfaz::MMEmodificar(empresa); break;
	case 3: Interfaz::MMEeliminar(empresa); break;
	case 4: Interfaz::MMEmostrarid(empresa); break;
	case 5: Interfaz::MMEmostrartodos(empresa); break;
	case 6: system("cls"); break;
	}

	return opccionMME;
}
