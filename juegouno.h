#ifndef JUEGOUNO_H_INCLUDED
#define JUEGOUNO_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//#include<conio.h>
//void posicion(int , int );
//void mapa(int , int);
void candado(void);
void laberinto(void);
void grafica(char imagen[50][50]);
void casa(void );
void oscuridad1(void );
void habitacion(void );
void imprime(FILE *pf,int);
void ice_cave(void);
void carga(void);

#endif // JUEGOUNO_H_INCLUDED
