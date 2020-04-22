#pragma once
#include "Estudiante.h"
class NodoDE
{
private:
	Estudiante dato;
	NodoDE* ante;
	NodoDE* sgte;
public:
	NodoDE();
	NodoDE(Estudiante);
	Estudiante getDato();
	void setDato(Estudiante);
	NodoDE* getAnte();
	void setAnte(NodoDE*);
	NodoDE* getSgte();
	void setSgte(NodoDE*);
};

