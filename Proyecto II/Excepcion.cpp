#include "Excepcion.h"

Excepcion::Excepcion()
{
	id = 0;
	error = "";
}

Excepcion::Excepcion(int ID)
{
	id = ID;
	error = Error(ID);
}

Excepcion::~Excepcion()
{
}

string Excepcion::Error(int ID)
{
	switch (ID)
	{
	case 0: //tipo dato
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#        El tipo de dato es incorrecto         #" << endl;
		return r.str();
		break;
	}
	case 1: //Pacientes
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#    No se encuentran pacientes registrados    #" << endl;
		return r.str();
		break;
	}
	case 2: //doctores
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#    No se encuentran doctores registrados     #" << endl;
		return r.str();
		break;
	}
	case 3: //citas
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#     No se encuentran citass registradas      #" << endl;
		return r.str();
		break;
	}
	case 4: //facturas
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#     No se encuentran facturas registradas    #" << endl;
		return r.str();
		break;
	}
	case 5: //no id
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#        No se encuentran ID resgistrado       #" << endl;
		return r.str();
		break;
	}
	case 6: //id ya existente
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#                 El ID ya existe              #" << endl;
		return r.str();
		break;
	}
	case 7: //campo ya reservado
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#     Este campo ya se encentra reservado      #" << endl;
		return r.str();
		break;
	}
	case 8: //fecha invalida
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#     La Fecha u Hora ingresada no es valid    #" << endl;
		return r.str();
		break;
	}
	case 9: //solo letras
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#            Solo se permiten letras           #" << endl;
		return r.str();
		break;
	}
	case 10: //solo numeros
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#             Solo se permiten numeros         #" << endl;
		return r.str();
		break;
	}
	default: //desconocido
	{
		stringstream r;
		r
			<< "#----------------------------------------------#" << endl
			<< "#             Error desconocido                #" << endl;
		return r.str();
		break;
	}
	}
}

string Excepcion::toString()
{
	system("cls");
	stringstream r;
	r
		<< "#----------------------------------------------#" << endl
		<< "#                      ERROR                   #" << endl
		<< error << endl
		<< "#----------------------------------------------#" << endl;

	return r.str();
}