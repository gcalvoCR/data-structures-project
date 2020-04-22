#include "NodoDE.h"

NodoDE::NodoDE()
{
	this->dato = Estudiante();
	this->ante = NULL;
	this->sgte = NULL;
}

NodoDE::NodoDE(Estudiante pDato)
{
	this->dato = pDato;
	this->ante = NULL;
	this->sgte = NULL;
}

Estudiante NodoDE::getDato()
{
	return this->dato;
}

void NodoDE::setDato(Estudiante pDato)
{
	this->dato = pDato;
}

NodoDE* NodoDE::getAnte()
{
	return this->ante;
}

void NodoDE::setAnte(NodoDE* pAnte)
{
	this->ante = pAnte;
}

NodoDE* NodoDE::getSgte()
{
	return this->sgte;
}

void NodoDE::setSgte(NodoDE* pSgte)
{
	this->sgte = pSgte;
}
