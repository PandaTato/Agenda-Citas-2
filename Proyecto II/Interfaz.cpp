#include "Interfaz.h"

Empresa * Interfaz::inicio()
{
	system("cls");

	string nombre = "Leiton";
	cout << "#----------------------------------------------#" << endl;
	cout << "#     ¡Bienvenidos a la clinica " << nombre << " !       #" << endl;
	cout << "#----------------------------------------------#" << endl;
	return new Empresa(nombre);
}

int Interfaz::menu()
{
	return 0;
}

int Interfaz::MFactura()
{
	return 0;
}

bool Interfaz::MFactura(Empresa *)
{
	return false;
}

int Interfaz::mantenimiento()
{
	int opcionMm;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Mantenimiento               #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Factura                                  #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Cliente                                  #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Doctor                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Cita                                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Agenda                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: ";  cin >> opcionMm;
	cout << "#----------------------------------------------#" << endl;

	system("pause");
	return opcionMm;
}

int Interfaz::MMFactura()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Factura                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Ingresar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Modificar                                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Eliminar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Mostrar uno en especifico                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Mostrar todos                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: " << endl; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}

bool Interfaz::MMFingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMFanular(Empresa *)
{
	return false;
}

bool Interfaz::MMFmostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMFmostrarPersona(Empresa *)
{
	return false;
}

bool Interfaz::MMFmostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMPaciente()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Paciente                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Ingresar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Modificar                                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Eliminar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Mostrar uno en especifico                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Mostrar todos                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: " << endl; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}

bool Interfaz::MMPingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMPmodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMPeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMPmostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMPmostrarPersona(Empresa *)
{
	return false;
}

bool Interfaz::MMPmostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMDoctor()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                   Doctor                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Ingresar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Modificar                                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Eliminar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Mostrar uno en especifico                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Mostrar todos                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: " << endl; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}

bool Interfaz::MMDingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMDmodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMDeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMDmostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMDmostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMCita()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                    Citas                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Ingresar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Modificar                                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Eliminar                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Mostrar uno en especifico                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Mostrar todos                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: " << endl; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}

bool Interfaz::MMCIingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMCImodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMCIeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMCImostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMFCImostrarPersona(Empresa *)
{
	return false;
}

bool Interfaz::MMCImostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMAgenda()
{
	return 0;
}

bool Interfaz::MMFAmostrarFecha(Empresa *)
{
	return false;
}

bool Interfaz::MMFAmostrarHoy(Empresa *)
{
	return false;
}


void Interfaz::salir()
{
}

void Interfaz::defaul()
{
}
