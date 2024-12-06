#include"arrays.h"
#include"display.h"
#include"linked_list.h"
#include"cars.h"
#include"player.h"
#include"scene.h"
#include"game.h"

void checkStatus(ELEMENT **arr, int rows, int cols, int* running, int* status) 
{
    /* function for checking for collisions between player and car or player
       and goal */
    int i, j;    
    for (i=0; i<rows; i++) 
    {
        for (j=0; j<cols; j++) 
        {
        /* if the next position of the player is the car, status is set to the 
           lose condition (0) and the game is ended by setting running to 
           FALSE */
            if (arr[i][j].car == 1 && arr[i][j].player == 1)
            {
                *running = FALSE;    
                *status = 0;
            }
        /* if the position of the player is the goal, status is set to the win
           condition (1) and the game is ended by setting running to FALSE*/ 
            else if (arr[i][j].player == 1 && arr[i][j].tile == 2)
            {
                *running = FALSE;
                *status = 1;
            }
        }
    }
}

void printStatus(int status) 
{
    /* winning condition results in 'you win' being printed */
    if(status == 1) 
    {
        printf("\nyou win\n");
    }
    else  
    /* otherwise you lost and 'you lose' is printed */
    {
        printf("\nyou lose\n");
    }
}

void gameLoop(ELEMENT **arr, int rows, int cols) 
{           
    /* function for main game loop of the game */

    int running = TRUE;
    int status;
    PLAYER *player;
    CAR *car;
    LIST *scene_list = createLinkedList();

    /* initialise player and car + find their position*/
    player = createPlayer();
    car = createCar();
    findPlayerPos(arr, rows, cols, player);
    findCarPos(arr, rows, cols, car);

    printMap(arr, rows, cols, car->direction);

    while (running != FALSE)
    {
        /* updates position of player and car */
        changeScene(player, car, arr, rows, cols, scene_list);
        /* collision check*/
        checkStatus(arr, rows, cols, &running, &status);

        printMap(arr, rows, cols, car->direction);
    }
    printStatus(status);
    /* free functions */
    freePlayer(player);
    freeCar(car);
    freeArray(arr, rows);
    freeLinkedList(scene_list, &freeNode);
}
