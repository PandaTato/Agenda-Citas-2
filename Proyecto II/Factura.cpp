#include "Factura.h"

int ID = 0;

Factura::Factura()
{
	this->id = "0";

	this->agenda = NULL;

	this->subTotal = 0.0;
	this->descuento = 0.0;
	this->impuestoVenta = 0.0;
	this->total = 0.0;
}
Factura::Factura(float pSubTotal, float pDescuento,  float pImpuestoVenta, float pTotal, Agenda * pAgenda)
{
	this->id = ID++;

	this->agenda = pAgenda;

	this->subTotal = pSubTotal;
	this->descuento = pDescuento;
	this->impuestoVenta = pImpuestoVenta;
	this->total = pTotal;
}
Factura::Factura(string pID, float pSubTotal, float pDescuento, float pImpuestoVenta, float pTotal, Agenda * pAgenda)
{
	this->id = pID;

	this->agenda = pAgenda;

	this->subTotal = pSubTotal;
	this->descuento = pDescuento;
	this->impuestoVenta = pImpuestoVenta;
	this->total = pTotal;
}

Factura::~Factura(){}

string Factura::getId(){	return id;}
float Factura::getSubTotal() { return subTotal; }
float Factura::getDescuento() { return descuento; }
float Factura::getImpuestoVenta() { return impuestoVenta; }
float Factura::getTotal() { return total; }
Agenda * Factura::getAgenda() { return agenda; }

void Factura::setId(string pID) { this->id = pID; }
void Factura::setSubTotal(float pSubTotal){	this->subTotal = pSubTotal;}
void Factura::setDescuento(float pDesceunto) { this->descuento = pDesceunto; }
void Factura::setImpuestoVenta(float pImpuestoVenta){	this->impuestoVenta = pImpuestoVenta;}
void Factura::setTotal(float pTotal){ this->total = pTotal; }
void Factura::setAgenda(Agenda * pAgenda){	this->agenda = pAgenda;}

string Factura::toString()
{
	stringstream r;

	r
		<< "# Numero de Factura | " << id << endl
		<< "# Servicios Medicos | " << subTotal << endl
		<< "# Descuento         | " << descuento << endl
		<< "# Impuesto de Venta | " << impuestoVenta << endl
		<< "# Total             | " << total << endl
		<< endl;

	return r.str();
}

void Factura::guardar(ofstream & salida)
{
	salida << id << '\t';
	salida << subTotal << '\t';
	salida << descuento << '\t';
	salida << impuestoVenta << '\t';
	salida << total << '\n'; 

	agenda->guardar(salida);
}

Factura * Factura::leer(ifstream & entrada)
{
	string pID, pSubTotal, pDescuento, pImpuestoVenta, pTotal;
	Agenda* pAgenda = NULL;

	getline(entrada, pID, '\t');
	getline(entrada, pSubTotal, '\t');
	getline(entrada, pDescuento, '\t');
	getline(entrada, pImpuestoVenta, '\t');
	getline(entrada, pTotal, '\n');

	pAgenda = Agenda::leer(entrada);


	return nullptr;
}
