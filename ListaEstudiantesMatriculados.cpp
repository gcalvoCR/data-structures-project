#include "ListaEstudiantesMatriculados.h"
#include <iostream>


ListaEstudiantesMatriculados::ListaEstudiantesMatriculados()
{
	this->cab = NULL;
	this->largo = 0;
}

NodoDEM* ListaEstudiantesMatriculados::getCab()
{
	return this->cab;
}

void ListaEstudiantesMatriculados::setCab(NodoDEM* pCab)
{
	this->cab = pCab;
}

int ListaEstudiantesMatriculados::getLargo()
{
	return this->largo;
}

void ListaEstudiantesMatriculados::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoDEM* ListaEstudiantesMatriculados::buscarNodo(EstudianteMatriculado x)
{
	NodoDEM* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		if (this->getCab()->getDato().getCedula().compare(x.getCedula()) != 0) {
			do {
				aux = aux->getSgte();
			} while (aux != this->getCab() && aux->getDato().getCedula().compare(x.getCedula()) != 0);

			if (aux->getDato().getCedula().compare(x.getCedula()) != 0) {
				aux = NULL;
			}
		}
	}

	return aux;
}

NodoDEM* ListaEstudiantesMatriculados::nodoUltimo()
{
	NodoDEM* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux->getSgte() != this->getCab());
	}

	return aux;
}

NodoDEM* ListaEstudiantesMatriculados::nodoAnt(EstudianteMatriculado x)
{
	NodoDEM* aux = NULL;

	if (this->existe(x)) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux != this->getCab() && aux->getSgte()->getDato().getCedula().compare(x.getCedula()) != 0);
	}

	return aux;
}

NodoDEM* ListaEstudiantesMatriculados::nodoAnt(NodoDEM* dir)
{
	NodoDEM* aux = NULL;

	if (dir != NULL) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux != this->getCab() && aux->getSgte() != dir);

		if (aux->getSgte() != dir) {
			aux = NULL;
		}
	}

	return aux;
}

NodoDEM* ListaEstudiantesMatriculados::nodoPrimero()
{
	return this->getCab();
}

EstudianteMatriculado ListaEstudiantesMatriculados::demeDato(NodoDEM* dir)
{
	EstudianteMatriculado dato;

	if (dir != NULL) {
		dato = dir->getDato();
	}

	return dato;
}

void ListaEstudiantesMatriculados::borrarNodo(NodoDEM* dir)
{
	if (!this->esVacia()) {
		NodoDEM* aux = this->getCab();

		if (this->getCab() == dir) {
			this->getCab()->getSgte()->setAnte(this->getCab()->getAnte());
			this->getCab()->getAnte()->setSgte(this->getCab()->getSgte());

			this->setCab(this->getCab()->getSgte());

			delete aux;

			this->setLargo(this->getLargo() - 1);
		}
		else {
			do {
				aux = aux->getSgte();
			} while (aux != this->getCab() && aux != dir);

			if (aux == dir) {
				aux->getAnte()->setSgte(aux->getSgte());

				if (aux->getSgte() != NULL) {
					aux->getSgte()->setAnte(aux->getAnte());
				}

				delete aux;

				this->setLargo(this->getLargo() - 1);
			}
		}
	}
}

bool ListaEstudiantesMatriculados::esVacia()
{
	return this->getLargo() == 0;
}

int ListaEstudiantesMatriculados::cantidad()
{
	return this->getLargo();
}

EstudianteMatriculado ListaEstudiantesMatriculados::primero()
{
	EstudianteMatriculado valor;

	if (!this->esVacia()) {
		valor = this->getCab()->getDato();
	}

	return valor;
}

EstudianteMatriculado ListaEstudiantesMatriculados::ultimo()
{
	EstudianteMatriculado valor;

	if (!this->esVacia()) {
		valor = this->nodoUltimo()->getDato();
	}

	return valor;
}

int ListaEstudiantesMatriculados::posicion(EstudianteMatriculado x)
{
	int pos = -1;

	if (this->existe(x)) {
		pos = 0;

		if (this->getCab()->getDato().getCedula().compare(x.getCedula()) != 0) {
			NodoDEM* n = this->getCab();

			do {
				n = n->getSgte();

				pos++;
			} while (n != this->getCab() && n->getDato().getCedula().compare(x.getCedula()) != 0);
		}
	}

	return pos;
}

EstudianteMatriculado ListaEstudiantesMatriculados::demeDato(int pos)
{
	EstudianteMatriculado dato;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		NodoDEM* n = this->getCab();

		for (int i = 0; i != pos; i++) {
			n = n->getSgte();
		}

		dato = n->getDato();
	}

	return dato;
}

bool ListaEstudiantesMatriculados::existe(EstudianteMatriculado x)
{
	return this->buscarNodo(x) != NULL;
}

