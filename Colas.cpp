#include<iostream>

//Estructura base del nodo.
struct Nodo{
	char dato;
	Nodo *sig;
};

void insertarNodo(Nodo *&ini, Nodo *&fin, char letra){
	//Crear Nodo.
	Nodo *nuevo_nodo = new Nodo();
	
	//Asignar Informacion.
	nuevo_nodo->dato = letra;
	nuevo_nodo->sig = NULL;

	//Actualizar frente y fin.
	if(ini == NULL){
		ini = nuevo_nodo;
	}
	else{
		fin->sig = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
}

void eliminarNodo(Nodo *&ini, Nodo *&fin, char &letra){
	//Obtener la informacion.
	letra = ini->dato;
	
	//Guardar frente cola en Auxiliar.
	//Nodo *aux = ini;
	
	//Eliminar frente de cola
	if(ini == fin){
		ini = NULL;
		fin = NULL;
	}
	else{
		ini = ini->sig;
	}
	//delete aux;
}

int main(){
	char dato, opc;
	Nodo *ini = NULL;
	Nodo *fin = NULL;
	
	do{
		std::cout<<"Ingrese caracter a la cola: "; std::cin>>dato;
		insertarNodo(ini, fin, dato);
		std::cout<<"Desea salir? (s/n): "; std::cin>>opc;
	}while(opc != 'n');
	
	std::cout<<"\nElementos en la Cola"<<std::endl;
	while(ini != NULL){
		eliminarNodo(ini, fin, dato);
		std::cout<<dato<<" ";
	}
}
