#pragma once
#include <string>
#include "NodoDE.h"
class EstudianteMatriculado
{
private:
	string cedula;
	int nota;
	NodoDE* estudiante;
	string materia;
	int grupo;

public:
    EstudianteMatriculado();
    EstudianteMatriculado(string, int, NodoDE*, string, int);

    string getCedula();
    void setCedula(string cedula);

    int getNota();
    void setNota(int nota);

    NodoDE* getEstudiante();
    void setEstudiante(NodoDE* estudiante);

	string getMateria();
	void setMateria(string materia);

	int getGrupo();
	void setGrupo(int grupo);

    void desplegar();

};

