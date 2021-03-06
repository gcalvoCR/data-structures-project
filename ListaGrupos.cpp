#include "ListaGrupos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

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
			if (this->getLargo() > 1) {
				this->getCab()->getSgte()->setAnte(this->getCab()->getAnte());
				this->getCab()->getAnte()->setSgte(this->getCab()->getSgte());

				this->setCab(this->getCab()->getSgte());
			}
			else {
				this->setCab(NULL);
			}

			ListaEstudiantesMatriculados lEM = dir->getDato().getListaMatricula();
			lEM.limpiar();

			dir->getDato().setListaMatricula(lEM);

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

				ListaEstudiantesMatriculados lEM = dir->getDato().getListaMatricula();
				lEM.limpiar();

				dir->getDato().setListaMatricula(lEM);

				delete aux;

				this->setLargo(this->getLargo() - 1);
			}
		}
	}
}

void ListaGrupos::agregarAArchivo(Grupo x)
{
	ofstream archivoGrupos;

	archivoGrupos.open("Grupos.txt", ios::app);

	archivoGrupos << "Materia:" << x.getMateria();
	archivoGrupos << ",Numero:" << x.getNumero();
	archivoGrupos << ",Estatus:" << x.getEstatus();
	archivoGrupos << ",Maximo:" << x.getMaximo();
	archivoGrupos << ",Matriculados:" << x.getMatriculados() << endl;

	archivoGrupos.close();
}

void ListaGrupos::borrarDeArchivo(Grupo x)
{
	string grupo;
	ifstream archivoGrupos;
	ofstream temp;

	archivoGrupos.open("Grupos.txt");
	temp.open("Temp.txt");

	while (getline(archivoGrupos, grupo))
	{
		if (!(grupo.find("Materia:" + x.getMateria()) != std::string::npos && grupo.find("Numero:" + x.getNumero()) != std::string::npos)) {
			temp << grupo << endl;
		}
	}

	archivoGrupos.close();
	temp.close();

	remove("Grupos.txt");
	rename("Temp.txt", "Grupos.txt");
}

void ListaGrupos::modificarEnArchivo(Grupo x)
{
	string grupo;
	ifstream archivoGrupos;
	ofstream temp;

	archivoGrupos.open("Grupos.txt");
	temp.open("Temp.txt");

	while (getline(archivoGrupos, grupo))
	{
		if (grupo.find("Materia:" + x.getMateria()) != std::string::npos && grupo.find("Numero:" + x.getNumero()) != std::string::npos) {
			temp << "Materia:" << x.getMateria();
			temp << ",Numero:" << x.getNumero();
			temp << ",Estatus:" << x.getEstatus();
			temp << ",Maximo:" << x.getMaximo();
			temp << ",Matriculados:" << x.getMatriculados() << endl;
		}
		else {
			temp << grupo << endl;
		}
	}

	archivoGrupos.close();
	temp.close();

	remove("Grupos.txt");
	rename("Temp.txt", "Grupos.txt");
}

