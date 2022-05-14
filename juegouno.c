#include "juegouno.h"
#include "adddelay.h"

typedef struct
{
    char nombre[20];
    int devuelve;
} provincia;
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
                    if(*(pf + i*N + j )=='M')printf("%c%c%c%c", 219,219,219,219);
                    if(*(pf + i*N + j )=='.')printf("%c%c%c%c", 177,177,177,177);
                    if(*(pf + i*N + j )=='/')printf("%c%c%c%c", 178,178,178,178);
                }
            }
            printf("\n");
        }
    }
}
void ice_cave()
{
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
}
void candado()
{
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
    //delay(2);
    //laberinto();
}
void laberinto()
{
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
}
void habitacion(void )
{
    FILE *pf;
    char respuesta1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ... Entras en una nueva habitacion iluminada ...\n\n");
    delay(2.5);
    int c1;
    do
    {
        printf("\n\n\n\n");
        pf = fopen("Proyecto/Imagen Estaneria Mapa Puerta Cerrada.txt", "r"); //Este programa abre un fichero en el cual se encuentra un dibujo con caracteres ASCII
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
                    pf = fopen("Proyecto/Puerta Candado Cerrado.txt", "r"); //Se abre un fichero con la imagen de la puerta y un candado cerrado
                    imprime(pf,c1); //Se manda a imprimir el fichero en la funcion imprime
                    char numeropalabra[5]="0000"; //se crea un string que absorbe 5 caracteres
                    scanf(" %s",numeropalabra);
                    c1=1000*(numeropalabra[0]-48)+100*(numeropalabra[1]-48)+10*(numeropalabra[2]-48)+(numeropalabra[3]-48); //estalinea convierte un caracter en texto, y ese texto en una unidad,decena,centena, o milena.
                }
                while((c1!=1492)&&(c1!=1800));
                if(c1==1492)
                {
                    pf = fopen("Proyecto/Puerta Candado Abierto.txt", "r"); //Si resuelves el candado, se abre un nuevo fichero que contiene una imagen del candado abierto
                    imprime(pf,c1);
                }
            }
        }
        if(respuesta1 == '3') //En el caso de la opcion 3, apareceran en la pantalla una animacion con diferentes mapas de España
        {
            pf = fopen("Proyecto/Mapa Espana.txt", "r");
            imprime(pf,0);
            delay(1);
        }
    }
    while(c1!=1492);
    fclose(pf);
}

void casa(void )
{
    FILE *pf;
    pf = fopen("Proyecto/Puerta Entrada.txt", "r"); //Esta funcion imprime una imagen guardada en un fichero, que se imprimira mediante la funcion imprime
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

void carga(void)
{
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
        pf=fopen("Proyecto/pantalla inicial.txt", "r");
        imprime(pf,0);
        scanf("%c", &a);
        if(a=='3')
        {
            //imprimimos las opciones que tenemos en ajustes
            pf=fopen("Proyecto/ajustes.txt","r");
            imprime(pf,0);
            getch();
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
                delay(1);
            }
            while((practica!='1')&&(practica!='2')&&(practica!='3')&&(practica!='4')&&(practica!='9'));
        }
    }
    while(a!='1');
    fclose(pf);
    delay(1);
}
void imprime(FILE *pf,int solucion)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); //La funcion imrime actua como un restaurante en el cual al chef le llegan comandas, y el chef cocina lo que se le pide.
    char foto; //En este caso la funcion imprime funciona como chef, y las comandas vienen de las distintas funciones void alojadas a lo largo de todo el programa
    while(fscanf(pf, "%c",&foto) !=EOF )
    {
        if(foto=='º') delay(1);
        else if(foto=='^')delay(0.5);
        else if(foto=='%') printf("%i", solucion/1000);
        else if(foto=='#') printf("%i", (solucion%1000)/100);
        else if(foto=='+') printf("%i", (solucion%100)/10);
        else if(foto=='&') printf("%i", (solucion%10));
        else printf("%c",foto);
    }
}
void grafica(char imagen[50][50])
{
    for(int a=0; a<11; a++)
    {
        for(int b=0; b<11; b++ ) printf("%c", imagen[a][b]);
    }
}
void fin(void)
{
    int a;
    a=0;
}
