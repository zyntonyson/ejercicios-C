// Uso de Arreglos para informacion;
// Calcular media, mediana y moda de los datos
#include <stdio.h>
#define SIZE 99

// Prototipos de funciones
void mean( const unsigned int answer[] );
void median( unsigned int answer[] );
void mode( unsigned int freq[], const unsigned int answer[] ) ;
void bubbleSort( unsigned int a[] );
void printArray( const unsigned int a[] );

// Funcion main que inicia el programa
int main( void )
{
   unsigned int frequency[ 10 ] = { 0 }; // inicializar arreglo con las frecuencias

   // inicializacion de arreglo con los datos
   unsigned int response[ SIZE ] =
      { 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
        7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
        6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
        7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
        6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
        7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
        5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
        7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
        7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
        4, 5, 6, 1, 6, 5, 7, 8, 7 };

   // procesar las respuestas
   mean( response );
   median( response );
   mode( frequency, response );
} // final de main

// calcular la media de todas las respuestas
void mean( const unsigned int answer[] )
{
   size_t j; // Contador del total de las respuestas
   unsigned int total = 0; // variable que contiene la suma de los elementos

   printf( "%s\n%s\n%s\n", "********", "  Media", "********" );

   // Valor total de las respuestas
   for ( j = 0; j < SIZE; ++j ) {
      total += answer[ j ];
   } // end for

   printf( "La media es el valor promedio de los\n"
           "datos. La media es igual al total de los\n"
           "datos dividido por el numero \n"
           "de datos ( %u ). El valor medio de  for\n"
           "esta corrida es: %u / %u = %.4f\n\n",
           SIZE, total, SIZE, (  double  ) total / SIZE );
} // termina funcion

// ordena el arreglo y obtiene el valor de la mediana
void median( unsigned int answer[] )
{
   printf( "\n%s\n%s\n%s\n%s",
           "********", " Mediana", "********",
           "El arreglo no ordenado" );

   printArray( answer ); // salida arreglo no ordenado

   bubbleSort( answer ); // ordena arreglo

   printf( "%s", "\n\nEl arreglo ordenado es" );
   printArray( answer ); // muestra el arreglo ordenado

   // Muestra el elemento de la mediana
   printf( "\n\nLa mediana es el elemento %u of\n"
           "de los datos de tamano %u .\n"
           "Para estos datos la mediana es  %u\n\n",
           SIZE / 2, SIZE, answer[ SIZE / 2 ] );
} // termina funcion media

// determina la frecuencia mas comun
void mode( unsigned int freq[], const unsigned int answer[] )
{
   size_t rating; // contador para accesar los elementos 1-9 del arreglo de frecuencias
   size_t j; // contador para hacer un resument de los elementos del arreglo
   unsigned int h; // contador para mostrar los histogramas
   unsigned int largest = 0; // representa la frecuencia mas grande
   unsigned int modeValue = 0; // representa la frecuencia mas comun

   printf( "\n%s\n%s\n%s\n",
           "********", "  Moda", "********" );

   // Inicializar las frecuencias a 0
   for ( rating = 1; rating <= 9; ++rating ) {
      freq[ rating ] = 0;
   } // end for

   // resumen de frecuencias
   for ( j = 0; j < SIZE; ++j ) {
      ++freq[ answer[ j ] ];
   } // end for

   // encabezados de los resultados de columnas
   printf( "%s%11s%19s\n\n%54s\n%54s\n\n",
           "Respuesta", "Frecuencia", "Histograma",
           "1    1    2    2", "5    0    5    0    5" );

   // Salida resultados
   for ( rating = 1; rating <= 9; ++rating ) {
      printf( "%8u%11u          ", rating, freq[ rating ] );

      // Verificar la moda y el valor mas alto
      if ( freq[ rating ] > largest ) {
         largest = freq[ rating ];
         modeValue = rating;
      } // end if

      // salida del histograma con las barras representando frecuencia
      for ( h = 1; h <= freq[ rating ]; ++h ) {
         printf( "%s", "*" );
      } // end inner for

      puts( "" ); // nueva linea de salida
   } // end outer for

   // Muestra el valor de la moda
   printf( "\nLa moda es el valor mas frecuente\n"
           "Para estos datos la moda es %u que ocurrio"
           " %u veces.\n", modeValue, largest );
} // end function mode

// Funcion que ordena un arreglo con el algoritmo de burbuja
void bubbleSort( unsigned int a[] )
{
   unsigned int pass; // contador paso
   size_t j; // contador comparacion
   unsigned int hold; // locacion temporal para intercambiar elementos

   // ciclo de control del numero de pasos
   for ( pass = 1; pass < SIZE; ++pass ) {

      // Ciclo para controlar el numero de comparaciones por paso
      for ( j = 0; j < SIZE - 1; ++j ) {

         // Intercambia elementos si estan fuera de orden
         if ( a[ j ] > a[ j + 1 ] ) {
            hold = a[ j ];
            a[ j ] = a[ j + 1 ];
            a[ j + 1 ] = hold;
         } // end if
      } // end inner for
   } // end outer for
} // termina funcion

// muestra contenidos arreglo (20 valores por renglon)
void printArray( const unsigned int a[] )
{
   size_t j; //contador

   // mostrar valores arreglo
   for ( j = 0; j < SIZE; ++j ) {

      if ( j % 20 == 0 ) { // comenzar nueva linea cada 20 valores
         puts( "" );
      } // end if

      printf( "%2u", a[ j ] );
   } // end for
} // end function printArray


