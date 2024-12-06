#ifndef PLAYER_H
#define PLAYER_H

typedef struct player {
    int xpos;
    int ypos;
}PLAYER;


PLAYER* createPlayer();
void findPlayerPos(ELEMENT**, int, int, PLAYER*);
void movePlayer(PLAYER*, int, int, int);
void freePlayer(PLAYER*);

#endif

#include<stdio.h>
#include<stdlib.h>

