#ifndef INTERFAZ_H
#define ITERFAZ_H

#include "Paciente.h"

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
	static bool MMFingresar(Empresa*);
	static bool MMFanular(Empresa*);
	static bool MMFmostrarid(Empresa*);
	static bool MMFmostrarPersona(Empresa*);
	static bool MMFmostrartodos(Empresa*);

	static int MMPaciente();
	//cliente mantenimiento
	static bool MMPingresar(Empresa*);
	static bool MMPmodificar(Empresa*);
	static bool MMPeliminar(Empresa*);
	static bool MMPmostrarid(Empresa*);  //
	static bool MMPmostrarPersona(Empresa*);
	static bool MMPmostrartodos(Empresa*);  //

	static int MMDoctor();
	//Pilotos mantenimiento
	static bool MMDingresar(Empresa*);
	static bool MMDmodificar(Empresa*);
	static bool MMDeliminar(Empresa*);
	static bool MMDmostrarid(Empresa*);
	static bool MMDmostrartodos(Empresa*);

	static int MMCita();
	//cita mantenimiento
	static bool MMCIingresar(Empresa*);
	static bool MMCImodificar(Empresa*);
	static bool MMCIeliminar(Empresa*);
	static bool MMCImostrarid(Empresa*);
	static bool MMFCImostrarPersona(Empresa*);
	static bool MMCImostrartodos(Empresa*);

	static int MMAgenda();
	//agenda mantenimiento
	static bool MMFAmostrarFecha(Empresa*);
	static bool MMFAmostrarHoy(Empresa*);

	static void salir();
	static void defaul();
};

#endif // !INTERFAZ_H
