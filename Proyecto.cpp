
#include <iostream>
using namespace std;

static int leerOpcion() {

    cout << "Elija una opción por favor." << endl;
    cout << endl;
    int opcion;
    cin >> opcion;

    return opcion;
}

void mostrarMenuMaterias() {

    cout << endl;
    cout << "*********** Menú de materias ***********" << endl;
    cout << endl;
    cout << "1.  Registrar materia" << endl;
    cout << "2.  Listar materias" << endl;
    cout << "3.  Eliminar materia" << endl;
    cout << "4.  Buscar materia por código" << endl;
    cout << "5.  Modificar materia" << endl;
    cout << "6.  Mostrar detalle de materia" << endl;
    cout << "7.  Volver a menu principal" << endl;
    cout << endl;

}

static bool ejecutarAccionMateria(int popcion) {

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

static void administrarMaterias() {
    int opc;
    bool noSalir = true;

    do {
        mostrarMenuMaterias();
        opc = leerOpcion();
        noSalir = ejecutarAccionMateria(opc);
    } while (noSalir);
}


static bool ejecutarAccion(int popcion) {

        bool noSalir = true;

        switch (popcion) {

            case 1:
                //administrarEstudiantes();
                break;

            case 2:
                administrarMaterias();
                break;

            case 3:
                //administrarCursos();
                break;

            case 4:
                //administrarMatricula();
                break;

            case 5:
                //estadisticas();
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
