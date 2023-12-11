//Estructuras Lineales
#include<iostream>
#include<algorithm>

struct nodo{
	int dato;
	nodo *sig;
};

void agregarNodo(nodo *&pila, int n){
	nodo *nodoNuevo = new nodo();
	nodoNuevo->dato = n;
	nodoNuevo->sig = pila;
	pila = nodoNuevo;
}

void quitarNodo(nodo *&pila,int &n){
	nodo *nodoAux = pila;
	n = nodoAux->dato;
	pila = nodoAux->sig;
	delete nodoAux;
}

int main(){
	nodo *pila = NULL;
	int dato;
	char opc;
	
	do{
		std::cout<<"Ingrese un dato: ";
		std::cin>>dato;
		
		agregarNodo(pila, dato);
		
		std::cout<<"Agregar otro dato (s/n)?: ";
		std::cin>>opc;
	}while(opc == 's');
	
	std::cout<<"\nDATOS DE LA PILA:";
	while(pila != NULL){
		quitarNodo(pila, dato);
		std::cout<<dato<<" ";
	}
}
