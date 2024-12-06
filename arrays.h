#include<stdio.h>
#include<stdlib.h>

#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct element {
    int player;
    int car;
    int tile;
}ELEMENT;

ELEMENT createElement();
ELEMENT** createArray(int, int);
void initElement(ELEMENT**, int, int, int);
void initArray(ELEMENT**, FILE*, int, int);
void freeElement(ELEMENT*);
void freeArray(ELEMENT**, int);

#endif
