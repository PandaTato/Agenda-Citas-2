#include "Utiles.h"

int convertirInt(string m)
{
	stringstream r(m);
	int v;
	r >> v;
	return v;
}
float convertirFloat(string m)
{
	stringstream r(m);
	float v;
	r >> v;
	return v;
}
char convertirChar(string m)
{
	stringstream r(m);
	char v;
	r >> v;
	return v;
}

string convertirString(char m)
{
	stringstream r;
	r << m;
	return r.str();
}
string convertirString(int m)
{
	stringstream r;
	r << m;
	return r.str();
}


bool soloLetras(string s)
{
	char sl[250];
	strcpy_s(sl, s.c_str());

	for (int i = 0; i < strlen(sl); i++)
	{
		if (sl[i] == ' ') i++;
		if (!isalpha(sl[i]))
		{
			cout << "#----------------------------------------------#" << endl;
			cout << "# ERROR : Solo se permiten letras              #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
	return true;
}
bool soloNumeros(string s)
{
	char sn[250];
	strcpy_s(sn, s.c_str());

	for (int i = 0; i < strlen(sn); i++)
	{
		if (!isdigit(sn[i]))
		{
			cout << "#----------------------------------------------#" << endl;
			cout << "# ERROR : Solo se permiten numeros             #" << endl;
			cout << "#----------------------------------------------#" << endl;
			system("pause");
			return false;
		}
	}
	return true;
}

bool soloLetras(char s)
{
	string a = convertirString(s);
	char sl[250];
	strcpy_s(sl, a.c_str());

	if (!isalpha(sl[0]))
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# ERROR : Solo se permiten letras              #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}

	return true;
}
bool soloNumeros(char s)
{
	string a = convertirString(s);
	char sl[250];
	strcpy_s(sl, a.c_str());

	if (!isalpha(sl[0]))
	{
		cout << "#----------------------------------------------#" << endl;
		cout << "# ERROR : Solo se permiten numeros             #" << endl;
		cout << "#----------------------------------------------#" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool divisible4(string m)
{
	int num = convertirInt(m);

	if (num % 4 == 0)
		return true;
	else
		return false;
}
bool divisible7(string m)
{
	int num = convertirInt(m);

	if (num % 7 == 0)
		return true;
	else
		return false;
}
