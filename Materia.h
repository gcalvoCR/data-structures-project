#pragma once
#include <string>
using namespace std;
class Materia
{
private:
	string codigoMateria;
	string nombre;
	string descripcion;

public:
    Materia();
    Materia(string codigoMateria, string nombre, string descripcion);

    string getCodigoMateria();
    void setCodigoMateria(string codigoMateria);

    string getNombre();
    void setNombre(string nombre);

    string getDescripcion();
    void setDescripcion(string descripcion);

    void desplegar();

};



