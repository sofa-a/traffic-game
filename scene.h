#ifndef SCENE_H
#define SCENE_H

typedef struct value{
    PLAYER *p_value;
    CAR *c_value;
}VALUE;

VALUE* createValue();
VALUE* initValue(VALUE*, PLAYER*, CAR*);
LIST* addScene(LIST*, PLAYER*, CAR*);
void processInput(char, PLAYER*, CAR*, ELEMENT**, int, int, LIST*);
void changeScene(PLAYER*, CAR*, ELEMENT**, int, int, LIST*);

#endif

#include<stdio.h>
#include<stdlib.h>

