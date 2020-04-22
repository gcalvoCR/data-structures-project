#pragma once
#include <string>
using namespace std;
class Estudiante
{
private:
	string cedula;
	string nombre;
	string celular;
	string correo;
	bool activo;
public:
	Estudiante();
	Estudiante(string, string, string, string, bool);
	string getCedula();
	void setCedula(string);
	string getNombre();
	void setNombre(string);
	string getCelular();
	void setCelular(string);
	string getCorreo();
	void setCorreo(string);
	bool isActivo();
	void setActivo(bool);
	void desplegar();
};

