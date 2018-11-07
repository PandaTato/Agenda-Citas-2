#include "Interfaz.h"

Empresa * Interfaz::inicio()
{
	system("cls");

	string nombre = "Leiton";
	cout << "#----------------------------------------------#" << endl;
	cout << "#     ˇBienvenidos a la clinica " << nombre << " !       #" << endl;
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
	cout << "# 6 | Volver                                   #" << endl;
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
	cout << "# Digite la opcion que desee: " << endl; cin >> opF;
	cout << "#----------------------------------------------#" << endl;

	system("pause");

	return opF;
}
bool Interfaz::MMFingresar(Empresa * e)
{
	if (e->getCitas()->cantidadElementos() == 0) { system("cls"); cout <<"----------------------------------"<<endl<< "No hay datos" <<endl<< "----------------------------------" << endl; system("pause"); return false; }
	else {
		string id,st,desc,imp;
		float tot, stt,descc,impp;
		bool op1 = true;
		bool op2 = true;

		while (op1) {
			system("cls");
			cout << "----------------------------------" << endl;
			cout << "Digite el Id de la cita" << endl;
			cin.ignore();
			getline(cin, id);
			if (soloNumeros(id)) {
				if (e->getCitas()->existeID(id)) { //ver el metodo
					bool find = false;
					for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
						if (e->getFacturas()->getElemento(i)->getEstado() != "NULO") {
							if (e->getFacturas()->getElemento(i)->getAgenda()->getID() == id) {
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
			cin.ignore();
			getline(cin, st);
			cout << "----------------------------------" << endl;
			cout << endl << "Digite el descuento(0-100): ";
			cin.ignore();
			getline(cin, desc);
			cout << "----------------------------------" << endl;
			cout << endl << "Digite el impuesto(Max 20): ";
			cin.ignore();
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
	if (e->getCitas()->cantidadElementos() == 0) { system("cls"); cout << "----------------------------------" << endl << "No hay datos" << endl << "----------------------------------" << endl; system("pause"); return false; }
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
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id de la Factura " << endl;
		cin.ignore();
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
bool Interfaz::MMPingresar(Empresa * e) //?
{
	string nom, ape, tel,numm;
	bool op = true;
	bool op1 = true;
	bool op2 = true;

	system("cls");

	while (op) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite unicamente el nombre: ";
		cin.ignore();
		getline(cin, nom);
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el apellido: ";
		cin.ignore();
		getline(cin, ape);
		if (soloLetras(nom)) { op = false; }
		else { 
			cout << "-----------------------------------------------" << endl;
			cout << "		     Solo se permiten letras" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
	
	while (op1) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el telefono: ";
		cin.ignore();
		getline(cin, tel);
		if (soloNumeros(tel)) { op1 = false; }
		else{ 
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
	while (op2) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el ID de la persona: ";
		cin.ignore();
		getline(cin, numm);
		if (soloNumeros(numm)) { 
			if(e->getPacientes()->existeID(numm)){
				cout << "-----------------------------------------------" << endl;
				cout << "                  YA EXISTENTE" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
				return false;
			}
			op1 = false; 
		}
		else { 
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			
			system("pause");
			system("cls");
		}
	}
	Paciente* pa = new Paciente(numm,nom,ape,tel);
	e->getPacientes()->agregarElemento(pa);
	return true;
}
bool Interfaz::MMPmodificar(Empresa * e)
{
	bool op = true;
	bool op1 = true;
	string id, swt,aux,cambios;
	while (op) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Paciente " << endl;
		cin.ignore();
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getPacientes()->existeID(id)) { //ver el metodo
				op = false;
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
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}

	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Que desea cambiar?" << endl;
		cout << "1 Nombre"<<endl;
		cout << "2 Apellido" << endl;
		cout << "3 Telefono" << endl;
		cout << "4 ID" << endl;
		cout << "5 SALIR AL MENU" << endl;
		cout << "Digite el numero: ";
		cin.ignore();
		getline(cin, swt);
		
		if (soloNumeros(swt)) {
			int swtt = convertirInt(swt);
			if (swtt > 0 && swtt < 6) {
				switch (swtt)
				{
				case 1:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "Nombre nuevo: ";
					cin.ignore();
					getline(cin, aux);
					if (soloLetras(aux)) {
						e->getPacientes()->getID(id)->setNombre(aux);
					}
					
					break;
				case 2:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "Apellido nuevo: ";
					cin.ignore();
					getline(cin, aux);
					e->getPacientes()->getID(id)->setApellido(aux);
					break;
				case 3:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "Telefono nuevo: ";
					cin.ignore();
					getline(cin, aux);
					e->getPacientes()->getID(id)->setTelefono(aux);
					break;
				case 4:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "ID nuevo: ";
					cin.ignore();
					getline(cin, aux);
					e->getPacientes()->getID(id)->setID(aux);
					break;
				case 5:
					system("cls");
					return false;
					break;
				default:
					break;
				}
				cout << "-----------------------------------------------" << endl;
				cout << "Desea hacer mas cambios en este paciente? S/N ";
				cin.ignore();
				getline(cin, cambios);
				if (cambios == "N" || cambios == "n") {
					op1 = false;
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
		else {
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}
	return true;
}
bool Interfaz::MMPeliminar(Empresa * e)
{
	bool op = true;
	bool op1 = true;
	bool op2 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Paciente " << endl;
		cin.ignore();
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getPacientes()->existeID(id)) { //ver el metodo
				op = false;
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
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}
	for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) {
		if (e->getCitas()->getID(convertirString(i))->getPaciente()->getID()== e->getPacientes()->getID(id)->getID()) {
			op2 = false;
		}
	}
	
	if (op2) {
		e->getPacientes()->eliminarElemento(convertirInt(id));
	}
	else {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "             No es posible eliminarlo ya " << endl;
		cout << "             que tiene asignado una cita." << endl;
		cout << "-----------------------------------------------" << endl;
		system("pause");
	}
	
	
	
	return true;
}
bool Interfaz::MMPmostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Paciente " << endl;
		cin.ignore();
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

//listo? //tal vez falta mostrar id
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
bool Interfaz::MMDingresar(Empresa * e)
{
	string nom, ape, tel, numm;
	bool op = true;
	bool op1 = true;
	bool op2 = true;

	system("cls");

	while (op) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite unicamente el nombre: ";
		getline(cin, nom);
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el apellido: ";
		getline(cin, ape);
		if (soloLetras(nom)) { op = false; }
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "		     Solo se permiten letras" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}

	while (op1) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el telefono: ";
		getline(cin, tel);
		if (soloNumeros(tel)) { op1 = false; }
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
	while (op2) {
		cout << "#----------------------------------------------#" << endl;
		cout << "Digite el ID de la persona: ";
		getline(cin, numm);
		if (soloNumeros(numm)) {
			if (e->getDoctores()->existeID(numm)) {
				cout << "-----------------------------------------------" << endl;
				cout << "                  YA EXISTENTE" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
				return false;
			}
			op1 = false;
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;

			system("pause");
			system("cls");
		}
	}
	Doctor* pa = new Doctor(numm, nom, ape, tel);
	e->getDoctores()->agregarElemento(pa);
	return true;
}
bool Interfaz::MMDmodificar(Empresa * e)
{
	if (e->getDoctores()->cantidadElementos() == 0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "              No hay doctores registradas" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	bool op = true;
	bool op1 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Doctor " << endl;
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getDoctores()->existeID(id)) { //ver el metodo
				op = false;
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
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}

	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Que desea cambiar?" << endl;
		cout << "1 Nombre" << endl;
		cout << "2 Apellido" << endl;
		cout << "3 Telefono" << endl;
		cout << "4 ID" << endl;
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
					cout << "-----------------------------------------------" << endl;
					cout << "Nombre nuevo: ";
					getline(cin, aux);
					if (soloLetras(aux)) {
						e->getDoctores()->getID(id)->setNombre(aux);
					}

					break;
				case 2:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "Apellido nuevo: ";
					getline(cin, aux);
					e->getDoctores()->getID(id)->setApellido(aux);
					break;
				case 3:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "Telefono nuevo: ";
					getline(cin, aux);
					e->getDoctores()->getID(id)->setTelefono(aux);
					break;
				case 4:
					system("cls");
					cout << "-----------------------------------------------" << endl;
					cout << "ID nuevo: ";
					getline(cin, aux);
					e->getDoctores()->getID(id)->setID(aux);
					break;
				case 5:
					system("cls");
					return false;
					break;
				default:
					break;
				}
				cout << "-----------------------------------------------" << endl;
				cout << "Desea hacer mas cambios en este doctor? S/N ";
				getline(cin, cambios);
				if (cambios == "N" || cambios == "n") {
					op1 = false;
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
		else {
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}
	return true;
}
bool Interfaz::MMDeliminar(Empresa *e)
{
	bool op = true;
	bool op1 = true;
	bool op2 = true;
	string id, swt, aux, cambios;
	while (op) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Doctor " << endl;
		cin.ignore();
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getDoctores()->existeID(id)) { //ver el metodo
				op = false;
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
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}
	for (int i = 0; i < e->getCitas()->cantidadElementos(); i++) {
		if (e->getCitas()->getID(convertirString(i))->getDoctor()->getID() == e->getDoctores()->getID(id)->getID()) {
			op2 = false;
		}
	}

	if (op2) {
		e->getDoctores()->eliminarElemento(convertirInt(id));
	}
	else {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "             No es posible eliminarlo ya " << endl;
		cout << "             que tiene asignado una cita." << endl;
		cout << "-----------------------------------------------" << endl;
		system("pause");
	}



	return true;
}
bool Interfaz::MMDmostrarid(Empresa * e)
{
	bool op1 = true;
	string id;
	while (op1) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id del Doctor " << endl;
		cin.ignore();
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
bool Interfaz::MMCIingresar(Empresa *e)
{
	if (e->getDoctores()->cantidadElementos() == 0 || e->getPacientes()->cantidadElementos()==0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "  Se necesita la existencia de pacientes y doctores" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	else {
		bool op = true;
		bool op1 = true;
		bool op2 = true;
		bool op3 = true;
		string id, id2, dd,mm,aa,mimi,hh;
		Fecha* fecha=NULL;
		Hora* hora=NULL;

		while (op) {
			system("cls");
			cout << "--------------------------------------" << endl;
			cout << "Digite el Id del Paciente " << endl;
			cin.ignore();
			getline(cin, id);
			if (soloNumeros(id)) {
				if (e->getPacientes()->existeID(id)) { //ver el metodo
					op = false;
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
				system("cls");
				cout << "-----------------------------------------------" << endl;
				cout << "                  No es numero" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
			}
		}
		while (op1) {
			system("cls");
			cout << "--------------------------------------" << endl;
			cout << "Digite el Id del Doctor " << endl;
			cin.ignore();
			getline(cin, id2);
			if (soloNumeros(id2)) {
				if (e->getDoctores()->existeID(id2)) { //ver el metodo
					op1 = false;
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
				system("cls");
				cout << "-----------------------------------------------" << endl;
				cout << "                  No es numero" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
			}
		}
		while (op2) {
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
					op2 = false;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "         Valores no validos para fecha" << endl;
					cout << "-----------------------------------------------" << endl;
					system("pause");
					system("cls");
				}
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "            Solo se aceptan numeros" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		while (op3) {
			cout << "-----------------------------------------------" << endl;
			cout << "Digite la hora(7-16): " << endl;
			cin.ignore();
			getline(cin, hh);
			cout << "-----------------------------------------------" << endl;
			cout << "Digite los minutos(0-50): " << endl;
			cin.ignore();
			getline(cin, mimi);

			if (soloNumeros(hh) && soloNumeros(mimi) ) {
				int mi = convertirInt(mimi);
				int h = convertirInt(hh);
				if (mi < 51 && mi >= 0 && h>6 && h < 17) {  //empieza a las 7, termina a las 4
					hora = new Hora(h, mi);
					op3 = false;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "         Valores no validos para hora" << endl;
					cout << "-----------------------------------------------" << endl;
					system("pause");
					system("cls");
				}
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "            Solo se aceptan numeros" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		//doctor,paciente,fecha,hora
		Cita *cit = new Cita(e->getDoctores()->getID(id2),e->getPacientes()->getID(id),fecha,hora);
		e->getCitas()->agregarElemento(cit);
	}
	return true;
}
bool Interfaz::MMCImodificar(Empresa *e)
{
	if (e->getCitas()->cantidadElementos() == 0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "              No hay Citas registradas" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}

	return true;
}
bool Interfaz::MMCIeliminar(Empresa *e)
{
	bool opp = true;
	bool op2 = true;
	string id;

	if (e->getCitas()->cantidadElementos() == 0) {
		system("cls");
		cout << "#---------------------------------------------------#" << endl;
		cout << "              No hay Citas registradas" << endl;
		cout << "#---------------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	while (opp) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "Digite el Id de la cita " << endl;
		cin.ignore();
		getline(cin, id);
		if (soloNumeros(id)) {
			if (e->getCitas()->existeID(id)) { //ver el metodo
				opp = false;
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
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "                  No es numero" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
		}
	}
	/////////////////////////////////
	for (int i = 0; i < e->getFacturas()->cantidadElementos(); i++) {
		if (e->getFacturas()->getID(convertirString(i))->getAgenda()->getID() == e->getCitas()->getID(id)->getID()) {
			op2 = false;
		}
	}

	if (op2) {
		e->getCitas()->eliminarElemento(convertirInt(id));
	}
	else {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "             No es posible eliminarlo ya " << endl;
		cout << "          que ya fue incluido en una factura." << endl;
		cout << "-----------------------------------------------" << endl;
		system("pause");
	}
	return true;
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

//listo
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
	bool op = true;
	bool op1 = true;
	string id,dd,mm,aa;
	Fecha *fecha=NULL;

	while (op) {
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
				fecha = new Fecha(a, m, d,Fecha::getWeekDay(a,m,d));
				op = false;
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "         Valores no validos para fecha" << endl;
				cout << "-----------------------------------------------" << endl;
				system("pause");
				system("cls");
			}
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "            Solo se aceptan numeros" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
	while (op1) {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "Digite el Id del doctor " << endl;
		cin.ignore();
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
	return true;
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
		cin.ignore();
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
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "            Solo se aceptan numeros" << endl;
			cout << "-----------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
	}
	return true;
}

void Interfaz::salir(){}
void Interfaz::defaul(){}
