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

//menu
int Interfaz::menu()
{
	int opcionMm;

	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Mantenimiento               #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 1 | Factura                                  #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 2 | Paciente                                 #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 3 | Doctor                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 4 | Cita                                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Agenda                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 6 | Salir                                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: ";  cin >> opcionMm;
	cout << "#----------------------------------------------#" << endl;

	system("pause");
	return opcionMm;
}

//Menu Factura
int Interfaz::MMFactura()
{
	int opF;

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
	cout << "# 4 | Mostrar todos                            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# 5 | Volver                                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << "# Digite la opcion que desee: "; cin >> opF;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opF;
}
bool Interfaz::MMFingresar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getCitas()->cantidadElementos() == 0) { throw 3; }
		else 
		{
			string id, st, desc, imp;
			float tot, stt, descc, impp;
			bool op1 = true;
			bool op2 = true;

			while (op1) 
			{
				system("cls");
				cout << "----------------------------------" << endl;
				cout << "Digite el Id de la cita: ";
				getline(cin, id);

				if (soloNumeros(id)) 
				{
					if (e->getCitas()->existeID(id))
					{ //ver el metodo
						bool find = false;
						for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
							if (e->getFacturas()->getElemento(i)->getEstado() != "NULO") {
								if (e->getFacturas()->getElemento(i)->getAgenda()->getID() == id) {
									find = true;
								}
							}
						}
						if (!find) { op1 = false; }
						else { cout << "----------------------------------" << "Cita ya usada" << endl << "----------------------------------"; system("pause"); return false; }

					}
				}
			}
			while (op2) {
				system("cls");
				cout << "----------------------------------" << endl;
				cout << "# Digite el subtotal: ";
				getline(cin, st);

				cout << "----------------------------------" << endl;
				cout << "# Digite el descuento(0-100): ";
				getline(cin, desc);
				
				cout << "----------------------------------" << endl;
				cout << "# Digite el impuesto(Max 20): ";
				getline(cin, imp);

				if (soloNumeros(st) && soloNumeros(desc) && soloNumeros(imp)) 
				{
					stt = convertirFloat(st);
					descc = convertirFloat(desc);
					impp = convertirFloat(imp);

					if (stt > 0 && descc >= 0 && descc < 101 && impp > 0 && impp < 20) 
					{ //descuento maximo 100%, impuesto maximo 20%
						op2 = false;
					}
					else 
					{
						cout << "##########----------------------------------" << endl;
						cout << "              Valores erroneos" << endl;
						cout << "##########----------------------------------" << endl;
						system("pause");
					}

				}
				else
				{
					cout << "##########----------------------------------" << endl;
					cout << "              Valores erroneos" << endl;
					cout << "##########----------------------------------" << endl;
					system("pause");
				}
			}
			float aux = (stt - ((stt / 100) * descc));
			tot = (aux + ((aux / 100) * impp));
			Factura* ff = new Factura(stt, descc, impp, tot, e->getCitas()->getID(id));
			e->getFacturas()->agregarElemento(ff);

			cout << "#----------------------------------------------#" << endl;
			cout << "#               Factura Ingresado              #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");

			return true;
		}
	}
	catch (int e)
	{
		Excepcion* error = new Excepcion(e);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}
}
bool Interfaz::MMFanular(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getFacturas()->cantidadElementos() == 0) { throw 4; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Digite el Id de la Factura a anular" << endl;
		cin.ignore();
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
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getFacturas()->cantidadElementos() == 0) { throw 4; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "# Digite el Id de la Factura " << endl;
		cin.ignore();
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getFacturas()->existeID(id)) 
			{ //ver el metodo
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
bool Interfaz::MMFmostrartodos(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getFacturas()->cantidadElementos() == 0) { throw 4; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Facturas                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout<<e->getFacturas()->toString();
	cout << "#----------------------------------------------#" << endl;
	cout << "#               Fin del Contenedor             #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");
	return false;
}

