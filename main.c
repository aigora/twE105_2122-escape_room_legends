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
/*
delay(3);
printfdelay("... al pisar ves que el suelo resbala tanto que para frenarte tienes que chocar con un obstaculo o una pared ...\n\n" , 3);
printfdelay("para moverte usa las teclas 'W','A','S','D' \n\n" , 3);
printfdelay("tu objetivo es llegar hasta la salida, en la parte superior derecha, para pasar a la siguiente sala\n\n" , 3);
printf("pulsa cualquier tecla para empezar");
getch();
*/
delay(1);
printf("\n\n\n\n");
//graficamos el mapa en la posicion inicial(1 , 0) y con la funcion posicion calcularemos en que posicion se encuentra en cada instante el usuario y la graficaremos
mapa(1 , 0);
posicion(1 , 0);
// ---------------------------------------------------cambio de fase(a fase2)------------------------------------------
//estas dos funciones funcionan igual que las utilizadas para la sala 1 pero a la funcion mapa la llamamos laberinto
//los cuatro 0 del final indican que ninguna de las monedas esta cogida , si cambiamos un 0 por un uno no tendriamos que recoger esa moneda
printfdelay("la siguiente sala es un laberinto en el que hay que recoger 4 monedas\n\n" , 3);
printfdelay("una vez las tengas todas podras pasar por la puerta que se encuentra a la izquierda de la casilla en la que apareces\n\n" , 3);
printf("pulsa cualquier tecla para empezar");
getch();
delay(1);
laberinto(1,39,0,0,0,0);
posicion2(1,39);
delay(1);
habitacion();
return 0 ;
}


