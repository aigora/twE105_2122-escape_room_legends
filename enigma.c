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

    char elige,elige1,e='1';
    int n,cod=501,cod1;
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
    int res2,res3,res4,ptos,ptos1;
    strcpy(ans, "Andres");
    strcpy(ans1,"Iniesta");


    puerta = fopen("Proyecto/3puertas.txt", "r");
    imprime1 (puerta,0);
    fclose(puerta);
    printf ("Entras?:\t1.si\t2.No\n\n\t");
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
          n=0;
          ptos=0;
          printf("\n\n\n\n\n\n\n\n\n");
          mat = fopen("Proyecto/matematica.txt", "r");
          imprime1(mat,0);
          fclose(mat);
              delay(3);
              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
              p1 = fopen("Proyecto/prueba1.txt", "r");
              imprime1(p1,0);
              fclose(p1);
              printf("\n\n\n\n\n\n\n\n\n\n\tResponde:");
              scanf ("%s",res1);
              if (strcmp(resp1, res1) == 0)
              {
                  printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n\n\n\n");
                  ptos++;
              }
              else
              {
                  printf ("\n\n\tRESPUESTA INCORRECTA\n\n\n\n\n");
              }
              n++;
            delay(3);


              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
              p2 = fopen("Proyecto/prueba2.txt", "r");
                imprime1(p2,0);
                fclose(p2);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\tResponde:");
                scanf ("%i",&res2);
                if(res2==resp2)
                {
                   printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n\n\n\n");
                   ptos++;
                }
                else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA...\n\n\n\n\n");
                }
                n++;
                delay(3);


            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            p3 = fopen("Proyecto/prueba3.txt", "r");
            imprime1(p3,0);
            fclose(p3);
            printf("\n\n\n\n\n\n\n\tResponde:");
            scanf ("%i",&res3);
                if(res3==resp3)
                {
                   printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                   ptos++;
                }
                else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA...\n\n");
                }
                n++;
                delay(3);

              printf("\n\n\n\n\n\n\n\n\n");
              p4 = fopen("Proyecto/prueba4.txt", "r");
            imprime1(p4,0);
            fclose(p4);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\tResponde:");
            scanf ("%i",&res4);
                if(res4==resp4[0]||res4==resp4[1])
                {
                   printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                   ptos++;
                }
                else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA..\n\n");
                }
                n++;
                delay(2);
                if(ptos>=2)
                {
                    printf("\n\n\tFELICIDADES LOGRASTE COMPLETAR 3 ACERTIJOS!!!\n\n");
                    printf("\tPASAS A LA SIGUIENTE PRUEBA\n");
                }
                else
                {
                    printf("\n\n\tNO LOGRASTE COMPLETAR TODOS LOS ACERTIJOS!!!\n\n");
                    printf("\tTENDRAS QUE VOLVER A EMPEZAR\n");
                }
                delay(3);

        }while (n<=2||ptos<=2);

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

          ptos1=0;
          printf("\n\n\n\n\n\n\n\n\n\n\n");
          mesa = fopen("Proyecto/mesa.txt", "r");
          imprime1(mesa,0);
          fclose(mesa);
          delay(3);


              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
              suma = fopen("Proyecto/suma_encriptada.txt", "r");
              imprime1(suma,0);
              fclose(suma);
              printf ("\n\n\t\tElige cual de las 3 opciones es la correcta...\n\n\n\n\n\n");
              scanf ("%s",re);
              if (re[0]== 'a'||re[0]=='A')
              {
                  printf ("\n\n\tESPUESTA CORRECTA!!!\n\n");
                  ptos1++;
              }
              else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                }
            delay(2);

              printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
              letras = fopen("Proyecto/letras.txt", "r");
                imprime1(letras,0);
                fclose(letras);
                scanf ("%s",res6);
                if(strcmp(resp6, res6) == 0)
                {
                   printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                   ptos1++;
                }
                else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                }

            delay(2);

              printf("\n\n\n\n\n\n\n\n\n\n\n");
              pistas = fopen("Proyecto/pistas.txt", "r");
            imprime1(pistas,0);
            fclose(pistas);
            scanf ("%s",a);
            scanf ("%s",a1);
                if((strcmp(a,ans) == 0) ||(strcmp(a1,ans1) == 0) )
                {
                   printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                   ptos1++;
                }
                else
                {
                    printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                }

            delay(2);

                if(ptos1>=2)
                {
                    printf("\n\n\tFELICIDADES LOGRASTE COMPLETAR TODOS LOS ENIGMAS!!!\n\n");
                    printf("\tPASAS A LA SIGUIENTE PRUEBA\n");
                }
                else
                {
                    printf("\n\n\tNO LOGRASTE COMPLETAR TODOS LOS ENIGMAS!!!\n\n");
                    printf("\tTENDRAS QUE VOLVER A EMPEZAR\n");
                }
                delay(3);
        }while(ptos1<=2);
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
        delay(3);
        do{
         if(e=='1')
         {
         peluche =fopen("Proyecto/luz.txt","r");
         imprime1(peluche,0);
         fclose(peluche);
         delay(5);
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
         printf("\n\n\t..Necesitas ver de nuevo?...\n\n1.si\n\n2.no\n\n\n\n\n\n\n\t\t");
         e=0;
         }
         scanf(" %c",&e);
         if (e!='1'&& e!='2')
            {
        printf ("\n\n\tElige nuevamente\n\n\n\n\n\n\n");
            }

        }while (e!='2');

        printf("\n\n\n\n\n\n");
        do{
        printf ("\n\n\tDigita el codigo oculto....\n\n");
        scanf("%i",&cod1);
        if (cod1==cod)
        {
            printf ("\n\n\tFELICIDADES HAS CONSEGUIDO PASAR A LA SIGUIENTE PRUEBA....");
        }
        else
            printf ("\n\n\tERROR!!! CODIGO INCORRECTO...");
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