int Interfaz::MMPaciente()
{
	int opP;

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
	cout << "# Digite la opcion que desee: " << endl; cin >> opP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opP;
}
bool Interfaz::MMPingresar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");

	string nom, ape, tel, numm;
	bool op = true;
	bool op1 = true;
	bool op2 = true;

	system("cls");

	while (op)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el nombre: ";

		getline(cin, nom);
		if (soloLetras(nom)) { op = false; }
		else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); }
	}	op = true;
	while (op)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el apellido: ";
		
		getline(cin, ape);		
		if (soloLetras(ape)) { op = false; }
		else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op1)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el telefono: ";
		
		getline(cin, tel);
		if (soloNumeros(tel)) { op1 = false; }
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op2) 
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el ID del paciente: ";

		getline(cin, numm);
		if (soloNumeros(numm))
		{
			if (e->getPacientes()->existeID(numm)) { Excepcion* error = new Excepcion(6); cout << error->toString() << endl;	system("pause"); system("cls"); }
			else { op2 = false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	Paciente* pa = new Paciente(numm, nom, ape, tel);
	e->getPacientes()->agregarElemento(pa);

	cout << "#----------------------------------------------#" << endl;
	cout << "#              Paciente Ingresado              #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

	return true;	
}
bool Interfaz::MMPmodificar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getPacientes()->cantidadElementos() == 0) { throw 1; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool op1 = true;
	string id, swt,aux,cambios;
	
	while (op)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Paciente: ";
		getline(cin, id);

		if (soloNumeros(id))
		{
			if (e->getPacientes()->existeID(id)) { op = false; }
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op1)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#                Que desea cambiar?            #" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 1 | Nombre"<<endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 2 | Apellido" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 3 | Telefono" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 4 | ID" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 5 | SALIR AL MENU" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el numero: ";
		getline(cin, swt);
		
		if (soloNumeros(swt))
		{
			int swtt = convertirInt(swt);
			if (swtt > 0 && swtt < 6) 
			{
				switch (swtt)
				{
				case 1:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Nombre nuevo: ";
					getline(cin, aux);

					if (soloLetras(aux)) { e->getPacientes()->getID(id)->setNombre(aux); }
					else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 2:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Apellido nuevo: ";
					getline(cin, aux);

					if (soloLetras(aux)) { e->getPacientes()->getID(id)->setApellido(aux); }
					else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 3:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Telefono nuevo: ";
					getline(cin, aux);
					
					if (soloNumeros(aux)) { e->getPacientes()->getID(id)->setTelefono(aux); }
					else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 4:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# ID nuevo: ";
					getline(cin, aux);
					
					if (e->getPacientes()->existeID(aux)) { Excepcion* error = new Excepcion(6); cout << error->toString() << endl;	system("pause"); system("cls");  break; }
					if (soloNumeros(aux)) { e->getPacientes()->getID(id)->setID(aux); }
					else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); break; }
					break;
				case 5:
					system("cls");
					return false;
					break;
				default:
					break;
				}
				cout << "#----------------------------------------------#" << endl;
				cout << "# Desea hacer mas cambios en este paciente? S/N ";
			
				getline(cin, cambios);
				if (cambios == "N" || cambios == "n") { op1 = false; }
			}
			else 
			{
				
				cout << "-----------------------------------------------" << endl;
				cout << "                 Numero no valido" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl;	system("pause"); system("cls"); }
	}

	return true;
}
bool Interfaz::MMPeliminar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getPacientes()->cantidadElementos() == 0) { throw 1; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool op1 = true;
	bool op2 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Paciente ";	
		getline(cin, id);

		if (soloNumeros(id)) 
		{
			if (e->getPacientes()->existeID(id)) { op = false; }
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); 	return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); 	return false; }
	}
	for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) {if (e->getCitas()->getID(convertirString(i))->getPaciente()->getID() == e->getPacientes()->getID(id)->getID()) { op2 = false; }}
	
	if (op2) { e->getPacientes()->eliminarElemento(convertirInt(id)); }
	else 
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#            No es posible eliminarlo ya       #" << endl;
		cout << "#            que tiene asignado una cita.      #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
	}
	
	return true;
}
bool Interfaz::MMPmostrarid(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getPacientes()->cantidadElementos() == 0) { throw 1; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op1 = true;
	bool citss = true;
	bool factss = true;
	string id;
	while (op1) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Paciente ";
		getline(cin, id);

		if (soloNumeros(id)) 
		{
			if (e->getPacientes()->existeID(id)) 
			{
				system("cls");
				cout << e->getPacientes()->getID(id)->toString();
				system("pause");
				return true;
			}
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); return false; }
		}
		else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (citss)
	{
		string ver;
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Quiere ver todas las citas? S/N";
		getline(cin, ver);
		cout << endl;
		cout << "#----------------------------------------------#" << endl;

		if (ver == "N" || ver == "n") 
		{
			citss = false;
			system("cls");
		}
		else 
		{
			if (ver == "S" || ver == "s") 
			{
				if (e->getCitas()->cantidadElementos() == 0) 
				{
					/*EXCEPION*/
					system("pause"); system("cls");
					citss = false;
				}
				else 
				{

					for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) 
					{ 
						if (e->getCitas()->getID(convertirString(i))->getPaciente()->getID() == e->getPacientes()->getID(id)->getID())
						{ 
							cout << e->getCitas()->getID(convertirString(i))->toString();
						} 
					}
				}
			}
			else {
				/*EXCEPION*/
				system("pause"); system("cls");
			}
		}

	}
	while (factss)
	{
		string ver;
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Quiere ver todas las facturas? S/N";
		getline(cin, ver);
		cout << endl;
		cout << "#----------------------------------------------#" << endl;

		if (ver == "N" || ver == "n") {
			factss = false;
			system("cls");
		}
		else 
		{
			if (ver == "S" || ver == "s") 
			{
				if (e->getFacturas()->cantidadElementos() == 0)
				{
					/*EXCEPION*/
					system("pause"); system("cls");
					factss = false;
				}
				else {
					for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
						if (e->getFacturas()->getID(convertirString(i))->getAgenda()->getPaciente()->getID() == e->getPacientes()->getID(id)->getID()) {
							cout << e->getFacturas()->getID(convertirString(i))->toString();
						}
					}
				}
			}
			else {
				/*EXCEPION*/
				system("pause"); system("cls");
			}
		}
	}
	return false;

}
bool Interfaz::MMPmostrartodos(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getPacientes()->cantidadElementos() == 0) { throw 1; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Pacientes                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << e->getPacientes()->toString();
	cout << "#----------------------------------------------#" << endl;
	cout << "#               Fin del Contenedor             #" << endl;
	cout << "#----------------------------------------------#" << endl;
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
	cout << "# Digite la opcion que desee: "; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}
