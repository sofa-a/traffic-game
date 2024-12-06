#ifndef GAME_H
#define GAME_H

void checkStatus(ELEMENT**, int, int, int*, int*);
void printStatus(int);
void gameLoop(ELEMENT**, int, int);

#endif

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE !FALSE
