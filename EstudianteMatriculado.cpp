#include "EstudianteMatriculado.h"
#include <iostream>

EstudianteMatriculado::EstudianteMatriculado()
{
}

EstudianteMatriculado::EstudianteMatriculado(string pcedula, int pnota, NodoDE* pestudiante)
{
	this->cedula = pcedula;
	this->nota = pnota;
	this->estudiante = pestudiante;
}

string EstudianteMatriculado::getCedula()
{
	return cedula;
}

void EstudianteMatriculado::setCedula(string cedula)
{
	this->cedula = cedula;
}

int EstudianteMatriculado::getNota()
{
	return nota;
}

void EstudianteMatriculado::setNota(int nota)
{
	this->nota = nota;
}

NodoDE* EstudianteMatriculado::getEstudiante()
{
	return estudiante;
}

void EstudianteMatriculado::setEstudiante(NodoDE* estudiante)
{
	this->estudiante = estudiante;
}

void EstudianteMatriculado::desplegar()
{

	cout << "Cedula: " << this->estudiante->getDato().getCedula() << endl;
	cout << "Nombre: " << this->estudiante->getDato().getNombre() << endl;
	cout << "Celular: " << this->estudiante->getDato().getCelular() << endl;
	cout << "Correo: " << this->estudiante->getDato().getCorreo() << endl;
	cout << "Activo: " << this->estudiante->getDato().isActivo() << endl;

	cout << "Nota: " << this->nota << endl;
}

