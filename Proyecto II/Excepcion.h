#ifndef EXCEPCION_H
#define EXCEPCION_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Excepcion
{
private:
	int id;
	string error;
public:
	Excepcion();
	Excepcion(int);
	~Excepcion();

	string Error(int);

	string toString();
};
#endif // !EXCEPCION_H

