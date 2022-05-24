#ifndef JUEGOUNO_H_INCLUDED
#define JUEGOUNO_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int candado(void);
int laberinto(void);
//void grafica(char imagen[50][50]);
void casa(void );
void oscuridad1(void );
int habitacion(void );
void imprime(FILE *pf,int);
int ice_cave(void);
float carga(void);
void highscore(char nick[],int diff,float score);
int enigmas(void);

#endif // JUEGOUNO_H_INCLUDED
