#include "NodoDM.h"

NodoDM::NodoDM()
{
	this->dato = Materia();
	this->ante = NULL;
	this->sgte = NULL;
}

NodoDM::NodoDM(Materia pDato)
{
	this->dato = pDato;
	this->ante = NULL;
	this->sgte = NULL;
}

Materia NodoDM::getDato()
{
	return this->dato;
}

void NodoDM::setDato(Materia pDato)
{
	this->dato = pDato;
}

NodoDM* NodoDM::getAnte()
{
	return this->ante;
}

void NodoDM::setAnte(NodoDM* pAnte)
{
	this->ante = pAnte;
}

NodoDM* NodoDM::getSgte()
{
	return this->sgte;
}

void NodoDM::setSgte(NodoDM* pSgte)
{
	this->sgte = pSgte;
}
