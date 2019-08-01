/*		PROGRAMACION Y ANÁLISIS DE ALGORITMOS
 *
 * 		TAREA 3.  EJERCICIO 2
 *
 * Escrito por :  Román Castillo Casanova
 *Fecha de entrega:  7/09/2018
 *
 * Descripción: Este programa convierte los dígitos de un número de 7 cifras a una palabra tambien
 * de 7 letras.  Tomando en cuenta que cada dígito tiene asignado más de una letra, se muestran
 * todas las posibles permutaciones de palabras.  Las palabras se guardan en un archivo  en la
 * computadora
 *
 * */


#include <stdio.h>   
#include <stdlib.h>  


FILE *tarea; // Puntero al archivo "palabras.dat"


/*PROTOTIPOS DE LAS FUNCIONES*/
// Recodifica el número telefónico ingresado para ser leído como caracteres
int *ingresar_numero();
// Genera las permutaciones de cada número
void permutaciones( int *telefono);


int main () {

	int *telefono;
	tarea = fopen( "palabras.dat", "w+" );
	if ( tarea == NULL ) {
		puts( "El archivo de guardado no puede abrirse" );
		}	 // end if
	else {
		telefono = (int *) ingresar_numero(); // Se crea el número de telefono codificado
		permutaciones (telefono);
		}// fin else
	fclose( tarea); // Se cierra el archivo .dat
	return 0;
}


/*-------------------------------------
 * ingresar_numero():
 * Se pide al usuario que ingrese un número de  7 dígitos, se verifica que esten en el rango
 * de 2:9. Una vez ingresados son codificados para ser leídos como caracter.
 * -------------------------------------*/

int *ingresar_numero(){

int digito; //  variable auxilar
int i;  // iterador
int *vec; //  vector auxiliar
vec=(int *) calloc(7,sizeof(int ));

	// Se pide al usuario que ingrese los dígitos uno a uno
	printf("Ingresa un número de 7 dígitos, ingresando los dígitos uno a uno \n");
	printf("Solo se permiten números con dígitos de 2:9 \n\n\n");
		// Se crean encabezados en el  archivo.dat
    fprintf(tarea,"\n------PALABRAS POSIBLES CON UN NÚMERO TELEFÓNICO------\n" );
	fprintf(tarea,"El número ingresado es:  \t");	

       // Ingreso de datos
	for(i=0;i<7;i++){
		printf("Ingresa el %i ° digito \n", i+1);
		scanf("%i",&digito);

			// Se verifica que solo se usen dígitos del 2:9
		while(digito<2 || digito>9){ // Se evita el ingreso de cantidades ajenas de 2:9
			printf("Dígito invalido, ingresa de nuevo el digito % i° \n",i+1);
			scanf("%i",&digito);
				}// fin de while
			
		// Se guarda el número ingresado en el archivo .dat
		fprintf(tarea,"%i", digito);
		
		   /* Conversión de los dígitos a asciI,  se asigna a cada dígito por defecto
		    * la primera letra que le corresponde  representa por el valor ascii.  Por ejemplo:
		    * ->dígito 2 comienza con A, esta en ASCII es 65
		    * ->dígito 3 comienza con D, esta en ASCII es 68
		    * ->dígito 3 comienza con G, esta en ASCII es 71.
		    * Dado lo anterior se establece que la conversión del dígito a su ASCII correspondiente es:
		    *              ASCII=3*digito +59 */
		vec[i]= (3* digito +59); 

	}// fin de for
	// Se devuelve el puntero del número codificado
	return vec;
}// fin ingresar_numero()


/*-------------------------------------
 * permutaciones():
 * Recibe el puntero del número codificado, crea permutaciones base 3 que simulan las diversas
 * combinaciones de letras por casilla. Cada permutacion se lee como caracter, para las diferentes
 * palabras 
 * -------------------------------------*/

void permutaciones( int *telefono){
	int j=0,i; // Contador de palabras
	int n=7; // Longitud del numero telefonico
	int vec[]={0,0,0,0,0,0,0}; // vector auxiliar donde se realizan las  permutaciones
	int posicion;  // variable auxilar

	// Texto inicial de salida al documento
	printf("\n\n---------------------- PALABRAS  FORMADAS----------------------\n\n" );
    fprintf(tarea,"\n----------------------------------------------------------------------------------\n" );
	fprintf(tarea,"\n\nLas palabras formadas son: \n" );

	// Se imprime la primera palabra correspondiente al  número codificado
	// se muestra en pantalla y se guarda en el archivo
	printf("Palabra 1 ° :  " );
	fprintf(tarea,"Palabra 1 ° :  " );

	for(i=0;i<n;i++){printf("%c", telefono[i]);
		fprintf(tarea,"%c", telefono[i]);
	}//fin for
	printf("\n");
	fprintf(tarea,"\n");



	// Se simula el funcionamiento de un contador, se aumenta uno de manera constante
	// cada espacio solo puede ir de 0 a 2, cuando se llega a 2, se reinicia a cero
	// y se aumenta uno a la posicion anterior (Conversión a número base 3).

	while(vec[0] <3  ){
		posicion=n-1; 
		vec[n-1]++;  

		while(posicion > 0){
			if(vec[posicion]>2){ vec[posicion]=0;  vec[posicion-1]++ ;}
			posicion--;
			}// fin while

		j++;
		if(vec[0]<3){
			printf("Palabra %i ° :  ", j+1 );
			fprintf(tarea,"Palabra %i ° :  ", j+1 );

			for(i=0;i<n;i++){

				// debido a que no se utiliza la "q" se realiza el  salto de una letra 
				if(vec[i]+telefono[i]<81){printf("%c", vec[i]+telefono[i]);// pantalla
				fprintf(tarea,"%c", vec[i]+telefono[i]);
				}// fin If
				
				else{printf("%c", (vec[i]+telefono[i]+1));
				fprintf(tarea,"%c", (vec[i]+telefono[i]+1));}
			}//fin del for
			
			printf("\n");
			fprintf(tarea,"\n");

			}//fin if
		}// fin while
	printf("\nLas palabras fueron guardadas en el archivo palabras.dat\n");
	}// fin permutacion();
