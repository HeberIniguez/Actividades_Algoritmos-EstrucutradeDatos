#include<iostream>
#include<stdlib.h>

//Estructuras
struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
};

struct NodoCola{
    Nodo *nodoArbol;
    NodoCola *sig;
};

//Prototipos de Funciones
void Pausa();
//Operaciones con Arboles
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
bool buscarNodo(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void amplitud(Nodo *);
void insertarCola(NodoCola *&, NodoCola *&, Nodo *);
void eliminarNodoCola(NodoCola  *&, NodoCola *&);
void eliminarNodo(Nodo *&, int);
Nodo *minimo(Nodo *);
//Propiedades del arbol
int nivelNodo(Nodo *, int);
int alturaArbol(Nodo *);
int contarNodos(Nodo *);



//Funcion Principal
int main(){
	Nodo *arbol = NULL;
	int dato, opc;
	
	do{
		std::cout<<"\t.::MENU::.\n";
		std::cout<<"\n1.- Insertar Nodo.";
		std::cout<<"\n2.- Mostrar Arbol.";
		std::cout<<"\n3.- Buscar Nodo.";
		std::cout<<"\n4.- Recorrido en PreOrden.";
     	std::cout<<"\n5.- Recorrido en InOrden.";
     	std::cout<<"\n6.- Recorrido en postOrden.";
     	std::cout<<"\n7.- Recorrido en Amplitud.";
     	std::cout<<"\n8.- Eliminar un Nodo.";
     	std::cout<<"\n9.- Nivel del nodo.";
     	std::cout<<"\n10.- Altura del arbol.";
     	std::cout<<"\n11.- Peso del arbol.";
		std::cout<<"\n0.- Salir\n";
		std::cout<<"\n\Opcion: "; std::cin>>opc;
		
		switch(opc){
			case 1: std::cout<<"\nDigite un numero: "; 
					std::cin>>dato;
					insertarNodo(arbol, dato);
					Pausa();
					break;
					
			case 2: std::cout<<"\n";
					mostrarArbol(arbol, 0);
					Pausa();
					break;
					
			case 3: std::cout<<"\nDigite un numero: "; 
					std::cin>>dato;
					buscarNodo(arbol, dato) ? std::cout<<"\nSi esta el nodo con el numero: "<<dato: 
											  std::cout<<"\nNo esta el nodo con el numero: "<<dato;
					Pausa();
					break;
			
			case 4: std::cout<<"\nRecorrido del arbol en PreOrden: ";
                	preOrden(arbol);
                	Pausa();
					break;
                   
     		case 5: std::cout<<"\nRecorrido del arbol en InOrden: ";
                    inOrden(arbol);
                    Pausa();
					break;
     
     		case 6: std::cout<<"\nRecorrido del arbol en PostOrden: ";
                	postOrden(arbol);
                	Pausa();
					break;
     
     		case 7: std::cout<<"\nRecorrido del arbol por niveles: ";
                	amplitud(arbol);
                	Pausa();
					break;
			
			case 8: std::cout<<"\nDigite un numero a eliminar: "; 
					std::cin>>dato;
					eliminarNodo(arbol, dato);
					Pausa();
					break;
			
			case 9: std::cout<<"\nDigite el numero a buscar: "; 
					std::cin>>dato;
					std::cout<<"\nEl numero "<<dato<<" esta en el nivel "<<nivelNodo(arbol, dato);
					Pausa();
					break;
			
			case 10: std::cout<<"\nLa altura del arbol es de "<<alturaArbol(arbol)<<" niveles.";
					 Pausa();
					 break;	
			
			case 11: std::cout<<"\nEl peso del arbol es de: "<<contarNodos(arbol)<<" nodos";
					 Pausa();
					 break;		 
		}
		std::cin.get();
		system("cls");
	}while(opc!=0);
	
	return 0;
}

void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = new Nodo();
	
		nuevo_nodo->dato = n;
		nuevo_nodo->izq = NULL;
		nuevo_nodo->der = NULL;
		
		arbol = nuevo_nodo;
	} else{
		if(n < arbol->dato){
			insertarNodo(arbol->izq, n);
		}else{
			insertarNodo(arbol->der, n);
		}
	}
	
}

