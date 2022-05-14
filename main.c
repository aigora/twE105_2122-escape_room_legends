#include "juegouno.h"
#include"adddelay.h"
int main()
{
//imprimimos 10000 saltos de linea ya para llegar al final de el ejecutador del programa ya que asi las imagenes se ven mas fluidas
//carga();
    int a,k=0;
    char respuesta,respuesta2;
    delay(1);
    casa();
    while(k!=1) //Este while tiene como objetivo preguntarle al usuario si quiere empezar el juego, y se repetirá una y otra vez
    { //hasta que el usuario decida o empezar, o salirse del programa
        while ((respuesta!='1')&&(respuesta!='2')) //este while le pregunta al usuario si quiere empezar la simulacion o irse,
            scanf("%c",&respuesta);// y hace la misma pregunta hasta que el usuario escoje uno de los dos
        if((respuesta!='1')&&(respuesta!='2'))
            while((respuesta!='1')&&(respuesta!='2')) //Estas lineas se aseguran de que el usuario escribe "1" o "2", ya que de
                scanf("%c",&respuesta); // lo contrario el programa 'peta'
        if(respuesta=='1') //si el usuario responde con un 1, el programa empieza su desarrollo
            k=1;
        if(respuesta=='2') //si el usuario responde con un 2, el programa vuelve a preguntar por si acaso
        {
            printf("\nEstas seguro?                                             				    1:No     2:Si\n");
            scanf("%c",&respuesta2);//Estas lineas se aseguran de que el usuario escribe "1" o "2", ya que de
            if((respuesta2!='1')&&(respuesta2!='2')) // lo contrario el programa 'peta'
                while((respuesta2!='1')&&(respuesta2!='2'))
                    scanf("%c",&respuesta2);
            if(respuesta2=='2')
                return 0;           //si el ususario responde 2, el programa acaba
            else
                respuesta=0;        //si el ususario responde 1, el programa vuelve a la primera pregunta
            respuesta2=0;
            printf("\nQue haces?                                                                                  1:Entro  2:Huyo\n");
        }
    }

oscuridad1();
ice_cave();
candado();
laberinto();
habitacion();
    return 0 ;
}

