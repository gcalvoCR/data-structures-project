#include "SistemaMatricula.h"
#include <iostream>



#pragma region AccionesEstudiantes
void SistemaMatricula::registrarEstudiante()
{
	string ced, nombre, celular, correo;

	cout << "Ingrese por favor los siguientes datos:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Cedula:" << endl;
	getline(std::cin, ced);
	cout << "Nombre:" << endl;
	getline(std::cin, nombre);
	cout << "Celular:" << endl;
	getline(std::cin, celular);
	cout << "Correo:" << endl;
	getline(std::cin, correo);

	Estudiante e = Estudiante(ced, nombre, celular, correo, true);

	maestroEstudiantes.agregarFinal(e);
	cout << "El estudiante " << e.getNombre() << " fue registrdo correctamente." << endl;
	cout << endl;

}

void SistemaMatricula::listarEstudiantes()
{
	if (maestroEstudiantes.cantidad() == 0) {
		cout << endl;
		cout << "No hay estudiantes registrados." << endl;
		cout << endl;
	}
	else
	{
		cout << "Estudiantes registrados:" << endl;
		cout << endl;
		for (int i = 0; i < maestroEstudiantes.cantidad(); i++)
		{
			Estudiante e = maestroEstudiantes.demeDato(i);
			cout << "Ced: " << e.getCedula() << ", nombre: " << e.getNombre() << endl;
		}
	}
}

void SistemaMatricula::listarEstudiantesDetalladamente()
{

	if (maestroEstudiantes.cantidad() == 0) 
	{
		cout << "No hay estudiantes registrados." << endl;;
	}
	else
	{
		cout << "Estudiantes registrados:" << endl;
		cout << endl;
		maestroEstudiantes.desplegar();
	}

}

void SistemaMatricula::eliminarEstudiante()
{
	string ced;



	cout << "Ingrese por favor la cedula del estudiante que desea eliminar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ced);

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

void SistemaMatricula::buscarEstudiante()
{
	string ced;

	cout << "Ingrese por favor la cedula del estudiante que desea consultar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ced);

	Estudiante e = maestroEstudiantes.consultar(ced);
	e.desplegar();
}

void SistemaMatricula::modificarEstudiante()
{
	string ced;

	cout << "Ingrese por favor la cedula del estudiante que desea modificar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ced);

	Estudiante e = maestroEstudiantes.consultar(ced);

	if (e.getNombre() == " ")
	{
		cout << "El estudiante consultado no se encuentra registrado" << endl;
		cout << endl;
	}
	else
	{
		string texto="";

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Ingrese por favor la actualizacion del nombre [registrado: " << e.getNombre() << "]" << endl;
		getline(std::cin, texto);
		if (texto.length() != 0) {
			e.setNombre(texto);
			texto = "";
		}
		cout << "Ingrese por favor el nuevo numero de telefono [registrado: " << e.getCelular() << "]" << endl;
		getline(std::cin, texto);
		if (texto.length() != 0) {
			e.setCelular(texto);
			texto = "";
		}
		cout << "Ingrese por favor el nuevo correo [registrado: " << e.getCorreo() << "]" << endl;
		getline(std::cin, texto);
		if (texto.length() != 0) {
			e.setCorreo(texto);
			texto = "";
		}

		maestroEstudiantes.modificar(e);
		cout << "El estudiante con cedula " << e.getCedula() << " fue modificado correctamente." << endl;
		cout << endl;
	}
}

void SistemaMatricula::activarEstudiante()
{
	string ced;

	cout << "Ingrese por favor la cedula del estudiante que desea activar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ced);

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

void SistemaMatricula::desactivarEstudiante()
{
	string ced;

	cout << "Ingrese por favor la cedula del estudiante que desea desactivar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ced);

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
		cout << "El estudiante " << e.getNombre() << " fue desactivado correctamente." << endl;
		cout << endl;
	}
}
#pragma endregion


#pragma region AccionesMaterias

void SistemaMatricula::registrarMateria() {

	string codigo, nombre;
	string descripcion ="";

	cout << "Ingrese por favor los siguientes datos:" << endl;
	cout << endl;
	cout << "Codigo:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);
	cout << "Nombre:" << endl;
	getline(std::cin, nombre);
	cout << "Descripcion [default: sin descripcion]:" << endl;
	getline(std::cin, descripcion);
	if (descripcion.length() == 0) {
		descripcion = "Sin descripcion";
	}

	Materia m = Materia(codigo, nombre, descripcion, ListaGrupos());

	listaMaterias.agregarFinal(m);
	cout << "La materia " << m.getNombre() << " fue registrada correctamente." << endl;
	cout << endl;

}

void SistemaMatricula::listarMaterias()
{
	if (listaMaterias.cantidad() == 0) {
		cout << endl;
		cout << "No hay materias registradas." << endl;
		cout << endl;
	}
	listaMaterias.desplegar();
}

void SistemaMatricula::eliminarMateria()
{
	string codigo;

	cout << "Ingrese por favor el codigo de la materia que desea eliminar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::buscarMateria()
{
	string codigo;

	cout << "Ingrese por favor el codigo de la materia que desea consultar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

	Materia m = listaMaterias.consultar(codigo);
	m.desplegar();
}

void SistemaMatricula::modificarMateria()
{
	string codigo;

	cout << "Ingrese por favor el codigo de la materia que desea modificar:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
		getline(std::cin, descripcion);

		m.setDescripcion(descripcion);

		listaMaterias.modificar(m);
		cout << "La materia " << m.getNombre() << " fue modificada correctamente." << endl;
		cout << endl;
	}

}

void SistemaMatricula::mostrarDetallesMateria()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		if (lg.cantidad() == 0) {
			cout << "La materia : " << m.getNombre() << " no tiene grupos asociados." << endl;

		}

		int cont = 0;

		for (int j = 0; j < lg.cantidad(); j++)
		{

			Grupo g = lg.demeDato(j);

			if (g.getListaMatricula().cantidad() > 0)
			{
				cout << endl;
				cout << "Materia: " << g.getMateria() << ", grupo: " << to_string(g.getNumero()) << ", estado: " << to_string(g.getEstatus()) << endl;
			}


			ListaEstudiantesMatriculados lm = g.getListaMatricula();

			for (int k = 0; k < lm.cantidad(); k++)
			{
				if (lm.cantidad()>0)
				{
					EstudianteMatriculado em = lm.demeDato(k);
					cout << "ced: " << em.getCedula() << ", nota: " << to_string(em.getNota()) << endl;
				}
			}
			cout << endl;
		}
	}
}

