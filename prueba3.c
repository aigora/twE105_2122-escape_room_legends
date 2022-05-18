#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{

    int elige,el_prueba,el_mesa,n=0,n1=0,e,n3=0,cod=501,cod1;
    int resp2=2,resp3=4,resp4[2]={40,96};
    char resp1[7]="9/9+99",res1[7],resp6[7]="etsidi",res6[7];
    char s[3],r[3]="si";
    char re[2];
    char ans[7],ans1[8],a[7],a1[8];
    int res2,res3,res4,vidas=8,ptos=0,ptos1=0;
    strcpy(ans, "Andres");
    strcpy(ans1,"Iniesta");
    casa();
    printf("\n\t\t");
    do{
    scanf ("%s",s);
    if (strcmp(r,s) == 0)
    {
        printf ("\n\n\t\tRespuesta correcta\t\t");
        delay (2);
        printf ("\n\n\t\tRisas......\n\n");
    }
    else
    {
        printf ("\n\n\t\tRespuesta incorrecta\t\t");
        delay (2);
        printf ("\n\n\t\tLlanto......\n\n");
        printf ("\t\tResponde nuevamente....\t\t");
    }
    }while (strcmp(r,s) != 0);
    delay (2);
    system ("cls");
    printf ("\n\nENTRAS Y VES 3 PUERTAS....\n\n");
    do{
    puertas();
    printf ("\t\tELIGE LA PUERTA:\t");
    scanf("%i",&elige);



    switch (elige)
    {
    case 1:
        {
        do{
          system("cls");
          matematica();
          printf("\n\nELIGE UNA CAJA\n");
        do
        {
          scanf ("%i",&el_prueba);
          switch (el_prueba)
          {
          case 1:
              system("cls");
              prueba1();
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
              system("cls");
                prueba2();
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
            system("cls");
            prueba3();
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
              system("cls");
            prueba4();
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
            system ("cls");
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

    case 2:
        {
        do{
          system("cls");
          mesa();
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
              system("cls");
              suma();
              printf ("\n\n\t\tElige cual de las 3 opciones es la correcta...");
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
              system("cls");
                letras();
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
              system("cls");
            pistas();
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
            system ("cls");
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
    }
    system("cls");
    n3++;
    }while(n3<=2);
        system("cls");
        printf ("\n\n\t...Para Pasar a la siguiente prueba...\n");
        printf ("\n\t...Debes poner el codigo secreto que se muestra a continuacion....\n");
        delay(5);
        do{
         peluche();
         printf("\n\n\t..Necesitas ver de nuevo?...\n\n1.si\n\n2.no\n\n");
         scanf("%i",&e);
        }while(e!=2);
        system("cls");
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


void prueba1()
{
char c;
FILE *p1;
p1 = fopen("prueba1.txt", "r");
if (p1 == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(p1,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(p1);

}

void prueba2()
{
char c;
FILE *p2;
p2 = fopen("prueba2.txt", "r");
if (p2 == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(p2,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(p2);
}

void prueba3()
{
char c;
FILE *p3;
p3 = fopen("prueba3.txt", "r");
if (p3 == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(p3,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(p3);

}

void prueba4()
{
char c;
FILE *p4;
p4 = fopen("prueba4.txt", "r");
if (p4 == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(p4,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(p4);
}

void matematica()
{
char c;
FILE *mat;
mat = fopen("matematica.txt", "r");
if (mat == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(mat,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(mat);
}
void casa()
{
char c;
FILE *casa;
casa = fopen("casa.txt", "r");
if (casa == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(casa,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(casa);
}

void puertas()
{
char c;
FILE *puerta;
puerta = fopen("3puertas.txt", "r");
if (puerta == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(puerta,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(puerta);
}
void mesa()
{
char c;
FILE *mesa;
mesa = fopen("mesa.txt", "r");
if (mesa == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(mesa,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(mesa);
}

void pistas()
{
 char c;
FILE *pistas;
pistas = fopen("pistas.txt", "r");//se abre el fichero que contiene el letrero en modo lectura
if (pistas == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(pistas,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(pistas);
}

void letras()
{
 char c;
FILE *letras;
letras = fopen("letras.txt", "r");
if (letras == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(letras,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(letras);
}

void suma()
{
 char c;
FILE *suma;
suma = fopen("suma_encriptada.txt", "r");
if (suma == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(suma,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(suma);
}

void peluche()
{
    char c;
    FILE *fd;
    fd =fopen("luz.txt","r");
    if (fd == NULL)
    {
        printf("\nEl fichero no pudo ser abierto.");
    }
    while (fscanf(fd,"%c",&c) != EOF)
    printf ("%c",c);
    printf("\n");
    fclose(fd);
    delay(0.5);
    system("cls");
}

void delay(float number_of_seconds)//añade una pequeña pausa al igual que lo haria "sleep"
{

float milli_seconds = 1000 * number_of_seconds;

clock_t start_time = clock();

while (clock() < start_time + milli_seconds);
}
