#include "juegouno.h"
#include"adddelay.h"
int main()
{
char usuario[20];
/*ejecutamos el menu principal , si el usuario no cambia la dificultad esta sera facil
 la variable dificultad lo que haces es que cuanto mayor dificultad haya menos puntos recibe el usuario por prueba*/
float dificultad=carga();
//imprimimos 10000 saltos de linea ya para llegar al final de el ejecutador del programa ya que asi las imagenes se ven mas fluidas
float puntuacion=0;
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
puntuacion = puntuacion  + (50-ice_cave()*dificultad);
puntuacion = puntuacion  + (60-candado()*dificultad);
puntuacion = puntuacion  + (300-laberinto()*dificultad);
puntuacion = puntuacion  + (500-enigmas1()*dificultad);
puntuacion = puntuacion  + (100-habitacion()*dificultad);

//enigmas1();

printf("\n\n\n\nEscribe tu nombre\n\n\n");
scanf("%s",usuario);
highscore(usuario,dificultad*10,puntuacion);
    return 0 ;

}

