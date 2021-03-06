#include "ListaMaterias.h"

#include "MaestroEstudiantes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

NodoDM* ListaMaterias::getCab()
{
	return this->cab;
}

void ListaMaterias::setCab(NodoDM* pCab)
{
	this->cab = pCab;
}

int ListaMaterias::getLargo()
{
	return this->largo;
}

void ListaMaterias::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoDM* ListaMaterias::buscarNodo(Materia x)
{
	NodoDM* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		if (this->getCab()->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0) {
			do {
				aux = aux->getSgte();
			} while (aux != this->getCab() && aux->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0);

			if (aux->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0) {
				aux = NULL;
			}
		}
	}

	return aux;
}

NodoDM* ListaMaterias::nodoUltimo()
{
	NodoDM* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux->getSgte() != this->getCab());
	}

	return aux;
}

NodoDM* ListaMaterias::nodoAnt(Materia x)
{
	NodoDM* aux = NULL;

	if (this->existe(x)) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux != this->getCab() && aux->getSgte()->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0);
	}

	return aux;
}

NodoDM* ListaMaterias::nodoAnt(NodoDM* dir)
{
	NodoDM* aux = NULL;

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

NodoDM* ListaMaterias::nodoPrimero()
{
	return this->getCab();
}

Materia ListaMaterias::demeDato(NodoDM* dir)
{
	Materia dato;

	if (dir != NULL) {
		dato = dir->getDato();
	}

	return dato;
}

void ListaMaterias::borrarNodo(NodoDM* dir)
{
	if (!this->esVacia()) {
		NodoDM* aux = this->getCab();

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

void ListaMaterias::agregarAArchivo(Materia x)
{
	ofstream archivoMaterias;

	archivoMaterias.open("Materias.txt", ios::app);

	archivoMaterias << "Codigo:" << x.getCodigoMateria();
	archivoMaterias << ",Nombre:" << x.getNombre();
	archivoMaterias << ",Descripcion:" << x.getDescripcion() << endl;

	archivoMaterias.close();
}

void ListaMaterias::borrarDeArchivo(Materia x)
{
	string materia;
	ifstream archivoMaterias;
	ofstream temp;

	archivoMaterias.open("Materias.txt");
	temp.open("Temp.txt");

	while (getline(archivoMaterias, materia))
	{
		if (materia.find("Codigo:" + x.getCodigoMateria()) == std::string::npos) {
			temp << materia << endl;
		}
	}

	archivoMaterias.close();
	temp.close();

	remove("Materias.txt");
	rename("Temp.txt", "Materias.txt");
}

void ListaMaterias::modificarEnArchivo(Materia x)
{
	string materia;
	ifstream archivoMaterias;
	ofstream temp;

	archivoMaterias.open("Materias.txt");
	temp.open("Temp.txt");

	while (getline(archivoMaterias, materia))
	{
		if (materia.find("Codigo:" + x.getCodigoMateria()) != std::string::npos) {
			temp << "Codigo:" << x.getCodigoMateria();
			temp << ",Nombre:" << x.getNombre();
			temp << ",Descripcion:" << x.getDescripcion() << endl;
		}
		else {
			temp << materia << endl;
		}
	}

	archivoMaterias.close();
	temp.close();

	remove("Materias.txt");
	rename("Temp.txt", "Materias.txt");
}

ListaMaterias::ListaMaterias()
{
	string materia;
	ifstream archivoMaterias("Materias.txt");

	this->largo = 0;
	this->cab = NULL;

	if (archivoMaterias.is_open())
	{
		while (getline(archivoMaterias, materia))
		{
			stringstream ss(materia);
			string dato;
			Materia m;
			NodoDM* n;

			while (std::getline(ss, dato, ','))
			{
				if (dato.find("Codigo") != std::string::npos) {
					m.setCodigoMateria(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Nombre") != std::string::npos) {
					m.setNombre(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Descripcion") != std::string::npos) {
					m.setDescripcion(dato.substr(dato.find(":") + 1));
				}
			}

			m.setGrupos(ListaGrupos(m.getCodigoMateria()));

			n = new NodoDM(m);

			if (this->esVacia()) {
				n->setSgte(n);
				n->setAnte(n);

				this->setCab(n);
			}
			else {
				NodoDM* ult = this->nodoUltimo();

				n->setAnte(ult);
				n->setSgte(this->getCab());

				ult->setSgte(n);

				this->getCab()->setAnte(n);
			}

			this->setLargo(this->getLargo() + 1);
		}

		archivoMaterias.close();
	}
}

bool ListaMaterias::esVacia()
{
	return this->getLargo() == 0;
}

int ListaMaterias::cantidad()
{
	return this->getLargo();
}

Materia ListaMaterias::primero()
{
	Materia valor;

	if (!this->esVacia()) {
		valor = this->getCab()->getDato();
	}

	return valor;
}

Materia ListaMaterias::ultimo()
{
	Materia valor;

	if (!this->esVacia()) {
		valor = this->nodoUltimo()->getDato();
	}

	return valor;
}

int ListaMaterias::posicion(Materia x)
{
	int pos = -1;

	if (this->existe(x)) {
		pos = 0;

		if (this->getCab()->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0) {
			NodoDM* n = this->getCab();

			do {
				n = n->getSgte();

				pos++;
			} while (n != this->getCab() && n->getDato().getCodigoMateria().compare(x.getCodigoMateria()) != 0);
		}
	}

	return pos;
}

Materia ListaMaterias::demeDato(int pos)
{
	Materia dato;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		NodoDM* n = this->getCab();

		for (int i = 0; i != pos; i++) {
			n = n->getSgte();
		}

		dato = n->getDato();
	}

	return dato;
}

bool ListaMaterias::existe(Materia x)
{
	return this->buscarNodo(x) != NULL;
}

void ListaMaterias::agregarInicio(Materia x)
{
	NodoDM* n = new NodoDM(x);

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

	this->agregarAArchivo(x);
}

void ListaMaterias::agregarFinal(Materia x)
{
	if (this->esVacia()) {
		this->agregarInicio(x);
	}
	else {
		NodoDM* n = new NodoDM(x);
		NodoDM* ult = this->nodoUltimo();

		n->setAnte(ult);
		n->setSgte(this->getCab());

		ult->setSgte(n);
		this->getCab()->setAnte(n);

		this->setLargo(this->getLargo() + 1);

		this->agregarAArchivo(x);
	}
}

bool ListaMaterias::agregarEnPos(int pos, Materia x)
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
			NodoDM* aux = this->getCab();
			NodoDM* n = new NodoDM(x);

			for (int i = 0; i < pos; i++) {
				aux = aux->getSgte();
			}

			n->setSgte(aux);
			n->setAnte(aux->getAnte());

			aux->getAnte()->setSgte(n);
			aux->setAnte(n);

			this->setLargo(this->getLargo() + 1);

			this->agregarAArchivo(x);
		}

		agregado = true;
	}

	return agregado;
}

bool ListaMaterias::agregarAntesDe(Materia x, Materia r)
{
	bool agregado = false;
	NodoDM* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDM* n = new NodoDM(x);

		n->setSgte(aux);
		n->setAnte(aux->getAnte());

		aux->getAnte()->setSgte(n);
		aux->setAnte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);

		this->agregarAArchivo(x);
	}

	return agregado;
}

