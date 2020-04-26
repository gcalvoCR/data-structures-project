#pragma once
#include <string>
#include "ListaGrupos.h"
using namespace std;
class Materia
{
private:
	string codigoMateria;
	string nombre;
	string descripcion;
	ListaGrupos grupos;

public:
	Materia();
	Materia(string codigoMateria, string nombre, string descripcion, ListaGrupos);

	string getCodigoMateria();
	void setCodigoMateria(string codigoMateria);

	string getNombre();
	void setNombre(string nombre);

	string getDescripcion();
	void setDescripcion(string descripcion);

	ListaGrupos getGrupos();
	void setGrupos(ListaGrupos grupos);

	void desplegar();

};