bool Interfaz::MMDingresar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");

	string nom, ape, tel, numm;
	bool op = true;
	bool op1 = true;
	bool op2 = true;

	system("cls");

	while (op) 
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite unicamente el nombre: ";
		getline(cin, nom);

		if (soloLetras(nom)) { op = false; }
		else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); }
	}	op = true;
	while (op)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el apellido: ";
		getline(cin, ape);
		
		if (soloLetras(ape)) { op = false; }
		else { Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op1) 
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el telefono: ";
		getline(cin, tel);

		if (soloNumeros(tel)) { op1 = false; }
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op2) 
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el ID del doctor: ";

		getline(cin, numm);
		if (soloNumeros(numm))
		{
			if (e->getDoctores()->existeID(numm)) { Excepcion* error = new Excepcion(6); cout << error->toString() << endl;	system("pause"); system("cls"); }
			else { op2 = false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	Doctor* pa = new Doctor(numm, nom, ape, tel);
	e->getDoctores()->agregarElemento(pa);

	cout << "#----------------------------------------------#" << endl;
	cout << "#               Doctor Ingresado               #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

	return true;
}
bool Interfaz::MMDmodificar(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getDoctores()->cantidadElementos() == 0) { throw 2; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool op1 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Doctor " << endl;
		getline(cin, id);
		if (soloNumeros(id))
		{
			if (e->getDoctores()->existeID(id))
			{ //ver el metodo
				op = false;
			}
			else 
			{
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else 
		{
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}

	while (op1)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#                Que desea cambiar?            #" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 1 | Nombre" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 2 | Apellido" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 3 | Telefono" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 4 | ID" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "# 5 | SALIR AL MENU" << endl;
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el numero: ";
		getline(cin, swt);

		if (soloNumeros(swt))
		{
			int swtt = convertirInt(swt);
			if (swtt > 0 && swtt < 6)
			{
				switch (swtt)
				{
				case 1:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Nombre nuevo: ";
					getline(cin, aux);

					if (soloLetras(aux)) { e->getDoctores()->getID(id)->setNombre(aux); }
					else {
						Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 2:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Apellido nuevo: ";
					getline(cin, aux);

					if (soloLetras(aux)) { e->getDoctores()->getID(id)->setApellido(aux); }
					else {
						Excepcion* error = new Excepcion(9); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 3:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# Telefono nuevo: ";
					getline(cin, aux);

					if (soloNumeros(aux)) { e->getDoctores()->getID(id)->setTelefono(aux); }
					else {
						Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); break;
					}
					break;
				case 4:
					system("cls");
					cout << "#----------------------------------------------#" << endl;
					cout << "# ID nuevo: ";
					getline(cin, aux);

					if (e->getDoctores()->existeID(aux)) { Excepcion* error = new Excepcion(6); cout << error->toString() << endl;	system("pause"); system("cls");  break; }
					if (soloNumeros(aux)) { e->getDoctores()->getID(id)->setID(aux); }
					else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); break; }
					break;
				case 5:
					system("cls");
					return false;
					break;
				default:
					break;
				}
				cout << "#----------------------------------------------#" << endl;
				cout << "# Desea hacer mas cambios en este paciente? S/N ";

				getline(cin, cambios);
				if (cambios == "N" || cambios == "n") { op1 = false; }
			}
			else
			{

				cout << "-----------------------------------------------" << endl;
				cout << "                 Numero no valido" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl;	system("pause"); system("cls"); }
	}
	return true;
}
bool Interfaz::MMDeliminar(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getDoctores()->cantidadElementos() == 0) { throw 2; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool op1 = true;
	bool op2 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Doctor ";
		getline(cin, id);

		if (soloNumeros(id)) 
		{
			if (e->getDoctores()->existeID(id)) { //ver el metodo
				op = false;
			}
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); 	return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) { if (e->getCitas()->getID(convertirString(i))->getDoctor()->getID() == e->getDoctores()->getID(id)->getID()) { op2 = false; } }

	if (op2) { e->getDoctores()->eliminarElemento(convertirInt(id)); }
	else 
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#            No es posible eliminarlo ya       #" << endl;
		cout << "#            que tiene asignado una cita.      #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
	}

	return true;
}
bool Interfaz::MMDmostrarid(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getDoctores()->cantidadElementos() == 0) { throw 2; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op1 = true;
	bool pass = true;
	bool factss = true;
	string id;
	while (op1) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Doctor " << endl;
		getline(cin, id);
		if (soloNumeros(id))
		{
			if (e->getDoctores()->existeID(id))
			{ //ver el metodo
				system("cls");
				cout << e->getDoctores()->getID(id)->toString();
				system("pause");
				return true;
			}
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (pass)
	{
		string ver;
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Quiere ver todos los pacientes? S/N";
		getline(cin, ver);
		cout << endl;
		cout << "#----------------------------------------------#" << endl;

		if (ver == "N" || ver == "n") {
			pass = false;
			system("cls");
		}
		else {
			if (ver == "S" || ver == "s") {
				if (e->getCitas()->cantidadElementos() == 0) {
					/*EXCEPION*/
					system("pause"); system("cls");
					pass = false;
				}
				else {
					for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) {
						if (e->getCitas()->getID(convertirString(i))->getDoctor()->getID() == e->getDoctores()->getID(id)->getID()) {
							cout << e->getCitas()->getID(convertirString(i))->getPaciente()->toString();
						}
					}
				}
			}
			else {
				/*EXCEPION*/
				system("pause"); system("cls");
			}
		}

	}
	while (factss)
	{
		string ver;
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Quiere ver todas las facturas? S/N";
		getline(cin, ver);
		cout << endl;
		cout << "#----------------------------------------------#" << endl;

		if (ver == "N" || ver == "n") {
			factss = false;
			system("cls");
		}
		else {
			if (ver == "S" || ver == "s") {
				if (e->getFacturas()->cantidadElementos() == 0) {
					/*EXCEPION*/
					system("pause"); system("cls");
					factss = false;
				}
				else {
					for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
						if (e->getFacturas()->getID(convertirString(i))->getAgenda()->getDoctor()->getID() == e->getDoctores()->getID(id)->getID()) {
							cout << e->getFacturas()->getID(convertirString(i))->toString();
						}
					}
				}
			}
			else {
				/*EXCEPION*/
				system("pause"); system("cls");
			}
		}
	}
	return false;
}
bool Interfaz::MMDmostrartodos(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getDoctores()->cantidadElementos() == 0) { throw 2; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Doctores                    #" << endl;
	cout << "#----------------------------------------------#" << endl;
	cout << e->getDoctores()->toString();
	cout << "#----------------------------------------------#" << endl;
	cout << "#               Fin del Contenedor             #" << endl;
	cout << "#----------------------------------------------#" << endl;
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
	cout << "# Digite la opcion que desee: "; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}
