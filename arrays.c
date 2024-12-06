#include"arrays.h"

ELEMENT createElement()
{
    /* creates the element and initialises the its values */
    ELEMENT element;
    element.player = 0;
    element.car = 0;
    element.tile = 0;
    return element;
}

ELEMENT** createArray(int rows, int cols) 
{
    /* function for allocating memory for the arrays */
    int i, j;
    /* memory first allocated to the row elements */
    ELEMENT** arr = (ELEMENT**)malloc(rows*sizeof(ELEMENT*));
    
    for(i=0; i<rows; i++) 
    {
        /* memory then allocated to the col elements */
        arr[i] = (ELEMENT*)malloc(cols*sizeof(ELEMENT));
        for(j=0; j<cols; j++) 
        {
            /* for each element in the array, the element struct there
               is initialised */
            arr[i][j] = createElement();
        }
    }
    return arr;
}

void initElement(ELEMENT **arr, int i, int j, int value)
{
    /* function for giving value to each of the elements based on the file 
       read into the program*/
    switch(value)
    {  
        case 1:
            /* road */
            arr[i][j].tile = 1;
            break;
        case 2:
            /* car with road as well */
            arr[i][j].car = 1;
            arr[i][j].tile = 1;
            break;
        case 3:
            /* player */
            arr[i][j].player = 1;
            break;
        case 4:
            /* goal */
            arr[i][j].tile = 2;
            break;
    }
}

void initArray(ELEMENT **arr, FILE *file, int rows, int cols) 
{
    /* function for initialising the values within the array */
    int i, j, value;
    for(i=0; i<rows; i++) 
    {
        for(j=0; j<cols; j++) 
        {
            /* reads in the value from the file and stores into value */
            fscanf(file, "%d", &value);
            /* for each element in the array, element struct is given the
               appropriate values */
            initElement(arr, i, j, value);    
        }
    }
} 

void freeElement(ELEMENT* element) 
{
    /* function for freeing the struct elements*/
    element->player = 0;
    element->car = 0;
    element->tile = 0;
    free(element);
}

void freeArray(ELEMENT** arr, int rows) 
{
    /* frees the memory used up by the arrays */
    int i;
    for(i=0; i<rows; i++) 
    {
        /* the arrays within the 2D array are first freed */
        freeElement(arr[i]);
    }
    free(arr);
}
