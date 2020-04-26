#include <iostream>
#include "SistemaMatricula.h"

using namespace std;

SistemaMatricula matricula;

#pragma region Menus

int leerOpcion() {

	cout << endl;
	cout << "Elija una opcion por favor." << endl;
	cout << endl;
	int opcion;
	std::cin >> opcion;
	system("CLS");
	return opcion;
}

void mostrarMenuMaterias() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU DE MATERIAS ***********" << endl;
	cout << endl;
	cout << "1.  Registrar materia" << endl;
	cout << "2.  Listar materias" << endl;
	cout << "3.  Eliminar materia" << endl;
	cout << "4.  Buscar materia por codigo" << endl;
	cout << "5.  Modificar materia" << endl;
	cout << "6.  Mostrar detalle de materia" << endl;
	cout << " " << endl;
	cout << "7.  Volver a menu principal" << flush;
	cout << endl;

}

void mostrarMenuEstudiantes() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU DE ESTUDIANTES ***********" << endl;
	cout << endl;
	cout << "1.  Registrar estudiante" << endl;
	cout << "2.  Listar estudiantes" << endl;
	cout << "3.  Listar estudiantes detalladamente" << endl;
	cout << "4.  Eliminar estudiante" << endl;
	cout << "5.  Buscar estudiante por cedula" << endl;
	cout << "6.  Modificar estudiante" << endl;
	cout << "7.  Mostrar detalle de estudiante" << endl;
	cout << "8.  Desactivar estudiante" << endl;
	cout << "9.  Activar estudiante" << endl;
	cout << " " << endl;
	cout << "10.  Volver a menu principal" << endl;
	cout << endl;

}

void mostrarMenuGrupos() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU DE GRUPOS ***********" << endl;
	cout << endl;
	cout << "1.  Registrar grupo a materia" << endl;
	cout << "2.  Listar grupos por materia" << endl;
	cout << "3.  Consultar grupo" << endl;
	cout << "4.  Eliminar grupo" << endl;
	cout << "5.  Modificar grupo" << endl;
	cout << "6.  Activar grupo" << endl;
	cout << "7.  Cerrar grupo" << endl;
	cout << " " << endl;
	cout << "8.  Volver a menu principal" << endl;
	cout << endl;

}

void mostrarMenuMatriculados() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU DE MATRICULA ***********" << endl;
	cout << endl;
	cout << "1.  Matricular estudiante" << endl;
	cout << "2.  Listar matriculados por curso" << endl;
	cout << "3.  Retirar estudiante de grupo" << endl;
	cout << "4.  Modificar nota de estudiante" << endl;
	cout << "5.  Mostrar detalle de estudiante matriculado" << endl;
	cout << endl;
	cout << "6.  Volver a menu principal" << endl;
	cout << endl;

}

void mostrarMenuEstadisticas() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU DE ESTADISTICAS ***********" << endl;
	cout << endl;
	cout << "1.  Total de materias" << endl;
	cout << "2.  Total de cursos por materia" << endl;
	cout << "3.  Total de estudiantes por materia" << endl;
	cout << "4.  Grupo con menos cantidad de estudiantes matriculados" << endl;
	cout << "5.  Grupo con mayor cantidad de estudiantes matriculados" << endl;
	cout << "6.  Lista de estudiantes activos" << endl;
	cout << "7.  Lista de estudiantes inactivos" << endl;
	cout << "8.  Lista del mejor estudiante de cada materia" << endl;
	cout << "9. Lista de estudiantes por materia con nota maxima (100)" << endl;
	cout << " " << endl;
	cout << "10.  Volver a menu principal" << endl;
	cout << endl;


}

void mostrarMenuPrincipal() {
	system("CLS");
	cout << endl;
	cout << "*********** MENU PRINCIPAL ***********" << endl;
	cout << endl;
	cout << "1.  Estudiantes" << endl;
	cout << "2.  Materias" << endl;
	cout << "3.  Grupos" << endl;
	cout << "4.  Matriculas" << endl;
	cout << "5.  Estadisticas" << endl;
	cout << ". " << endl;
	cout << "6.  Salir" << endl;
	cout << endl;
}
#pragma endregion

bool ejecutarAccionEstudiantes(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		matricula.registrarEstudiante();
		system("PAUSE");
		break;

	case 2:
		matricula.listarEstudiantes();
		system("PAUSE");
		break;

	case 3:
		matricula.listarEstudiantesDetalladamente();
		system("PAUSE");
		break;

	case 4:
		matricula.eliminarEstudiante();
		system("PAUSE");
		break;

	case 5:
		matricula.buscarEstudiante();
		system("PAUSE");
		break;

	case 7:
		matricula.modificarEstudiante();
		system("PAUSE");
		break;

	case 8:
		matricula.activarEstudiante();
		system("PAUSE");
		break;
	case 9:
		matricula.desactivarEstudiante();
		system("PAUSE");
		break;
	case 10:
		noSalir = false;
		break;

	default:
		cout << "************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		system("PAUSE");
		break;
	}
	return noSalir;
}