#pragma endregion


#pragma region AccionesGrupos

void SistemaMatricula::registrarGrupo() {

	string materia;
	int numero, maximo, matriculados;

	matriculados = 0;
	bool estatus = true;

	cout << "Ingrese por favor los siguientes datos:" << endl;
	cout << endl;
	cout << "Codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, materia);
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

void SistemaMatricula::listarGruposPorMateria()
{
	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

	Materia m = listaMaterias.consultar(codigo);

	if (m.getNombre() == " ")
	{
		cout << "La materia no se encuentra registrada" << endl;
		cout << endl;
	}
	else
	{
		if (m.getGrupos().cantidad() == 0) {
			cout << endl;
			cout << "La materia no tiene grupos registrados." << endl;
			cout << endl;
		}
		for (int i = 0; i < m.getGrupos().cantidad(); i++)
		{
			m.getGrupos().demeDato(i).desplegar();
			cout << endl;
		}
	}
}

void SistemaMatricula::consultarGrupo()
{
	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::eliminarGrupo()
{
	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::modificarGrupo()
{

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::activarGrupo()
{

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::cerrarGrupo()
{

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

void SistemaMatricula::matricularEstudiante() {

	string materia, cedula;
	int numero;

	bool estatus = true;

	cout << "Ingrese por favor los siguientes datos:" << endl;
	cout << endl;
	cout << "Cedula de la persona:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, cedula);

	Estudiante e = maestroEstudiantes.consultar(cedula);

	if (e.getNombre() == " ") {
		cout << endl;
		cout << "*** Estudiante no matriculado, redirigiendo a registro ***" << endl;

		registrarEstudiante();

		cout << endl;
		cout << " *** Continuacion del proceso de matricula ***" << endl;
		cout << endl;
		cout << "Ingrese por favor los siguientes datos:" << endl;

	}

	cout << endl;
	cout << "Codigo de la materia:" << endl;
	getline(std::cin, materia);
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
		ListaGrupos lem = m.getGrupos();

		Grupo g = lem.consultar(numero);

		if (g.getMatriculados() < g.getMaximo()) {
			Estudiante student;
			student.setCedula(cedula);

			NodoDE* e = maestroEstudiantes.buscarNodo(student);

			EstudianteMatriculado em = EstudianteMatriculado(cedula, -1, e, m.getCodigoMateria(), g.getNumero());

			ListaEstudiantesMatriculados lm = g.getListaMatricula();

			lm.agregarFinal(em);


			g.setListaMatricula(lm);

			int matriculados = g.getMatriculados();

			g.setMatriculados(matriculados + 1);

			lem.modificar(g);

			m.setGrupos(lem);

			listaMaterias.modificar(m);

			cout << "El estudiante " << cedula << " fue matriculado en la materia " << materia << "." << endl;
			cout << endl;
		}
		else {
			cout << "Lo sentimos, la cantidad máxima de estudiantes en el grupo " << g.getNumero() << " ha sido alcanzada" << endl;
			cout << endl;
		}
	}
}

void SistemaMatricula::listarMatriculadosPorGrupo()
{
	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			cout << endl;
			cout << "El grupo no esta registrado en el sistema." << endl;
			cout << endl;
		}
		else
		{
			ListaEstudiantesMatriculados lm = g.getListaMatricula();

			if (lm.cantidad() == 0) {
				cout << endl;
				cout << "El grupo no tiene alumnos registrados." << endl;
				cout << endl;
			}
			for (int i = 0; i < g.getListaMatricula().cantidad(); i++)
			{
				lm.demeDato(i).desplegar();
				cout << endl;
			}
		}
	}
}

void SistemaMatricula::mostrarDetallesEstudianteMatriculado()
{
	string codigo, cedula;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			getline(std::cin, cedula);

			ListaEstudiantesMatriculados lm = g.getListaMatricula();

			EstudianteMatriculado em = lm.consultar(cedula);

			em.desplegar();
		}
	}
}

void SistemaMatricula::retirarEstudianteDeGrupo()
{
	string codigo, cedula;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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

		ListaGrupos lg = m.getGrupos();
		Grupo g = lg.consultar(numero);

		if (g.getMateria() == " ")
		{
			cout << "El curso no se fue registrado" << endl;
			cout << endl;
		}
		else
		{
			cout << "Ingrese por favor la cedula del estudiante matriculado:" << endl;
			getline(std::cin, cedula);

			ListaEstudiantesMatriculados lm = g.getListaMatricula();

			EstudianteMatriculado em = lm.consultar(cedula);

			bool eliminado = lm.borrar(em);

			if (eliminado)
			{
				g.setListaMatricula(lm);

				int matriculados = g.getMatriculados();
				g.setMatriculados(matriculados - 1);

				lg.modificar(g);

				cout << "El estudiante con cedula " << cedula << " fue retirado del grupo." << endl;
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

void SistemaMatricula::modificarNotaEstudianteMatriculado()
{

	string codigo, cedula;
	int numero, nota;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ingrese por favor la cedula del estudiante matriculado:" << endl;
			getline(std::cin, cedula);

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

void SistemaMatricula::totalMaterias()
{
	cout << endl;
	cout << "La cantidad de materias registradas en el sistema es de: " << listaMaterias.cantidad() << endl;
	cout << endl;
}

void SistemaMatricula::totalGruposPorMateria()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		cout << "Materia: " << listaMaterias.demeDato(i).getNombre() << ", cantidad de grupos: " << to_string(listaMaterias.demeDato(i).getGrupos().cantidad()) << endl;
		cout << endl;
	}
}

void SistemaMatricula::totalEstudiantesPorMateria()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();


		int cont = 0;

		for (int j = 0; j < lg.cantidad(); j++)
		{

			cont += lg.demeDato(j).getMatriculados();

		}

		cout << "Materia: " << listaMaterias.demeDato(i).getNombre() << ", cantidad de alumnos matriculados: " << to_string(cont) << endl;
		cout << endl;
	}

}

void SistemaMatricula::grupoMenosMatriculados()
{
	cout << endl;

	Grupo g;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		if (g.getMateria() == " ") {
			g = lg.demeDato(0);
		}

		for (int j = 0; j < lg.cantidad(); j++) {
			if (lg.demeDato(j).getListaMatricula().cantidad() < g.getListaMatricula().cantidad()) {
				g = lg.demeDato(j);
			}
		}
	}

	if (g.getMateria() != " ") {
		cout << "La materia y grupo con menos matricula es:" << endl;
		cout << endl;
		g.desplegar();
		cout << endl;
	}
}

