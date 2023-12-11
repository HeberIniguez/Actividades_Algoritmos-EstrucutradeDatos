#include<iostream>

struct Coordenada{
	float x, y;
};

int main(){
	struct Coordenada c, *cp;
	int numero, *p;
	
	cp = &c;
	
	cp->x = 3.5;  
	cp->y = 4.6;
	
	std::cout<<"La coordenada es: ("<<cp->x<<", "<<cp->y<<")"<<std::endl;
	std::cout<<"La direccion de memoria de la coordenada es: "<<cp;
	
	//numero = 20;
	
	/*std::cout<<"Digite un numero: "; std::cin>>numero;
	p = &numero;
	
	(*p%2) == 0 ? std::cout<<"El numero es: "<<*p<<"y es un numero par" : false;
	*/
	
	
	//std::cout<<"El numero es: "<<numero;
	//std::cout<<"El numero es: "<<*p;
	//std::cout<<"\nLa direccion de memoria es: "<<p;
		
	return 0;
}
