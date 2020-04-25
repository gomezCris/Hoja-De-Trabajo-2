/*				EJERCICIO #2
El director de un colegio desea realizar un programa que procese un archivo de registros 
correspondiente a los diferentes alumnos del centro a fin de obtener los siguientes datos:

-Nota más alta y número de identificación del alumno correspondiente.
-Nota media del colegio.

Datos de Estudiantes:

-Identificación
-Nombre
-Nota 

*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <vector>
using namespace std;

//Declaración de la estructura correspondiente a estudiantes
struct Estudiantes{
	int identificacion;
	string nombre;
	float nota;
};

//Creación de vector de tipo Estudiante
std::vector<Estudiantes> estudiante;

//Función para agregar estudiantes
void agregarEstudiantes(){
	
	Estudiantes _estudiante;
	
	//Ingreso de identificación
	cout << "Ingrese la identificación del estudiante: " << "\n";
	cin >> _estudiante.identificacion;
	
	//Ingreso del nombre del estudiante
	cout << "Ingrese el nombre del estudiante: " << "\n";
	cin >> _estudiante.nombre;
	
	//Ingreso de la nota del estudiante
	cout << "Ingrese nota del estudiante: " << "\n";
	cin >> _estudiante.nota;
	
	//Grabar Estudiante en archivo
	ofstream archivoEstudiantes("ESTUDIANTES.txt", std::ios_base::app);
	
	archivoEstudiantes <<
	_estudiante.identificacion << "\t"<< _estudiante.nombre << "\t" <<  _estudiante.nota 
	<< endl;
	
	archivoEstudiantes.close();
}

//Función encargada de extraer la nota más alta y el alumno correspondiente
void notaAlta(float _Nota){
	int _idEstudiante;
	
	for (int i; i <= estudiante.size(); i++){
		
		if (estudiante[i].nota > _Nota){
			_Nota = estudiante[i].nota;
			_idEstudiante = estudiante[i].identificacion;
		}
	}
	
	cout << "---------------------------------------------------" << endl;
	cout << "La identificación del alumno con la nota más alta es: " << _idEstudiante << " con una nota de: " << _Nota << endl;
	cout << "---------------------------------------------------" << endl;
    return;
}

//Función encargada de mostrar la nota promedio
void notaPromedio(){
	float sumaNotas;
	float promedioNota;
	int noEstudiantes;
	
	for (int i; i <= estudiante.size(); i++){
		sumaNotas = sumaNotas + estudiante[i].nota;
		noEstudiantes = i;
	}
	
	promedioNota = sumaNotas/noEstudiantes;
	
	cout << "---------------------------------------------------" << endl;
	cout << "La nota media del colegio es de: " << promedioNota << endl;
	cout << "---------------------------------------------------" << endl;
	return;
	
}


//Función encargada de leer archivos
void leerArchivo(){
	
	//Declaración de variable de tipo archivo.
	ifstream archivoAlumnos;
	//Declaración de variable de tipo estructura de Productos
	Estudiantes stEstudiantes;
	//Declaración de variable Nota
	float nota = 0;
	
	//Abrir archivo Estudiantes
	archivoAlumnos.open("ESTUDIANTES.txt", ios::in);
	
	//Obtener los datos desde el archivo.
	while(archivoAlumnos >> stEstudiantes.identificacion >> stEstudiantes.nombre >> stEstudiantes.nota){
		//Guardar los datos obtenidos en un vector
		estudiante.push_back(stEstudiantes);
	}
	
	//Cerrar archivo.
	archivoAlumnos.close();
	//Invocación de la función para mostrar los productos
	
	notaAlta(nota);
	notaPromedio();
	
	return;
}

// Principal
int main(){
	char opcion;
	string vacio;
	bool terminar = false;
	
	do {
		cin.clear();
		
		cout << "---------------------ESTUDIANTES---------------------" << endl;
		cout << "1. Agregar Estudiantes" << "\n"
		<< "2. Mostrar nota más alta y nota media del colegio" << "\n"
		<< "3. Salir" << endl;
		cout << "Elija una opción (1-3)" << endl;
		cin >> opcion;
		
		switch(opcion){
			case '1':
				agregarEstudiantes();
				break;
			case '2':
				leerArchivo();
				break;
			case '3':
				terminar = true;
				break;
			default:
				cout << "Opción inválida";
				getchar();
				getline(cin, vacio);
				break;
		}
		
	}while(terminar != true);
	
	return 0;
}
