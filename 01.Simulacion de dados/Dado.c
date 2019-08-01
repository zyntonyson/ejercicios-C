// Enteros aleatorios producidos por 1 + rand() % 6.
#include <stdio.h>
#include <stdlib.h>

// funcion main empieza la ejecucion del programa
int main( void )
{
  unsigned int i; // counter

  // ciclo 20 veces

  for (i=1;i <= 20; ++i ) {

    // Toma un numero aleatorio del 1 al  y lo imprime
    printf( "%10d", 1 + ( rand() % 6 ));

    // Si el contador es divisible entre 5 empieza otra linea
    if ( i % 5 == 0 ) {
       puts( "" );
    } // end if
  } // end for
} // end main
