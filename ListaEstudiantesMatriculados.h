#pragma once
#include "NodoDEM.h"
class ListaEstudiantesMatriculados
{
private:
	NodoDEM* cab;
	int largo;

	NodoDEM* getCab();
	void setCab(NodoDEM*);
	int getLargo();
	void setLargo(int);

	NodoDEM* buscarNodo(EstudianteMatriculado);
	NodoDEM* nodoUltimo();
	NodoDEM* nodoAnt(EstudianteMatriculado);
	NodoDEM* nodoAnt(NodoDEM*);
	NodoDEM* nodoPrimero();
	EstudianteMatriculado demeDato(NodoDEM*);
	void borrarNodo(NodoDEM*);

	void agregarAArchivo(EstudianteMatriculado);
	void borrarDeArchivo(EstudianteMatriculado);
	void modificarEnArchivo(EstudianteMatriculado);
public:
	ListaEstudiantesMatriculados();
	ListaEstudiantesMatriculados(string, int);

	bool esVacia();
	int cantidad();
	EstudianteMatriculado primero();
	EstudianteMatriculado ultimo();
	int posicion(EstudianteMatriculado);
	EstudianteMatriculado demeDato(int);
	bool existe(EstudianteMatriculado);
	void agregarInicio(EstudianteMatriculado);
	void agregarFinal(EstudianteMatriculado);
	bool agregarEnPos(int, EstudianteMatriculado);
	bool agregarAntesDe(EstudianteMatriculado, EstudianteMatriculado);
	bool agregarDespuesDe(EstudianteMatriculado, EstudianteMatriculado);
	bool borrar(EstudianteMatriculado);
	bool borrarEnPos(int);
	void limpiar();
	void desplegar();

	EstudianteMatriculado consultar(string);
	bool modificar(EstudianteMatriculado);
};

