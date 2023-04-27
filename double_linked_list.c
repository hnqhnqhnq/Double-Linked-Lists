#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

NodeT *createNode(int givenKey) {
    NodeT *node = malloc(sizeof(NodeT));

    if (node == NULL) {
        printf("Couldn't allocate memory!");
        return NULL;
    }

    node->key = givenKey;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void insertFirst(DLL *list, int givenKey) {
    NodeT *node = createNode(givenKey);

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    node->next = list->first;
    list->first->previous = node;
    list->first = node;
}

void printListForward(DLL list) {
    NodeT *current = list.first;

    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
}

void printListBackwards(DLL list) {
    NodeT *current = list.last;

    while (current != NULL) {
        printf("%d ", current->key);
        current = current->previous;
    }
}

void insertLast(DLL *list, int givenKey) {
    NodeT *node = createNode(givenKey);

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    list->last->next = node;
    node->previous = list->last;
    list->last = node;
}

NodeT *searchKey(DLL list, int givenKey) {
    NodeT *current = list.first;

    if (list.first == NULL) {
        return NULL;
    }

    while (current != NULL) {
        if (givenKey == current->key) {
            return current;
        }

        current = current->next;
    }
}

void insertBefore(DLL *list, int beforeKey, int givenKey) {
    NodeT *node = createNode(givenKey);
    NodeT *current = list->first;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    if (beforeKey == list->first->key) {
        node->next = list->first;
        list->first->previous = node;
        list->first = node;
        return;
    }

    while (current != NULL) {
        if (current->next->key == beforeKey) {
            node->next = current->next;
            node->previous = current;
            current->next->previous = node;
            current->next = node;
            break;
        }

        current = current->next;
    }
}

void insertAfter(DLL *list, int afterKey, int givenKey) {
    NodeT *node = createNode(givenKey);
    NodeT *current = list->first;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    if (afterKey == list->last->key) {
        node->previous = list->last;
        list->last->next = node;
        list->last = node;
        return;
    }

    while (current != NULL) {
        if (afterKey == current->key) {
            node->next = current->next;
            node->previous = current;
            current->next->previous = node;
            current->next = node;
            break;
        }

        current = current->next;
    }
}

void deleteFirst(DLL *list) {
    NodeT *current = list->first;

    if (list->first == NULL) {
        printf("\nList is already empty!\n");
        return;
    }

    list->first = list->first->next;

    if (list->first == NULL) {
        list->last = NULL;
        return;
    } else {
        list->first->previous = NULL;
    }

    free(current);
}

void listSize(DLL *list) {
    list->size = 0;

    NodeT *current = list->first;

    while (current != NULL) {
        list->size++;
        current = current->next;
    }
}

void deleteLast(DLL *list) {
    NodeT *current = list->last;

    if (list->first == NULL) {
        printf("\nList is already empty!\n");
        return;
    }

    list->last = list->last->previous;

    if (list->last == NULL) {
        list->first = NULL;
    } else {
        list->last->next = NULL;
    }

    free(current);
}

void deleteKey(DLL *list, int givenKey) {
    if (list->first == NULL) {
        printf("list is already empty.\n");
        return;
    }

    if (list->first->key == givenKey) {
        deleteFirst(list);
        return;
    }

    if (list->last->key == givenKey) {
        deleteLast(list);
        return;
    }

    NodeT *current = list->first;

    while (current != NULL) {
        if (current->next == NULL)
            break;
        if (current->next->key == givenKey) {
            NodeT *aux = current->next;
            current->next = current->next->next;
            current->next->previous = current;
            free(aux);
            return;
        }
        current = current->next;
    }
    printf("the key you want to delete does not exist.\n");
    free(current);
}