void ListaEstudiantesMatriculados::agregarInicio(EstudianteMatriculado x)
{
	NodoDEM* n = new NodoDEM(x);

	if (!this->esVacia()) {
		n->setSgte(this->getCab());
		n->setAnte(this->getCab()->getAnte());

		this->getCab()->getAnte()->setSgte(n);
		this->getCab()->setAnte(n);
	}
	else {
		n->setSgte(n);
		n->setAnte(n);
	}

	this->setCab(n);
	this->setLargo(this->getLargo() + 1);
}

void ListaEstudiantesMatriculados::agregarFinal(EstudianteMatriculado x)
{
	if (this->esVacia()) {
		this->agregarInicio(x);
	}
	else {
		NodoDEM* n = new NodoDEM(x);
		NodoDEM* ult = this->nodoUltimo();

		n->setAnte(ult);
		n->setSgte(this->getCab());

		ult->setSgte(n);
		this->getCab()->setAnte(n);

		this->setLargo(this->getLargo() + 1);
	}
}

bool ListaEstudiantesMatriculados::agregarEnPos(int pos, EstudianteMatriculado x)
{
	bool agregado = false;

	if (pos >= 0 && pos <= this->cantidad()) {
		if (pos == 0) {
			this->agregarInicio(x);
		}
		else if (pos == this->cantidad()) {
			this->agregarFinal(x);
		}
		else {
			NodoDEM* aux = this->getCab();
			NodoDEM* n = new NodoDEM(x);

			for (int i = 0; i < pos; i++) {
				aux = aux->getSgte();
			}

			n->setSgte(aux);
			n->setAnte(aux->getAnte());

			aux->getAnte()->setSgte(n);
			aux->setAnte(n);

			this->setLargo(this->getLargo() + 1);
		}

		agregado = true;
	}

	return agregado;
}

bool ListaEstudiantesMatriculados::agregarAntesDe(EstudianteMatriculado x, EstudianteMatriculado r)
{
	bool agregado = false;
	NodoDEM* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDEM* n = new NodoDEM(x);

		n->setSgte(aux);
		n->setAnte(aux->getAnte());

		aux->getAnte()->setSgte(n);
		aux->setAnte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);
	}

	return agregado;
}

bool ListaEstudiantesMatriculados::agregarDespuesDe(EstudianteMatriculado x, EstudianteMatriculado r)
{
	bool agregado = false;
	NodoDEM* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDEM* n = new NodoDEM(x);

		n->setSgte(aux->getSgte());
		n->setAnte(aux);

		aux->getSgte()->setAnte(n);
		aux->setSgte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);
	}

	return agregado;
}

bool ListaEstudiantesMatriculados::borrar(EstudianteMatriculado x)
{
	bool borrado = false;

	if (this->existe(x)) {
		this->borrarNodo(this->buscarNodo(x));

		borrado = true;
	}

	return borrado;
}

bool ListaEstudiantesMatriculados::borrarEnPos(int pos)
{
	bool borrado = false;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		if (pos == 0) {
			this->borrarNodo(this->nodoPrimero());
		}
		else if (pos == this->cantidad() - 1) {
			this->borrarNodo(this->nodoUltimo());
		}
		else {
			NodoDEM* aux = this->nodoPrimero();

			for (int i = 0; i < pos; i++) {
				aux = aux->getSgte();
			}

			this->borrarNodo(aux);
		}

		borrado = true;
	}

	return borrado;
}

void ListaEstudiantesMatriculados::limpiar()
{
	if (!this->esVacia()) {
		NodoDEM* aux = this->getCab();
		NodoDEM* sgte = NULL;

		do {
			sgte = aux->getSgte();

			delete aux;

			aux = sgte;
		} while (aux != this->getCab());

		this->setLargo(0);
	}
}

void ListaEstudiantesMatriculados::desplegar()
{
	if (!this->esVacia()) {
		NodoDEM* aux = this->getCab();

		for (int i = 0; i < this->cantidad(); i++) {
			cout << "Posicion " << i << ", Valor = {" << endl;
			aux->getDato().desplegar();
			cout << "}\n" << endl;

			aux = aux->getSgte();
		}
	}
}

EstudianteMatriculado ListaEstudiantesMatriculados::consultar(string pCedula)
{
	EstudianteMatriculado e = EstudianteMatriculado();
	NodoDEM* aux;

	e.setCedula(pCedula);

	aux = this->buscarNodo(e);

	if (aux != NULL) {
		return aux->getDato();
	}
	else {
		return e;
	}
}

bool ListaEstudiantesMatriculados::modificar(EstudianteMatriculado x)
{
	bool modificado = false;
	NodoDEM* aux = this->buscarNodo(x);

	if (aux != NULL) {
		//EstudianteMatriculado e = EstudianteMatriculado(x.getCedula(), x.getNota(), x.getEstudiante());

		aux->setDato(x);

		modificado = true;
	}

	return modificado;
}
