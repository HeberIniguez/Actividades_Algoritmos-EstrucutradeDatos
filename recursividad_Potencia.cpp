#include<iostream>

int elevacion(int x, int exp){
	if(exp == 1){
		return x;
	}else{
		return x * elevacion(x, exp-1);
	}
}

int main(){
	int num, pot;
	
	std::cout<<"Digite un numero y su exponente: "; std::cin>>num>>pot;
	std::cout<<"\nEl numero "<<num<<" elevado a "<<pot<<" es: "<<elevacion(num, pot);
}
