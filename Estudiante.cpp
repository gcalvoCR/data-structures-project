#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante()
{
	this->cedula = " ";
	this->nombre = " ";
	this->celular = " ";
	this->correo = " ";
	this->activo = false;
}

Estudiante::Estudiante(string pCedula, string pNombre, string pCelular, string pCorreo, bool pActivo)
{
	this->cedula = pCedula;
	this->nombre = pNombre;
	this->celular = pCelular;
	this->correo = pCorreo;
	this->activo = pActivo;
}

string Estudiante::getCedula()
{
	return this->cedula;
}

void Estudiante::setCedula(string pCedula)
{
	this->cedula = pCedula;
}

string Estudiante::getNombre()
{
	return this->nombre;
}

void Estudiante::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

string Estudiante::getCelular()
{
	return this->celular;
}

void Estudiante::setCelular(string pCelular)
{
	this->celular = pCelular;
}

string Estudiante::getCorreo()
{
	return this->correo;
}

void Estudiante::setCorreo(string pCorreo)
{
	this->correo = pCorreo;
}

bool Estudiante::isActivo()
{
	return this->activo;
}

void Estudiante::setActivo(bool pActivo)
{
	this->activo = pActivo;
}

void Estudiante::desplegar()
{
	cout << "Cedula: " << this->cedula << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Celular: " << this->celular << endl;
	cout << "Correo: " << this->correo << endl;
	cout << "Activo: " << this->activo << endl;
}
