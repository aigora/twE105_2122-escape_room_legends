#include "juegouno.h"
#include"adddelay.h"
#include"enigmas.h"
int main()
{
char usuario[20];
/*ejecutamos el menu principal , si el usuario no cambia la dificultad esta sera facil
 la variable dificultad lo que haces es que cuanto mayor dificultad haya menos puntos recibe el usuario por prueba*/
float dificultad=carga();
//dile al tio que diga su nombre y lo escaneas
delay(5);
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

puntuacion = puntuacion  + (100-ice_cave()*dificultad);
puntuacion = puntuacion  + (100-candado()*dificultad);
puntuacion = puntuacion  + (500-laberinto()*dificultad);
puntuacion = puntuacion  + (501-habitacion()*dificultad);
//enigmas();
//puntuacion = puntuacion  + (500-enigmas()*habitacion);
printf("\n\n\n\nEscribe tu nombre\n\n\n");
scanf("%s",usuario);
highscore(usuario,dificultad,puntuacion);
    return 0 ;

}

