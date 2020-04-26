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
	cout << "7.  Desactivar estudiante" << endl;
	cout << "8.  Activar estudiante" << endl;
	cout << " " << endl;
	cout << "9.  Volver a menu principal" << endl;
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

<<<<<<< Updated upstream
=======
    Grupo g = Grupo(materia, numero, estatus, maximo, matriculados);

    Materia m = listaMaterias.consultar(materia);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        ListaGrupos listaGrupos = m.getGrupos();

        listaGrupos.agregarFinal(g);

        m.setGrupos(listaGrupos);

        listaMaterias.modificar(m);

        cout << "El grupo " << numero << " fue agregado a la materia " << materia << "." << endl;
        cout << endl;
    }
}

void listarGruposPorMateria()
{
    string codigo;
    int numero;

    cout << "Ingrese por favor el codigo de la materia:" << endl;
    cin >> codigo;

    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < m.getGrupos().cantidad(); i++)
        {
            m.getGrupos().demeDato(i).desplegar();
        }
    }
}

void consultarGrupo()
{
    string codigo;
    int numero;

    cout << "Ingrese por favor el codigo de la materia:" << endl;
    cin >> codigo;

    cout << "Ingrese por favor el numero de grupo:" << endl;
    cin >> numero;

    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        Grupo g = m.getGrupos().consultar(numero);
        g.desplegar();
    }
}

void eliminarGrupo()
{
    string codigo;
    int numero;

    cout << "Ingrese por favor el codigo de la materia:" << endl;
    cin >> codigo;

    cout << "Ingrese por favor el numero de grupo:" << endl;
    cin >> numero;

    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == "")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        ListaGrupos listaGrupos = m.getGrupos();
        Grupo g = listaGrupos.consultar(numero);

        bool eliminado = m.getGrupos().borrar(g);

        if (eliminado)
        {
            cout << "El grupo " << to_string(g.getNumero()) << " fue eliminado del sistema." << endl;
            cout << endl;
        }
        else
        {
            cout << "El grupo que intenta eliminar no esta registrado." << endl;
            cout << endl;
        }

    }
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
bool ejecutarAccionEstudiantes(int popcion) {
=======
#pragma region AccionesMatricula

void matricularEstudiante() {

    string materia, cedula;
    int numero;

    bool estatus = true;

    cout << "Ingrese por favor los siguientes datos:" << endl;
    cout << endl;
    cout << "Cedula de la persona:" << endl;
    cin >> cedula;

    Estudiante e = maestroEstudiantes.consultar(cedula);

    if (e.getNombre() == " ") {
        cout << endl;
        cout << "*** Estudiante no matriculado, redirigiendo a registro ***" <<  endl;

        registrarEstudiante();

        cout << endl;
        cout << " *** Continuacion del proceso de matricula ***" << endl;
        cout << endl;
        cout << "Ingrese por favor los siguientes datos:" << endl;

    }

    cout << endl;
    cout << "Codigo de la materia:" << endl;
    cin >> materia;
    cout << "Numero de grupo:" << endl;
    cin >> numero;

    Materia m = listaMaterias.consultar(materia);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        Grupo g = m.getGrupos().consultar(numero);

        NodoDE* e = maestroEstudiantes.buscarNodo(cedula);

        EstudianteMatriculado em = EstudianteMatriculado(cedula, -1, e);

        ListaEstudiantesMatriculados lm = g.getListaMatricula();

        lm.agregarFinal(em);

        g.setListaMatricula(lm);

        lm.modificar(em);


       /* ListaGrupos listaGrupos = m.getGrupos();

        listaGrupos.agregarFinal(g);

        m.setGrupos(listaGrupos);

        listaMaterias.modificar(m);*/

        //g.getListaMatricula().agregarFinal(em);
>>>>>>> Stashed changes

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

	case 6:
		matricula.modificarEstudiante();
		system("PAUSE");
		break;

	case 7:
		matricula.activarEstudiante();
		system("PAUSE");
		break;
	case 8:
		matricula.desactivarEstudiante();
		system("PAUSE");
		break;
	case 9:
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

<<<<<<< Updated upstream
	bool noSalir = true;

	switch (popcion) {
=======
void mostrarDetallesEstudianteMatriculado()
{
    string codigo, cedula;
    int numero;

    cout << "Ingrese por favor el codigo de la materia:" << endl;
    cin >> codigo;

    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        cout << "Ingrese por favor el numero de grupo:" << endl;
        cin >> numero;

        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() == " ")
        {
            cout << "El curso no se fue registrado" << endl;
            cout << endl;
        }
        else
        {
            cout << "Ingrese por favor la cedula del estudiante matriculado:" << endl;
            cin >> cedula;

            ListaEstudiantesMatriculados lm = g.getListaMatricula();

            EstudianteMatriculado em = lm.consultar(cedula);

            em.desplegar();
        }
    }
}

void retirarEstudianteDeCurso()
{
    string codigo, cedula;
    int numero;
>>>>>>> Stashed changes

	case 1:
		matricula.registrarMateria();
		system("PAUSE");
		break;

<<<<<<< Updated upstream
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
=======
    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        cout << "Ingrese por favor el numero de grupo:" << endl;
        cin >> numero;

        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() == " ")
        {
            cout << "El curso no se fue registrado" << endl;
            cout << endl;
        }
        else
        {
            cout << "Ingrese por favor la cedula del estudiante matriculado:" << endl;
            cin >> cedula;

            ListaEstudiantesMatriculados lm = g.getListaMatricula();

            EstudianteMatriculado em = lm.consultar(cedula);

            bool eliminado = lm.borrar(em);

            if (eliminado)
            {
                cout << "El estudiante con cedula " << cedula << " fue eliminado del sistema." << endl;
                cout << endl;
            }
            else
            {
                cout << "El estudiante que intenta eliminar no esta registrado en el grupo." << endl;
                cout << endl;
            }

        }
    }
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
	bool noSalir = true;
