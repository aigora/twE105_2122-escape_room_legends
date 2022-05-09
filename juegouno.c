#include "juegouno.h"
#include "adddelay.h"

typedef struct
{
    char nombre[20];
    int devuelve;
} provincia;
void ice_cave()
{
    printf("\n\n\n");
    int a=0;
    FILE *pf;
    char imagen[12][13];
    //cargamos el mapa en una matriz de carateres
    pf=fopen("Proyecto/ice_cave.txt", "r");
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++) fscanf(pf,"%c",&imagen[i][j]);
    }
    int x=9,y=8;
    do
    {
        int avancex=0,avancey=0;
        char c;
        do
        {
            /*escaneamos la letra que pulsa el usuario y gracias a avancex y avance y vemos que coordenada hay que aumentar
            si es la primera vez que este bucle se ejecuta la variable a valdra 0 por lo que se imprimira el mapa en la posicion
            inicial sin necesidad de pulsar ninguna tecla*/
            if(a==0) c='d';
            else c=getch();
            if(c=='w')avancex=-1;
            else if(c=='s')avancex=1;
            else if(c=='a')avancey=-1;
            else if(c=='d')avancey=1;
            a++;
        }
        while((avancex!=0)&&(avancey!=0));
        do
        {
            //en este bucle movemos al personaje segun la tecla introducida y dibujamos su posicion cada vez que cambiamos sus coordenadas hasta llegar a la salida o chocar
            x=x+avancex;
            y=y+avancey;
            for(int i=0; i<11; i++)
            {
                if(imagen[x][y]!='M')
                {
                    //usamos este bucle para ddar el doble de grosor a los bloques
                    for(int k=0; k<2; k++)
                    {
                        for(int j=0; j<11; j++)
                        {
                 /*en la matriz de caracteres las paredes vienen representadas con la letra'M'
                 con este if lo que hacemos es no graficar el mapa si el personaje esta en las coordenadas de un obstaculo
                 ya que es ilogico que este en una pared, por ello luego retrocedera una casilla*/

                            if(imagen[x][y]!='M')
                            {
                            /*como el mapa en el fichero esta por asi decirlo encriptado lo desencriptamos con este if else
                            si las coordenadas a dibujar coinciden con las del jugador no imprimimos nada , si estas coinciden
                            con una M imprimimos una pared y si estas coinciden con un . imprimimos el fondo*/
                                if(x==i&&y==j) printf("    ");
                                else
                                {
                                    if(imagen[i][j]=='M')printf("%c%c%c%c", 219,219,219,219);
                                    if(imagen[i][j]=='.'||imagen[i][j]=='/')printf("%c%c%c%c", 176,176,176,176);
                                }
                            }
                        }
                        printf("\n");
                    }
                }
            }
            //imprimimos saltos de linea una vez acabado el mapa para centrar la siguiente graficacion del mapa
            if(imagen[x][y]!='M')  printf("\n\n\n\n");
            //esperamos un poco y avanzamos la posicion de nuevo como se indicaba al principio del bucle
            delay(0.075);
        }
        while((imagen[x][y]!='M')&&((imagen[x][y]!='/')));
        //cuando las coordenadas del jugador coincidan con las de de un obstaculo retrocedemos una casilla para que no este el jugador dentro del obstaculo
        x=x-avancex;
        y=y-avancey;
    }
    while(x!=2||y!=9);
    //imprimimos las instrucciones de la siguiente prueba y damos comienzo a la misma
    pf=fopen("Proyecto/texto_ice_cave.txt","r");
    imprime(pf,0);
    delay(1.5);
    fclose(pf);
    //candado();
}

