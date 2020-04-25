/*				EJERCICIO #1
Se dispone de un archivo STOCK correspondiente a la existencia de artículos de un almacén 
y se desea señalar aquellos artículos cuyo nivel está por debajo del mínimo y que visualicen un mensaje “hacer pedido”. 
Cada artículo contiene un registro con los siguientes campos: número del código del artículo, nivel mínimo, nivel actual, proveedor, precio.

El programa debe tener un menu que se especifiquen las siguientes opciones:
1) Agregar productos (Grabar datos a un archivo)
2) Leer archivo y mostrar en pantalla que productos tiene nivel minimo. 

*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <vector>
using namespace std;


//Declaración de la estructura correspondiente a productos
struct Productos{
	string codArticulo;
	int nivMinimo;
	int nivActual;
	string proveedor;
	float precio;
};

//Creación de vector
std::vector<Productos> producto;

//Función para agregar productos
void agregarArticulo(){
	
	Productos _producto;
	
	//Ingreso de código
	cout << "Ingrese el código del producto: " << "\n";
	cin >> _producto.codArticulo;
	
	//Ingreso del nivel mínimo
	cout << "Ingrese el mínimo del producto: " << "\n";
	cin >> _producto.nivMinimo;
	
	//Ingreso del nivel máximo
	cout << "Ingrese la cantidad acutal del producto: " << "\n";
	cin >> _producto.nivActual;
	
	//Ingreso del proveedor
	cout << "Ingrese el proveedor del producto: " << "\n";
	cin >> _producto.proveedor;
	
	//Ingreso del precio
	cout << "Ingrese el precio del producto: " << "\n";
	cin >> _producto.precio;
	
	//Grabar producto en archivo
	ofstream archivoStock("STOCK.txt", std::ios_base::app);
	
	archivoStock << "\n" <<
	_producto.codArticulo << "\t" << "\t" << _producto.nivMinimo << "\t"<< "\t" <<  
	_producto.nivActual << "\t"<< "\t" << _producto.proveedor << "\t" <<"\t"  <<
	_producto.precio << endl;
	
	archivoStock.close();
}

//Función que muestra la estructura de datos
void estructuraDatos(){
	cout << "Se necesita realizar pedidos de los siguientes productos: " << endl;
	cout << "---------------------------------------------" << endl;
	cout << "CODIGO"<< "\t" << "MINIMO" << "\t" << "EXISTENCIA" << "\t" << "PROVEEDOR" << "\t" << "PRECIO" << endl;
	cout << "---------------------------------------------" << endl; 
}


//Función encargada de validar los productos que necesitan realizar pedidos
void pedidoProductos(){
	for (int i; i <= producto.size(); i++){
		
		/*
			Validación que se realiza para saber cuál producto está por debajo del nivel mínimo para
			realizar el pedido
		*/
		if (producto[i].nivMinimo >= producto[i].nivActual){
			
			//Se muestra la información del producto correspondiente
			cout << 
			producto[i].codArticulo << "\t" <<
			producto[i].nivMinimo << "\t" <<
			producto[i].nivActual << "\t" << "\t" <<
			producto[i].proveedor << "\t" << "\t" <<
			producto[i].precio << "\t" <<
			endl;  
			
		}
	}
	
	string empty;
	cin >> empty;
    return;
}

//Función para mostrar datos de los productos
void mostrarProductos(){
	
	//Muestra la estructura de los datos
	estructuraDatos();
	
	//Invocación de la función correspondiente para mostrar los datos del producto
	pedidoProductos();	
}

//Función encargada de leer archivos
void leerArchivo(){
	
	//Declaración de variable de tipo archivo.
	ifstream archivoStock;
	//Declaración de variable de tipo estructura de Productos
	Productos stProductos;
	
	archivoStock.open("STOCK.txt", ios::in);
	
	//Obtener los datos desde el archivo.
	while(archivoStock >> stProductos.codArticulo >> stProductos.nivMinimo >> stProductos.nivActual >> stProductos.proveedor >> stProductos.precio){
		//Guardar los datos obtenidos en un vector
		producto.push_back(stProductos);
	}
	
	//Cerrar archivo.
	archivoStock.close();
	//Invocación de la función para mostrar los productos
	mostrarProductos();
	
	return;
}


// Principal
int main(){
	char opcion;
	string vacio;
	bool terminar = false;
	
	do {
		//system("clear");
		cin.clear();
		
		cout << "---------------------PRODUCTOS---------------------" << endl;
		cout << "1. Agregar Productos" << "\n"
		<< "2. Leer archivo y mostrar productos para pedido" << "\n"
		<< "3. Salir" << endl;
		cout << "Elija una opción (1-3)" << endl;
		cin >> opcion;
		
		switch(opcion){
			case '1':
				agregarArticulo();
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

