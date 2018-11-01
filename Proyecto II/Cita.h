#ifndef Cita_H
#define Cita_H

#include "Doctor.h"
#include "Paciente.h"
#include "Fecha.h"
#include "Hora.h"

class Cita
{
private:
	string id;

	Doctor * doctor;
	Paciente* paciente;
	Fecha* fecha;
	Hora* hora;

public:
	Cita();
	Cita(Doctor*, Paciente*, Fecha*, Hora*);
	Cita(string, Doctor*, Paciente*, Fecha*, Hora*);
	
	~Cita();

	string getId();
	Doctor * getDoctor();
	Paciente* getPaciente();
	Fecha* getFecha();
	Hora* getHora();

	void setId(string);
	void setDoctor(Doctor*);
	void setPaciente(Paciente*);
	void setFecha(Fecha*);
	void setHora(Hora*);

	string toString();
	friend ostream& operator<<(ostream& out, Cita* e);

	void guardar(ofstream&);
	static Cita* leer(ifstream&);
};

#endif /*Cita_H*/