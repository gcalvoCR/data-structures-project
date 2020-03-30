#include "Nodo.h"
#include <cstddef>

Nodo::Nodo()
{
	dato = 0;
	next = NULL;
	previous = NULL;
}

Nodo::Nodo(int pdato)
{
	dato = pdato;
	next = NULL;
	previous = NULL;
}

Nodo::~Nodo()
{

}

int Nodo::getDato()
{
	return dato;
}

Nodo* Nodo::getNext()
{
	return this->next;
}

Nodo* Nodo::getPrevious()
{
	return this->previous;
}

void Nodo::setDato(int pdato)
{
	dato = pdato;
}

void Nodo::setNext(Nodo* pNext)
{
	this->next = pNext;
}

void Nodo::setPrevious(Nodo* pPrevious)
{
	this->previous = pPrevious;
}
