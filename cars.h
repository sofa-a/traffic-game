#ifndef CARS_H
#define CARS_H

typedef struct car {
    int xpos;
    int ypos;
    int direction;
}CAR;

CAR* createCar();
void findCarPos(ELEMENT**, int, int, CAR*);

void checkLeftRight(CAR*, ELEMENT**, int);
void checkUpDown(CAR*, ELEMENT**, int);
void moveCar(CAR*, ELEMENT**);

void freeCar(CAR*);

#endif

#include<stdio.h>
#include<stdlib.h>