bool Interfaz::MMCIingresar(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getDoctores()->cantidadElementos() == 0) { throw 2; }
		if (e->getDoctores()->cantidadElementos() == 0) { throw 1; }
	}
	catch (int e)
	{
		Excepcion* error = new Excepcion(e);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool op1 = true;
	bool op2 = true;
	bool op3 = true;
	bool agen = true;
	string id, id2, dd, mm, aa, mimi, hh,ingreso;
	Fecha* fecha = NULL;
	Hora* hora = NULL;

	
	while (op1)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Doctor: ";
		getline(cin, id2);

		if (soloNumeros(id2))
		{
			if (e->getDoctores()->existeID(id2)) { op1 = false; }
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls");	return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	while (op2)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el dia: ";
		getline(cin, dd);

		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el mes: ";
		getline(cin, mm);

		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el anio: ";
		getline(cin, aa);

		if (soloNumeros(dd) && soloNumeros(mm) && soloNumeros(aa))
		{
			int a = convertirInt(aa);
			int m = convertirInt(mm);
			int d = convertirInt(dd);
			if (Fecha::validarFecha(a, m, d))
			{
				fecha = new Fecha(a, m, d, Fecha::getWeekDay(a, m, d));
				op2 = false;
			}
			else { Excepcion* error = new Excepcion(8); cout << error->toString() << endl; system("pause"); system("cls"); }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	//
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                  Mostrando agenda            #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");
	system("cls");
	cout << e->getAgenda()->obtenerAgenda(e->getDoctores()->getID(id2), fecha);
	system("pause");
	//
	while (agen) {
		system("cls");
		cout << "Desea continuar con el ingreso de la cita?  S/N";
		getline(cin, ingreso);
		if (ingreso == "N" || ingreso == "n") {
			return false;
		}
		else {
			if (ingreso == "S" || ingreso == "s") {
				agen = false;
			}
		}
	}

	while (op3)
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite la hora(7-16): ";
		getline(cin, hh);

		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite los minutos(0-50): ";
		getline(cin, mimi);

		if (soloNumeros(hh) && soloNumeros(mimi)) 
		{
			int mi = convertirInt(mimi);
			int h = convertirInt(hh);
			if (mi < 51 && mi >= 0 && h>6 && h < 17) 
			{  //empieza a las 7, termina a las 4
				hora = new Hora(h, mi);
				op3 = false;
			}
			else { Excepcion* error = new Excepcion(8); cout << error->toString() << endl; system("pause"); system("cls"); }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	while (op)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del Paciente ";

		getline(cin, id);
		if (soloNumeros(id))
		{
			if (e->getPacientes()->existeID(id)) { op = false; }
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls");	return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	//doctor,paciente,fecha,hora

	Cita *cit = new Cita(e->getDoctores()->getID(id2), e->getPacientes()->getID(id), fecha, hora);
	e->getCitas()->agregarElemento(cit);

	cout << "#----------------------------------------------#" << endl;
	cout << "#               Cita Registrada                #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

	return true;
}
bool Interfaz::MMCImodificar(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getCitas()->cantidadElementos() == 0) { throw 3; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op = true;
	bool opi = true;
	bool ops = true;
	bool opt = true;
	string id,swt,cambios,idd,dd,mm,aa,hh,mimi;
	Fecha* fecha = NULL;
	Hora* hora = NULL;
	
	if (e->getCitas()->cantidadElementos() == 0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "              No hay Citas registradas" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	while (op) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "# Digite el Id de la Cita " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getCitas()->existeID(id)) { //ver el metodo
				op = false;
			}
			else { Excepcion* error = new Excepcion(5); cout << error->toString() << endl; system("pause"); system("cls"); return false; }
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	//
	for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
		if (e->getFacturas()->getID(convertirString(i))->getAgenda()->getID() == e->getCitas()->getID(id)->getID()) {
			ops = false;
		}
	}

	if (!ops) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "             No es posible modificarlo ya " << endl;
		cout << "          que ya fue incluido en una factura." << endl;
		cout << "-----------------------------------------------" << endl;
		system("pause");
		return false;
	}
	//
	while (opi) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Que desea cambiar?" << endl;
		cout << "1 Paciente" << endl;
		cout << "2 Doctor" << endl;
		cout << "3 Fecha" << endl;
		cout << "4 Hora" << endl;
		cout << "5 SALIR AL MENU" << endl;
		cout << "Digite el numero: ";
		getline(cin, swt);

		if (soloNumeros(swt)) {
			int swtt = convertirInt(swt);
			if (swtt > 0 && swtt < 6) {
				switch (swtt)
				{
				case 1:
					system("cls");
					while (opt) {
						system("cls");
						cout << "--------------------------------------" << endl;
						cout << "Digite el Id del Paciente " << endl;
						cin.ignore();
						getline(cin, idd);
						if (soloNumeros(idd)) {
							if (e->getPacientes()->existeID(idd)) { //ver el metodo
								opt = false;
								e->getCitas()->getID(id)->setPaciente(e->getPacientes()->getID(idd));
							}
							else {
								cout << "-----------------------------------------------" << endl;
								cout << "|                   No existe                 |" << endl;
								cout << "-----------------------------------------------" << endl;
								system("pause");
								return false;
							}
						}
						else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
					}

					break;
				case 2:
					system("cls");
					while (opt) {
						system("cls");
						cout << "--------------------------------------" << endl;
						cout << "Digite el Id del Doctor " << endl;
						cin.ignore();
						getline(cin, idd);
						if (soloNumeros(idd)) {
							if (e->getDoctores()->existeID(idd)) { //ver el metodo
								opt = false;
								e->getCitas()->getID(id)->setDoctor(e->getDoctores()->getID(idd));
							}
							else {
								cout << "-----------------------------------------------" << endl;
								cout << "|                   No existe                 |" << endl;
								cout << "-----------------------------------------------" << endl;
								system("pause");
								return false;
							}
						}
						else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
					}
					break;
				case 3:
					system("cls");
					while (opt) {
						cout << "-----------------------------------------------" << endl;
						cout << "Digite el dia: " << endl;
						cin.ignore();
						getline(cin, dd);
						cout << "-----------------------------------------------" << endl;
						cout << "Digite el mes: " << endl;
						cin.ignore();
						getline(cin, mm);
						cout << "-----------------------------------------------" << endl;
						cout << "Digite el anio: " << endl;
						cin.ignore();
						getline(cin, aa);

						if (soloNumeros(dd) && soloNumeros(mm) && soloNumeros(aa)) {
							int a = convertirInt(aa);
							int m = convertirInt(mm);
							int d = convertirInt(dd);
							if (Fecha::validarFecha(a, m, d)) {
								fecha = new Fecha(a, m, d, Fecha::getWeekDay(a, m, d));
								opt = false;
								e->getCitas()->getID(id)->setFecha(fecha);
							}
							else {
								cout << "-----------------------------------------------" << endl;
								cout << "         Valores no validos para fecha" << endl;
								cout << "-----------------------------------------------" << endl;
								system("pause");
								system("cls");
							}
						}
						else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
					}
					break;
				case 4:
					system("cls");
					while (opt) {
						cout << "-----------------------------------------------" << endl;
						cout << "Digite la hora(7-16): " << endl;
						cin.ignore();
						getline(cin, hh);
						cout << "-----------------------------------------------" << endl;
						cout << "Digite los minutos(0-50): " << endl;
						cin.ignore();
						getline(cin, mimi);

						if (soloNumeros(hh) && soloNumeros(mimi)) {
							int mi = convertirInt(mimi);
							int h = convertirInt(hh);
							if (mi < 51 && mi >= 0 && h>6 && h < 17) {  //empieza a las 7, termina a las 4
								hora = new Hora(h, mi);
								opt = false;
								e->getCitas()->getID(id)->setHora(hora);
							}
							else {
								cout << "-----------------------------------------------" << endl;
								cout << "         Valores no validos para hora" << endl;
								cout << "-----------------------------------------------" << endl;
								system("pause");
								system("cls");
							}
						}
						else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
					}
					break;
				case 5:
					system("cls");
					return false;
					break;
				default:
					break;
				}
				cout << "-----------------------------------------------" << endl;
				cout << "Desea hacer mas cambios en esta cita? S/N ";
				getline(cin, cambios);
				if (cambios == "N" || cambios == "n") {
					opi = false;
				}
			}
			else {

				cout << "-----------------------------------------------" << endl;
				cout << "                 Numero no valido" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}

	return true;
}
bool Interfaz::MMCIeliminar(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getCitas()->cantidadElementos() == 0) { throw 3; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool opp = true;
	bool op2 = true;
	string id;

	if (e->getCitas()->cantidadElementos() == 0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "#              No hay Citas registradas             #" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	while (opp) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id de la cita " << endl;
		
		getline(cin, id);
		if (soloNumeros(id))
		{
			if (e->getCitas()->existeID(id))
			{ //ver el metodo
				opp = false;
			}
			else 
			{
				cout << "-----------------------------------------------" << endl;
				cout << "|                   No existe                 |" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				return false;
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	/////////////////////////////////
	for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) 
	{
		if (e->getFacturas()->getID(convertirString(i))->getAgenda()->getID() == e->getCitas()->getID(id)->getID()) 
		{
			op2 = false;
		}
	}

	if (op2) 
	{
		e->getCitas()->eliminarElemento(convertirInt(id));
	}
	else 
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#             No es posible eliminarlo ya      #" << endl;
		cout << "#          que ya fue incluido en una factura. #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
	}
	return true;
}
bool Interfaz::MMCImostrarid(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getCitas()->cantidadElementos() == 0) { throw 3; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}

	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id de la Cita " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getCitas()->existeID(id)) { //ver el metodo
				system("cls");
				cout << e->getCitas()->getID(id)->toString();
				system("pause");
				return true;
			}
			else {
				cout << "#----------------------------------------------#" << endl;
				cout << "|                   No existe                  |" << endl;
				cout << "#----------------------------------------------#" << endl;
				system("pause");
				return false;
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	return false;
}
bool Interfaz::MMCImostrartodos(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");
	try
	{
		if (e->getCitas()->cantidadElementos() == 0) { throw 3; }
	}
	catch (int n)
	{
		Excepcion* error = new Excepcion(n);
		cout << error->toString() << endl;
		system("pause");
		return false;
	}
	system("cls");
	cout << "#----------------------------------------------#" << endl;
	cout << "#                    Citas                     #" << endl;
	cout << "#----------------------------------------------#" << endl;
	
	cout << e->getCitas()->toString();
	
	cout << "#----------------------------------------------#" << endl;
	cout << "#               Fin del Contenedor             #" << endl;
	cout << "#----------------------------------------------#" << endl;
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
	cout << "# Digite la opcion que desee: "; cin >> opMMP;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opMMP;
}
bool Interfaz::MMFAmostrarFecha(Empresa * e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");

	bool op = true;
	bool op1 = true;
	string id,dd,mm,aa;
	Fecha *fecha=NULL;

	while (op) 
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el dia: ";
		getline(cin, dd);

		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el mes: ";
		getline(cin, mm);

		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el anio: ";
		getline(cin, aa);

		if (soloNumeros(dd) && soloNumeros(mm) && soloNumeros(aa)) 
		{
			int a = convertirInt(aa);
			int m = convertirInt(mm);
			int d = convertirInt(dd);
			if (Fecha::validarFecha(a, m, d))
			{
				fecha = new Fecha(a, m, d,Fecha::getWeekDay(a,m,d));
				op = false;
			}
			else {
				cout << "#----------------------------------------------#" << endl;
				cout << "#         Valores no validos para fecha        #" << endl;
				cout << "#----------------------------------------------#" << endl;
				system("pause");
				system("cls");
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	while (op1) 
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del doctor ";
		getline(cin, id);
		
		cout << "#----------------------------------------------#" << endl;
		if (soloNumeros(id))
		{
			if (e->getDoctores()->existeID(id))
			{ 
				system("cls");
				cout << e->getAgenda()->obtenerAgenda(e->getDoctores()->getID(id), fecha);
				system("pause");
				return true;
			}
			else 
			{
				system("cls");
				cout << "#----------------------------------------------#" << endl;
				cout << "#                   No existe                  #" << endl;
				cout << "#----------------------------------------------#" << endl;
				system("pause");
				return false;
			}
		}
	}
	return true;
}
bool Interfaz::MMFAmostrarHoy(Empresa *e)
{
	cin.ignore();
	cin.exceptions(ifstream::failbit | istream::badbit);
	system("cls");

	Fecha * fecha = new Fecha();
	bool op1 = true;
	string id;

	while (op1) 
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "# Digite el Id del doctor: ";		
		getline(cin, id);

		cout << "#----------------------------------------------#" << endl;
		if (soloNumeros(id))
		{
			if (e->getDoctores()->existeID(id)) 
			{ //ver el metodo
				system("cls");
				cout << e->getAgenda()->obtenerAgenda(e->getDoctores()->getID(id), fecha);
				system("pause");
				return true;
			}
			else 
			{
				system("cls");
				cout << "#----------------------------------------------#" << endl;
				cout << "#                   No existe                  #" << endl;
				cout << "#----------------------------------------------#" << endl;
				system("pause");
				return false;
			}
		}
		else { Excepcion* error = new Excepcion(10); cout << error->toString() << endl; system("pause"); system("cls"); }
	}
	return true;
}

//-------------------------------------------------------------------------------------------

void Interfaz::salir()
{
	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                   Gracias!                   #" << endl;
	cout << "#----------------------------------------------#" << endl;
	system("pause");

}

void Interfaz::defaul()
{
	system("cls");

	cout << "#----------------------------------------------#" << endl;
	cout << "#                Opcion Invalida               #" << endl;
	cout << "#----------------------------------------------#" << endl;

	system("pause");
	system("cls");
}