#include<iostream>
#include<stdlib.h>

//Estructura del nodo lista.
struct Nodo{
	int dato;
	Nodo *sig;
	//Nodo *ant;
};

//Definicion de funciones
void insertarNodo(Nodo *&lista, int num){
	//1.- Crear nuevo nodo
	Nodo *nuevoNodo = new Nodo();
	
	//2.- Asignar la informacion
	nuevoNodo->dato = num;
	
	//3.- crear 2 nodos auxiliares, 4.- asignarle lista a auxiliar 1
	Nodo *aux_1 = lista;
	Nodo *aux_2;
	
	//5.- Buscar donde insertar el nuevo nodo
	while((aux_1 != NULL) && (aux_1->dato < num)){
		aux_2 = aux_1;
		aux_1 = aux_1->sig;
	}
	
	//6.- Insertar nodo a la lista
	if(lista == aux_1){
		lista = nuevoNodo;
		//nuevoNodo->sig = NULL;
	}else{
		aux_2->sig = nuevoNodo;
		//nuevoNodo->sig = aux_1;
	}
	nuevoNodo->sig = aux_1;
	
	std::cout<<"\n Nodo insertado correctamente\n\n";
}

void mostrarLista(Nodo *lista){
	//Crear nodo
	Nodo *act = new Nodo();
	
	//Inicializarlo a la lista
	act = lista;
	
	//Recorrer la lista
	while(act != NULL){
		std::cout<<act->dato<<" -> ";
		act = act->sig;
	}
	
	std::cout<<" NULL"<<std::endl;
}

//Funcion Principal.
int main(){
	int numero, opc;
	Nodo *lista = new Nodo();
	
	do{
		std::cout<<" ===MENU DE LISTAS=== \n";
		std::cout<<"1.- Insertar elemento. \n";
		std::cout<<"2.- Buscar elemento. (No disponible) \n";
		std::cout<<"3.- Eliminar elemento. (No disponible) \n";
		std::cout<<"4.- Mostrar Lista. \n";
		std::cout<<"0.- Salir\n";
		std::cout<<"Opcion: "; std::cin>>opc;
	
		switch(opc){
			case 1: 
				std::cout<<"\nDigite un numero: ";
				std::cin>>numero; 
				insertarNodo(lista, numero); 
				break;
				
			case 4:
				std::cout<<"\nElementos de la lista: ";
				mostrarLista(lista);
		}
		
		std::cout<<"\n\nPresione una tecla para continuar..."<<std::endl;
		std::cin.get();
		std::cin.get();
		system("cls");
	}while(opc != 0);
}
