#pragma once
#include "NodoDM.h"
class ListaMaterias
{
private:
	NodoDM* cab;
	int largo;

	NodoDM* getCab();
	void setCab(NodoDM*);
	int getLargo();
	void setLargo(int);

	NodoDM* buscarNodo(Materia);
	NodoDM* nodoUltimo();
	NodoDM* nodoAnt(Materia);
	NodoDM* nodoAnt(NodoDM*);
	NodoDM* nodoPrimero();
	Materia demeDato(NodoDM*);
	void borrarNodo(NodoDM*);

	void agregarAArchivo(Materia);
	void borrarDeArchivo(Materia);
	void modificarEnArchivo(Materia);
public:
	ListaMaterias();

	bool esVacia();
	int cantidad();
	Materia primero();
	Materia ultimo();
	int posicion(Materia);
	Materia demeDato(int);
	bool existe(Materia);
	void agregarInicio(Materia);
	void agregarFinal(Materia);
	bool agregarEnPos(int, Materia);
	bool agregarAntesDe(Materia, Materia);
	bool agregarDespuesDe(Materia, Materia);
	bool borrar(Materia);
	bool borrarEnPos(int);
	void limpiar();
	void desplegar();

	Materia consultar(string);
	bool modificar(Materia);

};

