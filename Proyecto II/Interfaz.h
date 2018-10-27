#ifndef INTERFAZ_H
#define ITERFAZ_H

class Empresa;

class Interfaz
{
public:
	static Empresa* inicio();

	static int menu();

	//venta
	static int MFactura();
	static bool MFactura(Empresa*);

	//mantenimiento
	static int mantenimiento();


	static int MMFactura();
	//Reservas mantenimiento
	static bool MMFIingresar(Empresa*);
	static bool MMFImodificar(Empresa*);
	static bool MMFIeliminar(Empresa*);
	static bool MMFImostrarid(Empresa*);
	static bool MMFImostrartodos(Empresa*);

	static int MMCliente();
	//cliente mantenimiento
	static bool MMCingresar(Empresa*);
	static bool MMCmodificar(Empresa*);
	static bool MMCeliminar(Empresa*);
	static bool MMCmostrarid(Empresa*);
	static bool MMCmostrartodos(Empresa*);

	static int MMDoctor();
	//Pilotos mantenimiento
	static bool MMDingresar(Empresa*);
	static bool MMDmodificar(Empresa*);
	static bool MMDeliminar(Empresa*);
	static bool MMDmostrarid(Empresa*);
	static bool MMDmostrartodos(Empresa*);

	static int MMCita();
	//Aviones mantenimiento
	static bool MMCIingresar(Empresa*);
	static bool MMCImodificar(Empresa*);
	static bool MMCIeliminar(Empresa*);
	static bool MMCImostrarid(Empresa*);
	static bool MMCImostrartodos(Empresa*);

	static int MMViaje();
	//Aviones mantenimiento
	static bool MMVingresar(Empresa*);
	static bool MMVmodificar(Empresa*);
	static bool MMVeliminar(Empresa*);
	static bool MMVmostrarid(Empresa*);
	static bool MMVmostrartodos(Empresa*);

	static int MMEmpresa();
	//empresa mantenimiento
	static bool MMEmodificar(Empresa*);
	static bool MMEmostrar(Empresa*);


	static void salir();
	static void defaul();

	//hola

};

#endif // !INTERFAZ_H
