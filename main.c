#include "juegouno.h"
#include"adddelay.h"
//#include<wchar.h>
int main(){
//indicamos al usuario las instrucciones a seguir para comletar el primer escenario/nivel/mapa dando tiempo entre indicaciones
//haciendo uso de la funcion delay
//imprimimos 10000 saltos de linea ya para llegar al final de el ejecutador del programa ya que asi las imagenes se ven mas fluidas
for(int i=0;i<10000;i++)printf("\n");
casa();
oscuridad1();
delay(1);
printf("\n\n\n\n");
mapa(1 , 0);
posicion(1 , 0);
// ---------------------------------------------------cambio de fase(a fase2)------------------------------------------
posicion2(1,39);
delay(1);
habitacion();
return 0 ;
}


