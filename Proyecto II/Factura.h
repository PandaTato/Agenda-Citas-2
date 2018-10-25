#ifndef FACTURA_H
#define FACTURA_H

#include "Agenda.h"

class Factura
{
private:
	string id;

	float subTotal;
	float descuento;
	float impuestoVenta;
	float total;
	
	Agenda* agenda;
public:
	Factura();
	Factura(float, float, float, float, Agenda*);
	Factura(string, float, float, float, float, Agenda*);

	~Factura();

	string getId();
	float getSubTotal();
	float getDescuento();
	float getImpuestoVenta();
	float getTotal();
	Agenda* getAgenda();

	void setId(string);
	void setSubTotal(float);
	void setDescuento(float);
	void setImpuestoVenta(float);
	void setTotal(float);
	void setAgenda(Agenda*);
	string toString();

	void guardar(ofstream&);
	static Factura* leer(ifstream&);
};

#endif // !FACTURA_H
