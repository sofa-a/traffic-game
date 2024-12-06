#include"arrays.h"
#include"display.h"

void printMap(ELEMENT **arr, int rows, int cols, int dir) 
{
    /* function for printing the array */
    int i, j;

    system("clear");

    starCols(cols);    
    for(i=0; i<rows; i++) 
    {
        printf("*"); /* print * on right of game */
        for(j=0; j<cols; j++) 
        {
            selectOutput(arr, i, j, dir);
        } 
        printf("*\n"); /* print * on left of game */
    }
    starCols(cols);    

    printf("Press w to move up\n");
    printf("Press s to move down\n");
    printf("Press a to move left\n");
    printf("Press d to move right\n");
}

void starCols(int cols) 
{ 
    /* helper function for printMap to print the * rows */
    int i;
    for(i=0; i<(cols+2); i++) 
    {
        printf("*");
    } 
    printf("\n");
}

void displayCarDirection(int dir) {
    /* prints character based on the number passed into the function (car 
       direction)*/
    switch(dir)
    {
        case 1:
            printf(">");
            break;
        case 2:
            printf("<");
            break;
        case 3:
            printf("^");
            break;
        case 4:
            printf("V");
            break;
    }
}

void selectOutput(ELEMENT **arr, int i, int j, int dir) 
{
    /* helper function for printMap to select the appropriate character
       based on the value in the array */
    switch(arr[i][j].tile) 
    {
        case 0:
        /* case for printing the empty space. If player found on tile == 0
            the player is printed instead of empty space. */
            if (arr[i][j].player == 1)
            {
                printf("P");
            }
            else {
                printf(" ");
            }
            break;
        case 1:
        /* case for printing the road. If player or car found on tile == 1
            the car or player is printed instead of the road. */
            if (arr[i][j].player == 1)
            {
                printf("P");
            }
            else if (arr[i][j].car == 1) 
            {
                displayCarDirection(dir); 
            }
            else 
            { 
                printf(".");
            }
            break;
        case 2:
        /* case for printing the goal */
            printf("G");
            break;
        default:
            printf(" ");
            break;
    }
}
