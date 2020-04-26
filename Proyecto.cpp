#include <iostream>
using namespace std;


static int leerOpcion() {

    cout << "Elija una opcion por favor." << endl;
    cout << endl;
    int opcion;
    cin >> opcion;

    return opcion;
}

void mostrarMenuMaterias() {

    cout << endl;
    cout << "*********** MENU DE MATERIAS ***********" << endl;
    cout << endl;
    cout << "1.  Registrar materia" << endl;
    cout << "2.  Listar materias" << endl;
    cout << "3.  Eliminar materia" << endl;
    cout << "4.  Buscar materia por codigo" << endl;
    cout << "5.  Modificar materia" << endl;
    cout << "6.  Mostrar detalle de materia" << endl;
    cout << ". " << endl;
    cout << "7.  Volver a menu principal" << endl;
    cout << endl;

}

void mostrarMenuEstudiantes() {

    cout << endl;
    cout << "*********** MENU DE ESTUDIANTES ***********" << endl;
    cout << endl;
    cout << "1.  Registrar estudiante" << endl;
    cout << "2.  Listar estudiantes" << endl;
    cout << "3.  Eliminar estudiante" << endl;
    cout << "4.  Buscar estudiante por cedula" << endl;
    cout << "5.  Modificar estudiante" << endl;
    cout << "6.  Mostrar detalle de estudiante" << endl;
    cout << ". " << endl;
    cout << "7.  Volver a menu principal" << endl;
    cout << endl;

}

void mostrarMenuGrupos() {

    cout << endl;
    cout << "*********** MENU DE GRUPOS ***********" << endl;
    cout << endl;
    cout << "1.  Registrar grupo a materia" << endl;
    cout << "2.  Listar grupos" << endl;
    cout << "3.  Eliminar grupo" << endl;
    cout << "4.  Buscar grupo por codigo" << endl;
    cout << "5.  Modificar grupo" << endl;
    cout << "6.  Mostrar detalle de grupo" << endl;
    cout << ". "<< endl;
    cout << "7.  Volver a menu principal" << endl;
    cout << endl;

}

void mostrarMenuMatriculados() {

    cout << endl;
    cout << "*********** MENU DE MATRICULA ***********" << endl;
    cout << endl;
    cout << "1.  Matricular estudiante" << endl;
    cout << "2.  Listar matriculados" << endl;
    cout << "3.  Remover estudiante de materia" << endl;
    cout << "4.  Buscar estudiante" << endl;
    cout << "5.  Modificar informacion de estudiante matriculado" << endl;
    cout << "6.  Mostrar detalle de estudiantr matriculado" << endl;
    cout << ". " << endl;
    cout << "7.  Volver a menu principal" << endl;
    cout << endl;

}

void mostrarMenuEstadisticas() {

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
    cout << "8.  Lista de 10 mejores estudiantes" << endl;
    cout << "9.  Lista de 10 mejores estudiantes" << endl;
    cout << "10. Lista de estudiantes por materia con nota maxima (100)" << endl;
    cout << ". " << endl;
    cout << "11.  Volver a menu principal" << endl;
    cout << endl;

}

bool ejecutarAccionMaterias(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        //RegistrarMateria();
        break;

    case 2:
        //ListarListar();
        break;

    case 3:
        //eliminarMateria();
        break;

    case 4:
        //buscarMateriaPorCodigo();
        break;

    case 5:
        //modificarMateria();
        break;

    case 6:
        //mostrarDetallesMateria();
        break;

    case 7:
        noSalir = false;
        break;

    default:
        cout << "************************" << endl;
        cout << "Opcion invalida" << endl;
        cout << endl;
        break;
    }
    return noSalir;
}

bool ejecutarAccionEstudiantes(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        //sin implementar
        break;

    case 2:
        //sin implementar
        break;

    case 3:
        //sin implementar
        break;

    case 4:
        //sin implementar
        break;

    case 5:
        //sin implementar
        break;

    case 6:
        //sin implementar
        break;

    case 7:
        noSalir = false;
        break;

    default:
        cout << "************************" << endl;
        cout << "Opcion invalida" << endl;
        cout << endl;
        break;
    }
    return noSalir;
}

bool ejecutarAccionGrupos(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        //sin implementar
        break;

    case 2:
        //sin implementar
        break;

    case 3:
        //sin implementar
        break;

    case 4:
        //sin implementar
        break;

    case 5:
        //sin implementar
        break;

    case 6:
        //sin implementar
        break;

    case 7:
        noSalir = false;
        break;

    default:
        cout << "************************" << endl;
        cout << "Opcion invalida" << endl;
        cout << endl;
        break;
    }
    return noSalir;
}

bool ejecutarAccionMatriculados(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        //sin implementar
        break;

    case 2:
        //sin implementar
        break;

    case 3:
        //sin implementar
        break;

    case 4:
        //sin implementar
        break;

    case 5:
        //sin implementar
        break;

    case 6:
        //sin implementar
        break;

    case 7:
        noSalir = false;
        break;

    default:
        cout << "************************" << endl;
        cout << "Opcion invalida" << endl;
        cout << endl;
        break;
    }
    return noSalir;
}

bool ejecutarAccionEstadisticas(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        //sin implementar
        break;

    case 2:
        //sin implementar
        break;

    case 3:
        //sin implementar
        break;

    case 4:
        //sin implementar
        break;

    case 5:
        //sin implementar
        break;

    case 6:
        //sin implementar
        break;
    case 7:
        //sin implementar
        break;
    case 8:
        //sin implementar
        break;
    case 9:
        //sin implementar
        break;
    case 10:
        //sin implementar
        break;
    case 11:
        noSalir = false;
        break;

    default:
        cout << "************************" << endl;
        cout << "Opcion invalida" << endl;
        cout << endl;
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
                cout <<"************************************" << endl;
                cout << "Opcion invalida" << endl;
                cout << endl;
                break;
        }
        return noSalir;
}

void mostrarMenuPrincipal() {

    cout << endl;
    cout << "*********** Menú principal ***********" << endl;
    cout << endl;
    cout << "1.  Alumnos" << endl;
    cout << "2.  Materias" << endl;
    cout << "3.  Grupos" << endl;
    cout << "4.  Matrículas" << endl;
    cout << "5.  Estadísticas" << endl;
    cout << endl;
    cout << "6.  Salir" << endl;
    cout << endl;
}    

//int main()
//{
//    int opc;
//    bool noSalir = true;
//
//    do {
//        mostrarMenuPrincipal();
//        opc = leerOpcion();
//        noSalir = ejecutarAccion(opc);
//    } while (noSalir);
//}