bool ejecutarAccionMaterias(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		matricula.registrarMateria();
		system("PAUSE");
		break;

	case 2:
		matricula.listarMaterias();
		system("PAUSE");
		break;

	case 3:
		matricula.eliminarMateria();
		system("PAUSE");
		break;

	case 4:
		matricula.buscarMateria();
		system("PAUSE");
		break;

	case 5:
		matricula.modificarMateria();
		system("PAUSE");
		break;

	case 6:
		matricula.mostrarDetallesMateria();
		system("PAUSE");
		break;

	case 7:
		noSalir = false;
		break;

	default:
		cout << "************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		system("PAUSE");
		break;
	}
	return noSalir;
}

bool ejecutarAccionGrupos(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		matricula.registrarGrupo();
		system("PAUSE");
		break;

	case 2:
		matricula.listarGruposPorMateria();
		system("PAUSE");
		break;

	case 3:
		matricula.consultarGrupo();
		system("PAUSE");
		break;

	case 4:
		matricula.eliminarGrupo();
		system("PAUSE");
		break;

	case 5:
		matricula.modificarGrupo();
		system("PAUSE");
		break;

	case 6:
		matricula.activarGrupo();
		system("PAUSE");
		break;

	case 7:
		matricula.cerrarGrupo();
		system("PAUSE");
		break;

	case 8:
		noSalir = false;
		break;

	default:
		cout << "************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		system("PAUSE");
		break;
	}
	return noSalir;
}

bool ejecutarAccionMatriculados(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		matricula.matricularEstudiante();
		system("PAUSE");
		break;

	case 2:
		matricula.listarMatriculadosPorGrupo();
		system("PAUSE");
		break;

	case 3:
		matricula.retirarEstudianteDeGrupo();
		system("PAUSE");
		break;

	case 4:
		matricula.modificarNotaEstudianteMatriculado();
		system("PAUSE");
		break;

	case 5:
		matricula.mostrarDetallesEstudianteMatriculado();
		system("PAUSE");
		break;

	case 6:
		noSalir = false;
		break;

	default:
		cout << "************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		system("PAUSE");
		break;
	}
	return noSalir;
}

bool ejecutarAccionEstadisticas(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		matricula.totalMaterias();
		system("PAUSE");
		break;

	case 2:
		matricula.totalGruposPorMateria();
		system("PAUSE");
		break;

	case 3:
		matricula.totalEstudiantesPorMateria();
		system("PAUSE");
		break;

	case 4:
		matricula.grupoMenosMatriculados();
		system("PAUSE");
		break;

	case 5:
		matricula.grupoMasMatriculados();
		system("PAUSE");
		break;

	case 6:
		matricula.estudiantesActivos();
		system("PAUSE");
		break;
	case 7:
		matricula.estudiantesInactivos();
		system("PAUSE");
		break;
	case 8:
		matricula.TopEstudiantesPorMateria();
		system("PAUSE");
		break;
	case 9:
		matricula.estudiantesMaximaNotaPorMateria();
		system("PAUSE");
		break;;
	case 10:
		noSalir = false;
		break;

	default:
		cout << "************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		system("PAUSE");
		break;
	}
	return noSalir;
}

void administrarMaterias() {
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuMaterias();
		opc = leerOpcion();
		noSalir = ejecutarAccionMaterias(opc);
	} while (noSalir);
}

void administrarEstudiantes() {
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuEstudiantes();
		opc = leerOpcion();
		noSalir = ejecutarAccionEstudiantes(opc);
	} while (noSalir);
}

void administrarGrupos() {
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuGrupos();
		opc = leerOpcion();
		noSalir = ejecutarAccionGrupos(opc);
	} while (noSalir);
}

void administrarMatriculados() {
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuMatriculados();
		opc = leerOpcion();
		noSalir = ejecutarAccionMatriculados(opc);
	} while (noSalir);
}

void administrarEstadisticas() {
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuEstadisticas();
		opc = leerOpcion();
		noSalir = ejecutarAccionEstadisticas(opc);
	} while (noSalir);
}

static bool ejecutarAccion(int popcion) {

	bool noSalir = true;

	switch (popcion) {

	case 1:
		administrarEstudiantes();
		break;

	case 2:
		administrarMaterias();
		break;

	case 3:
		administrarGrupos();
		break;

	case 4:
		administrarMatriculados();
		break;

	case 5:
		administrarEstadisticas();
		break;

	case 6:
		noSalir = false;
		break;

	default:
		cout << "************************************" << endl;
		cout << "Opcion invalida" << endl;
		cout << endl;
		break;
	}
	return noSalir;
}

int main()
{
	int opc;
	bool noSalir = true;

	do {
		mostrarMenuPrincipal();
		opc = leerOpcion();
		noSalir = ejecutarAccion(opc);
	} while (noSalir);
}
