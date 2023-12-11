#include <iostream>
#include <stdlib.h>
using namespace std;

//Insertar nodo a la lista
//1-Crear nodo
//2-Asignarle informacion
//3-Crear 2 nodos auxiliares
//4-Auxiliar 1 asignarle el primer elemento de la lista
//5-Buscar en donde insertar el nuevo nodo
//6-Insertar nodo a la lista

//ESTRUCTURA DEL NODO DE LA LISTA
struct Nodo{
	int dato;
	Nodo *sig;
	//Nodo *ant
};
//PROTOTIPOS DE FUNCIONES
void insertarNodo(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarNodo(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int &);


//FUNCION PRINCIPAL
int main(){
	
	int dato, opc;
	Nodo *lista = NULL;
	do
	{
	
	
	cout<<"= = MENU DE LISTAS = = "<<endl;
	cout<<"1. INSERTAR NUEVO NODO."<<endl;
	cout<<"2. Mostrar lista completa"<<endl;
	cout<<"3. Buscar nodo."<<endl;
	cout<<"4. Eliminar nodo."<<endl;
	cout<<"5. Eliminar lista."<<endl;
	cout<<"6. SALIR"<<endl;
	cout<<"Opcion = ";
	cin>>opc;
	
	switch(opc)
	{
		case 1: cout<<"\nDIGITE DATO A INSERTAR: ";
		cin>>dato;
		insertarNodo(lista, dato);
		
		break;
		
		case 2: cout<<"\nElementos de la lista: ";
		mostrarLista(lista);
		break;
		
		case 3: cout<<"\nDigite dato a buscar: ";
		cin>>dato;
		buscarNodo(lista, dato);
		break;
		
		
		case 4: cout<<"\nDigite el dato a borrar: ";
		cin>>dato;
		eliminarNodo(lista, dato);
		cout<<"Dato eliminado!!"<<endl;
		break;
		
		case 5: while(lista != NULL)
		{
			eliminarLista(lista, dato);
			cout<<"Dato eliminado: "<<dato<<endl;
		}
		cout<<"\nLista eliminada!!!"<<endl;
		break;
	}
	
	cout<<"\nPresione una tecla para continuar"<<endl;
	cin.get();
	cin.get();
	system("CLS");
}while(opc != 6);
	
	return 0;
}

//DEFINICION DE FUNCIONES
void insertarNodo(Nodo *&lista, int n)
{
	//1- CRAR NUEVO NODO
	Nodo *nuevo_nodo = new Nodo();
	
	//2- Asignar informavion al nodo
	nuevo_nodo->dato = n;
	
	//3- CREAR DOS NODOS AUXILIARES, 4-Asignarle lista 
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	//5- BUSCAR EN DONDE INSERTAR NODO
	while((aux1 != NULL)&&(aux1->dato < n))
	{
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	//6- INSERTAR NODO A LA LISTA
	if(lista == aux1)
	{
		lista = nuevo_nodo;
	//	nuevo_nodo->sig = NULL;
	}
	else
	{
		aux2->sig = nuevo_nodo;
		//nuevo_nodo->sig = aux1;
	}
	nuevo_nodo->sig = aux1;
	
	cout<<"\nNodo insertado correctamente\n"<<endl;
}

void mostrarLista(Nodo *lista)
{
	//1. CREAR NODO
	Nodo *actual = new Nodo();
	
	//2. INICIALIZARLO A LA LISTA
	actual = lista;
	
	//3.RECORRER LA LISTA
	while(actual != NULL)
	{
		cout<<actual->dato<<" -> ";
		actual = actual->sig;
		
	}
	cout<<" NULL"<<endl;
	
}

void buscarNodo(Nodo *lista, int n)
{
	Nodo *busqueda = new Nodo();
	busqueda = lista;
	bool band = false;
	
	while(busqueda != NULL && busqueda->dato <= n)
	{
		if(busqueda->dato == n)
		{
			band = true;
			break;
		}
		
		busqueda = busqueda->sig;
	}
	
	if(band == true)
	{
		cout<<"El elemento se encuentra en la lista"<<endl;
	}
	else
	{
		cout<<"El elemento no se encuentra en la lista"<<endl;
	}
}

void eliminarNodo(Nodo *&lista, int n)
{
	if(lista != NULL)
	{
		Nodo *borrar;
		Nodo *anterior = NULL;
		
		borrar = lista;
		
		while(borrar != NULL && borrar->dato != n)
		{
			anterior = borrar;
			borrar = borrar->sig;
		}
		
		if(borrar == lista)
		{
			lista = borrar->sig;
			
		}
		else
		{
			anterior->sig = borrar->sig;
		}
		
		delete borrar;
		
		
		
	}
}

void eliminarLista(Nodo *&lista, int &n)
{
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->sig;
	delete aux;
}















