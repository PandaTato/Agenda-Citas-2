#include "Fecha.h"

Fecha::Fecha()
{
	annio = nowLocal.tm_year + 1900;
	mes = nowLocal.tm_mon + 1;
	dia = nowLocal.tm_mday;
	day = nowLocal.tm_wday ;
}
Fecha::Fecha(int pAnnio, int pMes, int pDia)
{
	annio = pAnnio;
	mes = pMes;
	dia = pDia;
}
Fecha::Fecha(int pAnnio, int pMes, int pDia, int pDay )
{
	annio = pAnnio;
	mes = pMes;
	dia = pDia;
	day = pDay;
}

Fecha::~Fecha() {}

int Fecha::getAnnio() { return annio; }
int Fecha::getMes() { return mes; }
int Fecha::getDia() { return dia; }
int Fecha::getwday() { return day; }

string Fecha::getMesPal(int pMes)
{
	switch (pMes)
	{
	case 1: return "Enero"; break;
	case 2: return "Febrero"; break;
	case 3: return "Marzo"; break;
	case 4: return "Abril"; break;
	case 5: return "Mayo"; break;
	case 6: return "Junio"; break;
	case 7: return "Julio"; break;
	case 8: return "Agosto"; break;
	case 9: return "Septimbre"; break;
	case 10: return "Octubre"; break;
	case 11: return "Novimebre"; break;
	case 12: return "Diciembre"; break;
	default:
	{
		system("cls");
		stringstream r;
		r << "#----------------------------------------------#" << endl;
		r << "#                Opcion Invalida               #" << endl;
		r << "#----------------------------------------------#" << endl;


		system("pause"); return r.str(); break;
	}
	}
}

void Fecha::setAnnio(int a) { annio = a; }
void Fecha::setMes(int pMes) { mes = pMes; }
void Fecha::setDia(int d) { dia = d; }
void Fecha::setwday(int pDay) { day = pDay; }

string Fecha::toString()
{
	stringstream r;
	r
		<< "#----------------------------------------------#" << endl
		<< "#                     Fecha                    #" << endl
		<< "#----------------------------------------------#" << endl
		<< "# Annio | " << annio << endl
		<< "#----------------------------------------------#" << endl
		<< "#  Mes  | " << mes << endl
		<< "#----------------------------------------------#" << endl
		<< "#  Dia  | " << day << dia << endl
		<< "#----------------------------------------------#" << endl;

	return string(r.str());
}
int Fecha::getWeekDay(int yy, int mm, int dd)
{
	int rst =
		dd
		+ ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5)
		+ (365 * (yy + 4800 - ((14 - mm) / 12)))
		+ ((yy + 4800 - ((14 - mm) / 12)) / 4)
		- ((yy + 4800 - ((14 - mm) / 12)) / 100)
		+ ((yy + 4800 - ((14 - mm) / 12)) / 400)
		- 32045;

	return (rst + 1) % 7;
}