void mostrarArbol(Nodo *arbol, int n){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der, n+1);
		for(int i=0; i<n; i++){
			std::cout<<"   ";
		}
		std::cout<<arbol->dato<<std::endl;
		
		mostrarArbol(arbol->izq, n+1);
	}
}

bool buscarNodo(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}else{
		if(arbol->dato == n){
			return true;
		}else{
			if(n<arbol->dato){
				buscarNodo(arbol->izq, n);
			}else{
				buscarNodo(arbol->der, n);
			}
		}
	}
}

void preOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        std::cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden (arbol->der);
    }
}

void inOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        inOrden(arbol->izq);
        std::cout<<arbol->dato<<" - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        std::cout<<arbol->dato<<" - ";
    }
}

void amplitud(Nodo *arbol){
    Nodo *auxArbol;
    
    NodoCola *frente = NULL;
    NodoCola *fin = NULL;
    
    insertarCola(frente, fin, arbol);
    
    while(frente!=NULL){
        auxArbol = frente->nodoArbol;
        std::cout<<auxArbol->dato<<" - ";
        eliminarNodoCola(frente, fin);
        
        if(auxArbol->izq != NULL){
            insertarCola(frente, fin, auxArbol->izq);
        }
        
        if(auxArbol->der != NULL){
            insertarCola(frente, fin, auxArbol->der);
        }
    }
    
}

void insertarCola(NodoCola *&frente, NodoCola *&fin, Nodo *n){
    NodoCola *nuevo_nodo = new NodoCola();
    
    nuevo_nodo->nodoArbol = n;
    nuevo_nodo->sig = NULL;   
    
    if(frente==NULL){
        frente = nuevo_nodo ;
    }else{
        fin->sig = nuevo_nodo;
    }
    
    fin = nuevo_nodo;
}

void eliminarNodoCola(NodoCola  *&frente, NodoCola *&fin){
    NodoCola  *aux = frente;
    
    if(frente==fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->sig;
    }
    delete aux;
}

void eliminarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		return;
	}else{
		if(n < arbol->dato){
			eliminarNodo(arbol->izq, n);
		}else{
			if(n > arbol->dato){
				eliminarNodo(arbol->der, n);
			}
			else{
				if(arbol->izq && arbol->der){
					Nodo *menor = minimo(arbol->der);
					arbol->dato = menor->dato;
					eliminarNodo(arbol->der, arbol->dato);
				
				}else{
					Nodo *temp = arbol;
					if(arbol->izq==NULL){
						arbol = arbol->der;
					
					}else{
						if(arbol->der == NULL){
							arbol = arbol->izq;
						}
					}
					delete temp;
				}
			}
		}
	}
}

Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	} else{
		if(arbol->izq == NULL){
			return arbol;
		}else{
			return minimo(arbol->izq);
		}
	}
}

int nivelNodo(Nodo *arbol, int n){
	if(arbol == NULL){
		return 0;
	}else{
		if(n < arbol->dato){
			return 1+nivelNodo(arbol->izq, n);
		}else{
			if(n > arbol->dato){
				return 1+nivelNodo(arbol->der, n);
			}else{
				return 1;
			}
		}
	}
}

int alturaArbol(Nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		return 1 + std::max(alturaArbol(arbol->izq), alturaArbol(arbol->der));
	}
}

int contarNodos(Nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		return 1 + contarNodos(arbol->izq) + contarNodos(arbol->der);
	}
}

void Pausa(){
	std::cout<<"\n\nPresione ENTER para continuar..."<<std::endl;
	std::cin.get();
}
