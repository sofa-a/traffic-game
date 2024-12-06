#include"arrays.h"
#include"player.h"

PLAYER* createPlayer() 
{
    /* creates the player struct*/
    PLAYER *player = (PLAYER*)malloc(sizeof(PLAYER));
    player->xpos = 0;
    player->ypos = 0;
    return player;
}

void findPlayerPos(ELEMENT **arr, int rows, int cols, PLAYER *player)
{
    /* finds the player in the array that was created and updates the players'
       position based on that */
    int i, j;
    for (i=0; i<rows; i++) 
    {
        for (j=0; j<cols; j++) 
        {
            if (arr[i][j].player == 1)
            {
                player->xpos = j;
                player->ypos = i;
            }
        }
    }
}

void movePlayer(PLAYER *player, int input, int rows, int cols)
{
    /* moves player based on the input given by the user + boundary checks*/
    switch(input)
    {
        case 'w':
            if (player->ypos > 0) 
            {
                player->ypos -= 1;
            }
            break;
        case 's':
            if (player->ypos < (rows-1)) 
            {
                player->ypos += 1;
            }
            break;
        case 'a':
            if (player->xpos > 0) 
            {
                player->xpos -= 1;
            }
            break;
        case 'd':
            if (player->xpos < (cols-1)) 
            {
                player->xpos += 1;
            }
            break;
    }
}

void freePlayer(PLAYER* player) 
{
    /* frees the player struct*/
    player->xpos = 0;
    player->ypos = 0;
    free(player);
}
