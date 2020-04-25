#pragma once
#include <string>
#include "NodoDE.h"
class EstudianteMatriculado
{
private:
	string cedula;
	string nota;
	NodoDE* estudiante;

public:
    EstudianteMatriculado();
    EstudianteMatriculado(string, string, NodoDE*);

    string getCedula();
    void setCedula(string cedula);

    string getNota();
    void setNota(string nota);

    NodoDE* getEstudiante();
    void setEstudiante(NodoDE* estudiante);

    void desplegar();

};

