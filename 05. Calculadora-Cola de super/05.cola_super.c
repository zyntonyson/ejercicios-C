
#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>
#define JORNADA 720
#define INTERVALO 4

// estructura autoreferencial
// A cada cliente se le asigna un número de llegada y su hora de salida
struct turnocola {
   int numCliente;
   int salida; 
   struct turnocola *sigPtr; 
}; //

typedef struct turnocola turno;
typedef turno *turnoap;

// PROTOTIPOS
void encabezado( );
int esVacio( turnoap cabezaPtr );
void quitarCola( turnoap *cabezaPtr, turnoap *ColaPtr, int *datos );
void ponerCola( turnoap *cabezaPtr, turnoap *ColaPtr, int *datos);
int duracion( );


int main(  )
{
	encabezado( );
   turnoap cabezaPtr = NULL; // inicializar cabezaPtr
   turnoap ColaPtr = NULL; // inicializar ColaPtr
	
	// Generador de  tiempos aleatorios	
	srand(time(NULL));
	// minutos del día
	int tiempo; 
	
	/* vector para concentrar  datos
	* datos= hora de llegada el próximo cliente
	* datos+1= # de cliente del día
	* datos+2= tiempo de espera en la cola
	* datos+3= clientes en espera o en atención
	* datos+4= tiempo máx. de espera en la cola
	* datos+5= clientes  máx. en espera o en atención
		*/ 
	int  *datos;
	datos=(int *)calloc(6,sizeof(int ));

    //Asignación a la llegada del primer cliente
	*datos=duracion();
  

	//INICIO DE LA SIMULACIÓN
	for(tiempo=1;tiempo<=JORNADA;tiempo++)
	{
		
		printf("Minuto %i:\n", tiempo);

		// un cliente llega y se acomoda en la cola
		if(tiempo==(*datos)&&*datos<=JORNADA)
		{
			 ponerCola( &cabezaPtr, &ColaPtr, datos );
			 //programar  hora de llegada siguiente cliente
			 *datos+=duracion( );
			 if(*datos<=JORNADA)
			 {
				printf("\tSe espera al cliente#%i al minuto %i\n",*(datos+1)+1,*datos);
			 }
		}// fin ingreso de cliente

			//----llega salida de un cliente---//

			//verificar si existe una cola
			if(cabezaPtr!=NULL)
			{ 
			//coincidencia con hora de salida
			if(tiempo == cabezaPtr->salida)
			{

			quitarCola(&cabezaPtr, &ColaPtr, datos);
			}// fin coincidencia de tiempo de salida
			}// fin verificacion cola


			// Actualizar datos para el siguiente minuto
			
			//Verificar tiempo máximo de espera
			if(*(datos+2)>*(datos+4)){*(datos+4)=*(datos+2);}
             //Verificar  máximo de clientes en espera
			if(*(datos+3)>*(datos+5)){*(datos+5)=*(datos+3);}
			
			// Dismuir tiempo de espera por paso natural de tiempo
					*(datos+2)-=1;
					if(*(datos+2)<0) *(datos+2)=0;
					printf("\tClientes en la cola al momento:%i\n",*(datos+3));
			
	}//fin for simulacion JORNADA

		//Resumen
		puts("\n\n---------------------------------------Resumen de la jornada---------------------------------------");
		printf("\n\nDurante la jornada se recibieron %i clientes\n",*(datos+1));
		printf("La cantidad máxima de clientes en la cola  fue de  %i \n",*(datos+5));
		printf("El tiempo máximo que estuvo un cliente desde su ingreso  fue de %i minutos\n",*(datos+4));
		puts("\nSe observa que al hacer más pequeño el tiempo de ingreso, los tiempo en\n"
					"cola aumentan, y por tanto el tiempo de espera de cliente para su atención.\n"
					"Esto puede verificarse cambio el valor de INTERVALO\n"
							"------------------------------------------------------------------------------------------------------------------");
		free(datos);
return 0;
}// fin de main

// insertar un nodo al final de la cola
void ponerCola( turnoap *cabezaPtr, turnoap *ColaPtr, int *datos )
{
	// puntero a un nuevo ingreso
	turnoap nuevoPtr; 
	nuevoPtr = (turnoap)malloc( sizeof( turno ) );

	if ( nuevoPtr != NULL )
	{ // hay espacio disponible

		//asignar número al nuevo cliente
		*(datos+1)+=1;

		//Asignar tiempo de espera del cliente
		*(datos+2)+=duracion();

		//Asignar datos al nuevo cliente
		nuevoPtr->numCliente = *(datos+1);
		nuevoPtr->salida = *(datos+2)+*datos;
		nuevoPtr->sigPtr = NULL;


		// Verificar si la cola está vacía
		if ( esVacio( *cabezaPtr ) )
		{
			*cabezaPtr = nuevoPtr;
		}
		else
		{
			( *ColaPtr )->sigPtr = nuevoPtr;
		}

		*ColaPtr = nuevoPtr;
		printf("\tIngresa el cliente %i a la cola. Sale al minuto %i\n", (*ColaPtr)->numCliente,(*ColaPtr)->salida);
	}//fin If espacio disponible
	else
	{
		printf( "Memoria insuficiente para colocar el nodo.\n" );
	}
	// Aumentar conteo de clientes en fila
	*(datos+3)+=1;

} // fin ponerCola


// quitar nodo del principio/head de la cola
void quitarCola( turnoap *cabezaPtr, turnoap *ColaPtr , int *datos)
{

	// apuntador temporal
	turnoap tempPtr; 

	// Redireccion de punteros para eliminar
	tempPtr = *cabezaPtr;
	*cabezaPtr = ( *cabezaPtr )->sigPtr;

	// si la cola esta vacia
	if ( *cabezaPtr == NULL )
	{
		*ColaPtr = NULL;
	}

	printf("\tEl cliente #%i ha salido\n",tempPtr->numCliente);
	free( tempPtr );

	// Actualizar cantidad de clientes en la cola
	*(datos+3)-=1;
} // fin quitarCola

	int duracion( ){
return (1+ rand( )%INTERVALO);

	}

// regresa 1 si la cola esta vacia, 0 de otra manera
int esVacio( turnoap cabezaPtr )
{
   return cabezaPtr == NULL;
} // fin esVacio

void encabezado( ){
puts(
"****************************************************************************************\n"
"\n\tPROGRAMACIÓN Y ANÁLISIS DE ALGORITMOS\n"
"\t\tTAREA 5: Estructura de datos\n"
"\tCódigo escrito por: Román Castillo Casanova\n"
"Descripción:El programa simula el ingreso y salida de clientes en una cola durante una\n"
"jornada. Se utiliza la estructura de cola para la simulación\n"
"\n"
"****************************************************************************************\n"
);

	}

