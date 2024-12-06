#include"linked_list.h"

LIST* createLinkedList() {
    /* creates the linked list struct */
    LIST* list = (LIST*)malloc(sizeof(LIST));
    list->head = NULL;
    return list;
}

void insertFirst(LIST *list, void *new_val) {
    /* inserts a node at the start of the linked list*/
    
    /* initialise elements */    
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->value = new_val;
    new_node->next = NULL;
   
    /* case for if the linked list is empty */ 
    if (list->head == NULL) {
        list->head = new_node;
    }
    /* case for all other situtations*/
    else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void insertLast(LIST *list, void *new_val) {
    /* inserts a node at the end of the linked list*/
    
    /* initialise elements */    
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    NODE *curr = list->head;
    new_node->value = new_val;
    new_node->next = NULL;

    /* case for if the linked list is empty */ 
    if (list->head == NULL) {
        list->head = new_node;
    }
    /* case for all other situtations*/
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }

}

void* removeFirst(LIST *list) {
    /* removes a node at the start of the linked list*/
    
    /* initialise elements */    
    NODE *curr = list->head;
    void *rem_val;
    
    /* case for if the linked list is empty */ 
    if (curr == NULL) {
        rem_val = NULL;
    }
    /* case for all other situtations*/
    else {
        rem_val = curr->value;
        list->head = curr->next;
        /* free curr value */
        free(curr->value);

        /* point curr value and next pointers to NULL */
        curr->value = NULL;
        curr->next = NULL;

        /* free curr */
        /*free(curr);*/
    }
    return rem_val;
}


void* removeLast(LIST *list) {
    /* removes a node at the end of the linked list*/
    
    /* initialise elements */    
    NODE *curr = list->head;
    NODE *prev = NULL;
    void *rem_val;
    
    /* case for if the linked list is empty */ 
    if (list->head == NULL) {
        rem_val = NULL;
    }
    else {
        /* case for if there's only one element in the linked list*/
        if (curr->next == NULL) {
            list->head = NULL;
        }
        /* case for all other situtations*/
        else {
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;

        }
        /* free the node and its value */
        rem_val = curr->value;
        free(curr->value);
        curr->value = NULL;
        curr->next = NULL;
        free(curr);
    }
    return rem_val;
}

void printData(void *value) {
    /* helper function for printList, casts (int*) in order to print the 
        element */
    int *num = (int*)value;
    printf("integer is --> %d\n", *num);
}

void printList(LIST *list, FP fun) {
    /* prints out the values within the nodes of the linked list */
    NODE *curr = list->head;
    while(curr) {
        (*fun)(curr->value);
        curr = curr->next;
    }
}

void freeNode(void *value) {
    /* helper method for the freeLinkedList function */
    free(value);
}

void freeLinkedList(LIST *list, FP fun) {
    /* frees the linked list struct */
    
    /* initialise elements */    
    NODE *curr = list->head;
    NODE *temp;
    while (curr) {
        /* store next node in the linked list */
        temp = curr->next;

        /* free the node and its value */
        (*fun)(curr->value);
        curr->value = NULL;
        curr->next = NULL;
        free(curr);
    
        /* get the next node */
        curr = temp;
    }
    free(list);
}

