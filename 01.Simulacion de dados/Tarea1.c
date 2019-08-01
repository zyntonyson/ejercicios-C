#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void tirar_dados(  int n);

int main (){

srand(time(NULL));
int n;
printf("¿ Cuantos lanzamientos desea realizar?\n");
scanf("%i",&n);
tirar_dados(n);

return 0;}



void tirar_dados( int n){

	int tiro,i,j,seq=0,rep=0;
	int anterior= 10;
	int mas_repetido,max_rep=0, max_seq=0;

	// tabla de resultados iniciada en ceros
	int tabla [2][6];
	for(i=0;i<6;i++){
		tabla[0][i]=(1+i);
		tabla[1][i]=0;
		}

	for (i=1;i <=n;++i) {

    tiro = 1 + ( rand() % 6 );

 //conteo de los tiros
    switch(tiro){
		case 1: tabla[1][0]++; break;
		case 2: tabla[1][1]++; break;
		case 3: tabla[1][2]++; break;
		case 4: tabla[1][3]++; break;
		case 5: tabla[1][4]++; break;
		case 6: tabla[1][5]++; break;}

// cadena más larga de un mismo número

	if(tiro==anterior){rep++;}
	else{
		if(rep>max_rep){
		max_rep=rep;
		mas_repetido=anterior;}
		rep=0;}



// veces que aparece "123456"

	if(tiro==(anterior+1))
        {seq++;
        if(seq==5)
            {max_seq++;};
        }
	else{seq=0;}


//guardar tiro anterior

	anterior=tiro;
    }


 //IMPRESION DE RESULTADOS

    //frecuencias de los tiros por números
    printf("\n---TABLA DE TIROS---\n");
    printf("Numero\t Frecuencia\n");
    for(i=0;i<6;i++){
		for(j=0;j<2;j++){

    printf( "%i \t",tabla[j][i]);}printf("\n");}

    //Repetición más larga
    printf("\n");
    printf("---Repeticion mas larga---\n");
    printf("Numero mas repetido: %i \n",mas_repetido);
    printf("Largo de la cadena:%i \n",max_rep);
    printf("\n");

    //veces de la secuencia
    printf("\n\n");
    printf("---Conteo de la secuencia 123456---\n");
    printf("veces que aparece la secuencia:%i \n",max_seq);




    }//fin tirar_dado()
