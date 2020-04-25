#include "NodoDEM.h"
#include <cstddef>

NodoDEM::NodoDEM()
{
    this->dato = EstudianteMatriculado();
    this->ante = NULL;
    this->sgte = NULL;
}

NodoDEM::NodoDEM(EstudianteMatriculado pDato)
{
	this->dato = pDato;
	this->ante = NULL;
	this->sgte = NULL;
}

EstudianteMatriculado NodoDEM::getDato()
{
    return dato;
}

void NodoDEM::setDato(EstudianteMatriculado dato)
{
    this->dato = dato;
}

NodoDEM* NodoDEM::getAnte()
{
    return ante;
}

void NodoDEM::setAnte(NodoDEM* ante)
{
    this->ante = ante;
}

NodoDEM* NodoDEM::getSgte()
{
    return sgte;
}

void NodoDEM::setSgte(NodoDEM* sgte)
{
    this->sgte = sgte;
}

