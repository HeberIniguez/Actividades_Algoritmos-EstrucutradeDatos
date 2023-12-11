#include<iostream>

int fibonacci(int  n){
	if(n<2){
		return n;
		
	} else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){
	int numero;
	
	std::cout<<"Digite un numero: "; std::cin>>numero;
	std::cout<<"\nSerie Fibonacci del numero "<<numero<<" es: ";
	
	for(int i=0; i<=numero; i++){
		std::cout<<fibonacci(i)<<" ";
	}
}
