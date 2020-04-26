#pragma once
#include "NodoDE.h"
class MaestroEstudiantes
{
private:
	NodoDE* cab;
	int largo;

	NodoDE* getCab();
	void setCab(NodoDE*);
	int getLargo();
	void setLargo(int);

	NodoDE* buscarNodo(Estudiante);
	NodoDE* nodoUltimo();
	NodoDE* nodoAnt(Estudiante);
	NodoDE* nodoAnt(NodoDE*);
	NodoDE* nodoPrimero();
	Estudiante demeDato(NodoDE*);
	void borrarNodo(NodoDE*);
public:
	MaestroEstudiantes();

	bool esVacia();
	int cantidad();
	Estudiante primero();
	Estudiante ultimo();
	int posicion(Estudiante);
	Estudiante demeDato(int);
	bool existe(Estudiante);
	void agregarInicio(Estudiante);
	void agregarFinal(Estudiante);
	bool agregarEnPos(int, Estudiante);
	bool agregarAntesDe(Estudiante, Estudiante);
	bool agregarDespuesDe(Estudiante, Estudiante);
	bool borrar(Estudiante);
	bool borrarEnPos(int);
	void limpiar();
	void desplegar();

	Estudiante consultar(string);
	bool modificar(Estudiante);

	NodoDE* buscarNodo(string cedula);
};

