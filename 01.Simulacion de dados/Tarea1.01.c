#include <stdio.h>
#include <time.h>
#include <stdlib.h>
# define TIROS 6000000

int **crear_mat();
void tirar_moneda(  int n, int **resultados);
void mostrar_resultados(  int n,  int **resultados);
void liberar( int **n);

int main (){
srand(time(NULL));

int **resultados;

resultados=crear_mat();

printf("******LANZAMIENTO DE UNA MONEDA %i VECES*****\n\n", TIROS);
tirar_moneda(TIROS, resultados);

liberar( resultados);

return 0;}



void tirar_moneda( int n, int **resultados){

	int tiro,i; //contadores
	int max_seq=0,seq=0; // acumulador de datos para secuencia
    int anterior= 0;// valor  arbitrario, solo para iniciar la variable

    //------------------------------
  // Se hace la simulación de  los  (n-1) tiros  restantes y se guardan frecuencias

  for (i=1;i <=n-1;++i) {
	  tiro = 1 + ( rand() % 6 );

    //------------------------------
    //conteo de los tiros: se aumenta en un  1, la casilla correspondiente al número

      resultados[tiro-1][1]++;
     //------------------------------
    // cadena más larga de un mismo número: compara el tiro actual con el anterior
    //verifica que sean iguales, en cuyo caso aumenta un contador. Si son diferentes
    //verifica si la repitición es la máxima registrada.

        if(anterior!=0){ // dado que 0 no está en el rango se pone la condición (segmentation fault)
		if(tiro==anterior){resultados[anterior-1][3]++;}
		if(resultados[anterior-1][3]>resultados[anterior-1][2] )
		{resultados[anterior-1][2]=resultados[anterior-1][3];}
		if(tiro!=anterior){resultados[anterior-1][3]=1;}



	//------------------------------
	// veces que aparece "123456" : verifica que se encuentre una
	//cadena de 5 consecutivos   desde n

	if(tiro==(anterior+1)){seq++; if(seq==5){max_seq++;};}
	else{seq=0;}}

    //-----guardar tiro para usarse en el siguiente ciclo
	anterior=tiro;
   }//fin del for

   mostrar_resultados(  max_seq, resultados); //imprimir

    }//fin tirar_dado()


// Crea una matriz para presentar los resultados, primera columna
// se rellena de 1:6, segunda y tercera
//se rellenan con ceros,  en estas se guarda la frecuencia de cada número
//y la longitud de la cadena
//más larga de su repetición

int **crear_mat(int **a){
int i,j;
int **mat;

mat=(int **)calloc(6,sizeof(int *));

for(i=0;i<6;i++){
	mat[i]=(int *)calloc(4,sizeof(int ));
	mat[i][0]=i+1;
	mat[i][1]=0;
	for(j=2;j<4;j++){
		mat[i][j]=1;}}
return  mat;
	}


// Imprime los resultados obtenidos de la simulación


void mostrar_resultados(  int n,  int **resultados){
	int i,j;

	//frecuencias de los tiros por números

    printf("\n---TABLA DE  LANZAMIENTOS---\n");
    printf("Numero\t Frecuencia\t Max. rep \n");
    for(i=0;i<6;i++){
		for(j=0; j<3 ;j++)
		{printf( "%i       ",resultados[i][j]);}printf("\n");}

    //Veces de la secuencia
    printf("\n");
    printf("---Conteo de la secuencia 123456---\n");
    printf("veces que aparece la secuencia: %i ", n);

   }

//liberar memoria dinámica

void liberar( int **n){
	int i;
	for(i=0;i<6;i++){
	free(n[i]);
	}
 free(n);

	}
