#include "Lista.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

/********************** Constructores y destructores **********************/

Lista::Lista()
{
	length = 0;
	this->head = NULL;
}

Lista::~Lista()
{
}

/**********************       Metodos privados       **********************/

Nodo* Lista::current(int pDato)
{
	Nodo* aux;
	int pos = 1;

	for (aux = head; aux != NULL; aux = aux->getNext()) {
		if (aux->getDato() == pDato) {
			return aux;
		}
		pos++;
	}

	if (aux == 0) {
		return NULL;
	}

	return aux;
}

Nodo* Lista::previous(int pDato)
{
	Nodo* aux = NULL;
	if (size() >= 1) {
		aux = getHead();
		while (aux != NULL && aux->getNext()->getDato() != pDato) {
			aux = aux->getNext();
		}
	}

	return aux;

}

Nodo* Lista::last()
{
	return head->getPrevious();
}

Nodo* Lista::getHead()
{
	return this->head;
}


/**********************       Metodos publicos       **********************/

int Lista::firstElement()
{
	return head->getDato(); //es la cabeza o mejor dicho el ultimo insertado

}

int Lista::lastElement()
{
	return last()->getDato();
}

int Lista::positionOfElement(int pDato)
{
	Nodo* aux;
	int pos = 0;

	for (aux = head; aux != NULL; aux = aux->getNext()) {
		if (aux->getDato() == pDato) {
			return pos;
		}
		pos++;
	}

	if (aux == 0) {
		pos = -1;
	}

	return pos;
}

bool Lista::insertAfter(int pDato, int pDatoRef)
{
	// Agregar un nuevo nodo con el dato pDato, luego del nodo con el dato pDatoRef
	bool agregado = false;
	Nodo* aux = current(pDatoRef);  // Buscando el valor de pDatoRef

	if (aux != NULL) { //Encontró a pDatoRef

		if (aux == last()) {
			agregado = insertEnd(pDato);
		}
		else {
			//Paso 1. Crear el nodo
			Nodo* nuevo = new Nodo(pDato);

			//Paso 2. Enlazar el nuevo nodo a la lista
			nuevo->setNext(aux->getNext());
			nuevo->setPrevious(aux);

			//Paso 3. Reacomadar la lista con el nuevo nodo
			if (aux->getNext() != NULL)
				aux->getNext()->setPrevious(nuevo);
			aux->setNext(nuevo);
			agregado = true;
			length++;
		}

	}

	return agregado;
}

bool Lista::insertBefore(int pDato, int pDatoRef)
{
	// Agregar un nuevo nodo con el dato pDato, luego del nodo con el dato pDatoRef
	bool agregado = false;
	Nodo* aux = previous(pDatoRef);  // Buscando el valor de pDatoRef	

	if (aux != NULL) { //Encontró a pDatoRef
		if (aux == last()) {
			agregado = insertStart(pDato);
		}
		else {
			//Paso 1. Crear el nodo
			Nodo* n = new Nodo(pDato);

			//Paso 2. Enlazar el nuevo nodo a la lista
			n->setNext(aux->getNext());
			n->setPrevious(aux);

			//Paso 3. Reacomadar la lista con el nuevo nodo
			if (aux->getNext() != NULL)
				aux->getNext()->setPrevious(n);
			aux->setNext(n);
			agregado = true;
			length++;
		}
	}

	return agregado;
}

int Lista::elementOnIndex(int index)
{
	Nodo* aux = head;

	if (index >= size())
	{
		return -1;
	}
	else {

		for (int i = 0; i < index; i++) {
			aux = aux->getNext();
		}

		return aux->getDato();
	}
}

bool Lista::insertStart(int pDato)
{
	//Paso 1 Crear el nodo
	Nodo* nuevo = new Nodo(pDato);
	bool insertado = false;

	if (this->isEmpty()) {
		setHead(nuevo);
		head->setPrevious(nuevo);
		head->setNext(nuevo);
	}
	else {
		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setNext(getHead());
		nuevo->setPrevious(last());
		getHead()->setPrevious(nuevo);

		//Paso 3. Reacomodar la lista con el nuevo nodo
		setHead(nuevo);
		last()->setNext(nuevo);

	}

	length++;
	insertado = true;

	return insertado;
}

