#include"arrays.h"
#include"cars.h"

CAR* createCar() 
{
    /* creates the car struct and initialises its values */
    CAR *car = (CAR*)malloc(sizeof(CAR));
    car->xpos = 0;
    car->ypos = 0;
    car->direction = 0;
    return car;
}

void findCarPos(ELEMENT **arr, int rows, int cols, CAR *car) 
{
    /* locates the cars' position and updates the cars' location + direction*/
    int i, j;
    for (i=0; i<rows; i++) 
    {
        for (j=0; j<rows; j++) 
        {
            if (arr[i][j].car == 1) 
            {
                car->ypos = i;
                car->xpos = j;
                car->direction = 1;
            }
        }
    }  
}

void checkLeftRight(CAR *car, ELEMENT **arr, int num)
{
    /* checking for the road and based on where the road is, the cars' 
        position and direction is changed */
    if (arr[car->ypos][car->xpos+num].tile == 1) 
    {
        car->xpos += num;
    }
    else if (arr[car->ypos+1][car->xpos].tile == 1)  
    {
        car->direction = 4;
        car->ypos += 1;
    }
    else if (arr[car->ypos-1][car->xpos].tile == 1)  
    {
        car->direction = 3;
        car->ypos -= 1;
    }
    else 
    {
        car->xpos += num;
    }
}

void checkUpDown(CAR *car, ELEMENT **arr, int num)
{
    /* checking for the road and based on where the road is, the cars' 
        position and direction is changed */
    if (arr[car->ypos+num][car->xpos].tile == 1) 
    {
        car->ypos += num;
    }
    else if (arr[car->ypos][car->xpos+1].tile == 1)  
    {
        car->direction = 1;
        car->xpos += 1;
    }
    else if (arr[car->ypos][car->xpos-1].tile == 1)  
    {
        car->direction = 2;
        car->xpos -= 1;
    }
    else 
    {
        car->ypos += num;
    }
}

void moveCar(CAR *car, ELEMENT **arr) 
{
    /* calls the necessary functions to update the cars position + updates 
        the cars' position in the array */

    /* remove car*/
    arr[car->ypos][car->xpos].car = 0;
    switch(car->direction) 
    {
        case 1:
            /* positive 1 for right*/
            checkLeftRight(car, arr, 1);
            break;
        case 2:
            /* negative 1 for right*/
            checkLeftRight(car, arr, -1);
            break;
        case 3:
            /* negative 1 for up*/
            checkUpDown(car, arr, -1);
            break;
        case 4:
            /* positive 1 for down*/
            checkUpDown(car, arr, 1);
            break;
    }
    /* add car*/
    arr[car->ypos][car->xpos].car = 1;
}

void freeCar(CAR* car) 
{
    /* frees the car struct */
    car->xpos = 0;
    car->ypos = 0;
    car->direction = 0;
    free(car);
} 
    
