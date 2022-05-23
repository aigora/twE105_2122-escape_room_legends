#include"enigma.h"
#include"juegouno.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"adddelay.h"

void imprime1(FILE *pf,int solucion);
int enigmas()
{

    char elige,elige1;
    int el_prueba,el_mesa,n=0,n1=0,e,cod=501,cod1;
    int resp2=2,resp3=4,resp4[2]={40,96};
    char resp1[7]="9/9+99",res1[7],resp6[7]="etsidi",res6[7];
    char re[2];
    char ans[7],ans1[8],a[7],a1[8];
    FILE *p1;
    FILE *p2;
    FILE *p3;
    FILE *p4;
    FILE *mat;
    FILE *puerta;
    FILE *puerta2;
    FILE *mesa;
    FILE *pistas;
    FILE *letras;
    FILE *suma;
    FILE *peluche;
    int res2,res3,res4,vidas=8,ptos=0,ptos1=0;
    strcpy(ans, "Andres");
    strcpy(ans1,"Iniesta");


    puerta = fopen("Proyecto/3puertas.txt", "r");
    imprime1 (puerta,0);
    fclose(puerta);
    printf ("\t\tEntras?:\t\t1.si\t\t2.No\n\n\t\t");
    do{
    scanf(" %c",&elige);
    if (elige!='1'&& elige!='2')
    {
        printf ("\n\nElige nuevamente\n\n\t\t");
    }
     }while (elige!='1'&& elige!='2');



    switch (elige)
    {
    case '1':
        {
        do{
          printf("\n\n\n\n\n\n");
          mat = fopen("Proyecto/matematica.txt", "r");
          imprime1(mat,0);
          fclose(mat);
          printf("\n\n%c",elige);
          printf("\n\nELIGE UNA CAJA\n");
        do
        {
          scanf ("%i",&el_prueba);
          switch (el_prueba)
          {
          case 1:
              printf("\n\n\n\n\n\n");
              p1 = fopen("Proyecto/prueba1.txt", "r");
              imprime1(p1,0);
              fclose(p1);
              scanf ("%s",res1);
              if (strcmp(resp1, res1) == 0)
              {
                  printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                  ptos++;
              }
              else
              {
                  printf ("RESPUESTA INCORRECTA\n");
                  vidas-=1;
              }
            delay(2);
          break;
          case 2:
              printf("\n\n\n\n\n\n");
              p2 = fopen("Proyecto/prueba2.txt", "r");
                imprime1(p2,0);
                fclose(p2);
                scanf ("%i",&res2);
                if(res2==resp2)
                {
                   printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                   ptos++;
                }
                else
                {
                    printf ("RESPUESTA INCORRECTA...\n");
                    vidas-=1;
                }
                delay(2);
          break;
          case 3:
            printf("\n\n\n\n\n\n");
            p3 = fopen("Proyecto/prueba3.txt", "r");
            imprime1(p3,0);
            fclose(p3);
            scanf ("%i",&res3);
                if(res3==resp3)
                {
                   printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                   ptos++;
                }
                else
                {
                    printf ("RESPUESTA INCORRECTA...\n");
                    vidas-=1;
                }
                delay(2);
          break;
          case 4:
              printf("\n\n\n\n\n\n");
              p4 = fopen("Proyecto/prueba4.txt", "r");
            imprime1(p4,0);
            fclose(p4);
            scanf ("%i",&res4);
                if(res4==resp4[0]||res4==resp4[1])
                {
                   printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                   ptos++;
                }
                else
                {
                    printf ("RESPUESTA INCORRECTA..\n");
                    vidas-=1;
                }
                delay(2);
          break;
          default:
            printf("Eleccion incorrecta\n");
            printf ("Introduce una opcion valida\n\n");
          }

        }while (el_prueba>4||el_prueba<1);
        n++;
            if(n<=3)
            {
            printf("\n\n\n\n\n\n");
            printf("\nQuieres seguir en esta Habitacion?\n\n1.si\n\n2.no\n\n");
            scanf("%i",&e);
            }
            if(e==2)
            {
                printf ("....Estas saliendo de la habitacion....\n");
                delay(2);
            }
        }while (n<=3&&e!=2);
        }
    break;
        printf ("\n\nSales de la habitacion....\n\n\n");

    case '2':
        {
        exit(-1);
        }
        break;
    }
    printf("\n\n\n\n\n\n\n"); //////!!!!!

    puerta2 = fopen("Proyecto/puerta2.txt", "r");
    imprime1 (puerta2,0);
    fclose(puerta2);
    printf ("\t\tEntras?:\t\t1.si\t\t2.No\n\n\t\t");
    do{
    scanf(" %c",&elige1);
    if (elige1!='1'&& elige1!='2')
    {
        printf ("\n\nElige nuevamente\n\n\t\t");
    }
     }while (elige1!='1'&& elige1!='2');

     switch (elige1)
    {
    case '1':
        {
        do{
          printf("\n\n\n\n\n\n\n\n\n");
          mesa = fopen("Proyecto/mesa.txt", "r");
          imprime1(mesa,0);
          fclose(mesa);
          printf("\n\n\t\tELIGE UN SOBRE\n");
        do
        {
          scanf ("%i",&el_mesa);
          if(el_mesa>3||el_mesa<1)
          {
            printf("Eleccion incorrecta\n");
            printf ("Introduce una opcion valida\n\n");
          }
         }while (el_mesa>3||el_mesa<1);
          switch (el_mesa)
          {
          case 1:
              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
              suma = fopen("Proyecto/suma_encriptada.txt", "r");
              imprime1(suma,0);
              fclose(suma);
              printf ("\n\n\t\tElige cual de las 3 opciones es la correcta...\n\n\n\n\n\n");
              scanf ("%s",re);
              if (re[0]== 'a'||re[0]=='A')
              {
                  printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
              }
              else
                {
                    printf ("RESPUESTA INCORRECTA\n");
                }
            delay(2);
          break;
          case 2:
              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
              letras = fopen("Proyecto/letras.txt", "r");
                imprime1(letras,0);
                fclose(letras);
                scanf ("%s",res6);
                if(strcmp(resp6, res6) == 0)
                {
                   printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                }
                else
                {
                    printf ("RESPUESTA INCORRECTA\n");
                }
            delay(2);
          break;
          case 3:
              printf("\n\n\n\n\n\n\n\n\n\n\n");
              pistas = fopen("Proyecto/pistas.txt", "r");
            imprime1(pistas,0);
            fclose(pistas);
            printf ("\n\nEn base a las pistas tendras que averiguar el personaje y responder con su nombre\n\n");
            scanf ("%s",a);
            scanf ("%s",a1);
                if((strcmp(a,ans) == 0) &&(strcmp(a1,ans1) == 0) )
                {
                   printf ("\n\nRESPUESTA CORRECTA!!!\n\n");
                }
                else
                {
                    printf ("RESPUESTA INCORRECTA\n");
                }
            delay(2);
          break;
            }
            n1++;
            if(n1<=2)
            {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\nQuieres seguir en esta Habitacion?\n\n1.si\n\n2.no\n\n");
            scanf("%i",&ptos1);
            }
            if(ptos1==2)
            {
                printf ("....Estas saliendo de la habitacion....\n");
                delay(2);
            }



        }while(n1<=2&&ptos1!=2);
        }
    break;
        printf ("\n\nSales de la habitacion....\n\n\n");

    case '2':
        {
        exit(-1);
        }
        break;
    }
        printf("\n\n\n\n\n\n\n\n");
        printf ("\n\n\t...Para Pasar a la siguiente prueba...\n");
        printf ("\n\t...Debes poner el codigo secreto que se muestra a continuacion....\n");
        delay(5);
        do{
         peluche =fopen("Proyecto/luz.txt","r");
         imprime1(peluche,0);
         fclose(peluche);
         delay(5);
         printf("\n\n\n\n\n\n");
         printf("\n\n\t..Necesitas ver de nuevo?...\n\n1.si\n\n2.no\n\n");
         scanf("%i",&e);
        }while(e!=2);
        printf("\n\n\n\n\n\n");
        do{
        printf ("\n\nDigita el codigo oculto....");
        scanf("%i",&cod1);
        if (cod1==cod)
        {
            printf ("\n\nFELICIDADES HAS CONSEGUIDO PASAR A LA SIGUIENTE PRUEBA....");
        }
        else
            printf ("\n\n....ERROR!!! CODIGO INCORRECTO...");
        }while(cod1!=cod);
 return 0;


}

void imprime1(FILE *pf,int solucion)
{
    //la funciojn imprime muestra en pantalla el contenido de un fichero que le haya sido dado.
    char foto;
    while(fscanf(pf, "%c",&foto) !=EOF )
    {
    printf("%c",foto);
    }
    printf("\n");
    fclose(pf);
}



/*void delay(float number_of_seconds)//añade una pequeña pausa al igual que lo haria "sleep"
{

float milli_seconds = 1000 * number_of_seconds;

clock_t start_time = clock();

while (clock() < start_time + milli_seconds);
}*/
