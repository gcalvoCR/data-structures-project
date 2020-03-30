#pragma once
#include "Nodo.h"
#include <string>

class Lista
{
private:
	Nodo* head;
	int length;

	Nodo* getHead();
	void setHead(Nodo*);

	int getLength();
	void setLength(int);

	//Metodos internos importantes
	Nodo* previous(int pDato);
	Nodo* current(int pDato); //devolver la direccion donde se ubica x
	Nodo* last(); //devolver la dirección del ultimo de la lista


public:
	//Constructores y destructores
	Lista();
	~Lista();

	//Metodos principales
	int size();
	bool isEmpty(); // true si la estructura esta vacia
	bool insertEnd(int);
	bool insertStart(int);
	bool insertOnPosition(int, int); //position, dato
	bool insertAfter(int, int); // El dato ultimo de la lista
	bool insertBefore(int, int); //dato nuevo, dato a buscar
	bool isOnList(int);
	bool deleteItem(int);
	bool deleteIndex(int);
	int firstElement();
	int lastElement();
	int positionOfElement(int);
	int elementOnIndex(int); //Quien está en la posicion pos
	bool clean();
	std::string toString();
};

