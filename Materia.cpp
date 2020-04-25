#include "Materia.h"
#include <iostream>

Materia::Materia()
{
    this->codigoMateria = " ";
    this->nombre = " ";
    this->descripcion = " ";
    this->grupos = ListaGrupos();
}

Materia::Materia(string codigoMateria, string nombre, string descripcion, ListaGrupos plistaGrupos)
{
    this->codigoMateria = codigoMateria;
    this->nombre = nombre;
    this->descripcion = descripcion;
	this->grupos = plistaGrupos;
}

string Materia::getCodigoMateria()
{
    return codigoMateria;
}

void Materia::setCodigoMateria(string codigoMateria)
{
    this->codigoMateria = codigoMateria;
}

string Materia::getNombre()
{
    return nombre;
}

void Materia::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Materia::getDescripcion()
{
    return descripcion;
}

void Materia::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

ListaGrupos Materia::getGrupos()
{
	return this->grupos;
}

void Materia::setGrupos(ListaGrupos grupos)
{
	this->grupos = grupos;
}

void Materia::desplegar()
{
    cout << "Codigo: " << this->codigoMateria << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Descripcion: " << this->descripcion << endl;

}

