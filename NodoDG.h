#pragma once
#include "Grupo.h"
class NodoDG
{
private:
	Grupo dato;
	NodoDG* ante;
	NodoDG* sgte;
public:
	NodoDG();
	NodoDG(Grupo);
	Grupo getDato();
	void setDato(Grupo);
	NodoDG* getAnte();
	void setAnte(NodoDG*);
	NodoDG* getSgte();
	void setSgte(NodoDG*);
};

