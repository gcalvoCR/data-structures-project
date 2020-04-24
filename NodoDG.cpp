#include "NodoDG.h"

NodoDG::NodoDG()
{
	this->dato = Grupo();
	this->ante = NULL;
	this->sgte = NULL;
}

NodoDG::NodoDG(Grupo pDato)
{
	this->dato = pDato;
	this->ante = NULL;
	this->sgte = NULL;
}

Grupo NodoDG::getDato()
{
	return this->dato;
}

void NodoDG::setDato(Grupo pDato)
{
	this->dato = pDato;
}

NodoDG* NodoDG::getAnte()
{
	return this->ante;
}

void NodoDG::setAnte(NodoDG* pAnte)
{
	this->ante = pAnte;
}

NodoDG* NodoDG::getSgte()
{
	return this->sgte;
}

void NodoDG::setSgte(NodoDG* pSgte)
{
	this->sgte = pSgte;
}