ListaGrupos::ListaGrupos()
{
	string grupo;
	ifstream archivoGrupos("Grupos.txt");

	this->largo = 0;
	this->cab = NULL;

	if (archivoGrupos.is_open())
	{
		while (getline(archivoGrupos, grupo))
		{
			stringstream ss(grupo);
			string dato;
			Grupo g;
			NodoDG* n;

			while (std::getline(ss, dato, ','))
			{
				if (dato.find("Materia") != std::string::npos) {
					g.setMateria(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Numero") != std::string::npos) {
					int numero;
					std::istringstream(dato.substr(dato.find(":") + 1)) >> numero;
					g.setNumero(numero);
				}
				else if (dato.find("Estatus") != std::string::npos) {
					bool estatus;
					std::istringstream(dato.substr(dato.find(":") + 1)) >> estatus;
					g.setEstatus(estatus);
				}
				else if (dato.find("Maximo") != std::string::npos) {
					int maximo;
					std::istringstream(dato.substr(dato.find(":") + 1)) >> maximo;
					g.setMaximo(maximo);
				}
				else if (dato.find("Matriculados") != std::string::npos) {
					int matriculados;
					std::istringstream(dato.substr(dato.find(":") + 1)) >> matriculados;
					g.setMatriculados(matriculados);
				}
			}

			n = new NodoDG(g);

			if (this->esVacia()) {
				n->setSgte(n);
				n->setAnte(n);

				this->setCab(n);
			}
			else {
				NodoDG* ult = this->nodoUltimo();

				n->setAnte(ult);
				n->setSgte(this->getCab());

				ult->setSgte(n);

				this->getCab()->setAnte(n);
			}

			this->setLargo(this->getLargo() + 1);
		}

		archivoGrupos.close();
	}
}

ListaGrupos::ListaGrupos(string pMateria)
{
	string grupo;
	ifstream archivoGrupos("Grupos.txt");

	this->largo = 0;
	this->cab = NULL;

	if (archivoGrupos.is_open())
	{
		while (getline(archivoGrupos, grupo))
		{
			stringstream ss(grupo);
			string dato;
			Grupo g;
			NodoDG* n;

			while (std::getline(ss, dato, ','))
			{
				if (grupo.find("Materia:" + pMateria) != std::string::npos) {
					if (dato.find("Materia") != std::string::npos) {
						g.setMateria(dato.substr(dato.find(":") + 1));
					}
					else if (dato.find("Numero") != std::string::npos) {
						int numero;
						std::istringstream(dato.substr(dato.find(":") + 1)) >> numero;
						g.setNumero(numero);
					}
					else if (dato.find("Estatus") != std::string::npos) {
						bool estatus;
						std::istringstream(dato.substr(dato.find(":") + 1)) >> estatus;
						g.setEstatus(estatus);
					}
					else if (dato.find("Maximo") != std::string::npos) {
						int maximo;
						std::istringstream(dato.substr(dato.find(":") + 1)) >> maximo;
						g.setMaximo(maximo);
					}
					else if (dato.find("Matriculados") != std::string::npos) {
						int matriculados;
						std::istringstream(dato.substr(dato.find(":") + 1)) >> matriculados;
						g.setMatriculados(matriculados);
					}
				}
			}

			if (g.getMateria() == pMateria) {
				g.setListaMatricula(ListaEstudiantesMatriculados(g.getMateria(), g.getNumero()));

				n = new NodoDG(g);

				if (this->esVacia()) {
					n->setSgte(n);
					n->setAnte(n);

					this->setCab(n);
				}
				else {
					NodoDG* ult = this->nodoUltimo();

					n->setAnte(ult);
					n->setSgte(this->getCab());

					ult->setSgte(n);

					this->getCab()->setAnte(n);
				}

				this->setLargo(this->getLargo() + 1);
			}
		}

		archivoGrupos.close();
	}
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

	this->agregarAArchivo(x);
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

		this->agregarAArchivo(x);
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

			this->agregarAArchivo(x);
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

		this->agregarAArchivo(x);
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

		this->agregarAArchivo(x);
	}

	return agregado;
}

bool ListaGrupos::borrar(Grupo x)
{
	bool borrado = false;

	if (this->existe(x)) {
		this->borrarNodo(this->buscarNodo(x));

		borrado = true;

		this->borrarDeArchivo(x);
	}

	return borrado;
}

bool ListaGrupos::borrarEnPos(int pos)
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
			NodoDG* aux = this->nodoPrimero();

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

void ListaGrupos::limpiar()
{
	if (!this->esVacia()) {
		NodoDG* aux = this->getCab();
		NodoDG* sgte = NULL;

		do {
			sgte = aux->getSgte();

			this->borrarDeArchivo(aux->getDato());

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
		aux->setDato(x);

		modificado = true;

		this->modificarEnArchivo(x);
	}

	return modificado;
}
