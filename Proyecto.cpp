#include <iostream>
#include "MaestroEstudiantes.h"
#include "ListaMaterias.h"
using namespace std;

//Listas generales
MaestroEstudiantes maestroEstudiantes;
ListaMaterias listaMaterias;


//Datos iniciales temporales, se cambiara por la implementacion de la BD
void datosIniciales()
{
    //Creacion de estudiantes
    for (int i = 0; i < 10; i++)
    {
        Estudiante e = Estudiante(to_string(i), "nom"+ to_string(i), to_string(i+10000000), "correo" + to_string(i), true);
        maestroEstudiantes.agregarFinal(e);
    }

    //creacion de materias
    for (int i = 0; i < 4; i++)
    {
        Materia m = Materia("cod"+to_string(i), "materia" + to_string(i), "Sin descripcion", ListaGrupos());
        listaMaterias.agregarFinal(m);
    }
}

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
    cout << ". " << endl;
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
    cout << "3.  Eliminar estudiante" << endl;
    cout << "4.  Buscar estudiante por cedula" << endl;
    cout << "5.  Modificar estudiante" << endl;
    cout << "6.  Mostrar detalle de estudiante" << endl;
    cout << "7.  Desactivar estudiante" << endl;
    cout << "8.  Activar estudiante" << endl;
    cout << ". " << endl;
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
    cout << ". " << endl;
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
    cout << "8.  Lista de 10 mejores estudiantes" << endl;
    cout << "9.  Lista de 10 mejores estudiantes" << endl;
    cout << "10. Lista de estudiantes por materia con nota maxima (100)" << endl;
    cout << ". " << endl;
    cout << "11.  Volver a menu principal" << endl;
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

#pragma region AccionesEstudiante

void registrarEstudiante() {

    string ced, nombre, celular, correo;

    cout << "Ingrese por favor los siguientes datos:" << endl;
    cout << endl;
    cout << "Cedula:" << endl;
    cin >> ced;
    cout << "Nombre:" << endl;
    cin >> nombre;
    cout << "Celular:" << endl;
    cin >> celular;
    cout << "Correo:" << endl;
    cin >> correo;

    Estudiante e = Estudiante(ced, nombre, celular, correo, true);

    maestroEstudiantes.agregarFinal(e);
    cout << "El estudiante " << e.getNombre() << " fue registrdo correctamente." << endl;
    cout << endl;

}

void listarEstudiantes()
{
    maestroEstudiantes.desplegar();
}

void eliminarEstudiante()
{
    string ced;

    cout << "Ingrese por favor la cedula del estudiante que desea eliminar:" << endl;
    cin >> ced;

    Estudiante e = maestroEstudiantes.consultar(ced);
    bool eliminado = maestroEstudiantes.borrar(e);

    if (eliminado) 
    {
        cout << "El estudiante " << e.getNombre() << " fue eliminado del sistema." << endl;
        cout << endl;
    }
    else
    {
        cout << "El estudiante no esta registrado." << endl;
        cout << endl;
    }

        
}

void buscarEstudiante()
{
    string ced;

    cout << "Ingrese por favor la cedula del estudiante que desea consultar:" << endl;
    cin >> ced;

    Estudiante e = maestroEstudiantes.consultar(ced);
    e.desplegar();
}

void modificarEstudiante()
{
    string ced;

    cout << "Ingrese por favor la cedula del estudiante que desea modificar:" << endl;
    cin >> ced;

    Estudiante e = maestroEstudiantes.consultar(ced);

    if (e.getNombre() == " ") 
    {
        cout << "El estudiante consultado no se encuentra registrado" << endl;
        cout << endl;
    }
    else
    {
        string celular, correo;
        cout << "Ingrese por favor el nuevo numero de telefono [registrado: " << e.getCelular() << "]"<<endl;
        cin >> celular;
        cout << "Ingrese por favor el nuevo correo [registrado: " << e.getCorreo() << "]" << endl;
        cin >> correo;

        e.setCelular(celular);
        e.setCorreo(correo);

        maestroEstudiantes.modificar(e);
        cout << "El estudiante " << e.getNombre() << " fue modificado correctamente." << endl;
        cout << endl;
    }

}

void activarEstudiante() 
{
    string ced;

    cout << "Ingrese por favor la cedula del estudiante que desea activar:" << endl;
    cin >> ced;

    Estudiante e = maestroEstudiantes.consultar(ced);

    if (e.getNombre() == " ")
    {
        cout << "El estudiante consultado no se encuentra registrado" << endl;
        cout << endl;
    }
    else
    {
        e.setActivo(true);
        maestroEstudiantes.modificar(e);
        cout << "El estudiante " << e.getNombre() << " fue activado correctamente." << endl;
        cout << endl;
    }
}