void candado(){
//creamos las variables en las que almacenamos la contraseña que introduce el usuario y las que usarimos para indicar si esta bien el numero o no ;
char respuesta[3];
char cent='~',dec='~',un='~';
FILE *pf;
pf=fopen("proyecto/candado.txt" , "r");
//graficamos una primera vez el candado y le pedimos al usuario que introduzca una clave
imprime(pf,0);
    printf("                [][][][][][][][][][][]\n                [][][][][][][][][][][]\n\n\n\n\n\n\n ...introduce una contraseñna de 3 digitos...");
fclose(pf);
do{
scanf("%s" , respuesta);
//para que la funcion no se rompa si el usuario introduce un caracter en vez de un numero por accidente,almacenamos inicialmente la respuesta en una cadena de carcteres que mas tarde convertimos a un entero
int solucion=((respuesta[0]-48)*1000+(respuesta[1]-48)*100+(respuesta[2]-48)*10);
FILE *pf;
pf=fopen("proyecto/candado.txt" , "r");
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

    printf("                [][]%c%c[][]%c%c[][]%c%c[][]\n                [][][][][][][][][][][]\n\n" ,cent,cent,dec,dec,un,un);
    printf("\n\n\n\n\n");
    fclose(pf);
//cuando el usuario acierte la clave los tres testigos marcaran'*' y dejaremos de escanear las respuestas del usuario para graficar el candado abierto
}while((cent!='*')||(dec!='*')||(un!='*'));
delay(1);
pf=fopen("proyecto/candado_abierto.txt" , "r");
imprime(pf,0);
fclose(pf);
//delay(2);
laberinto();
}
void laberinto()
{
    FILE *pf;
    int a=1;
    //imprimimos las instrucciones de la prueba
    pf=fopen("proyecto/texto_laberinto.txt", "r");
    char imagen[41][42];
    //abrimos el fichjero en el que se encuentra dibujado con caracteres el mapa y almacenamos el mapa en una matriz de caracteres
    pf=fopen("proyecto/laberinto.txt", "r");
    for(int i=0; i<41; i++)
    {
        for(int j=0; j<42; j++) fscanf(pf,"%c",&imagen[i][j]);
    }
    char c;
    //coordenadas iniciales del jugador
    int x=2,y=1;
    do
    {
        //escaneamos la tecla que pulsa el jugador y dependidendo de que tecla sea aumentaremos o reduciremos sus coordenadas en el eje x o y
        int avancex=0,avancey=0;
        do
        {
            //si es la primera vez que realizamos este bucle(eso lo sabemos porque a=0) no le pediremos al usuario que introduzca tecla e imprimiremos directamente el mapa
            if(a==1) avancex=-1;
            else{
            c=getch();
            if(c=='w')  avancex=-1;
            if(c=='s')  avancex=1;
            if(c=='a')  avancey=-1;
            if(c=='d')  avancey=1;
            if(c=='*')  x=39,y=39;
        }a++;
        }
        while(avancex==0&&avancey==0);
        x=x+avancex;
        y=y+avancey;
        //si las coordenadas del jugador coinciden con un obstaculo(identificable en la matriz de caracteres con el caracter'M')
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
        //para cada fila almacenamos los caracteres a imorimir en una cadena de caracteres que imprimimos dos veces para dar mas grosor al dibujo
        for(int i=xmin; i<xmax+1; i++)
        {
            for(int k=0; k<2; k++)
            {
                for(int j=ymin; j<ymax+1; j++)
                {
                    if((i!=xmax)||(k=1)){
                    if((x==i)&&(y==j))printf("    ");
                    else
                    {
                        if(imagen[i][j]=='M') printf("%c%c%c%c",219,219,219,219);
                        if(imagen[i][j]=='.')printf("%c%c%c%c", 176,176,176,176);
                        if(imagen[i][j]=='/')printf("%c%c%c%c",178,178,178,178);
                    }
                    if((j==ymax)&&(i!=xmax)) printf("\n");
                }}
            }
        }
    }
    //si las coordenadas del jugador coinciden con el caracter '/'que es el que indica el fin del mapa terminamos el bucle
    while(imagen[x][y]!='/');
    delay(1);
}

