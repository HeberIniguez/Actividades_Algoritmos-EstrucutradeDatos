#include<iostream>

int main(){
	int numeros[5] = {3, 5, 2, 7, 4};
	int *p;
	
	//p = &numeros[0];
	p = numeros;
	
	std::cout<<"No. |  Elemento   |"<<"  Direccion "<<std::endl;
	
	for(int i=0; i<32; i++){
		std::cout<<"-";
	}
	std::cout<<"\n";
	for(int i=0; i<5; ++i){
		//std::cout<<"Elemento "<<i<<": "<<numeros[i]<<std::endl;
		std::cout<<" "<<i<<"  |     "<<*p++<<"       |  "<<p<<std::endl;
	}
		
	return 0;
}
