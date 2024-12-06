#define FALSE 0
#define TRUE !FALSE

#include<stdlib.h>
#include<stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct node {
    void *value;
    struct node *next;
}NODE;

typedef struct list {
    NODE *head;
}LIST;

typedef void (*FP) (void*);


LIST* createLinkedList();
void insertFirst(LIST*, void*);
void insertLast(LIST*, void*);
void* removeFirst(LIST*);
void* removeLast(LIST*);
void printData(void*);
void printList(LIST*, FP);
void freeNode(void*);
void freeLinkedList(LIST*, FP);

#endif
