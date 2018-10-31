#include "Agenda.h"

Agenda::Agenda() { citas = NULL; }
Agenda::Agenda(Lista<Cita>* pCitas) { this->citas = pCitas; }
Agenda::Agenda(Agenda* pAgenda) { this->citas = pAgenda->getCitas(); }

Agenda::~Agenda(){}

Lista<Cita>* Agenda::getCitas() { return citas; }

void Agenda::setCitas(Lista<Cita>* pCitas){ this->citas = pCitas; }

string Agenda::toString()
{	
	stringstream r;

	r << citas->toString();

	return r.str();
}

string Agenda::obtenerAgenda(Doctor * doc)
{
	stringstream s;
	int yaux = 0;
	int daux = 0;
	int maux = 0;
	Fecha * fech = new Fecha();
	string Dsem[] = { "Domingo","Lunes","Martes","Miercoles","Jueves", "Viernes", "Sabado" };
	yaux = fech->getAnnio();
	maux = fech->getMes();
	daux = fech->getDia() - fech->getwday() + 1; //con esto me seteo en el domingo de esa semana

	if (fech->getDia() >= 7) {
		for (int i = 0; i < 7; i++) {
			Nodo<Cita>* actual = citas->primerElemento();
			s
				<< "--------------------------------------" << endl
				<< Dsem[i] << endl
				<< "--------------------------------------" << endl;
			while (actual != NULL) {
				if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
					int yy = actual->getElemento()->getFecha()->getAnnio();
					int mm = actual->getElemento()->getFecha()->getMes();
					int dd = actual->getElemento()->getFecha()->getDia();
					if (yy == yaux && mm == maux && dd == daux) {
						s << actual->getElemento();
					}
					else {
						actual = actual->getSiguiente();
					}
				}
				else {
					actual = actual->getSiguiente();
				}
			}
			daux++;
		}

	}
	else {
		if (daux<1) {
			if (maux == 1) { //enero
				int yaux2 = yaux - 1;
				int maux2 = 12;
				int daux2 = 31 + daux; //daux es negativo
				int j = (daux * -1) + 1; //si daux es 0, es dia del mes anterior
				for (int i = 0; i < j; i++) {
					Nodo<Cita>* actual = citas->primerElemento();
					s
						<< "--------------------------------------" << endl
						<< Dsem[i] << endl
						<< "--------------------------------------" << endl;
					while (actual != NULL) {
						if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
							int yy = actual->getElemento()->getFecha()->getAnnio();
							int mm = actual->getElemento()->getFecha()->getMes();
							int dd = actual->getElemento()->getFecha()->getDia();
							if (yy == yaux2 && mm == maux2 && dd == daux2) {
								s << actual->getElemento();
							}
							else {
								actual = actual->getSiguiente();
							}
						}
						else {
							actual = actual->getSiguiente();
						}
					}
					daux2++;
				}
				for (int i = 1; i <= fech->getDia(); i++) {
					Nodo<Cita>* actual = citas->primerElemento();
					s
						<< "--------------------------------------" << endl
						<< Dsem[i + j - 1] << endl
						<< "--------------------------------------" << endl;
					while (actual != NULL) {
						if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
							int yy = actual->getElemento()->getFecha()->getAnnio();
							int mm = actual->getElemento()->getFecha()->getMes();
							int dd = actual->getElemento()->getFecha()->getDia();
							if (yy == yaux && mm == maux && dd == i) {
								s << actual->getElemento();
							}
							else {
								actual = actual->getSiguiente();
							}
						}
						else {
							actual = actual->getSiguiente();
						}
					}
				}
			}
			else {
				int maux2 = maux - 1;
				int daux2 = 0;
				if (maux2 == 1 || maux2 == 3 || maux2 == 5 || maux2 == 7 || maux2 == 8 || maux2 == 10 || maux2 == 12) {
					daux2 = 31 + daux; //daux es negativo
				}
				else {
					if (maux2 == 2) {
						daux2 = 28 + daux;
					}
					else {
						daux2 = 30 + daux;
					}
				}
				int j = (daux * -1) + 1;
				for (int i = 0; i < j; i++) {
					Nodo<Cita>* actual = citas->primerElemento();
					s
						<< "--------------------------------------" << endl
						<< Dsem[i] << endl
						<< "--------------------------------------" << endl;
					while (actual != NULL) {
						if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
							int yy = actual->getElemento()->getFecha()->getAnnio();
							int mm = actual->getElemento()->getFecha()->getMes();
							int dd = actual->getElemento()->getFecha()->getDia();
							if (yy == yaux && mm == maux2 && dd == daux2) {
								s << actual->getElemento();
							}
							else {
								actual = actual->getSiguiente();
							}
						}
						else {
							actual = actual->getSiguiente();
						}
					}
					daux2++;
				}
				for (int i = 1; i <= fech->getDia(); i++) {
					s
						<< "--------------------------------------" << endl
						<< Dsem[i + j - 1] << endl
						<< "--------------------------------------" << endl;
					Nodo<Cita>* actual = citas->primerElemento();
					while (actual != NULL) {
						if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
							int yy = actual->getElemento()->getFecha()->getAnnio();
							int mm = actual->getElemento()->getFecha()->getMes();
							int dd = actual->getElemento()->getFecha()->getDia();
							if (yy == yaux && mm == maux && dd == i) {
								s << actual->getElemento();
							}
							else {
								actual = actual->getSiguiente();
							}
						}
						else {
							actual = actual->getSiguiente();
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < 7; i++) {
				Nodo<Cita>* actual = citas->primerElemento();
				s
					<< "--------------------------------------" << endl
					<< Dsem[i] << endl
					<< "--------------------------------------" << endl;
				while (actual != NULL) {
					if (actual->getElemento()->getDoctor()->getID() == doc->getID()) {
						int yy = actual->getElemento()->getFecha()->getAnnio();
						int mm = actual->getElemento()->getFecha()->getMes();
						int dd = actual->getElemento()->getFecha()->getDia();
						if (yy == yaux && mm == maux && dd == daux) {
							s << actual->getElemento();
						}
						else {
							actual = actual->getSiguiente();
						}
					}
					else {
						actual = actual->getSiguiente();
					}
				}
				daux++;
			}
		}
	}

	return s.str();
}

void Agenda::guardar(ofstream & salida) { citas->guardar(salida); }

Agenda* Agenda::leer(ifstream & entrada)
{
	Lista<Cita>* ptrLista = Lista<Cita>::leer(entrada);

	return new Agenda(ptrLista);
}
