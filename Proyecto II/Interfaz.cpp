#include "Interfaz.h"

Empresa * Interfaz::inicio()
{
	system("cls");

	string nombre = "Leiton";
	cout << "#----------------------------------------------#" << endl;
	cout << "#     ¡Bienvenidos a la clinica "<<nombre<<" !       #" << endl;
	cout << "#----------------------------------------------#" << endl;
	return new Empresa(nombre);
}

int Interfaz::menu()
{
	int opcionMp;
	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                      Menu                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Factura                                  #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Mantenimiento                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Salir                                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: ";  cin >> opcionMp;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

	return opcionMp;
}

int Interfaz::MFactura()
{
	int opcionMv;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                    Factura                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Ver                                      #" << endl;  //?
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: "; cin >> opcionMv;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

	return opcionMv;
}

bool Interfaz::MFactura(Empresa *)
{
	return false;
}

int Interfaz::mantenimiento()  //modificar la controladora
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

int Interfaz::MMFactura()  //entra si hay citas (metodos abajo)
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

bool Interfaz::MMFIingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMFImodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMFIeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMFImostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMFImostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMCliente()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Cliente                     #" << endl;
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

bool Interfaz::MMCingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMCmodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMCeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMCmostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMCmostrartodos(Empresa *)
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

int Interfaz::MMCita() //necesitan existir doctores y pacientes (metodos abajo)
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

bool Interfaz::MMCImostrartodos(Empresa *)
{
	return false;
}

//??????????????

int Interfaz::MMViaje()
{
	return 0;
}

bool Interfaz::MMVingresar(Empresa *)
{
	return false;
}

bool Interfaz::MMVmodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMVeliminar(Empresa *)
{
	return false;
}

bool Interfaz::MMVmostrarid(Empresa *)
{
	return false;
}

bool Interfaz::MMVmostrartodos(Empresa *)
{
	return false;
}

int Interfaz::MMEmpresa()
{
	return 0;
}

bool Interfaz::MMEmodificar(Empresa *)
{
	return false;
}

bool Interfaz::MMEmostrar(Empresa *)
{
	return false;
}

void Interfaz::salir()
{
}

void Interfaz::defaul()
{
}