bool ListaMaterias::agregarDespuesDe(Materia x, Materia r)
{
	bool agregado = false;
	NodoDM* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDM* n = new NodoDM(x);

		n->setSgte(aux->getSgte());
		n->setAnte(aux);

		aux->getSgte()->setAnte(n);
		aux->setSgte(n);

		agregado = true;

		this->setLargo(this->getLargo() + 1);

		this->agregarAArchivo(x);
	}

	return agregado;
}

bool ListaMaterias::borrar(Materia x)
{
	bool borrado = false;

	if (this->existe(x)) {
		ListaGrupos lg = x.getGrupos();
		lg.limpiar();

		this->borrarNodo(this->buscarNodo(x));

		borrado = true;

		this->borrarDeArchivo(x);
	}

	return borrado;

}

bool ListaMaterias::borrarEnPos(int pos)
{
	bool borrado = false;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		if (pos == 0) {
			this->borrarDeArchivo(this->nodoPrimero()->getDato());

			this->borrarNodo(this->nodoPrimero());
		}
		else if (pos == this->cantidad() - 1) {
			this->borrarDeArchivo(this->nodoUltimo()->getDato());

			this->borrarNodo(this->nodoUltimo());
		}
		else {
			NodoDM* aux = this->nodoPrimero();

			for (int i = 0; i < pos; i++) {
				aux = aux->getSgte();
			}

			this->borrarDeArchivo(aux->getDato());

			this->borrarNodo(aux);
		}

		borrado = true;
	}

	return borrado;
}

void ListaMaterias::limpiar()
{
	if (!this->esVacia()) {
		NodoDM* aux = this->getCab();
		NodoDM* sgte = NULL;

		do {
			sgte = aux->getSgte();

			delete aux;

			aux = sgte;
		} while (aux != this->getCab());

		this->setLargo(0);

		remove("Materias.txt");
	}
}

void ListaMaterias::desplegar()
{
	if (!this->esVacia()) {
		NodoDM* aux = this->getCab();

		for (int i = 0; i < this->cantidad(); i++) {
			cout << "Posicion " << i << ", Valor = {" << endl;
			aux->getDato().desplegar();
			cout << "}\n" << endl;

			aux = aux->getSgte();
		}
	}
}

Materia ListaMaterias::consultar(string pCodigoMateria)
{
	Materia e = Materia();
	NodoDM* aux;

	e.setCodigoMateria(pCodigoMateria);

	aux = this->buscarNodo(e);

	if (aux != NULL) {
		return aux->getDato();
	}
	else {
		return e;
	}
}

bool ListaMaterias::modificar(Materia x)
{
	bool modificado = false;
	NodoDM* aux = this->buscarNodo(x);

	if (aux != NULL) {
		aux->setDato(x);

		modificado = true;

		this->modificarEnArchivo(x);
	}

	return modificado;
}
