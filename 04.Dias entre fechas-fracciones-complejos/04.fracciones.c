#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Estructura de fracci�n
struct fraccion{
int numerador;
int denominador;
	};
//Alias para la estructura
typedef struct fraccion fraccion;

//PROTOTIPOS DE LAS FUNCIONES
fraccion  *ingreso_fraccion( int n);
void bienvenida();
void regresar(fraccion *a);
void menu(fraccion *a);
int mcd(int a, int b);
void suma(fraccion *a);
void resta(fraccion *a);
void simplificar(fraccion *a);
void multiplicacion(fraccion *a);
void division(fraccion *a);
void salir( );
void encabezado();

int main ( ) {
encabezado();
bienvenida( );
fraccion *fracciones;
fracciones= ingreso_fraccion(2);
menu(fracciones);

// liberacion de la memoria
free(fracciones);
return 0;}

/*-------------------------------------------------------------
 *ingreso_fraccion()
 *Reserva memoria y se ingresa las fracciones a operar
 * -----------------------------------------------------------------
 * */


fraccion *ingreso_fraccion(int n ){

	fraccion *predet;
	int i;
	predet= (fraccion*) calloc(n, sizeof(fraccion));

	if(n>1){
			for(i=0;i<n;i++){
							printf("\n\n---------------Fracci�n %i---------------\n\n",i+1);
							printf("ingresa el numerador de la  fracci�n %i \t",i+1);
							scanf("%i",&(predet+i)->numerador );
							printf("ingresa el denominador de la  fracci�n %i \t",i+1);
							scanf("%i", &(predet+i)->denominador);
							printf("--------------------------------------------------\n\n");
							}// fin for
							}// fin if

return  predet;
	}
/*-------------------------------------------------------------
 *mcd()
 *Calculo del MCD  usando el algoritmo de E�clides
 *Referencia:
 * https://es.wikibooks.org/wiki/Implementaci%C3%B3n_de_algoritmos_de_teor%C3%ADa_de_n%C3%BAmeros/Algoritmo_de_Euclides
 * -----------------------------------------------------------------
 * */


 int mcd(int a, int b){

     return (b == 0)? a : mcd(b, a % b);
 } //fin mcd


/*-------------------------------------------------------------
 *suma()
 *Se realiza la suma
 * -----------------------------------------------------------------
 * */


void suma(fraccion *a){
		fraccion *resultado=ingreso_fraccion(1);

//Algoritmo de la suma
		resultado->numerador= a[0].numerador*a[1].denominador + a[1].numerador*a[0].denominador;
		resultado->denominador=a[0].denominador*a[1].denominador;
		simplificar(resultado);
// Impresi�n de resultados
		printf("\n--------------------SUMA------------------------\n");
		printf("La suma de las fracciones es %i/%i", resultado->numerador, resultado->denominador);
//Liberaci�n de memoria
		free(resultado);

} //fin suma


/*-------------------------------------------------------------
 *Resta()
 *Se realiza la resta
 * -----------------------------------------------------------------
 * */

void resta(fraccion *a){
fraccion *resultado=ingreso_fraccion(1);

//Algoritmo de la resta
resultado->numerador= a[0].numerador*a[1].denominador - a[1].numerador*a[0].denominador;
resultado->denominador=a[0].denominador*a[1].denominador;
simplificar(resultado);

// Impresion de resultados
printf("\n--------------------RESTA------------------------\n");
printf("La resta de las fracciones es %i/%i", resultado->numerador, resultado->denominador);

// liberaci�n de memoria
free(resultado);
	}

/*-------------------------------------------------------------
 *Multiplicaci�n()
 *Se realiza el producto
 * -----------------------------------------------------------------
 * */

void multiplicacion(fraccion *a){
		fraccion *resultado=ingreso_fraccion(1);

//Algoritmo multiplicaci�n
		resultado->numerador= a[0].numerador*a[1].numerador;
		resultado->denominador=a[0].denominador*a[1].denominador;
		simplificar(resultado);

// Resultados
		printf("\n--------------------MULTIPLICACI�N------------------------\n");
		printf("La multiplicaci�n de las fracciones es %i/%i", resultado->numerador, resultado->denominador);

//Liberar memoria
		free(resultado);
	}// fin multiplicacion

