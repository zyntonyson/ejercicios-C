#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>
#include <math.h>

//Estructura que contendrá los resultados de las evaluaciones numéricas
struct nodo{
double operando;
struct nodo *sig;
	};

//Alias para la estructura y su puntero
typedef struct nodo nodo;
typedef nodo *nodoPtr;

//PROTOTIPOS DE FUNCIONES
double evaluarExpresionPostfija ( char *postfija);
double calcular( double op1, double op2, char operador);
void push( nodoPtr *inicio, double valor);
double pop(nodoPtr *inicio);
int esVacio(nodoPtr inicio);
void imprStack( nodoPtr actualPtr );
void encabezado( );

int main ( ) {
   //presentacion del código
	encabezado();
	// Se reserva memoria para ingresar la expresión postfija
	char *postfija;
	postfija=(char *)calloc(40,sizeof(char));
	puts("Ingresa una expresión postfija correcta:\n"
				"\tEjemplo:54+8-234**-\n\n:"	);
	scanf("%s",postfija);

	//  lSe realiza la evalación e impresión de la expresión
	printf("\n\nEl resultado es %.3lf",evaluarExpresionPostfija(postfija));


return 0;}



double evaluarExpresionPostfija ( char *postfija){
	//Puntero a la cabeza de la pila
	nodoPtr inicio=NULL;
	// contenedores de lectura de los caractéres
	char token, operador;
	// Contador
	int i;
	// Contenedores temporales de resultados
	double valor,op1,op2;

		//Lectura de la cadena caracter a caracter
	for(i=0;i<strlen(postfija);i++){
		//detectar si un caracter es un dígito (usando ASCII)
	if(postfija[i]>47 &&postfija[i]<58)
	{

		token=postfija[i];
		// conversión a flotante
		valor=atof(&token);
		//push a la pila
		push( &inicio, valor );

	}
	else
	{
		// se detecta un operador
		operador=postfija[i];

		// Se obtienen dos números de la pila para hacer la operacion
		if( !esVacio( inicio ) )
		{
			op2=pop( &inicio );
		 }

		if( !esVacio( inicio ) )
		{
			op1=pop( &inicio );
		 }

		//resultado de la operación y push a la pila
		push(&inicio,calcular(op1,op2,operador));

	}// fin else

	}//fin for **lectura de la expresión



return (pop( &inicio ));

	}

	
double calcular( double op1, double op2, char operador){
// Determinar el tipo de operación segun el operador detectado
	switch(operador){
				case '+': {return(op1+op2);
								  break;
								  }
				case '-': {return(op1-op2);
								  break;
								  }
				case '*': {return(op1*op2);
								  break;
								  }
				case '/': {return(op1/op2);
								  break;
								  }
				case '^': {return(pow(op1,op2));
								  break;
								  }	             
		}

	
	return 0;}// fin calcular

// Ingresar un valor a pila	
void push( nodoPtr *inicio, double valor){
nodoPtr nuevo; // pointer to new node

   nuevo =(nodoPtr) malloc( sizeof( nodo ) );

   // insertar el nodo al principio del stack
   if ( nuevo != NULL ) {
      nuevo->operando = valor;
      nuevo->sig = *inicio;
      *inicio = nuevo;
   }
   else { // no espacio disponible
      printf( "%f no  se ha insertado. No hay memoria disponible.\n", valor );
   }
	}//fin push

// eliminar un valor de la pila
double pop(nodoPtr *inicio){
 nodoPtr temp; // puntero temporal del nodo
   double valor_borrado; // valor del nodo

   temp = *inicio;
   valor_borrado = ( *inicio )->operando;
   *inicio = ( *inicio )->sig;
   free( temp);
   return valor_borrado;

	}// fin pop

	//verificar si la pila está vacía
int esVacio(nodoPtr inicio){
 return inicio == NULL;
	
	}// fin esVacio

	
void imprStack( nodoPtr actualPtr )
{
   // si el stack esta vacio
   if ( actualPtr == NULL ) {
      puts( "La pila  está vacio.\n" );
   } //
   else {
      puts( "La pila es:" );

      // while  no sea el final del stack
      while ( actualPtr != NULL ) {
         printf( "%lf--> ", actualPtr->operando );
         actualPtr = actualPtr->sig;
      } // end while

      puts( "NULL\n" );
   }
}

//instrucciones
	void encabezado( ){
puts(
"****************************************************************************************\n"
"\n\tPROGRAMACIÓN Y ANÁLISIS DE ALGORITMOS\n"
"\t\tTAREA 5: Estructura de datos\n"
"\tCódigo escrito por: Román Castillo Casanova\n"
"Descripción:El programa  permite la evaluación de una expresión postfija, devolviendo\n"
"el resultado de la expresión. Usa la estructrura de datos stack para el proceso\n"
"****************************************************************************************\n\n\n\n"
);

	}

