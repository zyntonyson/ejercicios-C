/*		PROGRAMACION Y ANÁLISIS DE ALGORITMOS
 *
 * 		TAREA 3.  EJERCICIO 1
 *
 * Escrito por :  Román Castillo Casanova
 *Fecha de entrega:  7/09/2018
 *
 * Descripción: Este programa  es un control de inventario para una ferreteria, permite las siguientes
 * acciones:
 *
 * Inicializar el archivo "hardware.dat" a 100 registros vacíos en la primera ejecución.
 * si el archivo existe, se procede a leerlo
 * Ingresar los datos relativos cada herramienta
 * Ver el inventario
 * Eliminar un registro de una herramienta que ya no tiene
 * Actualizar cualquier información en el archivo (modificar un nombre, costo o cantidad)
 *
 * */




#include <stdio.h>   
#include <stdlib.h>  

// Puntero al archivo hardware.dat
FILE *inventario;


//PROTOTIPOS DE LA FUNCIONES

void iniciar_archivo();
void menu();
void nuevo_registro(int a);
void ver_inventario(int a);
void eliminar_inventario(int a);
void actualizar_inventario(int a);
void salida( int a );
void regresar();

// ESTRUCTURA DE LOS DATOS DE LAS HERRAMIENTAS

struct tools{
unsigned int Registro;
char TipoHerramienta[30];
unsigned int Cantidad;
double  Costo;
};// Fin de definición de la estructura



int main () {

iniciar_archivo();

return 0;
}

/*-------------------------------------
 * iniciar_archivo( ) :
 * La función verifica que exista  "hardware.dat", si existe muestra el
 * menú de  opciones; si no existe crea el archivo con 100 entradas
 * vacias y muestra el meńu
 * -------------------------------------*/
void iniciar_archivo( ){
// asigna el apuntador a hardware.dat
inventario= fopen("hardware.dat","rb");

// Verifica que el archivo "hardware.dat" pueda crearse para lectura
if(inventario==NULL){
	// Si no se encuentra se intenta crearlo
		if((inventario= fopen("hardware.dat","wb"))==NULL){
				 printf("No se puede acceder al archivo de inventario");
				 }// fin de IF

		// Si el archivo puede crearse se llena con registros vacios
		else{
               // Contador para las veces que se agrega el registro vacío
				unsigned int i; 
				// Registro vacío
				struct tools predet ={0,"herramienta", 0 ,0.0};

				// Ciclo para llenado de 100 vacios
				for(i=1;i<101;i++){
						fwrite(&predet, sizeof(struct tools),1,inventario);
			}// fin del for	

				// Se cierra el archivo
				fclose(inventario);

				// Se indica que se crea el archivo 
				puts("Se ha  creado el archivo hardware.dat con 100 entradas vacías");
				menu();
			}// fin del else
			} // fin del if

//Si  el archivo está disponible para lectura, se cierra y se muestra el menú
else{

		fclose(inventario);
		menu();
		}
}
// fin de funcion iniciar archivo



/*-------------------------------------
 * menu( ) :
 * La función menú permite al usuario seleccionar la acción que desee y dirige a ella
 * -------------------------------------*/
void menu( ){

// Apuntador a las funciones
void (*f[ 5 ])( int ) = {nuevo_registro,
	                                ver_inventario,
	                                eliminar_inventario,
	                                actualizar_inventario,
									salida};

// Se guarda la selección de menú
 size_t  seleccion;

// Despliegue de las opciones para el menú
puts("\n------------------------------- MENÚ PRINCIPAL-------------------------------\n");
puts("Escoja una de las siguientes acciones: \n\n");
puts("1. Agregar una herramienta al inventario");
puts("2. Ver todo el  inventario");
puts("3. Eliminar herramientas que no estén en existencia");
puts("4. Actualizar  inventario");
puts("5. Salir");

// Se pide y guarda selección del menú del usuario
printf("\n\nSu selección: \t");
scanf("%lu",&seleccion);

// Se verifica que la opción sea válida
while(seleccion<0 || seleccion >5){
   puts("Su selección no es valida, repita:\t");
   scanf("%lu",&seleccion);
		}//fin while

// Se invoca la función
   (*f[seleccion-1])(seleccion);
}


