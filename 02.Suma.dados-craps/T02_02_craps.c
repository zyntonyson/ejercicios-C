#include <stdio.h>   
#include <time.h>
#include <stdlib.h> 
# define JUEGOS  10000000


int **crear_mat();
int dados(); // simula el lanzamiento de un par de dados, regresa la suma
void craps(int juegos, int **resultados); // La función realiza la simulación de los juegos
void mostrar_resultados(  int **resultados, int sum);
void liberar( int **n);


int main () {

int ** resultados=crear_mat();
srand(time(NULL));	

craps(JUEGOS, resultados);
liberar(resultados);
return 0;
}


// Matriz  de resultados // Se guardan los resultados en la tabla de 3*21
int **crear_mat(int **a){
int i;
int **mat;

mat=(int **)calloc(21,sizeof(int *));

for(i=0;i<21;i++){
	mat[i]=(int *)calloc(3,sizeof(int ));
	mat[i][0]=i+1;}
return  mat;
	}


// Simulación del tiro de  dos  dados
int dados(){
	int tiro, dado1, dado2;
	dado1= 1 + (rand()%6);
	dado2= 1 + (rand()%6);
	tiro=dado1+dado2;
	
	return tiro;
	}


// simulación del  juego
void craps(int juegos, int **resultados){
int i,tiro, saque;
int  lanzamientos=0, sum=0; // acumuladores
int game_over=0; // juego terminado=1 , juego continua=0
int ganador=0;  //ganador=1 ,  no ganador=0


for( i=0; i<juegos;i++){
	saque= dados(); // primer lanzamiento
	lanzamientos++;
      	
     // el juego termina si  sale un 2,3 ,11, 12
	if(saque==7 || saque==11){ganador=1;game_over=1;}
	if(saque==2 || saque==3|| saque==12){game_over=1;}

	if(game_over==0){// si el juego no termina, se asigna meta
			while(game_over==0 && lanzamientos<=50){ // Si son más de 50 lanzamientos
				                                                                                   // el juego termina
					tiro= dados();
					lanzamientos++;
					if(tiro==saque){game_over=1;  ganador=1;}
					if(tiro==7){game_over=1;  ganador=0;}
			}}// fin  if/while
     //Se suman todos los lanzamientos  para calcular el promedio
      sum+=lanzamientos;
     if(lanzamientos>20){resultados[20][ganador+1]++;}// contador para +20
	else{  resultados[lanzamientos-1][ganador+1]++; }// contador de tiros
	
	// reinicio de las condiciones del primer lanzamiento
    lanzamientos=0;
	ganador=0;
	game_over=0;
	}//  fin del for de repeticiones
	
	
	
mostrar_resultados(resultados, sum);
	}

// Impresión de resultados
void mostrar_resultados(  int **resultados, int sum){
	
int i, j;
int ganados=0;			
for(i=0;i<21;i++){ganados+= resultados[i][2]; }

printf(" ******** RESULTADOS DE LA SIMULACIÓN******** \n");
printf("Pregunta 2.1  \n");

printf("Juegos ganados  \n");
printf("TIROS  GANADOS \n");
for(i=0;i<20;i++){
		for(j=0;j<3 ;j++){ if(j!=1){printf("%i \t", resultados[i][j]);}}
printf("\n");}
printf("+20\t%i \n\n\n",resultados[20][2]);

printf("Pregunta 2.2  \n");
printf("Juegos perdidos  \n");
printf("TIROS  PERDIDOS \n");
for(i=0;i<20;i++){
		for(j=0;j<3 && j!=2;j++){ printf("%i \t", resultados[i][j]);}
printf("\n");}
printf("+20\t%i \n\n\n",resultados[20][1]);


printf("Pregunta 2.3 \n");
printf("La probabilidad de ganar en el juego es de  %.3f \n\n\n", (ganados/(float)JUEGOS));			

printf("Pregunta 2.4 \n");
printf("En promedio se necesitan  %.3f  tiros para ganar el juego \n\n\n", (sum/(float)JUEGOS));	

printf("Pregunta 2.5 \n");
printf("El primer tiro da mayor posibilidad de ganar que de perder que cualquier cantidad de tiros \n ");
printf("posteriores, en donde la relación entre ganar y perder se  mantiene practicamente constante\n ");
printf("Entonces, las probabilidades de ganar no aumentan con el número de tiros que se hacen\n ");


}


//liberar memoria dinámica
void liberar( int **n){
	int i;
	for(i=0;i<21;i++){
	free(n[i]);
	}
 free(n);}
