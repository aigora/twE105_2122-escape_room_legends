#include "juegouno.h"
#include "adddelay.h"
typedef struct
{
    char nombre[20];
    int devuelve;
} provincia;

void imprime1(FILE *pf,int solucion);

void imprimefn(char *pf,int x,int y,int xmax,int xmin,int ymax,int ymin,int N)
{
//el puntero pf apunta a la matriz de caracteres que queremos imprimir
    for(int i=xmin; i<xmax; i++)
    {
        //usamos este bucle for  para ddar el doble de grosor a los bloques
        for(int k=0; k<2; k++)
        {
            for(int j=ymin; j<ymax; j++)
            {
                /*como el mapa en la matriz esta por asi decirlo encriptado lo desencriptamos con este if else
                si las coordenadas a dibujar coinciden con las del jugador no imprimimos nada , si estas coinciden
                con una M imprimimos una pared y si estas coinciden con un . imprimimos el fondo*/
                if(x==i&&y==j) printf("    ");
                else
                {
                    if(*(pf + i*N + j )=='M')printf("%s%s%s%s", "\u2588", "\u2588", "\u2588", "\u2588");
                    if(*(pf + i*N + j )=='.')printf("%s%s%s%s", "\u2592","\u2592","\u2592","\u2592");
                    if(*(pf + i*N + j )=='/')printf("%s%s%s%s", "\u2593","\u2593","\u2593","\u2593");
                }
            }
            printf("\n");
        }
    }
}
int ice_cave()
{
    time_t now= time(NULL);
    FILE *pf;
    char imagen[12][12],*matrix;
    //cargamos el mapa en una matriz de carateres
    pf=fopen("Proyecto/ice_cave.txt", "r");
    if(pf==NULL)printf("no se ha encontrado ice_cave.txt");
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<12; j++) fscanf(pf,"%c",&imagen[i][j]);
    }
    //asociamos el puntero matrix a la matriz de caracteres
    matrix  = &imagen[0][0];
    int x=9,y=9;
    imprimefn(matrix,x,y,12,0,12,0,12);
    do
    {
        //avancex y avancey tomaran un valor u otro según la tecla pulsada por el jugador y serviran para ver en que sentido se mueve
        int avancex=0,avancey=0;
        char c;
        do
        {
            c=getch();
            if(c=='w')avancex=-1;
            else if(c=='s')avancex=1;
            else if(c=='a')avancey=-1;
            else if(c=='d')avancey=1;
        }
        while((avancex!=0)&&(avancey!=0));
        do
        {
            //en este bucle movemos al personaje segun la tecla introducida y dibujamos su posicion cada vez que cambiamos sus coordenadas hasta llegar a la salida o chocar
            imprimefn(matrix,x,y,12,0,12,0,12);
            x=x+avancex;
            y=y+avancey;
            printf("\n\n\n\n\n");
            //esperamos un poco y avanzamos la posicion de nuevo como se indicaba al principio del bucle
            delay(0.075);
        }
        while((imagen[x][y]!='M')&&((imagen[x][y]!='#')));//el caracter'#'marca la salida, gracias a este caracter el jugador se detendra al llegar a esta
        //cuando las coordenadas del jugador coincidan con las de de un obstaculo retrocedemos una casilla para que no este el jugador dentro del obstaculo
        x=x-avancex;
        y=y-avancey;
    }
    while(x!=2||y!=9);
    imprimefn(matrix,2,10,12,0,12,0,12);
    delay(0.5);
    return(time(NULL)-now);
}
int candado()
{
    time_t now=time(NULL);
    //creamos las variables en las que almacenamos la contraseña que introduce el usuario y las que usarimos para indicar si esta bien el numero o no ;
    char respuesta[3];
    char cent='~',dec='~',un='~';
    FILE *pf;
    //imprimimos las instrucciones de la siguiente prueba y damos comienzo a la misma
    pf=fopen("Proyecto/texto_ice_cave.txt","r");
    imprime(pf,0);
    pf=fopen("Proyecto/candado.txt", "r");
    //graficamos una primera vez el candado y le pedimos al usuario que introduzca una clave
    imprime(pf,0);
    printf("                [][][][][][][][][][][]\n                [][][][][][][][][][][]\n\n\n\n\n\n\n ...introduce una contraseñna de 3 digitos...");
    fclose(pf);
    do
    {
        scanf("%s", respuesta);
        //para que la funcion no se rompa si el usuario introduce un caracter en vez de un numero por accidente,almacenamos inicialmente la respuesta en una cadena de carcteres que mas tarde convertimos a un entero
        int solucion=((respuesta[0]-48)*1000+(respuesta[1]-48)*100+(respuesta[2]-48)*10);
        FILE *pf;
        pf=fopen("Proyecto/candado.txt", "r");
        //graficamos el candado con los caracteres que ha introducido el usuario
        imprime(pf,solucion);
        cent='~',dec='~',un='~';
        //revisamos la clave introducida por el usuario y en base a la clave q2ue sea los testigos toman unos valores u otros
        if ((respuesta[0]-48)==2) cent='*';
        else if(((respuesta[0]-48)==5)||((respuesta[0]-48)==1))cent='/';
        if ((respuesta[1]-48)==1) dec='*';
        else if(((respuesta[1]-48)==5)||((respuesta[1]-48)==2))dec='/';
        if ((respuesta[2]-48)==5) un='*';
        else if(((respuesta[2]-48)==1)||((respuesta[2]-48)==2))un='/';

        printf("                [][]%c%c[][]%c%c[][]%c%c[][]\n                [][][][][][][][][][][]\n\n",cent,cent,dec,dec,un,un);
        printf("\n\n\n\n\n");
        fclose(pf);
        //cuando el usuario acierte la clave los tres testigos marcaran'*' y dejaremos de escanear las respuestas del usuario para graficar el candado abierto
    }
    while((cent!='*')||(dec!='*')||(un!='*'));
    delay(1);
    pf=fopen("Proyecto/candado_abierto.txt", "r");
    imprime(pf,0);
    fclose(pf);
    return(time(NULL)-now);
}
int laberinto()
{
    time_t now=time(NULL);
    FILE *pf;
    //imprimimos las instrucciones de la prueba
    pf=fopen("Proyecto/texto_laberinto.txt", "r");
    imprime(pf,0);
    char *matrix, imagen[41][41];
    //abrimos el fichjero en el que se encuentra dibujado con caracteres el mapa y almacenamos el mapa en una matriz de caracteres
    pf=fopen("Proyecto/laberinto.txt", "r");
    for(int i=0; i<41; i++)
    {
        for(int j=0; j<42; j++) fscanf(pf,"%c",&imagen[i][j]);
    }
    //al puntero matrix,usado para imprimir el mapa, le asignamos la direccion de memoria de imagen[0][0];
    matrix=&imagen[0][0];
    char c;
    //coordenadas iniciales del jugador
    int x=1,y=1;
    imprimefn(matrix,x,y,15,0,14,0,41);
    do
    {
        //escaneamos la tecla que pulsa el jugador y dependidendo de que tecla sea aumentaremos o reduciremos sus coordenadas en el eje x o y
        int avancex=0,avancey=0;
        do
        {
            c=getch();
            if(c=='w')  avancex=-1;
            if(c=='s')  avancex=1;
            if(c=='a')  avancey=-1;
            if(c=='d')  avancey=1;
            if(c=='*')  x=39,y=39;
        }
        while(avancex==0&&avancey==0);
        x=x+avancex;
        y=y+avancey;
        //si las coordenadas del jugador coinciden con un obstaculo(identificable en la matriz de caracteres con el caracter'M')retrocede una casilla para asi no estar sobre el obstaculo
        if(imagen[x][y]=='M')
        {
            x=x-avancex;
            y=y-avancey;
        }
        //como el mapa es mas grande que la pantalla establecemos los margenes para que se muestren 7 bloques a cada lado del jugador, pero si el jugador esta a menos de 7 bloques de uno de los bordes se ajustan los bordes para q1ue se impriman siempre 15 caractersd
        int xmax=x+7,xmin=x-8,ymax=y+7,ymin=y-7;
        if(xmax>41) xmax=41,xmin=xmax-14;
        if(xmin<0)  xmin=0,xmax=xmin+15;
        if(ymax>41) ymax=41,ymin=ymax-14;
        if(ymin<0)  ymin=0,ymax=ymin+14;
        //imprimimos el mapa con las coordenadas del jugador y los margenes establecidos
        imprimefn(matrix,x,y,xmax,xmin,ymax,ymin,41);
    }
    //si las coordenadas del jugador coinciden con el caracter '/'que es el que indica el fin del mapa terminamos el bucle
    while(imagen[x][y]!='/');
    delay(1);
    return(time(NULL)-now);
    delay(2);
}
int habitacion(void )
{
    time_t now=time(NULL);
    FILE *pf;
    char respuesta1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ... Entras en una nueva habitacion iluminada ...\n\n");
    delay(2.5);
    int c1;
    do
    {
        printf("\n\n\n\n");
        pf = fopen("Proyecto/Imagen_Estaneria_Mapa_Puerta_Cerrada.txt", "r"); //Este programa abre un fichero en el cual se encuentra un dibujo con caracteres ASCII
        imprime(pf,0); //esta linea hace que se imprima el fichero mediante una funcion, la cual se ejecutará en otra parte.
        scanf("%c",&respuesta1);
        if((respuesta1!='1')&&(respuesta1!='2')&&(respuesta1!='3'))//estas lineas guardan un imput de parte del usuario, y se aseguran de
            while((respuesta1!='1')&&(respuesta1!='2')&&(respuesta1!='3'))//limitar los posibles imputs que se pueden introducir
                scanf("%c",&respuesta1);

        if(respuesta1=='2') //La opcion 2 corresponde a la opcion Estanteria
        {
            int res=0;
            pf = fopen("Proyecto/Estanteria.txt", "r"); //Se abre un archivo en el cual se encuentran escritos todos los nombre de los libros
            imprime(pf,0); //Se manda ese fichero a la funcion imprime para que se imprima
            provincia estanteria[17]; //Se nombra una estructura que contiene informacion acerca de los 17 libros
            pf = fopen("Proyecto/Matriz_Provincias.txt", "r");
            for(int i=0; i<17; i++)fscanf(pf, " %[^;];%i\n",estanteria[i].nombre,&estanteria[i].devuelve);
            do
            {
                scanf("%i",&res);
                if((res>0)&&(res<19)) printf("\n ... Abres el libro de %s, y ves que en la primera pagina esta escrito en grande el numero '%i' ... \n",estanteria[res-1].nombre,estanteria[res-1].devuelve);
            }
            while (res!=18); //Si el usuario pulsa 18, el programa vuelve a la habitacion anterior
        }
        if(respuesta1=='1') //La opcion 1 corresponde a la opcion puerta, en la cual se resuelve, o no, el candado
        {
            char respuesta2;
            pf = fopen("Proyecto/Puerta.txt", "r"); //Se abre una funcion que contiene una imagen ampliada de la puerta
            imprime(pf,0); //Se manda a imprimir la puerta en la funcion imprime
            scanf("%c",&respuesta2);
            if((respuesta2!='1')&&(respuesta2!='2')) //Se introducen unas lineas que tienen la funcion de guardar la respuesta
                while((respuesta2!='1')&&(respuesta2!='2'))//del usuario, a la vez de asegurarse de que son los esperados.
                    scanf("%c",&respuesta2);
            if(respuesta2=='1')
            {
                do
                {
                    pf = fopen("Proyecto/Puerta_Candado_Cerrado.txt", "r"); //Se abre un fichero con la imagen de la puerta y un candado cerrado
                    imprime(pf,c1); //Se manda a imprimir el fichero en la funcion imprime
                    char numeropalabra[5]="0000"; //se crea un string que absorbe 5 caracteres
                    scanf(" %s",numeropalabra);
                    c1=1000*(numeropalabra[0]-48)+100*(numeropalabra[1]-48)+10*(numeropalabra[2]-48)+(numeropalabra[3]-48); //estalinea convierte un caracter en texto, y ese texto en una unidad,decena,centena, o milena.
                }
                while((c1!=1492)&&(c1!=1800));
                if(c1==1492)
                {
                    pf = fopen("Proyecto/Puerta_Candado_Abierto.txt", "r"); //Si resuelves el candado, se abre un nuevo fichero que contiene una imagen del candado abierto
                    imprime(pf,c1);
                }
            }
        }
        if(respuesta1 == '3') //En el caso de la opcion 3, apareceran en la pantalla una animacion con diferentes mapas de España
        {
            pf = fopen("Proyecto/Mapa_Espana.txt", "r");
            imprime(pf,0);
            delay(1);
        }
    }
    while(c1!=1492);
    fclose(pf);
    return(time(NULL)-now);
}

