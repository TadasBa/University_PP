#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>

typedef struct List
{
    int x;
    struct List* next;

} List;

void menu(int option, FILE *pointerToDataFile, char dataFileName[], int n, List *root, int fileCount);

void openDataFile(FILE **pointerToDataFile, char dataFileName[]);

void constructList(FILE **pointerToDataFile, List **root);

void printList(List *root);

void insertElement(List **root, int elementToInsert, int insertBefore);

void clearList(List **root);

void reverseList(List **root);

void push(List **root, int x);

#endif // HEADER_H_INCLUDED
