#pragma once

typedef struct node {
    int key;
    struct node *previous;
    struct node *next;
} NodeT;

typedef struct dll {
    struct node *first;
    struct node *last;
    int size;
} DLL;

NodeT *createNode(int givenKey);

void insertFirst(DLL *list, int givenKey);

void printListForward(DLL list);

void printListBackwards(DLL list);

void insertLast(DLL *list, int givenKey);

NodeT *searchKey(DLL list, int givenKey);

void insertBefore(DLL *list, int beforeKey, int givenKey);

void insertAfter(DLL *list, int afterKey, int givenKey);

void deleteFirst(DLL *list);

void listSize(DLL *list);

void deleteLast(DLL *list);

void deleteKey(DLL *list, int givenKey);