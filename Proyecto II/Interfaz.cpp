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
	cout << "# 2 | Anular                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Mostrar uno en especifico                #" << endl;
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

bool Interfaz::MMFingresar(Empresa * e)
{
	if (e->getCitas()->cantidadElementos() == 0) { cout <<"----------------------------------"<< "No hay datos" << "----------------------------------" << endl; return false; }
	else {
		string id,st,desc,imp;
		float tot, stt,descc,impp;
		bool op1 = true;
		bool op2 = true;

		while (op1) {
			system("cls");
			cout << "----------------------------------" << endl;
			cout << "Digite el Id de la cita" << endl;
			getline(cin, id);
			if (soloNumeros(id)) {
				if (e->getCitas()->existeID(id)) { //ver el metodo
					bool find = false;
					for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
						if (e->getFacturas()->getElemento(i)->getEstado() != "NULO") {
							if (e->getFacturas()->getElemento(i)->getAgenda()->getId() == id) {
								find = true;
							}
						}
					}
					if(!find){ op1 = false; }
					else { cout << "----------------------------------" << "Cita ya usada" << endl << "----------------------------------"; system("pause"); return false; }
					
				}
			}
		}
		while (op2) {
			system("cls");
			cout << "----------------------------------" << endl;
			cout << "Digite el subtotal: ";
			getline(cin, st);
			cout << "----------------------------------" << endl;
			cout << endl << "Digite el descuento(0-100): ";
			getline(cin, desc);
			cout << "----------------------------------" << endl;
			cout << endl << "Digite el impuesto(Max 20): ";
			getline(cin, imp);
			if (soloNumeros(st)&&soloNumeros(desc)&&soloNumeros(imp)) {
				stt = convertirFloat(st);
				descc = convertirFloat(desc);
				impp = convertirFloat(imp);
				
				if (stt > 0 && descc >= 0 &&descc<101&& impp > 0&&impp<20) { //descuento maximo 100%, impuesto maximo 20%
					op2 = false;
				}
				else {
					cout << "##########----------------------------------" << endl;
					cout << "              Valores erroneos" << endl;
					cout << "##########----------------------------------" << endl;
					system("pause");
				}
				
			}
			else {
				cout << "##########----------------------------------" << endl;
				cout << "              Valores erroneos" << endl;
				cout << "##########----------------------------------" << endl;
				system("pause");
			}
		}
		float aux = (stt-((stt / 100) * descc));
		tot = (aux + ((aux / 100) * impp));
		Factura* ff = new Factura(stt, descc, impp, tot, e->getCitas()->getID(id));
		e->getFacturas()->agregarElemento(ff);
		return true;
	}
}

bool Interfaz::MMFanular(Empresa *e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Digite el Id de la Factura a anular" << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getFacturas()->existeID(id)) { //ver el metodo
				e->getFacturas()->getID(id)->setEstado("NULO");
				cout << "-----------------------------------------------" << endl;
				cout << "|                  Anulado                    |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return true;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
	}
	return false;
}

bool Interfaz::MMFmostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id de la Factura " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getFacturas()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getFacturas()->getID(id)->toString();
				system("pause");
				return true;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
	return false;
}

bool Interfaz::MMFmostrarPersona(Empresa * e)
{
	return false;
}

bool Interfaz::MMFmostrartodos(Empresa * e)
{
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Facturas                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout<<e->getFacturas()->toString();
	system("pause");
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

bool Interfaz::MMPingresar(Empresa * e) //?
{
	string nom, ape, tel,day,month,year,numm;
	int num = 0;
	bool op1 = true;
	cout << "#----------------------------------------------#" << endl;
	cout << "Digite unicamente el nombre: ";
	getline(cin, nom);
	cout << "#----------------------------------------------#" << endl;
	cout << "Digite el apellido: ";
	getline(cin, ape);
	while (op1) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el telefono: ";
		getline(cin, tel);
		if (soloNumeros(tel)) { op1 = false; }
	}
	num=e->getPacientes()->cantidadElementos();
	numm = convertirString(num);
	Fecha* fecha = new Fecha();
	Paciente* pa = new Paciente(numm,nom,ape,tel,fecha);
	e->getPacientes()->agregarElemento(pa);
	return false;
}

bool Interfaz::MMPmodificar(Empresa * e)
{

	return false;
}

bool Interfaz::MMPeliminar(Empresa * e)
{
	return false;
}

bool Interfaz::MMPmostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Paciente " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getPacientes()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getPacientes()->getID(id)->toString();
				system("pause");
				return true;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
	return false;
}

bool Interfaz::MMPmostrarPersona(Empresa *)
{
	return false;
}

bool Interfaz::MMPmostrartodos(Empresa * e)
{
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Pacientes                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << e->getPacientes()->toString();
	system("pause");
	return true;
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

bool Interfaz::MMDmostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Doctor " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getDoctores()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getDoctores()->getID(id)->toString();
				system("pause");
				return true;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
	return false;
}

bool Interfaz::MMDmostrartodos(Empresa * e)
{
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Doctores                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << e->getDoctores()->toString();
	system("pause");
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

bool Interfaz::MMCImostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id de la Cita " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getCitas()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getCitas()->getID(id)->toString();
				system("pause");
				return true;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
	return false;
}

bool Interfaz::MMFCImostrarPersona(Empresa *)
{
	return false;
}

bool Interfaz::MMCImostrartodos(Empresa *e)
{
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                    Citas                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << e->getCitas()->toString();
	system("pause");
	return false;
}

int Interfaz::MMAgenda()
{
	int opMMP;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                    Agenda                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Agenda de fecha cualquiera               #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Agenda de hoy                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: " << endl; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}

bool Interfaz::MMFAmostrarFecha(Empresa * e)
{
	//como hacer con el wday?
	string d, m, a;
	int dd, mm, aa;
	Fecha * fecha = new Fecha(dd,mm,aa);
	return false;
}

bool Interfaz::MMFAmostrarHoy(Empresa *e)
{
	Fecha * fecha = new Fecha();
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Digite el Id del doctor" << endl;
		getline(cin, id);
		cout << "-----------------------------------------------" << endl;
		if (soloNumeros(id)) {
			if (e->getDoctores()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getAgenda()->obtenerAgenda(e->getDoctores()->getID(id), fecha);
				system("pause");
				return true;
			}
			else {
				system("cls");
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
	}
	return false;
}


void Interfaz::salir()
{
}

void Interfaz::defaul()
{
}
