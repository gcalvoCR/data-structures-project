#pragma once
#include "Materia.h"
class NodoDM
{
private:
	Materia dato;
	NodoDM* ante;
	NodoDM* sgte;

public:
	NodoDM();
	NodoDM(Materia);
	Materia getDato();
	void setDato(Materia);
	NodoDM* getAnte();
	void setAnte(NodoDM*);
	NodoDM* getSgte();
	void setSgte(NodoDM*);

};


