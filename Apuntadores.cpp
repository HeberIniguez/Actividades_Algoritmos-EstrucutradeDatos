#include<iostream>

void intercambio(int *, int *);
void operaciones (int, int, int *, int *);

int main(){
	int a=5, b=7, suma, producto;
	
	std::cout<<"Valor a: "<<a<<", b: "<<b<<std::endl;
	
	std::cout<<"\nRealizando intercambio..."<<std::endl;
	intercambio(&a, &b);
	
	std::cout<<"\nValor a: "<<a<<", b: "<<b<<std::endl;
	
	operaciones(a, b, &suma, &producto);
	
	std::cout<<"\nLa suma es: "<<suma<<" y el producto es: "<<producto<<std::endl;
	std::cout<<"La suma se encuentra en: "<<&suma<<std::endl;
	std::cout<<"El producto se encuentra en: "<<&producto<<std::endl;
	
	return 0;
}

void intercambio(int *x, int *y){
	int au;
	
	au = *x;
	*x = *y;
	*y = au;
}

void operaciones (int n1, int n2, int *s, int *p){
	*s = n1 + n2;
	*p = n1 * n2;
}