void desactivarEstudiante()
{
    string ced;

    cout << "Ingrese por favor la cedula del estudiante que desea desactivar:" << endl;
    cin >> ced;

    Estudiante e = maestroEstudiantes.consultar(ced);

    if (e.getNombre() == " ")
    {
        cout << "El estudiante consultado no se encuentra registrado" << endl;
        cout << endl;
    }
    else
    {
        e.setActivo(false);
        maestroEstudiantes.modificar(e);
        cout << "El estudiante " << e.getNombre() <<" fue desactivado correctamente." << endl;
        cout << endl;
    }
}

#pragma endregion

#pragma region AccionesMaterias

void registrarMateria() {

    string codigo, nombre, descripcion;

    cout << "Ingrese por favor los siguientes datos:" << endl;
    cout << endl;
    cout << "Codigo:" << endl;
    cin >> codigo;
    cout << "Nombre:" << endl;
    cin >> nombre;
    cout << "Descripcion:" << endl;
    cin >> descripcion;

    Materia m = Materia(codigo, nombre, descripcion, ListaGrupos());

    listaMaterias.agregarFinal(m);
    cout << "La materia " << m.getNombre() << " fue registrada correctamente." << endl;
    cout << endl;

}

void listarMaterias()
{
    listaMaterias.desplegar();
}

void eliminarMateria()
{
    string codigo;

    cout << "Ingrese por favor el codigo de la materia que desea eliminar:" << endl;
    cin >> codigo;

    Materia m = listaMaterias.consultar(codigo);
    bool eliminado = listaMaterias.borrar(m);

    if (eliminado)
    {
        cout << "La materia " << m.getNombre() << " fue eliminada del sistema." << endl;
        cout << endl;
    }
    else
    {
        cout << "La materia no esta registrada." << endl;
        cout << endl;
    }


}

void buscarMateria()
{
    string codigo;

    cout << "Ingrese por favor el codigo de la materia que desea consultar:" << endl;
    cin >> codigo;

    Materia m = listaMaterias.consultar(codigo);
    m.desplegar();
}

void modificarMateria()
{
    string codigo;

    cout << "Ingrese por favor el codigo de la materia que desea modificar:" << endl;
    cin >> codigo;

    Materia m = listaMaterias.consultar(codigo);

    if (m.getNombre() == " ")
    {
        cout << "La materia no se encuentra registrada" << endl;
        cout << endl;
    }
    else
    {
        string descripcion;
        cout << "Ingrese por favor la nueva descripcion de la materia[actual: " << m.getDescripcion() << "]" << endl;
        cin >> descripcion;

        m.setDescripcion(descripcion);

        listaMaterias.modificar(m);
        cout << "La materia " << m.getNombre() << " fue modificada correctamente." << endl;
        cout << endl;
    }

}

void mostrarDetallesMateria()
{
    //Working on it
}

#pragma endregion

#pragma region AccionesGrupos

void registrarGrupo() {

    string materia;
    int numero, maximo, matriculados;

    matriculados = 0;
    bool estatus = true;

    cout << "Ingrese por favor los siguientes datos:" << endl;
    cout << endl;
    cout << "Codigo de la materia:" << endl;
    cin >> materia;
    cout << "Numero de grupo:" << endl;
    cin >> numero;
    cout << "Maximo de estudiantes permitidos:" << endl;
    cin >> maximo;

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
            cout << endl;
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

        bool eliminado = listaGrupos.borrar(g);

        if (eliminado)
        {
			m.setGrupos(listaGrupos);
			listaMaterias.modificar(m);
            cout << "El grupo " << to_string(g.getNumero()) << " fue eliminado del sistema." << endl;
            cout << endl;
        }
        else
        {
            cout << "El grupo que intenta eliminar no esta registrado." << endl;
            cout << endl;
        }

    }

}

void modificarGrupo()
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
        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() != " ")
        {
            int tam;
            cout << "Ingrese por favor la nueva cantidad maxima: [ " << to_string(g.getMaximo()) << "]" << endl;
            cin >> tam;

            g.setMaximo(tam);

            bool modificado = m.getGrupos().modificar(g);
            if (modificado)
            {
                cout << "El grupo fue modificado correctamente." << endl;
                cout << endl;
            }
            else
            {
                cout << "No fue posible modificar el grupo." << endl;
                cout << endl;
            }

        }

    }

}