=======
    string codigo, cedula;
    int numero, nota;
>>>>>>> Stashed changes

	switch (popcion) {

<<<<<<< Updated upstream
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
=======
    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        cout << "Ingrese por favor el numero de grupo:" << endl;
        cin >> numero;

        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() == " ")
        {
            cout << "El curso no se fue registrado" << endl;
            cout << endl;
        }
        else
        {
            cout << "Ingrese por favor la cedula del estudiante matriculado:" << endl;
            cin >> cedula;

            cout << "Ingrese por favor la nota del estudiante matriculado:" << endl;
            cin >> nota;

            ListaEstudiantesMatriculados lm = g.getListaMatricula();

            EstudianteMatriculado em = lm.consultar(cedula);

            em.setNota(nota);

            bool modificado = lm.modificar(em);

            if (modificado)
            {
                cout << "El estudiante con cedula " << cedula << " fue actualizado exitosamente." << endl;
                cout << endl;
            }
            else
            {
                cout << "El estudiante que intenta actualizar no esta registrado en el grupo." << endl;
                cout << endl;
            }

        }
    }
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
	bool noSalir = true;
=======
#pragma region AccionesEstadisticas

void totalMaterias()
{
    cout << endl;
    cout << "La cantidad de materias registradas en el sistema es de: " << listaMaterias.cantidad() << endl;
    cout << endl;
}

void totalCursosPorMateria() 
{
    cout << endl;

    for (int i = 0; i < listaMaterias.cantidad(); i++)
    {
        cout << "Materia: "<< listaMaterias.demeDato(i).getNombre() << ", cantidad de grupos: " << to_string(listaMaterias.demeDato(i).getGrupos().cantidad()) << endl;
        cout << endl;
    }
}

#pragma endregion


>>>>>>> Stashed changes

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
