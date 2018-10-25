#ifndef Nodo_H
#define Nodo_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
class Nodo
{
private:
	T * elemento;
	Nodo<T>* siguiente;
public:
	Nodo(T *, Nodo<T>*);
	~Nodo();

	T* getElemento();
	Nodo<T>* getSiguiente();

	void setElemento(T*);
	void setSiguiente(Nodo<T>*);
};

template<class T>
inline Nodo<T>::Nodo(T * elem, Nodo<T>* sig)
{
	this->elemento = elem;
	this->siguiente = sig;
}

template<class T>
inline Nodo<T>::~Nodo()
{
	delete elemento;
}

template<class T>
inline T* Nodo<T>::getElemento()
{
	return elemento;
}

template<class T>
inline Nodo<T>* Nodo<T>::getSiguiente()
{
	return siguiente;
}

template<class T>
inline void Nodo<T>::setElemento(T * elem)
{
	this->elemento = elem;
}

template<class T>
inline void Nodo<T>::setSiguiente(Nodo<T>*)
{
	this->siguiente = sig;
}

#endif /* Nodo_H */