void SistemaMatricula::grupoMasMatriculados()
{
	cout << endl;

	Grupo g;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		if (g.getMateria() == " ") {
			g = lg.demeDato(0);
		}

		for (int j = 0; j < lg.cantidad(); j++) {
			if (lg.demeDato(j).getListaMatricula().cantidad() > g.getListaMatricula().cantidad()) {
				g = lg.demeDato(j);
			}
		}
	}

	if (g.getMateria() != " ") {
		cout << "La materia y grupo con mas matricula es:" << endl;
		cout << endl;
		g.desplegar();
		cout << endl;
	}
}

void SistemaMatricula::gruposDesactivos()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		for (int j = 0; j < lg.cantidad(); j++) {
			if (!lg.demeDato(j).getEstatus()) {
				lg.demeDato(j).desplegar();
				cout << endl;
			}
		}
	}
}

void SistemaMatricula::estudiantesActivosMateria()
{
	cout << endl;

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			Grupo g = m.getGrupos().demeDato(i);

			for (int j = 0; j < g.getListaMatricula().cantidad(); j++)
			{
				EstudianteMatriculado e = g.getListaMatricula().demeDato(j);

				if (e.getEstudiante()->getDato().isActivo()) {
					cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getEstudiante()->getDato().getNombre() << endl;
					cout << endl;
				}
			}
		}
	}
}