//como en main.c hago mucho uso de la funcion printf y despues de la funcion delay, creo esta funcio para ahorrar codigo y que no se vea sobrecargado el documento main.c
void printfdelay(char frase[], float seconds)
{
    printf("%s",frase);
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
//////////////////////////
void habitacion(void )
{
    FILE *pf;
    int respuesta1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ... Entras en una nueva habitacion iluminada ...\n\n");
    delay(2.5);
    int c1;
    do
    {
        printf("\n\n\n\n");
        pf = fopen("Proyecto/Imagen Estaneria Mapa Puerta Cerrada.txt", "r");
        imprime(pf,0);
        do
        {
            scanf("%i",&respuesta1);
        }
        while ((respuesta1!=1)&&(respuesta1!=2)&&(respuesta1!=3));
        if(respuesta1==2)
        {
            int res=0;
            pf = fopen("Proyecto/Estanteria.txt", "r");
            imprime(pf,0);
            provincia estanteria[17];
            pf = fopen("Proyecto/Matriz_Provincias.txt", "r");
            for(int i=0; i<17; i++)fscanf(pf, " %[^;];%i\n",estanteria[i].nombre,&estanteria[i].devuelve);
            do
            {
                scanf("%i",&res);
                if((res>0)&&(res<19)) printf("\n ... Abres el libro de %s, y ves que en la primera pagina esta escrito en grande el numero '%i' ... \n",estanteria[res-1].nombre,estanteria[res-1].devuelve);
            }
            while (res!=18);
        }
        if(respuesta1==1)
        {
            int respuesta2;
            pf = fopen("Proyecto/Puerta.txt", "r");
            imprime(pf,0);
            do
            {
                scanf("%i", &respuesta2);
            }
            while((respuesta2!=1)&&(respuesta2!=2));
            if(respuesta2==1)
            {
                do
                {
                    pf = fopen("Proyecto/Puerta Candado Cerrado.txt", "r");
                    imprime(pf,c1);
                    char numeropalabra[5]="0000";
                    scanf(" %s",numeropalabra);
                    c1=1000*(numeropalabra[0]-48)+100*(numeropalabra[1]-48)+10*(numeropalabra[2]-48)+(numeropalabra[3]-48);
                }
                while((c1!=1492)&&(c1!=1800));
                if(c1==1492)
                {
                    pf = fopen("Proyecto/Puerta Candado Abierto.txt", "r");
                    imprime(pf,c1);
                }
            }
        }
        if(respuesta1 == 3)
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
    pf = fopen("Proyecto/Puerta Entrada.txt", "r");
    int respuesta;
    imprime(pf,0);
    while ((respuesta!=1)&&(respuesta!=2)) scanf("%i", &respuesta);
    fclose(pf);
}
void oscuridad1(void )
{
    FILE *pf;
    pf=fopen("Proyecto/Oscuridad.txt", "r");
    imprime(pf,0);
    getch();
    delay(1);
    printf("\n\n\n\n");
}
void tiempo1(void)
{
    FILE *pez1;
    time_t now = time(NULL);
    pez1= fopen("Proyecto/Hora.txt","w");
    fprintf(pez1,"%i,",now);
    fclose(pez1);
}
void tiempo2(void)
{
    FILE *pez1;
    time_t now = time(NULL);
    pez1= fopen("Proyecto/Hora.txt","a");
    fprintf(pez1,"%i,",now);
    fclose(pez1);
    int n1=0,n2=0;
    pez1= fopen("Proyecto/Hora.txt","r");
    fscanf(pez1,"%i,%i",&n1,&n2);
    printf("%i",n2-n1);
    fclose(pez1);
}
void imprime(FILE *pf,int solucion)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    char foto;
    while(fscanf(pf, "%c",&foto) !=EOF )
    {
        if(foto=='º') delay(1);
        else if(foto=='%') printf("%i"  , solucion/1000);
        else if(foto=='#') printf("%i" , (solucion%1000)/100);
        else if(foto=='+') printf("%i" , (solucion%100)/10);
        else if(foto=='&') printf("%i" , (solucion%10));
        else printf("%c",foto);
    }
}