void activarGrupo()
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
        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() != " ")
        {

            g.setEstatus(true);

            bool modificado = m.getGrupos().modificar(g);
            if (modificado)
            {
                cout << "El grupo fue activado correctamente." << endl;
                cout << endl;
            }
            else
            {
                cout << "No fue posible activar el grupo." << endl;
                cout << endl;
            }
        }
    }
}

void cerrarGrupo()
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
        Grupo g = m.getGrupos().consultar(numero);

        if (g.getMateria() != " ")
        {

            g.setEstatus(false);

            bool modificado = m.getGrupos().modificar(g);
            if (modificado)
            {
                cout << "El grupo fue cerrado (desactivado) correctamente." << endl;
                cout << endl;
            }
            else
            {
                cout << "No fue posible cerrar (desactivar) el grupo." << endl;
                cout << endl;
            }
        }
    }
}

#pragma endregion

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
        ListaGrupos lem= m.getGrupos();

        Grupo g = lem.consultar(numero);

        NodoDE* e = maestroEstudiantes.buscarNodo(cedula);

        EstudianteMatriculado em = EstudianteMatriculado(cedula, -1, e);

        ListaEstudiantesMatriculados lm = g.getListaMatricula();

        lm.agregarFinal(em);

        g.setListaMatricula(lm);

        lm.modificar(em);

        lm = g.getListaMatricula();

        cout << "El estudiante " << cedula << " fue matriculado en la materia " << materia << "." << endl;
        cout << endl;
    }
}

void listarMatriculadosPorCurso()
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
            ListaEstudiantesMatriculados lm = g.getListaMatricula();
            for (int i = 0; i < g.getListaMatricula().cantidad(); i++)
            {
                lm.demeDato(i).desplegar();
                cout << endl;
            }
        }  
    }
}

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

}

void modificarNotaEstudianteMatriculado()
{

    string codigo, cedula;
    int numero, nota;

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

}

#pragma endregion

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



bool ejecutarAccionMaterias(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        registrarMateria();
        system("PAUSE");
        break;

    case 2:
        listarMaterias();
        system("PAUSE");
        break;

    case 3:
        eliminarMateria();
        system("PAUSE");
        break;

    case 4:
        buscarMateria();
        system("PAUSE");
        break;

    case 5:
        modificarMateria();
        system("PAUSE");
        break;

    case 6:
        mostrarDetallesMateria();
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

bool ejecutarAccionEstudiantes(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        registrarEstudiante();
        system("PAUSE");
        break;

    case 2:
        listarEstudiantes();
        system("PAUSE");
        break;

    case 3:
        eliminarEstudiante();
        system("PAUSE");
        break;

    case 4:
        buscarEstudiante();
        system("PAUSE");
        break;

    case 5:
        modificarEstudiante();
        system("PAUSE");
        break;

    case 6:
        activarEstudiante();
        system("PAUSE");
        break;
    case 7:
        desactivarEstudiante();
        system("PAUSE");
        break;
    case 8:
        //sin implementar
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

bool ejecutarAccionGrupos(int popcion) {

    bool noSalir = true;

    switch (popcion) {

    case 1:
        registrarGrupo();
        system("PAUSE");
        break;

    case 2:
        listarGruposPorMateria();
        system("PAUSE");
        break;

    case 3:
        consultarGrupo();
        system("PAUSE");
        break;

    case 4:
        eliminarGrupo();
        system("PAUSE");
        break;

    case 5:
        modificarGrupo();
        system("PAUSE");
        break;

    case 6:
        activarGrupo();
        system("PAUSE");
        break;

    case 7:
        cerrarGrupo();
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
        matricularEstudiante();
        system("PAUSE");
        break;

    case 2:
        listarMatriculadosPorCurso();
        system("PAUSE");
        break;

    case 3:
        retirarEstudianteDeCurso();
        system("PAUSE");
        break;

    case 4:
        modificarNotaEstudianteMatriculado();
        system("PAUSE");
        break;

    case 5:
        mostrarDetallesEstudianteMatriculado();
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
        totalMaterias();
        system("PAUSE");
        break;

    case 2:
        totalCursosPorMateria();
        system("PAUSE");
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
                cout <<"************************************" << endl;
                cout << "Opcion invalida" << endl;
                cout << endl;
                break;
        }
        return noSalir;
}


int main()
{
    datosIniciales();

    int opc;
    bool noSalir = true;

    do {
        mostrarMenuPrincipal();
        opc = leerOpcion();
        noSalir = ejecutarAccion(opc);
    } while (noSalir);
}