/*-------------------------------------------------------------
 *Divisi�n()
 *Se realiza la divisi�n
 * -----------------------------------------------------------------
 * */

void division(fraccion *a){

		fraccion *resultado=ingreso_fraccion(1);
//Algoritmo  divisi�n
		resultado->numerador= a[0].numerador*a[1].denominador;
		resultado->denominador=a[0].denominador*a[1].numerador;
		simplificar(resultado);

		printf("\n--------------------DIVISI�N------------------------\n");
		printf("La divisi�n de las fracciones es %i/%i", resultado->numerador, resultado->denominador);
// liberacion de memoria
		free(resultado);
	}// fin multiplicacion


/*-------------------------------------------------------------
 *SImplificar ()
 *Se reduce la fracci�n a su m�nima expresi�n usando el MCD y se realiza el ajuste de signos entre
 * numerador y denomidor
 * -----------------------------------------------------------------
 * */

void simplificar(fraccion *a){

		int simpl= mcd(abs(a->numerador),abs(a->denominador));
// Se divide numerador y denominador entre el MCD
		a->numerador/=simpl;
		a->denominador/=simpl;

// Se determina el signo global de la fracci�n
		if(a->denominador*a->numerador<0){
		a->numerador= -abs(a->numerador);
		a->denominador= abs(a->denominador);
			}
		else{
		a->numerador= abs(a->numerador);
		a->denominador= abs(a->denominador);
			}

	}// fin simplificar

/*-------------------------------------------------------------
 *bienvenida()
 *Mensaje inicial del programa
 * -----------------------------------------------------------------
 * */

void bienvenida(){
	puts("�Hola!, este programa de permite realizar operaciones aritm�ticas con fracciones");
	puts("Para comenzar ingresa un par de fracciones:");
	}


/*-------------------------------------------------------------
 *regresar()
 *Permite acceder de nuevo al menu o terminar el programa
 * -----------------------------------------------------------------
 * */


void regresar( fraccion *a ){
	printf("\n\n\n");
	unsigned int selec;
	puts("Selecciona  una acci�n:");
	puts("1. Realizar otra operaci�n");
	puts("2. Salir");
	printf("Tu selecci�n: \t");
	scanf("%i",&selec);

	if(selec==1){
		menu(a);}
	else{ salir(); }

	}// fin regresar

/*-------------------------------------------------------------
 *Men�()
 *Permite la selecci�n de las operaciones disponibles
 * -----------------------------------------------------------------
 * */

void menu(fraccion *a){
		unsigned int selec;
		do{
				puts("------------------------------Operaciones disponibles--------------------");
				puts("");
				puts("1. Sumar");
				puts("2. Restar");
				puts("3. Multiplicaci�n");
				puts("4. Divisi�n");
				puts("");
				printf("Tu selecci�n:\t");
				scanf("%i",&selec);}while(selec<1 || selec>4);
		switch(selec){

				case 1:{ suma(a);
								regresar(a);
								break;
					}
				case 2:{resta(a);
								regresar(a);
								break;
					}
				case 3:{multiplicacion(a);
								regresar(a);
								break;
					}
				case 4:{division(a);
							 regresar(a);
								break;
					}

					}// Fin switch

	}// fin men�

/*-------------------------------------------------------------
 *Salir()
 *Despedida antes de salir del programa
 * -----------------------------------------------------------------
 * */


void salir( ){
puts("Has decido salir. �Hasta pronto! :)");

	}


void encabezado(){
printf("--------------------------------------------------------------------------------------");
printf("\n\n");
puts("Maestr�a en computo estad�stico- CIMAT-MTY");
printf("Programaci�n y an�lisis de algoritmos\n");
puts("C�digo escrito por: ROMAN CASTILLO C");
printf("\n\n");
printf("--------------------------------------------------------------------------------------");
printf("\n\n");
	}
