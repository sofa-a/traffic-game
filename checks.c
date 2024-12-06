#include"checks.h"
#include"arrays.h"
#include"game.h"

void scanArraySize(FILE *file, int *rows, int *cols)
{
    /* function for getting the array size from the top file passed in */
    if (file == NULL)
    {
        perror("file cannot be opened");
    }
    else
    {
        fscanf(file, "%d %d", rows, cols);
    }
}

void processArgs(int argc, char *arg1) 
{ 
    /* function for taking in arguments from the main function and using them
       to start the gameLoop in game.c */
    FILE *file;
    ELEMENT **arr;
    int rows, cols;
    if(argc == 2) 
    {
        file = fopen(arg1, "r");
        scanArraySize(file, &rows, &cols);

        /* if arguments entered by the user pass the checking stage
           in the function check_range, the game loop is initiated */
        
        /* initialise the game */
        arr = createArray(rows, cols);
        initArray(arr, file, rows, cols);
        fclose(file);

        /* start playing the actual game */
        gameLoop(arr, rows, cols);
    }   
    else    
    {
        printf("Incorrect amount of arguments has been entered\n");
    }
}            

int main(int argc, char*argv[])
{
    processArgs(argc, argv[1]);
    return 0;
}
