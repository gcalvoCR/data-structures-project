#include "Grupo.h"
#include <iostream>

Grupo::Grupo()
{
	this->materia = " ";
	this->numero = 0;
	this->estatus = false;
	this->maximo = 0;
	this->matriculados = 0;
	this->listaMatricula = ListaEstudiantesMatriculados();
}

Grupo::Grupo(string pMateria, int pNumero, bool pEstatus, int pMaximo, int pMatriculados)
{
	this->materia = pMateria;
	this->numero = pNumero;
	this->estatus = pEstatus;
	this->maximo = pMaximo;
	this->matriculados = pMatriculados;
	this->listaMatricula = ListaEstudiantesMatriculados();
}

string Grupo::getMateria()
{
	return this->materia;
}

void Grupo::setMateria(string pMateria)
{
	this->materia = pMateria;
}

int Grupo::getNumero()
{
	return this->numero;
}

void Grupo::setNumero(int pNumero)
{
	this->numero = pNumero;
}

bool Grupo::getEstatus()
{
	return this->estatus;
}

void Grupo::setEstatus(bool pEstatus)
{
	this->estatus = pEstatus;
}

int Grupo::getMaximo()
{
	return this->maximo;
}

void Grupo::setMaximo(int pMaximo)
{
	this->maximo = pMaximo;
}

int Grupo::getMatriculados()
{
	return this->matriculados;
}

void Grupo::setMatriculados(int pMatriculados)
{
	this->matriculados = pMatriculados;
}

void Grupo::desplegar()
{
	cout << "Materia: " << this->materia << endl;
	cout << "Numero: " << this->numero << endl;
	if (this->estatus) {
		cout << "Estatus: Activo" << endl;
	}
	else {
		cout << "Estatus: Cerrado" << endl;
	}
	cout << "Maximo: " << this->maximo << endl;
	cout << "Matriculados: " << this->matriculados << endl;
}

ListaEstudiantesMatriculados Grupo::getListaMatricula()
{
    return listaMatricula;
}

void Grupo::setListaMatricula(ListaEstudiantesMatriculados listaMatricula)
{
    this->listaMatricula = listaMatricula;
}

