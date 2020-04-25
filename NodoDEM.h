#pragma once
#include "EstudianteMatriculado.h"

class NodoDEM
{
private:
	EstudianteMatriculado dato;
	NodoDEM* ante;
	NodoDEM* sgte;
public:

public:
    NodoDEM();
    NodoDEM(EstudianteMatriculado);

    EstudianteMatriculado getDato();
    void setDato(EstudianteMatriculado dato);

    NodoDEM* getAnte();
    void setAnte(NodoDEM* ante);

    NodoDEM* getSgte();
    void setSgte(NodoDEM* sgte);

};