// Agregar una  herramienta nueva
void nuevo_registro(int a){

	inventario= fopen("hardware.dat","rb+");

		if(inventario==NULL){
				puts("No se pudo acceder al archivo del  inventario");}
		else{
				//	 Estructura para contener lectura y registros
				struct tools predet ;
				unsigned int registro;
				unsigned int eleccion;

				// Solicita el registro dónde el usuario desea agregar la herramienta
				puts("\n------------ INGRESAR NUEVA HERRAMIENTA------------\n");
				printf( "Introduzca un numero de registro ( 1 - 100 ): " );
				scanf( "%i", &registro );

				// Se verifica que la selección de registro sea válida
				while(registro<1 || registro >100){
						   printf( "El rango de cuentas es de 1 a 100, ingresa de nuevo" );
						   scanf( "%i", &registro );
							}// fin while

				// Se lee la posición en el registro seleccionado y se guarda en predet
				fseek( inventario, ( registro - 1 ) * sizeof( struct tools ),  SEEK_SET );
				fread( &predet, sizeof( struct tools ), 1, inventario );

					// Se verifica si el registro ya está en uso
				   if ( predet.Registro != 0 ) {
					  printf( "Ya existe una herramienta con el registro #%d .\n",predet.Registro );
							} // end if

					// Si está disponible se ingresa la nueva herramienta
				   else { 

					  // el usuario introduce los datos de la herramienta nueva
                     puts("Ingresa el nombre de la herramienta:");
					scanf(" %[^\n]", predet.TipoHerramienta);
					puts("Ingresa la cantidad en inventario de la herramienta:");
					scanf(" %i", &predet.Cantidad);
					puts("Ingresa el precio de la herramienta:");
					scanf(" %lf", &predet.Costo);
					predet.Registro = registro;							

					  // Se busca la posición correspondiente , se sobreescribe y se da un aviso
					  fseek( inventario, ( predet.Registro - 1 ) * sizeof( struct tools ),  SEEK_SET );
					  fwrite( &predet, sizeof( struct tools ), 1, inventario );
					  puts("El nuevo registro fue agregado exitosamente");
							}// fin-else

					do{
					 puts("");
					 puts("¿Deseas agregar otra herramienta?");
					 puts("1. Sí");
					 puts("2. No");
					 scanf("%i", &eleccion);}
                    while(eleccion<1 || eleccion>2);

				     switch(eleccion){
							case 1 :{fclose(inventario);
											nuevo_registro(2);
											break;}
							case 2 :{fclose(inventario);
                                           regresar();
                                           break;
                                           }
						        }// fin switch

				} //fin else inicial
				}// fin nuevo_registro


/*-------------------------------------
 * ver_inventario( ) :
 * Se muestran todas las herramientas capturadas (registro !=0) 
 * -------------------------------------*/

void ver_inventario(int a){

   // Se ingresa al archivo en modo lectura
	inventario= fopen("hardware.dat","rb");

	if(inventario==NULL){
			puts("No se pudo acceder al archivo del  inventario");
			}// fin if

	else{
			struct tools predet ={0,"",0,0.0};
			puts("\n------------------------------ MOSTRAR INVENTARIO ------------------------------\n");
			printf( "%-10s%-30s%-10s%10s\n", "Registro", "Herramienta",  "Cantidad", "Costo" );


			// Leer el archivo
            while ( !feof( inventario ) ) {
						int valido = fread( &predet, sizeof( struct tools ), 1, inventario );

						// Se imprimen las opciones validas con registros diferentes de cero
						if ( valido != 0 && predet.Registro !=0) {
							printf( "%-10i%-30s%-10i%10.2lf\n",
								predet.Registro, predet.TipoHerramienta,
								predet.Cantidad, predet.Costo);
								} // end if
								} // end while
			
			}//fin de else
	// Se cierra el archivo
	fclose(inventario);
	regresar();
	}// Fin iniciar_archivo()



/*-------------------------------------
 * eliminar_inventario() :
 * Se busca herramientas capturadas (registro !=0) que su existencia sea cero y se sobrescribe con
 * un registro vacío
 * -------------------------------------*/

void eliminar_inventario(int a){
 puts("------------------------------ELIMINAR ITEMS-----------------------------------");
	 
	inventario= fopen("hardware.dat","rb+");

	if(inventario==NULL){
			puts("No se pudo acceder al archivo del  inventario");}
	else{
		//Se declara  una estructura vacia, una contenedora y una para guarda la posición

			// contador  de la cantidad de registros a borrar
			unsigned int borrados=0;
            unsigned int posicion;
			struct tools predet ={0,"",0,0.0};
			struct tools  existente;

		//Se lee todo el archivo y se realiza la búsqueda de herramientas sin existencia
			while ( !feof( inventario ) ) {
					int valido = fread( &existente, sizeof( struct tools ), 1, inventario );
					// muestra el registro
					if ( valido != 0 && existente.Cantidad ==0 && existente.Registro !=0) {
						posicion=existente.Registro;
						fseek( inventario, ( posicion-1) * sizeof( struct tools ),  SEEK_SET );
						fwrite( &predet, sizeof( struct tools ), 1, inventario );
						borrados ++;
						}// fin if
						} // fin while

				// Se informa la cantidad de registros que se borraron y se cierra el archivo
				if(borrados!=0){
					puts("---------------------------------------------------");
					printf("Fueron borrados %i registros\n", borrados);}
				else{puts("No se encontraron registros por borrar");}


				fclose(inventario);
				regresar();}// fin else
				                   } // fin eliminar()
	



