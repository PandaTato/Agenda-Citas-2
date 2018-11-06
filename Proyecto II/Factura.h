#ifndef FACTURA_H
#define FACTURA_H

#include "Agenda.h"

class Factura
{
private:
	string id;
	string estado;

	float subTotal;
	float descuento;
	float impuestoVenta;
	float total;
	
	Cita* agenda;
public:
	Factura();
	Factura(float, float, float, float, Cita*);
	Factura(string, string, float, float, float, float, Cita*);

	~Factura();

	string getId();
	float getSubTotal();
	float getDescuento();
	float getImpuestoVenta();
	float getTotal();
	Cita* getAgenda();
	string getEstado();

	void setId(string);
	void setSubTotal(float);
	void setDescuento(float);
	void setImpuestoVenta(float);
	void setTotal(float);
	void setAgenda(Cita*);
	void setEstado(string);

	string toString();

	void guardar(ofstream&);
	static Factura* leer(ifstream&);
};

#endif // !FACTURA_H
