#include "juegouno.h"
#include "adddelay.h"

typedef struct
{
    char nombre[20];
    int devuelve;
} provincia;

void posicion(int x, int y )
{
    mapa(1, 0);
    //creo una variable que servira para poner fin al juego
    int j = 0 ;
    //la variable c es la que se escanea para ver que direccion toma el personaje
    char c;
//almaceno las coordenadas de los obstaculos en variables de tipo matriz , donde cada columna guarda las coordenadas de un obstaculo.
//en este caso lo obstaculos estan en el (2,0),(4,0),(5,0),(8,1)...
    int obs[2][9]= {{2,4,5,8,4,1,6,3,7},
        {0,0,0,1,2,3,5,6,8}
    };

    do
    {
//avancex y avancey tomaran un valor u otro en funcion de la tecla introducida por el usuario para ver en que direccion se mueve el personaje
//al pone fin al bucle siguiente.
        int avancex=0, avancey=0;
        int al=0;
        do
        {
            c=getch();
//scanf("%c" , &c);
//cuando la tecla que introduce el usuario es 'w''a''s' o 'd' al toma el valor de uno y se pone fin al bucle scanf-
//esto lo hacemos ya que de no hacerlo , si el usuario introdujese una teclpa diferente a estas las variavles anacex y avance y tendrian un valor de 0 por lo que el bucle do while que se encuentra despues de este no acabaria
            if (c== 'w' ) avancey= 1;
            if (c== 's' ) avancey=-1;
            if (c== 'a' ) avancex= 1;
            if (c== 'd' ) avancex=-1;
            if((avancex!=0)||(avancey!=0))al=1;
        }
        while(al!=1);
        int i = 0 ;

        do
        {
//avanzamos una posicion en el sentido que haya introducido el usuario, si las coordenadas del personaje coinciden con las de un obstaculo o un borde se deja de avanzar
            mapa(x, y);
            delay(0.1);
            y=y+avancey;
            x=x+avancex;
            int l;
//con este bucle revisamos si las coordeanadas del usuario coinciden con las de algun obstaculo.
            for(l=0; l<9; l++)
            {
                if((obs[0][l]==x)&&(obs[1][l])==y) i=1;
            }
            if((y==9)||(y==-1))i=1;
            if((x==9)||(x==-1))i=1;

        }
        while (i!=1) ;
//dado que el personaje no puede estar dentro de un obstaculo, se retrocede una casilla para que no coincidan las coordenadas del personaje con las de un obstaculo o borde del mapa
        y=y-avancey;
        x=x-avancex;

//una vex las coordenadas del personaje coincidan con las de la salida la variable j toma el valor'1' poniendose fin al bucle y con ello a la primera sala del scaperoom
        if((x==0)&&(y==7))
        {
            j=1;
            mapa(-1, 7);
        }
    }
    while (j!=1);
    delay(1);
//a�adimios varios altos de linea para perder de vista el escenario y procedemos a contar al usuario los pasos a seguir para pasar de fase
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printfdelay("...vaya, parece que la puerta se encuentra cerrada por un candado...\n\n",3);
    printfdelay("para abrir el candado  tendras que adivinar una clave de tres digitos\n\n",3);
    printfdelay("al lado de cada digito introducido aparecera una luz.\n\n", 3);
//dejaremos mas tiempo entre instrucciones ya que el usuariom necesita tener claro como funciona el reto del candado
    printf("si el digito es correcto se encendera esta luz: %c ", 176);
    delay(3);
    printf("\n\nsi el digito se encuentra en la clave pero no en la posicion adecuada, aparecera esta otra luz:%c\n\n", 178);
    delay(3);
    printfdelay("de lo contrario, si el digito no aparece en la clave del candado, no se encendera ninguna luz",6);
//entre los parentesis de la funcion candado indicamos cual va a ser la clave a adivinar, en este caso 215 pero esta podria ser facilmente cambiada
//y procedemos con la prueba del candado , una vez esta acabe el usuario pasara a la segunda fase del escape room
    candado(215);
}

