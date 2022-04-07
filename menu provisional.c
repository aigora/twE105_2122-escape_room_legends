#include <stdio.h>

int main()
{
    printf("Si quieres salir del programa pulsa 'Q' en cualquiera de los scanfs, para responder, use 'Si' y 'No'\n\n");
    char respuesta;
    printf("Quieres entrar en la casa?\n");
    while((respuesta!='N')&&(respuesta!='S'))
          {
            scanf("%c",&respuesta);
            if(respuesta=='Q')
                break;
          }
    switch(respuesta)
    {
    case 'S':
        {
          respuesta='a';
          printf("//Apareces dentro de la Casa\n");
          printf("//Dentro de la casa ves un laberinto que te permite moverte hacia arriba,abajo,izquierda y derecha\n");

          while(respuesta!='Q')
          {
              printf("Resuelves la prueba?\n");
               while((respuesta!='N')&&(respuesta!='S'))
          {
            scanf("%c",&respuesta);
            if(respuesta=='Q')
                break;
                }
                switch(respuesta)
          {
            case 'S':
                {
                respuesta='a';
                 printf("\nContinuas a la proxima habitacion\n");
                break;
                }

            case 'N':
                {
                respuesta='a';
                 printf("\nContinuas en la misma habitacion\n");
                break;
                }
          }
          }
        break;
        }
        case 'N':
            {
               printf("//Acaba el Juego 'The End' ");
        break;
            }
        default:
            break;
    }

    return 0;
}
