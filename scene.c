#include"arrays.h"
#include"linked_list.h"
#include"terminal.h"
#include"player.h"
#include"cars.h"
#include"scene.h"

VALUE* createValue()
{
    /* creates the value struct and initialises the values */
    VALUE *value = (VALUE*)malloc(sizeof(VALUE));
    value->p_value = NULL;
    value->c_value = NULL;
    return value;
}

VALUE* initValue(VALUE *value, PLAYER *player, CAR *car)
{
    /* fills the value struct with the relevant location data */
    value->p_value = player;
    value->c_value = car;
    return value;
}

LIST* addScene(LIST *scene_list, PLAYER *player, CAR *car)
{
    /* adds a node to the linked list using the value struct */
    VALUE *value = (VALUE*)malloc(sizeof(VALUE));
    value->p_value = NULL;
    value->c_value = NULL;

    value->p_value = player;
    value->c_value = car;
    insertFirst(scene_list, (void*) value);
    return scene_list;
}


void processInput(char input, PLAYER *player, CAR *car, ELEMENT **arr, \
                  int rows, int cols, LIST* scene_list)   
{
    /* instructions based on the input from the user */
    switch(input) 
    {
        case 'w': case 's': case 'a': case'd': 
            movePlayer(player, input, rows, cols);
            moveCar(car, arr);
            addScene(scene_list, player, car);
            break;
    }
}

void changeScene(PLAYER *player, CAR *car, ELEMENT **arr, int rows, int cols, \
                    LIST* scene_list) 
{
    /* takes input from the user and which is then processed */
    char input;

    disableBuffer();
    scanf(" %c", &input); 
    enableBuffer();
    
    arr[player->ypos][player->xpos].player = 0;
    processInput(input, player, car, arr, rows, cols, scene_list);
    arr[player->ypos][player->xpos].player = 1;
}