void candado(int x )
{
//hacemos que el candado se muestre en la posicion 000
    int ncent=0;
    int ndec=0;
    int nud=0;
//creamos variables donde almacenamos las decenes centenas y unidades de la clave a averiguar
    int xcent=x/100;
    int xdec=(x-xcent*100)/10;
    int xud=(x-xcent*100-xdec*10);
//creamos variables char a las que asignamos un codigo asci para imprimir en pantalla el dibujo del candado ya que de otra forma puede dar problemas imprimir en pantalla
//caracteres del codigo asci extendido
    char candado= 219;
    char barra=186;
    char izquierda=187, derecha=201;
    char tumbada=205;
//la variable a la usaremos para poner fin al bucle do while
    int a=0;
//la variable anterior la usaremos para almacenar en ella el ultimo numero de 3 digitos introducido , de esta forma, si el usuario introduce un numero no valido(superior a 3 digitos)
//este no se tendr� en cuenta
//int anterior;
    do
    {
        char numero[3];
//la variable open en principiuo dibuja el candado cerrado pero una vez se ha adivinado la contrase�a , esta cambiara de valor para dibujar el candado abierto
        char open=186;
//si la variable n(numero introducido por el usuario)es igual a la contrase�a , 'a' tomara un valor de uno poniendo fin al bucle una vez se dibuje el candado abierto
        int n=100*ncent+10*ndec+nud;
        if(n==x)
        {
            a=1;
            open='\t';
        }

//con estas funciones if , lo que hacemos es comprobar de que color hay que dibujar la luz para cada digito, dando asi unos valores u otros a las variables cand1 , cand2 y cand3
//y con ello cambiando la representacion del candado
        char cand1=219, cand2=219,cand3=219;
        if(ncent==xud) cand1=178;
        if(ncent==xdec) cand1=178;
        if(ncent==xcent) cand1=176;
        if(ndec==xud) cand2=178;
        if(ndec==xcent) cand2=178;
        if(ndec==xdec) cand2=176;
        if(nud==xcent) cand3=178;
        if(nud==xdec) cand3=178;
        if(nud==xud) cand3=176;
//dibujamos el candado , usando las vraibles open ,cand1 , cand2 y cand3 para adaptar el dibujo del candado a la situacion en la que nos encontramos
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                            %c%c%c%c%c%c\n", derecha, tumbada, tumbada, tumbada, tumbada, izquierda);
        printf("                            %c    %c\n", barra, barra);
        printf("                            %c    %c\n", barra, open);
        printf("                           %c%c%c%c%c%c%c%c\n", candado, candado, candado, candado, candado, candado, candado, candado);
        printf("                           %c%i%c%c%c%c%c%c\n", candado, ncent,cand1, candado, candado, candado, candado, candado);
        printf("                           %c%c%c%c%c%c%c%c\n", candado, candado, candado, candado, candado, candado, candado, candado);
        printf("                           %c%i%c%c%c%c%c%c\n", candado, ndec,  cand2, candado, candado, candado, candado, candado);
        printf("                           %c%c%c%c%c%c%c%c\n", candado, candado, candado, candado, candado, candado, candado, candado);
        printf("                           %c%i%c%c%c%c%c%c\n", candado, nud,cand3, candado, candado, candado, candado, candado);
        printf("                           %c%c%c%c%c%c%c%c\n", candado, candado, candado, candado, candado, candado, candado, candado);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//si a es distinto de uno significa que aun no se ha acertado la clave , por ello pedimos al usuario que introduzca una nueva clave a probar
//de no poner este if estariamos pidiendo al usuario que introduzca la clave aunque la haya acertado en el intento anterior
        if(a!=1)
        {
            int candadoscanf;
            do
            {
                candadoscanf=0;
                scanf("%s", numero);
//almacenamos el numero en una cadena de cracteres ya quer de lo contrario , si el usuario por accidente escribe un c aracter en vez de un numero el codigo fallaria y habria que reempezar el scape room
                ncent=numero[0]-48;
                ndec=numero[1]-48;
                nud=numero[2]-48;
                if((ncent>=0)&&(ncent<=9))candadoscanf++;
                if((ndec>=0)&&(ndec<=9))candadoscanf++;
                if((nud>=0)&&(nud<=9))candadoscanf++;
//si introduce un cacter le pedimos un nuevo numerto al usuario avisando de que este no es valido
                if(candadoscanf!=3)printf("\n introduce un numero valido\n");
            }
            while(candadoscanf!=3);
        };
    }
    while(a!=1);
//una vez se ha averiguado la contrase�a avisamos al usuario de que ha acertado la contrase�a y pasado un segundo pasaremos al siguiente escenario
    printf("HAS ABIERTO EL CANDADO!!\n\n\n\n");
    delay(2.5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void mapa(int x, int y )
{
    int obs[2][9]= {{2,4,5,8,4,1,6,3,7},
        {0,0,0,1,2,3,5,6,8}
    };
//como es mas rapido imprimir una cadena de caracteres que todos los caracteres de esta uno a uno , almacenamos los caracteres necesarios para mostrar el escenario en una cadena de cacateres.
    char fila[44];
//con estas variables revisamos una fila , dentro de esta fila , miramos de izquierda a derecha que valores tiene que tomar la string fila en esa posicion
    int xmap, ymap;
    for(ymap=9 ; ymap>-2; ymap--)
    {
        int f=0;
        for(xmap=9 ; xmap>-2; xmap--)
        {
            int p=0;
            int l;
//la variable p toma un valor u otro dependiendo si las cordenadas que estamos revisando corresponden con las de un obstaculo o poared , las de el njgadr , o las de el fondo.
            for(l=0; l<9; l++)
            {
                if((obs[0][l]==xmap)&&(obs[1][l])==ymap) p=1;
            }
            if((xmap==-1)||(ymap==-1)||(ymap==9)||(xmap==9))p=1;
            if((xmap==-1)&&(ymap==7))p=0;
            if((xmap==x)&&(ymap==y))p=2;
//segun el valor que haya tomado pa�adimos a la cadena de caracteres fila unos caracteres u otros
            if(p==0)fila[f]=(char)176,fila[f+1]=(char)176,fila[f+2]=(char)176,fila[f+3]=(char)176;
            if(p==1)fila[f]=(char)219,fila[f+1]=(char)219,fila[f+2]=(char)219,fila[f+3]=(char)219;
            if(p==2)fila[f]=' ',fila[f+1]=' ',fila[f+2]=' ',fila[f+3]=' ';
            f=f+4;
        }
//imprimimos en pantalla dos veces la cadena de caracteres con el fin de hacer mas grandes los cubos que dibujan el mapa
        printf("%.44s\n",fila);
//imprimimos solo los primeros 44 caracteres de la cadena , aunque esta tiene solo 44 caracteres , pero si no ponemos el limitador a�ade caracteres no deseados al final
        printf("%.44s\n",fila);
    }
    printf("\n\n\n\n");
}
void posicion2(int x, int y )
{
    printfdelay("...al abrir la puerta ves un conducto de ventilacion por el que podrias entrar...\n\n",2.5);
    printfdelay("...al entrar ves al lado tuyo una escotilla quer te llevaria a una sala en la que podria estar la salida... \n\n", 2.5);
    printfdelay("...la escotilla esta cerrada, para abrirla necesitaras 4 llaves que estan dispersas por los conductos...\n\n",2.5);
    printfdelay("...una vez las tengas todas podras abrir la escotilla que se encuentra a la izquierda de la casilla en la que apareces..\n\n", 2.5);
    printf("pulsa cualquier tecla para empezar");
    getch();
    delay(1);
    laberinto(1,39,0,0,0,0);
    int j = 0 ;
    char c;
//la variable c es donde almacenaremos la letra que introduzca el usuario, las variables m1,m2,m3 y m4 indican si la moneda yq se ha cogido o no , siendo un 0 que no se ha cogido y un 1 que si.
    int m1=0,m2=0,m3=0,m4=0;
    do
    {
        int avancex=0, avancey=0;
        int al=0;
        int a=0;
//estas matrices almacenan los obstaculos del mapa , como estos no son bloques sencillos sino largos los almaceno de la siguiente form:
//en obsx almaceno las paredes en el eje x , cada columna corresponde a un obstaculo , siendo la primera fila de cada columna la posicion en el eje y en la que se encuentra la pared , la segunda fila en que coordenada en x empieza y la tercera en que coordenada en x acaba.
//para obsy funciona igual pero cambiando las x por las y
        int obsx[3][90]= { {6,20,34,28,36,24,14,8,18,32,24,20,12,4,6,10,16,26,30,14,16,2,28,34,30,38,22,8,10,12,4,2,18,26,36,28,32,30,24,16,20,22,18,14,26,10,4,2,34,38,32,24,20,16,18,22,36,34,28,12,16,8,6,4,34,36,28,32,26,38,18,2,22,28,36,34,24,38,30,14,38,28,22,20,16,10,12,6,4,18,},
            {0,0,2,2,2,2,2,2,2,4,6,6,4,4,6,6,4,4,4,6,8,8,8,8,10,10,10,10,12,12,14,14,12,10,14,14,16,16,16,16,14,14,18,18,18,20,20,20,18,16,20,22,22,22,24,24,20,22,24,22,26,26,24,26,22,24,24,26,28,28,28,30,30,30,30,30,32,32,34,30,38,38,34,32,32,32,34,36,32,36,},
            {2,2,4,4,4,4,4,6,6,8,10,10,8,6,10,10,6,6,6,16,12,10,12,14,12,12,12,20,18,14,16,18,14,16,16,16,18,18,18,18,16,20,20,24,26,26,24,22,20,26,24,24,24,24,26,26,22,26,28,32,28,36,34,30,26,26,28,36,30,30,32,32,32,34,32,38,36,36,38,38,40,40,38,36,34,34,40,38,38,38,}
        };
        int obsy[3][97]= { {2,2,2,2,4,4,4,4,6,6,6,6,6,8,8,8,8,8,10,10,10,10,10,12,12,12,12,12,14,14,14,14,16,16,16,16,14,18,18,18,18,18,20,20,20,20,20,22,22,22,22,22,24,24,24,26,26,26,26,26,26,28,28,28,28,28,30,30,30,30,30,30,30,2,32,32,32,32,32,32,34,34,34,34,34,36,36,36,36,36,36,38,38,38,38,38,20},
            {38,24,2,10,2,6,18,34,0,12,26,32,20,2,6,16,22,34,2,8,16,32,36,0,10,18,28,34,4,14,28,38,4,10,24,32,20,2,12,18,26,34,0,4,10,14,28,6,12,16,26,34,2,16,28,0,8,14,18,30,36,0,10,18,32,38,2,10,16,20,24,30,34,20,4,8,12,18,30,38,0,10,16,26,34,0,4,8,14,24,36,2,6,16,22,30,36},
            {40,34,6,18,4,12,26,38,6,18,30,40,24,4,10,18,32,38,6,14,20,34,40,6,12,26,32,36,8,18,34,40,6,20,28,38,24,8,14,20,32,36,2,6,12,26,34,10,14,24,30,36,8,18,32,4,10,16,26,34,38,2,16,30,36,40,4,12,18,22,26,32,38,22,6,10,16,28,32,40,4,12,18,30,36,2,6,10,18,28,38,4,10,20,28,36,38,}
        };
//el resto de la funcion funciona igual que la funcion posicion usada para la primera sala
        do
        {
            c=getch();
            if (c== 'w' ) avancey= 1;
            if (c== 's' ) avancey=-1;
            if (c== 'a' ) avancex=-1;
            if (c== 'd' ) avancex=1;
            if(c== '*')
            {
                avancex=1;
                m1=1,m2=1,m3=1,m4=1;
            }
            if((avancex!=0)||(avancey!=0))al=1;
        }
        while(al!=1);
        delay(0.1);
        y=y+avancey;
        x=x+avancex;
        int i;
        for(i=0; i<90; i++)
        {
            if((y==obsx[0][i])&&(x>=obsx[1][i])&&(x<=obsx[2][i]))a=1;
        }
        for(i=0; i<97; i++)
        {
            if((x==obsy[0][i])&&(y>=obsy[1][i])&&(y<=obsy[2][i]))a=1;
        }
        if((x==0)||(x==40)||(y==0)||(y==40)) a=1;
        if(a==1)
        {
            y=y-avancey;
            x=x-avancex;
        }
//si el usuario pasa por las coordenadas de una moneda esta pasara a estar cogida, la sala acaba cuando se recogan las cuatro monedas
        if((x==39)&&(y==1))m1=1;
        if((x==33)&&(y==39))m2=1;
        if((x==19)&&(y==21))m3=1;
        if((x==1)&&(y==21))m4=1;
        laberinto(x,y,m1,m2,m3,m4);
        if(((m1+m2+m3+m4)==4)&&(x==1)&&(y==39)) j=1;
    }
    while (j!=1);
    delay(1);
}

void laberinto(int py, int px,int m1,int m2, int m3, int m4)
{
//almaceno las paredes de la misma forma que lo hago en posicion2
    int obsx[3][90]= { {6,20,34,28,36,24,14,8,18,32,24,20,12,4,6,10,16,26,30,14,16,2,28,34,30,38,22,8,10,12,4,2,18,26,36,28,32,30,24,16,20,22,18,14,26,10,4,2,34,38,32,24,20,16,18,22,36,34,28,12,16,8,6,4,34,36,28,32,26,38,18,2,22,28,36,34,24,38,30,14,38,28,22,20,16,10,12,6,4,18,},
        {0,0,2,2,2,2,2,2,2,4,6,6,4,4,6,6,4,4,4,6,8,8,8,8,10,10,10,10,12,12,14,14,12,10,14,14,16,16,16,16,14,14,18,18,18,20,20,20,18,16,20,22,22,22,24,24,20,22,24,22,26,26,24,26,22,24,24,26,28,28,28,30,30,30,30,30,32,32,34,30,38,38,34,32,32,32,34,36,32,36,},
        {2,2,4,4,4,4,4,6,6,8,10,10,8,6,10,10,6,6,6,16,12,10,12,14,12,12,12,20,18,14,16,18,14,16,16,16,18,18,18,18,16,20,20,24,26,26,24,22,20,26,24,24,24,24,26,26,22,26,28,32,28,36,34,30,26,26,28,36,30,30,32,32,32,34,32,38,36,36,38,38,40,40,38,36,34,34,40,38,38,38,}
    };
    int obsy[3][97]= { {2,2,2,2,4,4,4,4,6,6,6,6,6,8,8,8,8,8,10,10,10,10,10,12,12,12,12,12,14,14,14,14,16,16,16,16,14,18,18,18,18,18,20,20,20,20,20,22,22,22,22,22,24,24,24,26,26,26,26,26,26,28,28,28,28,28,30,30,30,30,30,30,30,2,32,32,32,32,32,32,34,34,34,34,34,36,36,36,36,36,36,38,38,38,38,38,20,},
        {38,24,2,10,2,6,18,34,0,12,26,32,20,2,6,16,22,34,2,8,16,32,36,0,10,18,28,34,4,14,28,38,4,10,24,32,20,2,12,18,26,34,0,4,10,14,28,6,12,16,26,34,2,16,28,0,8,14,18,30,36,0,10,18,32,38,2,10,16,20,24,30,34,20,4,8,12,18,30,38,0,10,16,26,34,0,4,8,14,24,36,2,6,16,22,30,36,},
        {40,34,6,18,4,12,26,38,6,18,30,40,24,4,10,18,32,38,6,14,20,34,40,6,12,26,32,36,8,18,34,40,6,20,28,38,24,8,14,20,32,36,2,6,12,26,34,10,14,24,30,36,8,18,32,4,10,16,26,34,38,2,16,30,36,40,4,12,18,22,26,32,38,22,6,10,16,28,32,40,4,12,18,30,36,2,6,10,18,28,38,4,10,20,28,36,38,}
    };
    int i, j, k;
//como el aberinto es mas grande que la pantalla , uso los valores ymin,ymax,xmin,xmax para mostrar en pantalla solo 7 bloques hacia cada lado del jugador
    int ymin, ymax, xmin, xmax;
    ymin=py-7;
    xmin=px-7;
    ymax=py+7;
    xmax=px+7;
//si por la posicion del jugador no se pueden mostrar todos los bloques que se deberia hacia uno de los lados, los bloques que no se puedan representar se mostraran en el lado opuesto
//manteniendose asi una pantalla cuadrada constante.
    if(xmax>40)
    {
        xmax=40;
        xmin=xmax-14;
    }
    if(ymax>40)
    {
        ymax=40;
        ymin=ymax-14;
    }
    if(ymin<0)
    {
        ymin=0;
        ymax=ymin+14;
    }
    if(xmin<0)
    {
        xmin=0;
        xmax=xmin+14;
    }
//el unico cambio que hay respecto a la funcion mapa ,apartir de aqui ,es que en esta funcion a�ado la posibilidad de que tome los valores de 3 y 4 para diubujar las monedas/fichas que hay que recoger y 5 para dibujar la puerta
    for(j=xmax; j>xmin-1; j--)
    {
        for(k=0; k<2; k++)
        {
            char fila[60];
            int f=0;
            for(i=ymin; i<ymax+1; i++)
            {
                int a=0;
                int i2;
                for(i2=0; i2<90; i2++)
                {
                    if((j==obsx[0][i2])&&(i>=obsx[1][i2])&&(i<=obsx[2][i2]))a=1;
                }
                for(i2=0; i2<97; i2++)
                {
                    if((i==obsy[0][i2])&&(j>=obsy[1][i2])&&(j<=obsy[2][i2]))a=1;
                }
                if((i==0)||(i==40)||(j==0)||(j==40))a=1;
                if((i==0)&&(j==39)) a=5;

                if((((i==1)&&(j==21))&&(m4==0))||(((i==19)&&(j==21))&&(m3==0))||(((i==33)&&(j==39))&&(m2==0))||(((i==39)&&(j==1))&&(m1==0)))
                {
                    if(k==0)a=3;
                    if(k==1)a=4;
                }
                if((j==px)&&(i==py)) a=2;
                if(a==0)fila[f]=(char)176,fila[f+1]=(char)176,fila[f+2]=(char)176,fila[f+3]=(char)176;
                if(a==1)fila[f]=(char)219,fila[f+1]=(char)219,fila[f+2]=(char)219,fila[f+3]=(char)219;
                if(a==2)fila[f]=' ',fila[f+1]=' ',fila[f+2]=' ',fila[f+3]=' ';
                if(a==3)fila[f]=' ',fila[f+1]=(char)220,fila[f+2]=(char)220,fila[f+3]=' ';
                if(a==4)fila[f]=' ',fila[f+1]=(char)223,fila[f+2]=(char)223,fila[f+3]=' ';
                if(a==5)fila[f]=(char)179,fila[f+1]=(char)176,fila[f+2]=(char)176,fila[f+3]=(char)176;
                f=f+4;
            }
            printf("%s", fila);
            if((j==xmax-2)&&(k==1))
            {
                if((m1+m2+m3+m4)==4) printf("   puedes abrir la puerta ,dirigete a la casilla de inicio");
                else
                {
                    if(m1+m2+m3+m4==3)printf("   falta una ficha para poder abrir la puerta" );
                    else printf("   faltan %i fichas para poder abrir la puerta", 4-m1-m2-m3-m4);
                }
            }
            printf("\n");
        }
    }
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
        imprime(pf);
        do
        {
            scanf("%i",&respuesta1);
        }
        while ((respuesta1!=1)&&(respuesta1!=2)&&(respuesta1!=3));
        if(respuesta1==2)
        {
        int res=0;
        pf = fopen("Proyecto/Estanteria.txt", "r");
        imprime(pf);
        provincia estanteria[17];
        pf = fopen("Proyecto/Matriz_Provincias.txt" , "r");
        for(int i=0;i<17;i++)fscanf(pf, " %[^;];%i\n",estanteria[i].nombre,&estanteria[i].devuelve);
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
            imprime(pf);
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
                    imprime(pf);
                    char numeropalabra[5]="0000";
                    scanf(" %s",numeropalabra);
                    c1=1000*(numeropalabra[0]-48)+100*(numeropalabra[1]-48)+10*(numeropalabra[2]-48)+(numeropalabra[3]-48);
                }
                while((c1!=1492)&&(c1!=1800));
                if(c1==1492)
                {
                    pf = fopen("Proyecto/Puerta Candado Abierto.txt", "r");
                    imprime(pf);
                }
            }
        }
        if(respuesta1 == 3)
        {
            pf = fopen("Proyecto/Mapa Espana.txt", "r");
            imprime(pf);
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
    imprime(pf);
    while ((respuesta!=1)&&(respuesta!=2)) scanf("%i", &respuesta);
    fclose(pf);
}
void oscuridad1(void )
{
    FILE *pf;
    pf=fopen("Proyecto/Oscuridad.txt" , "r");
    imprime(pf);
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
void imprime(FILE *pf)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    char foto;
    while(fscanf(pf, "%c",&foto) !=EOF )
    {
        if(foto=='�') delay(1);
        else printf("%c",foto);
    }
}
