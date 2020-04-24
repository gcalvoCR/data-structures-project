#include "ListaGrupos.h"
#include <iostream>

NodoDG* ListaGrupos::getCab()
{
	return this->cab;
}

void ListaGrupos::setCab(NodoDG* pCab)
{
	this->cab = pCab;
}

int ListaGrupos::getLargo()
{
	return this->largo;
}

void ListaGrupos::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoDG* ListaGrupos::buscarNodo(Grupo x)
{
	NodoDG* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		if (this->getCab()->getDato().getNumero() != x.getNumero()) {
			do {
				aux = aux->getSgte();
			} while (aux != this->getCab() && aux->getDato().getNumero() != x.getNumero());

			if (aux->getDato().getNumero() != x.getNumero()) {
				aux = NULL;
			}
		}
	}

	return aux;
}

NodoDG* ListaGrupos::nodoUltimo()
{
	NodoDG* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux->getSgte() != this->getCab());
	}

	return aux;
}

NodoDG* ListaGrupos::nodoAnt(Grupo x)
{
	NodoDG* aux = NULL;

	if (this->existe(x)) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux != this->getCab() && aux->getSgte()->getDato().getNumero() != x.getNumero());
	}

	return aux;
}

NodoDG* ListaGrupos::nodoAnt(NodoDG* dir)
{
	NodoDG* aux = NULL;

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

NodoDG* ListaGrupos::nodoPrimero()
{
	return this->getCab();
}

Grupo ListaGrupos::demeDato(NodoDG* dir)
{
	Grupo dato;

	if (dir != NULL) {
		dato = dir->getDato();
	}

	return dato;
}

void ListaGrupos::borrarNodo(NodoDG* dir)
{
	if (!this->esVacia()) {
		NodoDG* aux = this->getCab();

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

ListaGrupos::ListaGrupos()
{
	this->cab = NULL;
	this->largo = 0;
}

bool ListaGrupos::esVacia()
{
	return this->getLargo() == 0;
}

int ListaGrupos::cantidad()
{
	return this->getLargo();
}

Grupo ListaGrupos::primero()
{
	Grupo valor;

	if (!this->esVacia()) {
		valor = this->getCab()->getDato();
	}

	return valor;
}

Grupo ListaGrupos::ultimo()
{
	Grupo valor;

	if (!this->esVacia()) {
		valor = this->nodoUltimo()->getDato();
	}

	return valor;
}

int ListaGrupos::posicion(Grupo x)
{
	int pos = -1;

	if (this->existe(x)) {
		pos = 0;

		if (this->getCab()->getDato().getNumero() != x.getNumero()) {
			NodoDG* n = this->getCab();

			do {
				n = n->getSgte();

				pos++;
			} while (n != this->getCab() && n->getDato().getNumero() != x.getNumero());
		}
	}

	return pos;
}

Grupo ListaGrupos::demeDato(int pos)
{
	Grupo dato;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		NodoDG* n = this->getCab();

		for (int i = 0; i != pos; i++) {
			n = n->getSgte();
		}

		dato = n->getDato();
	}

	return dato;
}

bool ListaGrupos::existe(Grupo x)
{
	return this->buscarNodo(x) != NULL;
}

void ListaGrupos::agregarInicio(Grupo x)
{
	NodoDG* n = new NodoDG(x);

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

void ListaGrupos::agregarFinal(Grupo x)
{
	if (this->esVacia()) {
		this->agregarInicio(x);
	}
	else {
		NodoDG* n = new NodoDG(x);
		NodoDG* ult = this->nodoUltimo();

		n->setAnte(ult);
		n->setSgte(this->getCab());

		ult->setSgte(n);
		this->getCab()->setAnte(n);

		this->setLargo(this->getLargo() + 1);
	}
}

bool ListaGrupos::agregarEnPos(int pos, Grupo x)
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
			NodoDG* aux = this->getCab();
			NodoDG* n = new NodoDG(x);

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

bool ListaGrupos::agregarAntesDe(Grupo x, Grupo r)
{
	bool agregado = false;
	NodoDG* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDG* n = new NodoDG(x);

		n->setSgte(aux);
		n->setAnte(aux->getAnte());

		aux->getAnte()->setSgte(n);
		aux->setAnte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);
	}

	return agregado;
}

bool ListaGrupos::agregarDespuesDe(Grupo x, Grupo r)
{
	bool agregado = false;
	NodoDG* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDG* n = new NodoDG(x);

		n->setSgte(aux->getSgte());
		n->setAnte(aux);

		aux->getSgte()->setAnte(n);
		aux->setSgte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);
	}

	return agregado;
}

bool ListaGrupos::borrar(Grupo x)
{
	bool borrado = false;

	if (this->existe(x)) {
		this->borrarNodo(this->buscarNodo(x));

		borrado = true;
	}

	return borrado;
}

bool ListaGrupos::borrarEnPos(int pos)
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
			NodoDG* aux = this->nodoPrimero();

			for (int i = 0; i < pos; i++) {
				aux = aux->getSgte();
			}

			this->borrarNodo(aux);
		}

		borrado = true;
	}

	return borrado;
}

void ListaGrupos::limpiar()
{
	if (!this->esVacia()) {
		NodoDG* aux = this->getCab();
		NodoDG* sgte = NULL;

		do {
			sgte = aux->getSgte();

			delete aux;

			aux = sgte;
		} while (aux != this->getCab());

		this->setLargo(0);
	}
}

void ListaGrupos::desplegar()
{
	if (!this->esVacia()) {
		NodoDG* aux = this->getCab();

		for (int i = 0; i < this->cantidad(); i++) {
			cout << "Posicion " << i << ", Valor = {" << endl;
			aux->getDato().desplegar();
			cout << "}\n" << endl;

			aux = aux->getSgte();
		}
	}
}

Grupo ListaGrupos::consultar(int pNumero)
{
	Grupo g = Grupo();
	NodoDG* aux;

	g.setNumero(pNumero);

	aux = this->buscarNodo(g);

	if (aux != NULL) {
		return aux->getDato();
	}
	else {
		return g;
	}
}

bool ListaGrupos::modificar(Grupo x)
{
	bool modificado = false;
	NodoDG* aux = this->buscarNodo(x);

	if (aux != NULL) {
		Grupo g = Grupo(x.getMateria(), x.getNumero(), x.getEstatus(), x.getMaximo(), x.getMatriculados());

		aux->setDato(g);

		modificado = true;
	}

	return modificado;
}
