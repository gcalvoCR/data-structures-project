#include "EstudianteMatriculado.h"
#include <iostream>

EstudianteMatriculado::EstudianteMatriculado()
{
}

EstudianteMatriculado::EstudianteMatriculado(string pcedula, int pnota, NodoDE* pestudiante, string pmateria, int pgrupo)
{
	this->cedula = pcedula;
	this->nota = pnota;
	this->estudiante = pestudiante;
	this->materia = pmateria;
	this->grupo = pgrupo;
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

string EstudianteMatriculado::getMateria()
{
	return this->materia;
}

void EstudianteMatriculado::setMateria(string materia)
{
	this->materia = materia;
}

int EstudianteMatriculado::getGrupo()
{
	return this->grupo;
}

void EstudianteMatriculado::setGrupo(int grupo)
{
	this->grupo = grupo;
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

