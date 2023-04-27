#include <stdio.h>
#include "double_linked_list.h"

int main() {
    DLL list;

    list.first = NULL;
    list.last = NULL;

    insertFirst(&list, 5);
    insertFirst(&list, 4);
    insertFirst(&list, 3);
    insertFirst(&list, 2);
    insertFirst(&list, 1);

    insertLast(&list, 6);
    insertLast(&list, 7);
    insertLast(&list, 8);
    insertLast(&list, 9);
    insertLast(&list, 10);

    insertBefore(&list, 1, 11);
    insertBefore(&list, 5, 12);
    insertBefore(&list, 10, 13);

    insertAfter(&list, 11, 14);
    insertAfter(&list, 5, 15);
    insertAfter(&list, 10, 16);

//    printf("%d %d\n", list.first->key, list.last->key);

    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

    deleteFirst(&list);

    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

    deleteLast(&list);

    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

    deleteKey(&list, 14);

    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

    deleteKey(&list, 10);

    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

    deleteKey(&list, 5);
    printListForward(list);
    printf("\n");
    printListBackwards(list);
    printf("\n");

//    deleteKey(&list,14);
//
//    printListForward(list);
//    printf("\n");
//    printListBackwards(list);
//    printf("\n");
//
//    deleteKey(&list,10);
//
//    printListForward(list);
//    printf("\n");
//    printListBackwards(list);
//    printf("\n");
//
//    deleteKey(&list,5);
//
//    printListForward(list);
//    printf("\n");
//    printListBackwards(list);
//    printf("\n");



    //listSize(&list);

//    printf("\n%p", searchKey(list,1));
//    printf("\n%p", searchKey(list,5));
//    printf("\n%p", searchKey(list,10));
//    printf("\n%p", searchKey(list,11));

    return 0;
}
