#pragma once
#include "NodoDG.h"
class ListaGrupos
{
private:
	NodoDG* cab;
	int largo;

	NodoDG* getCab();
	void setCab(NodoDG*);
	int getLargo();
	void setLargo(int);

	NodoDG* buscarNodo(Grupo);
	NodoDG* nodoUltimo();
	NodoDG* nodoAnt(Grupo);
	NodoDG* nodoAnt(NodoDG*);
	NodoDG* nodoPrimero();
	Grupo demeDato(NodoDG*);
	void borrarNodo(NodoDG*);
public:
	ListaGrupos();

	bool esVacia();
	int cantidad();
	Grupo primero();
	Grupo ultimo();
	int posicion(Grupo);
	Grupo demeDato(int);
	bool existe(Grupo);
	void agregarInicio(Grupo);
	void agregarFinal(Grupo);
	bool agregarEnPos(int, Grupo);
	bool agregarAntesDe(Grupo, Grupo);
	bool agregarDespuesDe(Grupo, Grupo);
	bool borrar(Grupo);
	bool borrarEnPos(int);
	void limpiar();
	void desplegar();

	Grupo consultar(int);
	bool modificar(Grupo);
};