/*-------------------------------------
 * actualizar_inventario() :
 * Se busca herramientas capturadas  a través de su registro,
 * se permite que el usuario modifique la información 
 * -------------------------------------*/
 
void actualizar_inventario(int a){
	inventario= fopen("hardware.dat","rb+");

		if(inventario==NULL){
				puts("No se pudo acceder al archivo del  inventario");
				}// fin if
		else{
				// Estructura contenedor y guarda del registro
				struct tools predet;
				unsigned int registro;
				puts("\n------------ ACTUALIZAR REGISTRO------------\n");
				printf( "Introduzca el registro que desea actualizar ( 1 - 100 ): \t" );
				scanf( "%i", &registro );

				while(registro<1 || registro >100){
						   printf( "El rango de registros es de 1 a 100, ingresa de nuevo \t" );
						   scanf( "%i", &registro );
						   }// fin while

				fseek( inventario, ( registro - 1 ) * sizeof( struct tools ),  SEEK_SET );
				fread( &predet, sizeof( struct tools ), 1, inventario );
 
				if ( predet.Registro == 0 ) {
						  printf( "El registro se encuentra vacío\n" );
					   } // end if

			   else { // crear registro
						  // el usuario introduce los datos
						  unsigned int eleccion;

						do{ // bucle para realizar más de una actualización

						// Se muestra el que campo que se  selecciono para modificar	
						puts("\n\n\n----------------------------REGISTRO SELECCIONADO--------------------------\n\n");
						printf( "%-10s%-30s%-10s%10s\n", "Registro", "Herramienta",  "Cantidad", "Costo" );
                         printf( "%-10i%-30s%-10i%10.2lf\n",
								predet.Registro, predet.TipoHerramienta,
								predet.Cantidad, predet.Costo);  


						// Menú de opciones de modificación  
						 puts("\n\n\n----------------------------OPCIONES--------------------------\n\n");
						  printf( "1.Nombre de la herramienta \n" );
						  printf( "2.Existencia en almacen\n" );
						  printf( "3.Precio\n" );
						  printf( "4. Terminar edición\n" );
						   printf( "\n\n\nSelecciona el campo que deseas modificar: \t" );
						  scanf( "%i",&eleccion);

						while(eleccion <1 || eleccion>4){
									puts("Elección no válida, indica de nuevo:");
									scanf( "%i",&eleccion);
							}// fin while
						    
						// Se actualiza el registro según la eleccion del usuario
						 switch(eleccion){

							 case 1 :{ puts("Ingresa el nuevo nombre:");
								             scanf(" %[^\n]", predet.TipoHerramienta);
								             break;     }
							 case 2 :{
											puts("Ingresa la existencia actual:");
								             scanf(" %i", &predet.Cantidad);
								             break;}
							 case 3 :{
											puts("Ingresa el nuevo precio:");
								             scanf(" %lf", &predet.Costo);
								             break;}
							 }// fin switch
							 } while(eleccion!=4);

					// Se reemplaza el registro anterior con el nuevo		 
					fseek( inventario, ( registro - 1 ) * sizeof( struct tools ),  SEEK_SET );
					fwrite( &predet, sizeof( struct tools ), 1, inventario );
					puts("");
					puts("------------------------------------------------------------------");
					puts("El nuevo registro fue agregado exitosamente");

					}// fin-else

	fclose(inventario);
	regresar();
	}// fin de else
	}// fin de actualizar_registro();


/*-------------------------------------
 * Salida() :
 * Da mensaje antes de salir del programa 
 * -------------------------------------*/
void salida(int a){
    puts("------------------------------------------------------------------");
	puts("\n Has seleccionado salir. !Hasta luego! :) ");
		}// fin salida()


/*-------------------------------------
 * regresar() :
 * Da la opcion de volver al menú antes de finalizar el programa
 * -------------------------------------*/
void regresar(){

void (*f[ 2 ])( int ) = {menu, salida};
	                                    
size_t  seleccion;
puts("");
puts("------------------------------------------------------------------");
puts("Selecciona una opción:");
puts("1. Regresar al menú");
puts("2. Salir del programa");
printf("\n\nSu selección: \t");
scanf("%lu",&seleccion);

while(seleccion<0 || seleccion >2){
printf("\n\nSelección no válida, repita: \t");
scanf("%lu",&seleccion);}

   (*f[seleccion-1])(seleccion+1);

	}// fin regresar()

