#pragma once
#include "MaestroEstudiantes.h"
#include "ListaMaterias.h"
class SistemaMatricula
{
private:
	MaestroEstudiantes maestroEstudiantes;
	ListaMaterias listaMaterias;

public:

	//Acciones para estudiantes
	void registrarEstudiante(); 
	void listarEstudiantes();
	void listarEstudiantesDetalladamente();
	void eliminarEstudiante();
	void buscarEstudiante();
	void modificarEstudiante();
	void activarEstudiante();
	void desactivarEstudiante();

	//Acciones para materias
	void registrarMateria();
	void listarMaterias();
	void eliminarMateria();
	void buscarMateria();
	void modificarMateria();
	void mostrarDetallesMateria();

	//Acciones para grupos
	void registrarGrupo();
	void listarGruposPorMateria();
	void consultarGrupo();
	void eliminarGrupo();
	void modificarGrupo();
	void activarGrupo();
	void cerrarGrupo();

	//Acciones para matricula
	void matricularEstudiante();
	void listarMatriculadosPorGrupo();
	void mostrarDetallesEstudianteMatriculado();
	void retirarEstudianteDeGrupo();
	void modificarNotaEstudianteMatriculado();

	//Acciones estadisticas
	void totalMaterias();
	void totalGruposPorMateria();
	void totalEstudiantesPorMateria();

	//falta de implementar de aca para abajo
	void grupoMenosMatriculados();
	void grupoMasMatriculados();
	void gruposDesactivos();
	void estudiantesActivosMateria();
	void estudiantesActivosGrupo();
	void estudiantesActivos();
	void estudiantesInactivosMateria();
	void estudiantesInactivosGrupo();
	void estudiantesInactivos();
	void TopEstudiantesPorMateria();
	void estudiantesMaximaNotaPorMateria();
	
};

