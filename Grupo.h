#pragma once
#include <string>
#include "ListaEstudiantesMatriculados.h"
using namespace std;
class Grupo
{
private:
	string materia;
	int numero;
	bool estatus;
	int maximo;
	int matriculados;
	ListaEstudiantesMatriculados listaMatricula;

public:
	Grupo();
	Grupo(string, int, bool, int, int);
	string getMateria();
	void setMateria(string);
	int getNumero();
	void setNumero(int);
	bool getEstatus();
	void setEstatus(bool);
	int getMaximo();
	void setMaximo(int);
	int getMatriculados();
	void setMatriculados(int);
	ListaEstudiantesMatriculados getListaMatricula();
	void setListaMatricula(ListaEstudiantesMatriculados listaMatricula);
	void desplegar();

};

