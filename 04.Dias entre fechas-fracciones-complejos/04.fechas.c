#include <stdio.h>   
#include <stdlib.h>  

#define  DIAS_A  365

struct  fecha{
int aa;
int  mm;
int  dd;
	};

typedef struct fecha fecha;

int es_bisiesto( int anio);
int  duracion_mes( int mes, int anio);
int  dias_faltantes( fecha  inicial);
int dias_transcurridos(fecha final);
int dias_entreanios(fecha inicial, fecha final);
int dias_entre_fechas(fecha inicial, fecha final);

int main () {


int diferencia;

fecha inicio={1985,8,3};
fecha fin={2018,9,14};

diferencia=dias_entre_fechas(inicio, fin);

printf("%i", diferencia);

return 0;}

 int es_bisiesto( int a){
int bisiesto;

 if( ( (a%4 ==0) && (a%100!=0)) || (a%400==0)){
bisiesto=1;
}
else{bisiesto =0;} 

return bisiesto;
	}

int  duracion_mes( int mes, int anio){
int dias_mes;

if(mes==2){
dias_mes= (28 + es_bisiesto(anio));}
else if (mes ==4 ||mes ==6 || mes ==9 || mes==11 ){
dias_mes=30;
	}
else{dias_mes =31;}

return dias_mes;
	}

int  dias_faltantes( fecha  inicial){
int i, cont=0;

for(i=1; i<inicial.mm; i++){
     cont+=duracion_mes(i, inicial.aa);
	}

cont= DIAS_A + es_bisiesto(inicial.aa)- cont - inicial.dd;

return  cont;
	}
	
int dias_transcurridos(fecha final){

 int i, cont=0;

for(i=1; i<final.mm; i++){
     cont+=duracion_mes(i, final.aa);
	}

cont= cont + final.dd;
return  cont;

	}

int dias_entreanios(fecha inicial, fecha final){
int i, cont=0;

for(i=(inicial.aa+1);i<final.aa;i++){
 cont+=(365 + es_bisiesto(i));

	}

return cont;
	}
	
int dias_entre_fechas(fecha inicial, fecha final){
int dias_totales;

if( inicial.aa!=final.aa){
dias_totales= (dias_transcurridos(final)+
dias_entreanios(inicial, final)+
dias_faltantes(inicial)+1);

	}

else{ dias_totales= (dias_transcurridos(final)+dias_faltantes(inicial)-(DIAS_A+es_bisiesto(inicial.aa))+1); }

return dias_totales;
	}
