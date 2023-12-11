#include <iostream>
#include <string>
#include <stdlib.h>

//Prototipos de Funcion
int verificarPromedio(struct Alumnos *, float *, int);
void ingresarDatos(struct Alumnos *, int);
void imprimirDatos(struct Alumnos *, float, int);
void limpiarPantalla();

//Structuras
struct Calificaciones{
    float nota1;
    float nota2;
    float nota3;
};

struct Alumnos{
    std::string nombre;
    std::string sexo;
    int edad;
    struct Calificaciones promedio;
};

//Codigo principal
int main() {
	int cantidad;
	
	std::cout<<"Digite el total de alumnos: "; std::cin>>cantidad;
	struct Alumnos alu[cantidad];
	
	limpiarPantalla();
    ingresarDatos(alu, cantidad);
    
    float promMayor = 0.0; 				

	limpiarPantalla();
	imprimirDatos(alu, promMayor, verificarPromedio(alu, &promMayor, cantidad));
    
    std::cout<<"\n\n";
    system("pause");
    return 0;
}

//Funciones
void ingresarDatos(struct Alumnos *p_alumnos, int c){
	
	 for(int i=0; i<c; i++){
	 	std::cout<<"\tEstudiante No. "<<i+1<<std::endl;
	 	std::cin.ignore(50, '\n');
        std::cout<<"\nNombre: "; getline(std::cin, (p_alumnos[i].nombre));
        std::cout<<"Sexo: "; std::cin>>p_alumnos[i].sexo;
        std::cout<<"Edad: "; std::cin>>p_alumnos[i].edad;
        std::cout<<"Nota 1: "; std::cin>>p_alumnos[i].promedio.nota1;
        std::cout<<"Nota 2: "; std::cin>>p_alumnos[i].promedio.nota2;
        std::cout<<"Nota 3: "; std::cin>>p_alumnos[i].promedio.nota3;
		std::cout<<std::endl;
    }
}

void imprimirDatos(struct Alumnos *p_alumnos, float promedio, int i){
	std::cout<<"\t<-- ALUMNO CON MAYOR PROMEDIO -->\n"<<std::endl;
	std::cout<<"\n\tEstudiante No. "<<i+1<<std::endl;
	std::cout<<"Nombre: "<<p_alumnos[i].nombre<<std::endl;
	std::cout<<"Sexo: "<<p_alumnos[i].sexo<<std::endl;
	std::cout<<"Edad: "<<p_alumnos[i].edad<<std::endl;
	std::cout<<"Nota 1: "<<p_alumnos[i].promedio.nota1<<std::endl;
	std::cout<<"Nota 2: "<<p_alumnos[i].promedio.nota2<<std::endl;
	std::cout<<"Nota 3: "<<p_alumnos[i].promedio.nota3<<std::endl;
	std::cout<<"\nPromedio General: "<<promedio<<std::endl;
}

int verificarPromedio(struct Alumnos *p_alumnos, float *p_promMayor, int c){
	int flag;
	
	for(int i=0; i<c; i++){
    	float prom = (p_alumnos[i].promedio.nota1 + p_alumnos[i].promedio.nota2 + p_alumnos[i].promedio.nota3) / 3;
    	if(*p_promMayor < prom){
    		*p_promMayor = prom;
			flag = i;
		}
	}
	
	return flag;
}

void limpiarPantalla(){
	system("cls");
}
