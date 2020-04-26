#pragma once
#include <string>
#include "NodoDE.h"
class EstudianteMatriculado
{
private:
	string cedula;
	int nota;
	NodoDE* estudiante;

public:
    EstudianteMatriculado();
    EstudianteMatriculado(string, int, NodoDE*);

    string getCedula();
    void setCedula(string cedula);

    int getNota();
    void setNota(int nota);

    NodoDE* getEstudiante();
    void setEstudiante(NodoDE* estudiante);

    void desplegar();

};

