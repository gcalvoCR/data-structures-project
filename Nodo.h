#pragma once
class Nodo
{
private:
	int  dato;
	Nodo* next;
	Nodo* previous;

public:
	Nodo();
	Nodo(int pdato);
	~Nodo();

	int getDato();
	Nodo* getNext();
	Nodo* getPrevious();

	void setDato(int);
	void setNext(Nodo*);
	void setPrevious(Nodo*);
};