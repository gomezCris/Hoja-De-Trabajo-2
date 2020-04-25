/*				EJERCICIO #1
Se dispone de un archivo STOCK correspondiente a la existencia de art�culos de un almac�n 
y se desea se�alar aquellos art�culos cuyo nivel est� por debajo del m�nimo y que visualicen un mensaje �hacer pedido�. 
Cada art�culo contiene un registro con los siguientes campos: n�mero del c�digo del art�culo, nivel m�nimo, nivel actual, proveedor, precio.

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


//Declaraci�n de la estructura correspondiente a productos
struct Productos{
	string codArticulo;
	int nivMinimo;
	int nivActual;
	string proveedor;
	float precio;
};

//Creaci�n de vector
std::vector<Productos> producto;

//Funci�n para agregar productos
void agregarArticulo(){
	
	Productos _producto;
	
	//Ingreso de c�digo
	cout << "Ingrese el c�digo del producto: " << "\n";
	cin >> _producto.codArticulo;
	
	//Ingreso del nivel m�nimo
	cout << "Ingrese el m�nimo del producto: " << "\n";
	cin >> _producto.nivMinimo;
	
	//Ingreso del nivel m�ximo
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

//Funci�n que muestra la estructura de datos
void estructuraDatos(){
	cout << "Se necesita realizar pedidos de los siguientes productos: " << endl;
	cout << "---------------------------------------------" << endl;
	cout << "CODIGO"<< "\t" << "MINIMO" << "\t" << "EXISTENCIA" << "\t" << "PROVEEDOR" << "\t" << "PRECIO" << endl;
	cout << "---------------------------------------------" << endl; 
}


//Funci�n encargada de validar los productos que necesitan realizar pedidos
void pedidoProductos(){
	for (int i; i <= producto.size(); i++){
		
		/*
			Validaci�n que se realiza para saber cu�l producto est� por debajo del nivel m�nimo para
			realizar el pedido
		*/
		if (producto[i].nivMinimo >= producto[i].nivActual){
			
			//Se muestra la informaci�n del producto correspondiente
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

//Funci�n para mostrar datos de los productos
void mostrarProductos(){
	
	//Muestra la estructura de los datos
	estructuraDatos();
	
	//Invocaci�n de la funci�n correspondiente para mostrar los datos del producto
	pedidoProductos();	
}

//Funci�n encargada de leer archivos
void leerArchivo(){
	
	//Declaraci�n de variable de tipo archivo.
	ifstream archivoStock;
	//Declaraci�n de variable de tipo estructura de Productos
	Productos stProductos;
	
	archivoStock.open("STOCK.txt", ios::in);
	
	//Obtener los datos desde el archivo.
	while(archivoStock >> stProductos.codArticulo >> stProductos.nivMinimo >> stProductos.nivActual >> stProductos.proveedor >> stProductos.precio){
		//Guardar los datos obtenidos en un vector
		producto.push_back(stProductos);
	}
	
	//Cerrar archivo.
	archivoStock.close();
	//Invocaci�n de la funci�n para mostrar los productos
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
		cout << "Elija una opci�n (1-3)" << endl;
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
				cout << "Opci�n inv�lida";
				getchar();
				getline(cin, vacio);
				break;
		}
		
	}while(terminar != true);
	
	return 0;
}