void SistemaMatricula::estudiantesActivosGrupo()
{
	cout << endl;

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			cout << endl;
			cout << "El grupo no esta registrado en el sistema." << endl;
			cout << endl;
		}
		else
		{
			for (int i = 0; i < g.getListaMatricula().cantidad(); i++)
			{
				EstudianteMatriculado e = g.getListaMatricula().demeDato(i);

				if (e.getEstudiante()->getDato().isActivo()) {
					cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getEstudiante()->getDato().getNombre() << endl;
					cout << endl;
				}
			}
		}
	}
}

void SistemaMatricula::estudiantesActivos()
{
	cout << endl;

	for (int i = 0; i < maestroEstudiantes.cantidad(); i++)
	{
		Estudiante e = maestroEstudiantes.demeDato(i);
		
		if (e.isActivo()) {
			cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getNombre() << endl;
			cout << endl;
		}
	}
}

void SistemaMatricula::estudiantesInactivosMateria()
{
	cout << endl;

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			Grupo g = m.getGrupos().demeDato(i);

			for (int j = 0; j < g.getListaMatricula().cantidad(); j++)
			{
				EstudianteMatriculado e = g.getListaMatricula().demeDato(j);

				if (!e.getEstudiante()->getDato().isActivo()) {
					cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getEstudiante()->getDato().getNombre() << endl;
					cout << endl;
				}
			}
		}
	}

}

void SistemaMatricula::estudiantesInactivosGrupo()
{
	cout << endl;

	cout << endl;

	string codigo;
	int numero;

	cout << "Ingrese por favor el codigo de la materia:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, codigo);

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
			cout << endl;
			cout << "El grupo no esta registrado en el sistema." << endl;
			cout << endl;
		}
		else
		{

			for (int i = 0; i < g.getListaMatricula().cantidad(); i++)
			{
				EstudianteMatriculado e = g.getListaMatricula().demeDato(i);

				if (!e.getEstudiante()->getDato().isActivo()) {
					cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getEstudiante()->getDato().getNombre() << endl;
					cout << endl;
				}
			}
		}
	}
}

void SistemaMatricula::estudiantesInactivos()
{
	cout << endl;

	for (int i = 0; i < maestroEstudiantes.cantidad(); i++)
	{
		Estudiante e = maestroEstudiantes.demeDato(i);

		if (!e.isActivo()) {
			cout << "Cedula: " << e.getCedula() << ", Nombre: " << e.getNombre() << endl;
			cout << endl;
		}
	}
}

void SistemaMatricula::TopEstudiantesPorMateria()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		for (int j = 0; j < lg.cantidad(); j++) {
			Grupo g = lg.demeDato(j);
			ListaEstudiantesMatriculados lem = g.getListaMatricula();
			EstudianteMatriculado em;

			if (lem.cantidad() > 0) {
				em = lem.demeDato(0);
			}

			for (int k = 0; k < lem.cantidad(); k++) {
				if (lem.demeDato(k).getNota() > em.getNota()) {
					em = lem.demeDato(k);
				}
			}

			if (em.getNota() != 0) {
				cout << "Estudiante con mejor nota en la materia: " << g.getMateria() << ", grupo: " << g.getNumero() << endl;
				em.desplegar();
				cout << endl;
			}
		}
	}
}

void SistemaMatricula::estudiantesMaximaNotaPorMateria()
{
	cout << endl;

	for (int i = 0; i < listaMaterias.cantidad(); i++)
	{
		Materia m = listaMaterias.demeDato(i);
		ListaGrupos lg = m.getGrupos();

		for (int j = 0; j < lg.cantidad(); j++) {
			Grupo g = lg.demeDato(j);
			ListaEstudiantesMatriculados lem = g.getListaMatricula();

			for (int k = 0; k < lem.cantidad(); k++) {
				if (lem.demeDato(k).getNota() == 100) {
					cout << "Materia: " << g.getMateria() << endl;
					cout << "Grupo: " << g.getNumero() << endl;
					cout << "Cedula: " << lem.demeDato(k).getCedula() << endl;
					cout << "Nombre: " << lem.demeDato(k).getEstudiante()->getDato().getNombre() << endl;
					cout << "Nota: " << lem.demeDato(k).getNota() << endl;
					cout << endl;
				}
			}
		}
	}
}

#pragma endregion



