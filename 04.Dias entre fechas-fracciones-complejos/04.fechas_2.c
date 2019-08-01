#include <stdio.h>   
#include <stdlib.h>  

// Se define el valor predeterminado para los días en un año
#define  DIAS_A  365

//Se define la estructura donde se  guardarán las fechas
struct  fecha{
int aa;
int  mm;
int  dd;
	};

typedef struct fecha fecha;

//PROTOTIPOS DE LAS FUNCIONES
void encabezado();
void bienvenida();
fecha *crear_fecha(int a);
void llenar_fechas(fecha *fechas, int a);
int es_bisiesto( int anio);
int  duracion_mes( int mes, int anio);
int  dias_faltantes( fecha  inicial);
int dias_transcurridos(fecha final);
int dias_entreanios(fecha inicial, fecha final);
int dias_entre_fechas( fecha *fechas);


int main () {
	encabezado();
// Mensaje de inicio e instrucciones
	bienvenida();
// Puntero del contenedor de la fechas	
	fecha *fechas;
	fechas= crear_fecha(2);
// Ingreso de dos fechas 
	llenar_fechas(fechas,2);

// Se imprime la cantidad de días entre las fechas ingresadas
	printf("\n Entre las dos fechas hay %i días", dias_entre_fechas(fechas));
      free(fechas);

return 0;}

/*-------------------------------------------------------------
 int es_bisiesto( int a)*
 * La funcíon determina si un año es bisiesto, usando el algoritmo gregoriano.
 * Devuelve  1 si el año es bisiesto, 0 si no
 *
 *-----------------------------------------------------------------
 * */

int es_bisiesto( int a){
// indicador del año bisiesto
	int bisiesto;

// Condiciones lógicas que determinan si un año es bisiesto
	if( ( (a%4 ==0) && (a%100!=0)) || (a%400==0)){
		bisiesto=1;
}// fin del if
	else{bisiesto =0;} 

return bisiesto;
}


/*-------------------------------------------------------------
 duracion_mes( int mes, int anio)*
 * La funcíon  devuelve la cantidad de días de un mes, en función del mes y de si se trata de un año bisiesto
 *
 *-----------------------------------------------------------------
 * */

int  duracion_mes( int mes, int anio){
	int dias_mes;

	// Condicion para febrero
	if(mes==2){
		dias_mes= (28 + es_bisiesto(anio));}
	else if (mes ==4 ||mes ==6 || mes ==9 || mes==11 ){ // meses de 30 días
		dias_mes=30;
		}
	else{dias_mes =31;}

return dias_mes;
	}


/*-------------------------------------------------------------
 int  dias_faltantes( fecha  inicial)
 * La funcíon determina cuántos días restan al año desde la fecha inicial
 *
 *-----------------------------------------------------------------
 * */


int  dias_faltantes( fecha  inicial){
// contador del número de días
int i, cont=0; 

// Se cuentan los días desde el inicio del año
for(i=1; i<inicial.mm; i++){
     cont+=duracion_mes(i, inicial.aa);
	}

// Al total del días del año, se restan los días previos a la fecha
cont= DIAS_A + es_bisiesto(inicial.aa)- cont - inicial.dd;

return  cont;
	}


/*-------------------------------------------------------------
 int dias_transcurridos(fecha final)
 * La funcíon determina cuántos días han pasado del año hasta la fecha indicada
 *
 *-----------------------------------------------------------------
 * */

int dias_transcurridos(fecha final){

// contador de días
 int i, cont=0;

// Se cuentan los días desde el inicio de año
for(i=1; i<final.mm; i++){
     cont+=duracion_mes(i, final.aa);
	}

cont= cont + final.dd;
return  cont;

	}


/*-------------------------------------------------------------
 int dias_entreanios(fecha inicial, fecha final)
 * La funcíon determina cuántos días hay entre el primer día del año inmediato
 *  a la fecha inicial y el año anterior a la fecha final
 *
 *-----------------------------------------------------------------
 * */

int dias_entreanios(fecha inicial, fecha final){
	int i, cont=0;

	// Se hace un conteo desde el año inmediato a la primera fecha hasta el anterior a la segunda
	for(i=(inicial.aa+1);i<final.aa;i++){
	// Se considera si el año es bisiesto o no
		cont+=(DIAS_A + es_bisiesto(i));
	}
return cont;
	}


/*-------------------------------------------------------------
 int dias_entreanios(fecha inicial, fecha final)
 * La función devuelve los días entre un par de fechas
 *
 *-----------------------------------------------------------------
 * */

	
int dias_entre_fechas( fecha *fechas){
		// contador del total de días
	int dias_totales;

	// Se realiza un ajuste en caso de que se hayan ingresado fechas del mismo año
	if( fechas[0].aa!=fechas[1].aa){ // total de días para fechas en años diferentes
		dias_totales= (
				dias_transcurridos(fechas[1])+ // dias transcurridos de la fecha inicial al año siguiente
				dias_entreanios(fechas[0], fechas[1])+ // dias entre los años intermedios a las fechas
				dias_faltantes(fechas[0])+1);  // días transcurridos en el años de la fecha final 
	  }// fin if

else{// fechas en el mismo año. Los días transcurridos son la suma de los transcurridos y faltantes
				//menos el total de días del año
	dias_totales= (dias_transcurridos(fechas[1])+
								dias_faltantes(fechas[0])-
								(DIAS_A+es_bisiesto(fechas[0].aa))+1); }

return dias_totales;
	}


/*-------------------------------------------------------------
 fecha *crear_fecha(int a){
 *
 * Se reserva el espacio de memoria para las fechas*
 *-----------------------------------------------------------------
 * */

fecha *crear_fecha(int a){
fecha *predet;

predet=(fecha *)calloc(a,sizeof(fecha));

return predet;
	}


/*-------------------------------------------------------------
 void llenar_fechas(fecha *fechas, int a)
 *
 * Se ingresa las fechas y se verifica que sean válidas*
 *-----------------------------------------------------------------
 * */

void llenar_fechas(fecha *fechas, int a){
int i;


for(i=0;i<a;i++){

printf("Ingresa el año de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->aa);
printf("Ingresa el mes de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->mm);
printf("Ingresa el dia de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->dd);
printf("\n\n");
while(fechas[i].dd>duracion_mes(fechas[i].mm,fechas[i].aa) || fechas[i].mm>12 ){
puts("La fecha ingresada no es valida, ingrese de nuevo");
printf("Ingresa el año de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->aa);
printf("Ingresa el mes de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->mm);
printf("Ingresa el dia de la fecha %i: \t",i+1);
scanf("%i" , &(fechas +i)->dd);
printf("\n\n");

}}

}


/*-------------------------------------------------------------
void bienvenida( ) *
 * Mensaje inicial del programa*
 *-----------------------------------------------------------------
 * */

void bienvenida( ){
puts("-----------------------------------DÍAS ENTRE UN PAR DE FECHAS-----------------------------------");
printf("\n\n");
puts("Este programa permite el cálculo de días entre dos fechas. Con el último inclusive");
puts("Ingresa un par de fechas, el programa revisará que sean válidas.");
puts("NOTA: Asegúrate que la fecha 2 sea posterior a la fecha 1. El programa no revisa esa validación.");
printf("\n\n");
printf("\n\n");

	}

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
