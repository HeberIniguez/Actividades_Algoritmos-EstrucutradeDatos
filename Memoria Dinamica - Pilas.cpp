//Estructuras Lineales
#include<iostream>
#include<algorithm>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};

void agregarNodo(Nodo *&pila, int n){
	Nodo *nodo_nuevo = new Nodo();
	nodo_nuevo->dato = n;
	nodo_nuevo->sig = pila;
	pila = nodo_nuevo;
}

void quitarNodo(Nodo *&pila, int &n){
	Nodo *nodoAux = pila;
	n = nodoAux->dato;
	pila = nodoAux->sig;
	delete nodoAux;
}

int main(){
	Nodo *pila = NULL;
	int dato;
	char opc;
	
	do{
		cout<<"Ingrese un dato: ";
		cin>>dato;
		
		agregarNodo(pila, dato);
		
		cout<<"Agregar otro dato (s/n)?: ";
		cin>>opc;
	}while(opc == 's');
	
	cout<<"\nDATOS DE LA PILA: ";
	while(pila != NULL){
		quitarNodo(pila, dato);
		std::cout<<dato<<" ";
	}
}