bool Fecha::validarFecha(int a, int pMes, int d)
{
	cin.exceptions(ifstream::failbit | istream::badbit);
	try
	{
		if (a < 1850) { throw 0; }
		if (a > 2200) { throw 1; }
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error == 0)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "#       El annio debe ser superior a 1850      #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
		if (error == 1)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "#        El annio debe ser menor a 2220        #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
	try
	{
		if (pMes > 12 || pMes < 1) { throw 0; }
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error == 0)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "# El mes debe ser estar entre 1(enero) y       #" << endl;
			cout << "# 12(diciembre)                                #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
	try
	{
		switch (pMes)
		{
		case 1: if (d < 1 || d > 31) { throw 0; }; break;
		case 2: if (d < 1 || d > 29) { throw 3; }; break;
		case 3: if (d < 1 || d > 31) { throw 0; }; break;
		case 4: if (d < 1 || d < 30) { throw 1; }; break;
		case 5: if (d < 1 || d > 31) { throw 0; }; break;
		case 6: if (d < 1 || d > 30) { throw 1; }; break;
		case 7: if (d < 1 || d > 31) { throw 0; }; break;
		case 8: if (d < 1 || d > 31) { throw 0; }; break;
		case 9: if (d < 1 || d > 30) { throw 1; }; break;
		case 10: if (d < 1 || d > 31) { throw 0; }; break;
		case 11: if (d < 1 || d > 30) { throw 1; }; break;
		case 12: if (d < 1 || d > 31) { throw 0; }; break;
		default:
		{
			system("cls");

			cout << "#----------------------------------------------#" << endl;
			cout << "#                Opcion Invalida               #" << endl;
			cout << "#----------------------------------------------#" << endl;

			system("pause"); break;
		}
		}
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error = 0)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "#        El mes posee entre 1 y 30 dias        #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
		if (error = 1)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "#        El mes posee entre 1 y 31 dias        #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
		if (error = 3)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "#        El mes posee entre 1 y 28 dias        #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
}
bool Fecha::esMenor(Fecha * fec)
{
	int a = fec->getAnnio();
	int pMes = fec->getMes();
	int d = fec->getDia();

	if (annio <= a)
	{
		if (mes <= pMes)
		{
			if (dia <= d)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

Fecha* Fecha::validarFechaC(int a, int pMes, int d)
{
	Fecha fec;
	cin.exceptions(ifstream::failbit | istream::badbit);
	try
	{
		if (a < 1850) { throw 0; }
		if (a > 2200) { throw 1; }
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error == 0)
		{
			a = fec.getAnnio();
		}
		if (error == 1)
		{
			a = fec.getAnnio();
		}
	}
	try
	{
		if (pMes > 12) { throw 0; }
		if (pMes < 1) { throw 1; }
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error == 0)
		{
			pMes = 1;
			a++;
			return false;
		}
		if (error == 1)
		{
			system("cls");
			cout << "#----------------------------------------------#" << endl;
			cout << "# El mes debe ser estar entre 1(enero) y       #" << endl;
			cout << "# 12(diciembre)                                #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
	try
	{
		if (d < 1) { throw 1; }
		switch (pMes)
		{
		case 1: if (d > 31) { throw 0; }; break;
		case 2: if (d > 29) { throw 0; }; break;
		case 3: if (d > 31) { throw 0; }; break;
		case 4: if (d < 30) { throw 0; }; break;
		case 5: if (d > 31) { throw 0; }; break;
		case 6: if (d > 30) { throw 0; }; break;
		case 7: if (d > 31) { throw 0; }; break;
		case 8: if (d > 31) { throw 0; }; break;
		case 9: if (d > 30) { throw 0; }; break;
		case 10: if (d > 31) { throw 0; }; break;
		case 11: if (d > 30) { throw 0; }; break;
		case 12: if (d > 31) { throw 0; }; break;
		default:
		{
			system("cls");

			cout << "#----------------------------------------------#" << endl;
			cout << "#                Opcion Invalida               #" << endl;
			cout << "#----------------------------------------------#" << endl;

			system("pause"); break;
		}
		}
	}
	catch (ifstream::failure)
	{
		system("cls");
		cout << "#----------------------------------------------#" << endl;
		cout << "#          El dato debe ser un numero          #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	catch (int error)
	{
		if (error = 0)
		{
			d = 1;
			pMes++;
		}
	}

	return new Fecha(a, pMes, d);
}

void Fecha::guardar(ofstream& salida)
{
	salida << annio << '\t';
	salida << mes << '\t';
	salida << dia << '\t';
	salida << day << '\n';
}
Fecha * Fecha::leer(ifstream& entrada)
{
	string a, pMes, d, pDay;

	getline(entrada, a, '\t');
	getline(entrada, pMes, '\t');
	getline(entrada, d, '\t');
	getline(entrada, pDay, '\n');

	int pannio, pmes, pdia, pday;

	pannio = convertirInt(a);
	pmes = convertirInt(pMes);
	pdia = convertirInt(d);
	pday = convertirInt(pDay);

	return new Fecha(pannio, pmes, pdia, pday);
}