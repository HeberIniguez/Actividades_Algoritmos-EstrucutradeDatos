#include<iostream>

int factorial(int num){
	if(num>1){
		return num * factorial(num-1);
	} else{
		return 1;
	}
}

int main(){
	int num;
	
	std::cout<<"Digite un numero: "; std::cin>>num;
	std::cout<<"\nEl factorial del numero "<<num<<" es: "<<factorial(num);
	
}
