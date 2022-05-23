#include "juegouno.h"
#include"adddelay.h"
#include"enigma.h"
int main()
{
enigmas();
//imprimimos 10000 saltos de linea ya para llegar al final de el ejecutador del programa ya que asi las imagenes se ven mas fluidas
//carga();
delay(1);
casa();
char a;
while((a!='1')){
 scanf("%c" , &a );
 if(a=='2'){
    printf("estas seguro?                                                                   1:no,quiero entrar      2:si  \n");
    scanf(" %c" , &a );
    if(a=='2')return 0;
 }
}
oscuridad1();
ice_cave();
candado();
laberinto();
habitacion();
    return 0 ;
}

