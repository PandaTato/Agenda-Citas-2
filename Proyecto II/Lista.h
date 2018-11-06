 #ifndef Lista_H
#define Lista_H

#include "Nodo.h"

template <class T>
class Lista
{
protected:
	Nodo<T>* primero;
public:
	Lista();
	Lista(Lista<T>*);
	~Lista();

	int cantidadElementos();
	int cantidadElemCaracteristica(char);

	void agregarElemento(T*);

	bool eliminarElemento(int);
	bool eliminarElemento(T*);
	bool existeElemento(T*);
	bool existeID(string);


	T*  getElemento(int);
	T*  getElemento(T*);
	T*  getID(string);

	Nodo<T>* primerElemento();

	//to string
	string toString();
	string mostrarID(string);

	//sobrecargas
	Lista<T>* operator = (Lista<T>*);

	//guardar y leer elementos
	void guardar(ofstream&);
	static Lista<T>* leer(ifstream&);
};

template<class T>
inline Lista<T>::Lista()
{
	primero = NULL;
}

template<class T>
inline Lista<T>::Lista(Lista<T>* lista)
{
	primero = NULL;
	Nodo<T>* act = lista->primerElemento();

	while (act != NULL)
	{
		this->agregarElemento(act->getElemento());
		act = act->getSiguiente();
	}
}

template<class T>
inline Lista<T>::~Lista()
{
	Nodo<T>* actual = primero;
	Nodo<T>* siguiente = actual->getSiguiente();

	while (actual != NULL)
	{
		delete actual;
		actual = siguiente;
		siguiente = actual->getSiguiente();
	}
}

template<class T>
inline int Lista<T>::cantidadElementos()
{
	int contador = 0;
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		contador++;
		actual = actual->getSiguiente();

	}
	return contador;
}

template<class T>
inline int Lista<T>::cantidadElemCaracteristica(char car)
{
	int contador = 0;
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		if (actual->getElemento()->getEstado() == car)
		{
			contador++;
			actual = actual->getSiguiente();
		}
		else
			actual = actual->getSiguiente();

	}
	return contador;
}

template<class T>
inline void Lista<T>::agregarElemento(T* elemento)
{
	primero = new Nodo<T>(elemento, primero);
}

template<class T>
inline bool Lista<T>::eliminarElemento(int posicion)
{
	int contador = 0;
	Nodo<T>* actual = primero;

	if (posicion <= this->cantidadElementos() || actual != NULL)
	{
		while (contador != posicion) { actual->getSiguiente(); }
		delete actual;
		return true;
	}
	else
		return false;
}
template<class T>
inline bool Lista<T>::eliminarElemento(T* elemento)
{
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		if (typeid(actual) == typeid(elemento) && actual->getElemento() == elemento)
		{
			delete actual;
			return true;
		}
		else
			actual = actual->getSiguiente();
	}
	return false;
}

template<class T>
inline bool Lista<T>::existeElemento(T* elemento)
{
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		if (actual->getElemento()->getID() == elemento->getID())
			return true;
		else
			actual = actual->getSiguiente();
	}
	return false;
}

template<class T>
inline bool Lista<T>::existeID(string id)
{
	T* elemento = getID(id);
	if (elemento == NULL) { return false; }

	return existeElemento(elemento);
}

template<class T>
inline T*  Lista<T>::getElemento(int posicion)
{
	int contador = 0;
	Nodo<T>* actual = primero;

	if (posicion <= this->cantidadElementos() && actual != NULL)
	{
		while (contador != posicion) { actual->getSiguiente(); contador++; }
		return actual->getElemento();
	}
	else
		return NULL;
}

template<class T>
inline T * Lista<T>::getElemento(T * elemento)
{
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		if (actual->getElemento()->getID() == elemento->getID())
			return actual->getElemento();
		else
			actual = actual->getSiguiente();
	}
	return NULL;
}

template<class T>
inline T*  Lista<T>::getID(string caracteristica)
{
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		if (actual->getElemento()->getID() == caracteristica)
		{
			return actual->getElemento();
		}
		else
			actual = actual->getSiguiente();
	}
	return false;
}

template<class T>
inline Nodo<T>* Lista<T>::primerElemento()
{
	return primero;
}

template<class T>
inline string Lista<T>::toString()
{
	stringstream r;
	Nodo<T>* actual = primero;

	while (actual != NULL)
	{
		r << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return r.str();
}

template<class T>
inline string Lista<T>::mostrarID(string ID)
{
	stringstream r;
	T*elem = getID(ID);
	r << elem->toString();

	return r.str();
}

template<class T>
inline Lista<T>* Lista<T>::operator = (Lista<T>* lista)
{
	this->~Lista();
	Nodo<T>* actual = lista->primerElemento();

	while (actual != NULL)
	{
		agregarElemento(actual->getElemento());
		actual->getSiguiente();
	}

	return this;
}

template<class T>
void Lista<T>::guardar(ofstream & salida)
{
	Nodo<T>* actual = primero;

	salida << cantidadElementos() << '\n';

	for (int i = 0; i < cantidadElementos(); i++)
	{
		actual->getElemento()->guardar(salida);
		actual = actual->getSiguiente();
	}
}

template<class T>
inline Lista<T>* Lista<T>::leer(ifstream& entrada)
{
	Lista<T>* lista = new Lista<T>();
	T* nuevo = NULL;

	string can;
	string prueba;

	getline(entrada, can, '\n');

	int cantidad = convertirInt(can);

	for (int i = 0; i < cantidad; i++)
	{
		nuevo = T::leer(entrada);

		lista->agregarElemento(nuevo);
	}

	return lista;
}

#endif /* Nodo_H */