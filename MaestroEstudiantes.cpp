#include "MaestroEstudiantes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

NodoDE* MaestroEstudiantes::getCab()
{
	return this->cab;
}

void MaestroEstudiantes::setCab(NodoDE* pCab)
{
	this->cab = pCab;
}

int MaestroEstudiantes::getLargo()
{
	return this->largo;
}

void MaestroEstudiantes::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoDE* MaestroEstudiantes::buscarNodo(Estudiante x)
{
	NodoDE* aux = NULL;

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

NodoDE* MaestroEstudiantes::nodoUltimo()
{
	NodoDE* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux->getSgte() != this->getCab());
	}

	return aux;
}

NodoDE* MaestroEstudiantes::nodoAnt(Estudiante x)
{
	NodoDE* aux = NULL;

	if (this->existe(x)) {
		aux = this->getCab();

		do {
			aux = aux->getSgte();
		} while (aux != this->getCab() && aux->getSgte()->getDato().getCedula().compare(x.getCedula()) != 0);
	}

	return aux;
}

NodoDE* MaestroEstudiantes::nodoAnt(NodoDE* dir)
{
	NodoDE* aux = NULL;

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

NodoDE* MaestroEstudiantes::nodoPrimero()
{
	return this->getCab();
}

Estudiante MaestroEstudiantes::demeDato(NodoDE* dir)
{
	Estudiante dato;

	if (dir != NULL) {
		dato = dir->getDato();
	}

	return dato;
}

void MaestroEstudiantes::borrarNodo(NodoDE* dir)
{
	if (!this->esVacia()) {
		NodoDE* aux = this->getCab();

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

void MaestroEstudiantes::agregarAArchivo(Estudiante x)
{
	ofstream archivoEstudiantes;

	archivoEstudiantes.open("Estudiantes.txt", ios::app);

	archivoEstudiantes << "Cedula:" << x.getCedula();
	archivoEstudiantes << ",Nombre:" << x.getNombre();
	archivoEstudiantes << ",Celular:" << x.getCelular();
	archivoEstudiantes << ",Correo:" << x.getCorreo();
	archivoEstudiantes << ",Activo:" << x.isActivo() << endl;

	archivoEstudiantes.close();
}

void MaestroEstudiantes::borrarDeArchivo(Estudiante x)
{
	string estudiante;
	ifstream archivoEstudiantes;
	ofstream temp;

	archivoEstudiantes.open("Estudiantes.txt");
	temp.open("Temp.txt");

	while (getline(archivoEstudiantes, estudiante))
	{
		if (estudiante.find("Cedula:" + x.getCedula()) == std::string::npos) {
			temp << estudiante << endl;
		}
	}

	archivoEstudiantes.close();
	temp.close();

	remove("Estudiantes.txt");
	rename("Temp.txt", "Estudiantes.txt");
}

MaestroEstudiantes::MaestroEstudiantes()
{
	string estudiante;
	ifstream archivoEstudiantes("Estudiantes.txt");

	this->largo = 0;
	this->cab = NULL;

	if (archivoEstudiantes.is_open())
	{
		while (getline(archivoEstudiantes, estudiante))
		{
			stringstream ss(estudiante);
			string dato;
			Estudiante e;
			NodoDE* n;

			while (std::getline(ss, dato, ','))
			{
				if (dato.find("Cedula") != std::string::npos) {
					e.setCedula(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Nombre") != std::string::npos) {
					e.setNombre(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Celular") != std::string::npos) {
					e.setCelular(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Correo") != std::string::npos) {
					e.setCorreo(dato.substr(dato.find(":") + 1));
				}
				else if (dato.find("Activo") != std::string::npos) {
					bool activo;
					std::istringstream(dato.substr(dato.find(":") + 1)) >> activo;
					e.setActivo(activo);
				}
			}

			n = new NodoDE(e);

			if (this->esVacia()) {
				n->setSgte(n);
				n->setAnte(n);

				this->setCab(n);
			}
			else {
				NodoDE* ult = this->nodoUltimo();

				n->setAnte(ult);
				n->setSgte(this->getCab());

				ult->setSgte(n);

				this->getCab()->setAnte(n);
			}

			this->setLargo(this->getLargo() + 1);
		}

		archivoEstudiantes.close();
	}
}

bool MaestroEstudiantes::esVacia()
{
	return this->getLargo() == 0;
}

int MaestroEstudiantes::cantidad()
{
	return this->getLargo();
}

Estudiante MaestroEstudiantes::primero()
{
	Estudiante valor;

	if (!this->esVacia()) {
		valor = this->getCab()->getDato();
	}

	return valor;
}

Estudiante MaestroEstudiantes::ultimo()
{
	Estudiante valor;

	if (!this->esVacia()) {
		valor = this->nodoUltimo()->getDato();
	}

	return valor;
}

int MaestroEstudiantes::posicion(Estudiante x)
{
	int pos = -1;

	if (this->existe(x)) {
		pos = 0;

		if (this->getCab()->getDato().getCedula().compare(x.getCedula()) != 0) {
			NodoDE* n = this->getCab();

			do {
				n = n->getSgte();

				pos++;
			} while (n != this->getCab() && n->getDato().getCedula().compare(x.getCedula()) != 0);
		}
	}

	return pos;
}

Estudiante MaestroEstudiantes::demeDato(int pos)
{
	Estudiante dato;

	if (!this->esVacia() && pos >= 0 && pos < this->cantidad()) {
		NodoDE* n = this->getCab();

		for (int i = 0; i != pos; i++) {
			n = n->getSgte();
		}

		dato = n->getDato();
	}

	return dato;
}

bool MaestroEstudiantes::existe(Estudiante x)
{
	return this->buscarNodo(x) != NULL;
}

void MaestroEstudiantes::agregarInicio(Estudiante x)
{
	NodoDE* n = new NodoDE(x);

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

void MaestroEstudiantes::agregarFinal(Estudiante x)
{
	if (this->esVacia()) {
		this->agregarInicio(x);
	}
	else {
		NodoDE* n = new NodoDE(x);
		NodoDE* ult = this->nodoUltimo();

		n->setAnte(ult);
		n->setSgte(this->getCab());

		ult->setSgte(n);
		this->getCab()->setAnte(n);

		this->setLargo(this->getLargo() + 1);

		this->agregarAArchivo(x);
	}
}

int main()
{
	MaestroEstudiantes m;
	Estudiante e;

	m.desplegar();

	e.setCedula("123456789");

	m.borrar(e);

	m.desplegar();
}

bool MaestroEstudiantes::agregarEnPos(int pos, Estudiante x)
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
			NodoDE* aux = this->getCab();
			NodoDE* n = new NodoDE(x);

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

bool MaestroEstudiantes::agregarAntesDe(Estudiante x, Estudiante r)
{
	bool agregado = false;
	NodoDE* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDE* n = new NodoDE(x);

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

bool MaestroEstudiantes::agregarDespuesDe(Estudiante x, Estudiante r)
{
	bool agregado = false;
	NodoDE* aux = this->buscarNodo(r);

	if (aux != NULL) {
		NodoDE* n = new NodoDE(x);

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

bool MaestroEstudiantes::borrar(Estudiante x)
{
	bool borrado = false;

	if (this->existe(x)) {
		this->borrarNodo(this->buscarNodo(x));

		borrado = true;

		this->borrarDeArchivo(x);
	}

	return borrado;
}

bool MaestroEstudiantes::borrarEnPos(int pos)
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
			NodoDE* aux = this->nodoPrimero();

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

void MaestroEstudiantes::limpiar()
{
	if (!this->esVacia()) {
		NodoDE* aux = this->getCab();
		NodoDE* sgte = NULL;

		do {
			sgte = aux->getSgte();

			delete aux;

			aux = sgte;
		} while (aux != this->getCab());

		this->setLargo(0);

		remove("Estudiantes.txt");
	}
}

void MaestroEstudiantes::desplegar()
{
	if (!this->esVacia()) {
		NodoDE* aux = this->getCab();

		for (int i = 0; i < this->cantidad(); i++) {
			cout << "Posicion " << i << ", Valor = {" << endl;
			aux->getDato().desplegar();
			cout << "}\n" << endl;

			aux = aux->getSgte();
		}
	}
}

Estudiante MaestroEstudiantes::consultar(string pCedula)
{
	Estudiante e = Estudiante();
	NodoDE* aux;

	e.setCedula(pCedula);

	aux = this->buscarNodo(e);

	if (aux != NULL) {
		return aux->getDato();
	}
	else {
		return e;
	}
}

bool MaestroEstudiantes::modificar(Estudiante x)
{
	bool modificado = false;
	NodoDE* aux = this->buscarNodo(x);

	if (aux != NULL) {
		//Estudiante e = Estudiante(x.getCedula(), x.getNombre(), x.getCelular(), x.getCorreo(), x.isActivo());

		aux->setDato(x);

		modificado = true;
	}

	return modificado;
}

NodoDE* MaestroEstudiantes::buscarNodo(string cedula)
{
	NodoDE* aux = NULL;

	if (!this->esVacia()) {
		aux = this->getCab();

		if (this->getCab()->getDato().getCedula().compare(cedula) != 0) {
			do {
				aux = aux->getSgte();
			} while (aux != this->getCab() && aux->getDato().getCedula().compare(cedula) != 0);

			if (aux->getDato().getCedula().compare(cedula) != 0) {
				aux = NULL;
			}
		}
	}

	return aux;
}
