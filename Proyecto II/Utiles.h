#ifndef Utiles_H
#define Utiles_H

#include <iostream>
#include <sstream>

using namespace std;

int convertirInt(string);
float convertirFloat(string);
char convertirChar(string);
string convertirString(char);
string convertirString(int);

bool soloLetras(string);
bool soloNumeros(string);
bool soloLetras(char);
bool soloNumeros(char);

bool divisible4(string);
bool divisible7(string);

#endif /*Utiles_H*/