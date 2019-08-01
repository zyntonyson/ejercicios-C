#include <stdio.h>   
#include <time.h>
#include <stdlib.h> 
# define LANZAMIENTOS 36000


int **crear_mat();
int dado();
void tirar_dados(int tiros, int **resultados);
void mostrar_resultados(  int **resultados);
void liberar( int **n);


int main () {

int ** resultados=crear_mat();
srand(time(NULL));	

tirar_dados(LANZAMIENTOS, resultados);
liberar(resultados);

return 0;
}

int **crear_mat(int **a){
int i;
int **mat;

mat=(int **)calloc(11,sizeof(int *));

for(i=0;i<11;i++){
	mat[i]=(int *)calloc(2,sizeof(int ));
	mat[i][0]=i+2;
	mat[i][1]=0;
	}
return  mat;
	}


int dado(){
	int tiro;
	tiro= 1 + (rand()%6);
	return tiro;
	}

void tirar_dados(int tiros, int **resultados){
int i;

for(i=0;i<tiros;i++){
int suma_dados= dado()+ dado();	
resultados[suma_dados-2][1]++;}

mostrar_resultados(resultados);
	}
	

void mostrar_resultados(  int **resultados){
	
int i, j;
double p = (double) resultados[5][1]/LANZAMIENTOS;

printf(" ******** RESULTADOS DEL TIRO DE UN PAR DE DADOS %i VECES******** \n", LANZAMIENTOS);
printf("Suma\t Frecuencia \n");
for(i=0;i<11;i++){
		for(j=0;j<2;j++){ printf("%i \t", resultados[i][j]);}
	printf("\n");
	
	
		}
		printf("\nEn la simulación la proporción de la suma 7 es %.3lf.\nEs razonable pensar que es apróx. 1/6",p);	
	}
	

//liberar memoria dinámica

void liberar( int **n){
	int i;
	for(i=0;i<11;i++){
	free(n[i]);
	}
 free(n);
 
	}