void casa(void )
{
    FILE *pf;
    pf = fopen("Proyecto/Puerta_Entrada.txt", "r"); //Esta funcion imprime una imagen guardada en un fichero, que se imprimira mediante la funcion imprime
    imprime(pf,0);
    fclose(pf);
}
void oscuridad1(void )
{
    FILE *pf;
    pf=fopen("Proyecto/Oscuridad.txt", "r"); //Esta funcion imprime una imagen guardada en un fichero, que se imprimira mediante la funcion imprime
    imprime(pf,0);
    getch();
    delay(1);
    printf("\n\n\n\n");
}

float carga(void)
{
    float vuelta=1;
    delay(1);
    FILE *pf;
    //imprimimos la pantalla de carga
    pf=fopen("Proyecto/carga.txt","r");
    if(pf==NULL)printf("aaaa");
    imprime(pf,0);
    //imprimimos 10000 saltos de linea
    for(int i=0; i<10000; i++)printf("\n");
    char a='0';
    do
    {
        //imprimimos el menu inicial
        pf=fopen("Proyecto/pantalla_inicial.txt", "r");
        imprime(pf,0);
        scanf("%c", &a);
        if(a=='3')
        {
            char  b = 0;
            //imprimimos las opciones que tenemos en ajustes
            pf=fopen("Proyecto/opciones.txt","r");
            imprime(pf,0);
            while((b!='1')&&(b!='2')&&(b!='3')&&(b!='9'))scanf(" %c", &b);
            if(b=='1')
            {
                //si el usuario escoge ajustar la pantalla se mostraran los margenes a los que ajustar la pantalla
                pf=fopen("Proyecto/ajustes.txt","r");
                imprime(pf,0);
                getch();
            }
            if(b=='2')
            {
                FILE *pf1;
                pf1=fopen("Proyecto/Highscore.txt","r");
                imprime(pf1,0);
                //Esta funcion enseña al jugador la lista de puntuacion obtenida en veces anteriores, al igual que la dificultad;
                fclose(pf1);
                getch();

            }
            if(b=='3')
            {
                //mostramos al usuario que dificultades puede elegir y dependiendo de la que escoja la variable tomara un valor u otro
                pf=fopen("Proyecto/dificultades.txt", "r");
                imprime(pf,0);
                char c;
                while((c!='1')&&(c!='2')&&(c!='3')&&(c!='4')) scanf(" %c", &c);
                if(c=='1')vuelta=1;
                if(c=='2')vuelta=1.2;
                if(c=='3')vuelta=1.4;
                if(c=='4')vuelta=1.5;
            }
        }
        if(a=='2')
        {
            //imprimimos las pruebas que se pueden practicar y le pedimos que nos diga cual quiere
            pf=fopen("Proyecto/modo_practica.txt","r");
            imprime(pf,0);
            char practica;
            do
            {
                scanf("%c", &practica);
                if(practica=='1')laberinto();
                if(practica=='2')ice_cave();
                if(practica=='4')candado();
                if(practica=='3')habitacion();
                if(practica=='5')enigmas1();
                delay(1);
            }
            while((practica!='1')&&(practica!='2')&&(practica!='3')&&(practica!='4')&&(practica!='5')&&(practica!='9'));
        }
    }
    while(a!='1');
    fclose(pf);
    delay(1);
    return vuelta;
}
void imprime(FILE *pf,int solucion)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");//la funciojn imprime muestra en pantalla el contenido de un fichero que le haya sido dado.
    char foto;
    while(fscanf(pf, "%c",&foto) !=EOF )
    {
        //los ficheros tienen caracteres clave por asi decirlo que pretenden realizar una accion que no se puede realizar desde el fichero como es el caso de 'º' que indica que se ha de realizar una poausa de un segundo
        //hay otros carcteres como '%' que pretenden imprimir en pantalla numeros que haya introducido el usuario que no estan almacenados en el fichero
        if(foto=='º') delay(1);
        else if(foto=='^')delay(0.5);
        else if(foto=='%') printf("%i", solucion/1000);
        else if(foto=='#') printf("%i", (solucion%1000)/100);
        else if(foto=='+') printf("%i", (solucion%100)/10);
        else if(foto=='&') printf("%i", (solucion%10));
        else printf("%c",foto);
    }
}
void highscore(char nick[],int diff,float score)
{
    //esta funcion deja añade al fichero de resultados los resultados obtenidos
    char dificultad[20];
    if(diff==10)strcpy(dificultad,"Facil");
    if(diff==12)strcpy(dificultad,"Normal");
    if(diff==14)strcpy(dificultad,"Dificil");
    if(diff==15)strcpy(dificultad,"Muy Dificil");
    FILE *pf;
    pf=fopen("Proyecto/Highscore.txt","a");
    fprintf(pf,"%s \t\t %s \t\t %.2f\n",nick, dificultad, score);
    fclose(pf);
}



