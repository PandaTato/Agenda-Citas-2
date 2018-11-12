#include "Empresa.h"

Empresa::Empresa(string a)
{
	nombre = a;
	cita = new Lista<Cita>();
	agenda = new Agenda(cita);
	paciente = new Lista<Paciente>();
	doctor = new Lista<Doctor>();
	factura = new Lista<Factura>();
}

Empresa::Empresa(string pNombre, Lista<Cita>* pCita, Lista<Paciente>* pPaciente, Lista<Doctor>* pDoctor, Lista<Factura>* pFactura)
{
	nombre = pNombre;

	cita = pCita;
	agenda = new Agenda(pCita);
	paciente = pPaciente;
	doctor = pDoctor;
	factura = pFactura;
}

Empresa::~Empresa(){}

void Empresa::setNombre(string pNombre) { this->nombre = pNombre; }
void Empresa::setAgenda(Agenda * pAgenda) { this->agenda = pAgenda; }

void Empresa::setCitas(Lista<Cita>* pCita) { this->cita = pCita; }
void Empresa::setPacientes(Lista<Paciente>* pPaciente) { this->paciente = pPaciente; }
void Empresa::setDoctores(Lista<Doctor>* pDoctor) { this->doctor = pDoctor; }
void Empresa::setFacturas(Lista<Factura>* pFactura) { this->factura = pFactura; }


void Empresa::getNombre(string pNombre) { this->nombre = pNombre; }
Agenda * Empresa::getAgenda() { return this->agenda; }

Lista<Cita>* Empresa::getCitas(){	return this->cita;}
Lista<Paciente>* Empresa::getPacientes(){	return this->paciente;}
Lista<Doctor>* Empresa::getDoctores(){	return this->doctor;}
Lista<Factura>* Empresa::getFacturas(){	return this->factura;}

void Empresa::guardar(ofstream& salida)
{
	salida << nombre << '\n';
	
	cita->guardar(salida);
	paciente->guardar(salida);
	doctor->guardar(salida);
	factura->guardar(salida);
}

Empresa * Empresa::leer(ifstream& entrada)
{

	string pNombre;

	Lista<Cita>* pCita;
	Lista<Paciente>* pPaciente;
	Lista<Doctor>* pDoctor;
	Lista<Factura>* pFactura;

	getline(entrada, pNombre, '\n');

	pCita = Lista<Cita>::leer(entrada);

	pPaciente = Lista<Paciente>::leer(entrada);
	pDoctor = Lista<Doctor>::leer(entrada);
	pFactura = Lista<Factura>::leer(entrada);

	return new Empresa(pNombre, pCita, pPaciente, pDoctor, pFactura);
}
