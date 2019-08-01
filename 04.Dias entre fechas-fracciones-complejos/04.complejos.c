#include <stdio.h>   
#include <stdlib.h>  
#include <math.h>

// Tipo de estructura donde se guardara el número complejo
struct complejo{
	float real;
	float imaginario; };

// Alias para la estructura
typedef struct  complejo complejo;

// PROTOTIPOS DE LAS FUNCIONES
void encabezado();
complejo  *ingreso_complejo( int n);
void bienvenida();
void menu(complejo *a);
void suma(complejo *a);
void resta(complejo *a);
void multiplicar(complejo *a);
void dividir(complejo *a);
void regresar(complejo *a);
void salir( );


int main () {
encabezado();
//Indicaciones iniciales
bienvenida( );
// Arreglo donde se guardan las cantidades
complejo *complejos;
complejos= ingreso_complejo(2);
menu(complejos);

// liberar memoria
free(complejos);

return 0;}

/*-------------------------------------------------------------
 *ingreso_complejo(int n )*
 *
 * Se reserva la memoria y se ingresa el par de complejos
 *-----------------------------------------------------------------
 * */
complejo *ingreso_complejo(int n ){

	complejo *predet;
	int i;
	predet= (complejo*) calloc(n, sizeof(complejo));

	if(n>1){
			for(i=0;i<n;i++){
					printf("\n\n---------------Complejo %i---------------\n\n",i+1);
					printf("ingresa la parte real del complejo %i \t",i+1);
					scanf("%f",&(predet+i)->real );
					printf("ingresa la parte imaginaria del complejo %i  (sin agregar a i) \t",i+1);
					scanf("%f", &(predet+i)->imaginario);
					printf("--------------------------------------------------\n\n");
					}// fin for
					}// fin If

return  predet;
	}

/*-------------------------------------------------------------
 *bienvenida()
 *Mensaje de bienvenida
 * -----------------------------------------------------------------
 * */

void bienvenida(){
	puts("¡Hola!, este programa de permite realizar operaciones  con numeros complejos");
	puts("Para comenzar, ingresa un par :");
	}

/*-------------------------------------------------------------
 *suma(complejo *a)
 *Se realiza la suma de complejos
 * -----------------------------------------------------------------
 * */

void suma(complejo *a){

		complejo *resultado=ingreso_complejo(1);

// algoritmo de la suma
		resultado->real= a[0].real + a[1].real;
		resultado->imaginario=a[0].imaginario+ a[1].imaginario;

		printf("\n--------------------SUMA------------------------\n");
		printf("El resultado de la suma es %.3f%+.3fi", resultado->real, resultado->imaginario);
		// liberacion de memoria
		free(resultado);
} // fin suma



/*-------------------------------------------------------------
 *resta(complejo *a)
 *Se realiza la resta de complejos
 * -----------------------------------------------------------------
 * */

void resta(complejo *a){
	complejo *resultado=ingreso_complejo(1);
	// Algoritmo de la resta
	resultado->real= a[0].real - a[1].real;
	resultado->imaginario=a[0].imaginario - a[1].imaginario;

	printf("\n--------------------RESTA------------------------\n");
	printf("El resultado de la resta es %.3f%+.3fi", resultado->real, resultado->imaginario);
	// liberar memoria
	free(resultado);

	}// fin resta

/*-------------------------------------------------------------
 *multiplicar(complejo *a)
 *Se realiza el producto de complejos
 * -----------------------------------------------------------------
 * */

void multiplicar(complejo *a){

complejo *resultado=ingreso_complejo(1);

// algoritmo de la multiplicacion
resultado->real= a[0].real*a[1].real -  a[0].imaginario*a[1].imaginario;
resultado->imaginario=  a[0].real*a[1].imaginario -  a[0].imaginario*a[1].real;

// impresion de resultados
printf("\n--------------------MULTIPLICACIÓN------------------------\n");
printf("El resultado de la multiplicación es %.3f%+.3fi", resultado->real, resultado->imaginario);

// liberar memoria
free(resultado);

	}// fin multiplicar


/*-------------------------------------------------------------
 *dividir(complejo *a)
 *Se realiza el cociente de complejos
 * -----------------------------------------------------------------
 * */

void dividir(complejo *a){


	complejo *resultado=ingreso_complejo(1);
// algoritmo de la división
	float  den= a[1].real*a[1].real + a[1].imaginario*a[1].imaginario;
	resultado->real= (a[0].real*a[1].real -  a[0].imaginario*a[1].imaginario)/den;
	resultado->imaginario=  ( a[0].imaginario*a[1].real - a[0].real*a[1].imaginario )/den;

//Resultados
	printf("\n--------------------DIVISIÓN------------------------\n");
	printf("El resultado de la división es %.3f%+.3fi", resultado->real, resultado->imaginario);
// liberar memoria
	free(resultado);

	}// fin dividir

/*-------------------------------------------------------------
 *Menú(complejo *a)
 *Permite la elección de la operacion a realizar
 * -----------------------------------------------------------------
 * */

void menu(complejo *a){
// seleccion del usuario
unsigned int selec; 
do{
puts("------------------------------Operaciones disponibles--------------------");
puts("");
puts("1. Sumar");
puts("2. Restar");
puts("3. Multiplicación");
puts("4. División");
puts("");
printf("Tu selección:\t");
scanf("%i",&selec);}while(selec<1 || selec>4);
// Segun la elección se redirige a la función adecuada
switch(selec){

case 1:{ suma(a);
				regresar(a);
				break;
	}
case 2:{resta(a);
				regresar(a);
				break;
	}
case 3:{multiplicar(a);
				regresar(a);
				break;
	}
case 4:{dividir(a);
			 regresar(a);
				break;
	}

	}// fin switch

	}// fin menú

/*-------------------------------------------------------------
 *regresar(complejo *a)
 *Permite retornar al menú o salir del progra
 * -----------------------------------------------------------------
 * */


void regresar( complejo *a ){
printf("\n\n\n");
unsigned int selec;
puts("Selecciona  una acción:");
puts("1. Realizar otra operación");
puts("2. Salir");
printf("Tu selección: \t");
scanf("%i",&selec);

if(selec==1){ menu(a);}
else{ salir(); }

	}// fin regresar

/*-------------------------------------------------------------
 *salir()
 *Mensaje antes de salir
 * -----------------------------------------------------------------
 * */

	
void salir( ){
puts("Has decido salir. ¡Hasta pronto! :)");

	}// fin salir

void encabezado(){
printf("--------------------------------------------------------------------------------------");
printf("\n\n");
puts("Maestría en computo estadístico- CIMAT-MTY");
printf("Programación y análisis de algoritmos\n");
puts("Código escrito por: ROMAN CASTILLO C");
printf("\n\n");
printf("--------------------------------------------------------------------------------------");
printf("\n\n");
	}