int enigmas1()
{
    time_t now=time(NULL);
    //Variables para las respuestas a las preguntas de tipo si/no.
    char elige,elige1;
    //Variables que almacenan las respuestas correctas
    int cod=501;
    char resp6[7]="etsidi",resp7[7]="ETSIDI",resp8[7]="Etsidi",res6[7];
    //Variables que almacenan la respuesta del usuario para despues compararla con la respuesta correcta
    char a1,re,res1,res2,res3,res4;
    int cod1;
    //Variables que almacenan el contenido de los ficheros utilizados
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
    //Contadores
    int ptos,ptos1;
        printf("\n\n\n\n");
        puerta = fopen("Proyecto/puerta1.txt", "r");//Apertura e impresion del fichero que contiene la primera puerta
        imprime1 (puerta,0);
        fclose(puerta);
        printf ("Entras?:\t1.si\n\n\t");
            do{
                scanf(" %c",&elige);
                    if (elige!='1')//Sentencia condicional para comprobar que el jugador elige una opcion valida
                        {
                            printf ("\n\nRESPUESTA NO VALIDA!!\n\nElige nuevamente\n\n\t\t");
                        }
              }while (elige!='1');//Bucle para volver a elegir una opcion valida

            do{
                ptos=0;
                printf("\n\n\n\n\n\n\n\n\n");
                mat = fopen("Proyecto/matematica.txt", "r");//apertura e impresion del fichero que contiene 4 cajas y posterior cierre de fichero
                imprime1(mat,0);
                fclose(mat);
                delay(3);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                p1 = fopen("Proyecto/prueba1.txt", "r");//Apertura, impresion y cierre del fichero con el primer acertijo
                imprime1(p1,0);
                fclose(p1);
                printf("\n\n\n\n\n\n\n\n\n\n\tResponde:");
                    do{
                        scanf (" %c",&res1);//Funcion scanf para almacenar la respuesta del jugador
                            if (res1!='1'&&res1!='2'&&res1!='3'&&res1!='4')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t\t");
                                }
                      }while(res1!='1'&&res1!='2'&&res1!='3'&&res1!='4');
                    if (res1=='3')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n\n\n\n");
                        ptos++;//contador de acertijos completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA\n\n\n\n\n");
                      }
                delay(3);

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                p2 = fopen("Proyecto/prueba2.txt", "r");//Apertura, impresion y cierre del fichero con el segundo acertijo
                imprime1(p2,0);
                fclose(p2);
                printf("\n\n\n\n\n\n\n\n\tResponde:");
                    do{
                        scanf (" %c",&res2);//Funcion scanf para almacenar la respuesta del jugador
                            if (res2!='1'&&res2!='2'&&res2!='3'&&res2!='4')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t\t");//comprobacion de que la eleccion del jugador esta dentro de las opciones
                                }
                      }while(res2!='1'&&res2!='2'&&res2!='3'&&res2!='4');
                    if(res2=='3')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n\n\n\n");
                        ptos++;//contador de acertijos completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA...\n\n\n\n\n");
                      }
                delay(3);


                printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                p3 = fopen("Proyecto/prueba3.txt", "r");//Apertura, impresion y cierre del fichero con el tercer acertijo
                imprime1(p3,0);
                fclose(p3);
                printf("\n\n\n\n\n\n\n\tResponde:");
                    do{
                        scanf (" %c",&res3);//Funcion scanf para almacenar la respuesta del jugador
                            if (res3!='1'&&res3!='2'&&res3!='3'&&res3!='4')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t\t");//comprobacion de que la eleccion del jugador esta dentro de las opciones
                                }
                      }while(res3!='1'&&res3!='2'&&res3!='3'&&res3!='4');

                    if(res3=='2')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                        ptos++;//contador de acertijos completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA...\n\n");
                      }
                delay(3);

                printf("\n\n\n\n\n\n\n\n\n");
                p4 = fopen("Proyecto/prueba4.txt", "r");//Apertura, impresion y cierre del fichero con el cuarto acertijo
                imprime1(p4,0);
                fclose(p4);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\tResponde:");
                    do{
                        scanf (" %c",&res4);//Funcion scanf para almacenar la respuesta del jugador
                            if (res4!='1'&&res4!='2'&&res4!='3'&&res4!='4')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t\t");//comprobacion de que la eleccion del jugador esta dentro de las opciones
                                }
                      }while(res4!='1'&&res4!='2'&&res4!='3'&&res4!='4');

                    if(res4=='4')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                        ptos++;//contador de acertijos completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA..\n\n");
                      }
                delay(2);
                    if(ptos>=3)//Sentencia condicional if que comprueba que el jugador logro completar por lo menos 3 acertijos
                      {
                        printf("\n\n\tFELICIDADES LOGRASTE COMPLETAR 3 ACERTIJOS!!!\n\n");
                        printf("\tPASAS A LA SIGUIENTE PRUEBA\n");
                      }
                    else
                      {
                        printf("\n\n\tNO LOGRASTE COMPLETAR POR LO MENOS 3 LOS ACERTIJOS!!!\n\n");
                        printf("\tTENDRAS QUE VOLVER A EMPEZAR\n");
                      }
                delay(4);

              }while (ptos<=2);//Bucle que repite el juego si el jugador no ha logrado completar 3 acertijos


        printf("\n\n\n\n\n\n\n");

        puerta2 = fopen("Proyecto/puerta2.txt", "r");//Apertura e impresion del fichero que contiene la segunda puerta
        imprime1 (puerta2,0);
        fclose(puerta2);
            do{
                scanf(" %c",&elige1);
                    if (elige1!='1')//Sentencia condicional para comprobar que el jugador elige una opcion valida
                        {
                            printf ("\n\nRESPUESTA NO VALIDA!!\n\nElige nuevamente\n\n\t\t");
                        }
              }while (elige1!='1');//Bucle para volver a elegir una opcion correcta

            do{

                ptos1=0;
                printf("\n\n\n\n\n\n\n\n\n\n\n");
                mesa = fopen("Proyecto/mesa.txt", "r");//apertura e impresion del fichero que contiene 3 sobres y posterior cierre de fichero
                imprime1(mesa,0);
                fclose(mesa);
                delay(3);


                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                suma = fopen("Proyecto/suma_encriptada.txt", "r");//Apertura, impresion y cierre del fichero con el primer enigma
                imprime1(suma,0);
                fclose(suma);
                printf ("\n\n\t\tElige cual de las 3 opciones es la correcta...\n\n\n\n\n\n");
                printf("\n\n\n\n\n\n\tResponde:");
                    do{
                        scanf (" %c",&re);//Funcion scanf para almacenar la respuesta del jugador
                            if (re!='1'&&re!='2'&&re!='3')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t\t");//comprobacion de que la eleccion del jugador esta dentro de las opciones
                                }
                       }while(re!='1'&&re!='2'&&re!='3');//Bucle que se repite hasta que el jugador seleccione una opcion valida
                    if (re== '1')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                        ptos1++;//contador de enigmas completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                      }
                delay(2);//funcion similar a sleep que crea un tiempo de retardo antes de ejecutar la siguiente accion.

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                letras = fopen("Proyecto/letras.txt", "r");//Apertura, impresion y cierre del fichero con el segundo enigma
                imprime1(letras,0);
                fclose(letras);
                printf("\n\n\n\n\n\n\tResponde:");
                scanf ("%s",res6);//Funcion scanf para almacenar la respuesta del jugador en una cadena de caracteres
                    if(strcmp(resp6, res6) == 0||strcmp(resp7, res6) == 0||strcmp(resp8, res6) == 0)//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                        ptos1++;//contador de enigmas completados
                      }
                    else
                    {
                        printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                    }

                delay(2);

                printf("\n\n\n\n\n\n\n\n\n\n\n");
                pistas = fopen("Proyecto/pistas.txt", "r");//Apertura, impresion y cierre del fichero con el tercer enigma
                imprime1(pistas,0);
                fclose(pistas);
                printf("\n\n\tResponde:");
                    do{
                        scanf (" %c",&a1);//Funcion scanf para almacenar la respuesta del jugador
                            if (a1!='1'&&a1!='2'&&a1!='3'&&a1!='1'&&a1!='2'&&a1!='3')
                                {
                                    printf ("\n\n\tEleccion invalida!!\tElige nuevamente\n\n\t");//comprobacion de que la eleccion del jugador esta dentro de las opciones
                                }
                      }while(a1!='1'&&a1!='2'&&a1!='3'&&a1!='1'&&a1!='2'&&a1!='3');//Bucle que se repite hasta que el jugador seleccione una opcion valida
                    if(a1=='3')//Sentencia condicional if que compara la respuesta del jugador con las posibles respuestas correctas
                      {
                        printf ("\n\n\tRESPUESTA CORRECTA!!!\n\n");
                        ptos1++;//contador de enigmas completados
                      }
                    else
                      {
                        printf ("\n\n\tRESPUESTA INCORRECTA\n\n");
                      }

                delay(2);

                    if(ptos1>=3)//Sentencia condicional if que comprueba que el jugador logro completar todos los enigmas
                      {
                        printf("\n\n\tFELICIDADES LOGRASTE COMPLETAR TODOS LOS ENIGMAS!!!\n\n");
                        printf("\tPASAS A LA SIGUIENTE PRUEBA\n");
                      }
                    else
                      {
                        printf("\n\n\tNO LOGRASTE COMPLETAR TODOS LOS ENIGMAS!!!\n\n");
                        printf("\tTENDRAS QUE VOLVER A EMPEZAR\n");
                      }
                delay (4);
              }while(ptos1<=2);//Bucle que se repite hasta que el jugador logre completar todos los enigmas


                printf("\n\n\n\n\n\n\n\n");

                            peluche =fopen("Proyecto/luz.txt","r");//Apertura, impresion y cierre del fichero con la siguiente prueba
                            imprime1(peluche,0);

            do{
                //printf ("\n\n\tDigita el codigo oculto....\n\n\t");
                scanf("%i",&cod1);//Funcion scanf que almacena la respuesta del jugador para despues ejecutar la sentencia condicional
                    if (cod1==cod)//Sentencia condicional que comprueba si la respuesta del jugador es la correcta.
                        {
                            printf ("\n\n\tFELICIDADES HAS CONSEGUIDO PASAR A LA SIGUIENTE PRUEBA!!!");
                        }
                    else
                            printf ("\n\n\tERROR!!! CODIGO INCORRECTO...\n");
              }while(cod1!=cod);//Bucle que se repite hasta que el jugador digite el codigo correcto
            delay(3);
 return time(NULL)-now;
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
void fin(float puntuacionf,float diff){
char usuario[20];
delay(2);
FILE *pf;
int puntuacion=puntuacionf;
//imprimimos la pantalla final con la puntuacion del jugadfor
pf=fopen("Proyecto/final.txt","r");
imprime(pf,puntuacion);
//le pedimos al usuario su nick para guardarlo en el archivo
scanf("%s",usuario);
//guardamos en el archivo el usuario , la puntuacion y la dificultrad, como teniamos problemas con que la dificultad fuese un floa(puede ser 1,1.2,1.4,1.5) lo multiplicamos por 10 parfa que pierda la parte decimal(es una solucion cutre pero era la mas sencilla)
highscore(usuario,diff*10,puntuacionf);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nENHORABUENA %s, HAS COMPLETADO EL JUEGO. YA PUEDES CERRAR EL JUEGO." , usuario);
}