bool Lista::insertOnPosition(int posicion, int pDato)  //position, dato
{
	bool insertado = false;

	if (isEmpty() && posicion != 0) {

		insertado = false;

	}
	else {
		if (posicion == 0) {

			insertStart(pDato);

		}
		else {
			if (posicion == size()) {

				insertEnd(pDato);

			}
			else {
				if (posicion > 0 && posicion < size()) {
					int referencia = elementOnIndex(posicion);
					Nodo* aux = previous(referencia);
					if (aux != NULL) {
						//Paso 1
						Nodo* nuevo = new Nodo(pDato);
						//Paso 2. Enlazar el nuevo nodo a la lista
						nuevo->setNext(aux->getNext());
						nuevo->setPrevious(aux);
						//Paso 3. Reacomadar la lista con el nuevo nodo
						if (aux->getNext() != NULL)
							aux->getNext()->setPrevious(nuevo);
						aux->setNext(nuevo);
						length++;
						insertado = true;
					}
				}
			}
		}
	}

	return insertado;
}

bool Lista::insertEnd(int pDato)
{
	//Paso 1 Crear el nodo
	Nodo* nuevo = new Nodo(pDato);

	bool insertado = false;

	if (this->isEmpty()) {
		setHead(nuevo);
		head->setPrevious(head);
		head->setNext(head);
	}
	else {
		Nodo* aux = last();
		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setPrevious(aux);
		nuevo->setNext(head);
		//Paso 3. Reacomodar la lista con el nuevo nodo
		aux->setNext(nuevo);
		//Paso adicional para listas dobles circulares
		head->setPrevious(nuevo);

	}

	length++;
	insertado = true;

	return insertado;
}

bool Lista::isOnList(int pDato)
{
	Nodo* aux;

	for (aux = head; aux != NULL; aux = aux->getNext()) {
		if (aux->getDato() == pDato) {
			return true;
		}
	}

	if (aux == 0) {
		return false;
	}
}

bool Lista::deleteItem(int pelemento)
{
	bool borrado = false; // bandera que me indica si se borro o no el nodo
	Nodo* aux;

	if (!isEmpty()) {
		if (getHead()->getDato() == pelemento) {
			aux = getHead();
			setHead(getHead()->getNext());
			getHead()->setPrevious(last());
			delete aux;
			borrado = true;
			length--;
		}
		else {
			Nodo* aux = current(pelemento); // 
			if (aux != NULL) {
				aux->getPrevious()->setNext(aux->getNext());
				aux->getNext()->setPrevious(aux->getPrevious());
				delete aux;
				borrado = true;
				length--;
			}
		}
	}
	return borrado;
}

bool Lista::deleteIndex(int index)
{
	int dato = elementOnIndex(index);
	return deleteItem(dato);
}

void Lista::setHead(Nodo* pHead)
{
	this->head = pHead;
}

int Lista::getLength()
{
	return length;
}

void Lista::setLength(int pLength)
{
	length = pLength;
}

bool Lista::isEmpty()
{
	return (length == 0);
}

int Lista::size()
{
	return length;
}

bool Lista::clean()
{
	bool borrado = true;

	if (size() == 0) {
		borrado = false;
	}
	else {
		for (int i = size(); i > 0; i--) {
			deleteIndex(size() - 1);
		}
		borrado = true;
	}

	return borrado;
}

std::string Lista::toString()
{
	Nodo* aux = head;
	string lista = "[";

	for (int i = 0; i < size(); i++) {

		int data = aux->getDato();
		lista += to_string(data);

		if (i < (size() - 1))
			lista += ",";

		aux = aux->getNext();
	}
	lista += "]";

	return lista;
}