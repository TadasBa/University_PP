#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//--------------------------------------------------------
void openDataFile(FILE **pointerToDataFile, char dataFileName[])
{
    /* FUNCTION FOR OPENING FILE */

    printf("\nEnter data file name: ");
    scanf("%s", dataFileName);
    *pointerToDataFile = fopen(dataFileName, "r");

    if(*pointerToDataFile == NULL)
    {
        printf("ERROR: Failed to open data file");
        exit(0);
    }
}
//--------------------------------------------------------
void constructList(FILE **pointerToDataFile, List **root)
{
    /* FUNCTION FOR CREATING LINKED LIST */

    int y;

    while(fscanf(*pointerToDataFile, "%d", &y) != EOF)
    {
        push(root, y);
    }
}

//--------------------------------------------------------
void push(List **root, int y)
{
    List* node = (List*)malloc(sizeof(List));

    if(node == NULL)
    {
        exit(0);
    }

    node->next = NULL;

    node->x = y;

    if(*root == NULL)
    {
        *root = node;
        return;
    }
    List* curr = *root;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
}
//--------------------------------------------------------
void printList(List *temp)
{
    /* FUNCTION FOR PRINTING LINKED LIST */

    if(temp == NULL)
    {
        return;
    }
    printf("%d -> ", temp->x);
    printList(temp->next);
}
//--------------------------------------------------------
void insertElement(List **root, int elementToInsert, int insertBefore)
{
    /* FUNCTION FOR INSERTING ELEMENT BEFORE SPECIFIED ELEMENT OF LINKED LIST */

    /* INSERTING ELEMENT */

    List *node = malloc(sizeof(List));
    if(node == NULL)
    {
        exit(1);
    }
    node->x = elementToInsert;
    node->next = *root;
    List *elem = *root;
    List *elem1;

    /* CHECKING IF THE ELEMENT IS FIRST ELEMENT OF LINKED LIST */

    if(elem->x != insertBefore)
    {
        while(elem->x != insertBefore)
        {
            elem1 = elem;
            elem = elem->next;
        }
        elem1->next = node;
        node->next = elem;
    }
    else
    {
        *root = node;
    }
}
//--------------------------------------------------------
void clearList(List **root)
{
    /* FUNCTION FOR DEALLOCATING LINKED LIST */

    List *elem = *root;

    while(elem != NULL)
    {
        List *temp = elem;
        elem = elem->next;
        free(temp);
    }
    *root = NULL;
}
//--------------------------------------------------------
void reverseList(List **root)
{
    /* FUNCTION FOR REVERSING THE ORDER OF LINKED LIST */

    List *prev = NULL;
    List *curr = *root;

    while(curr != NULL)
    {
        List *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}
//--------------------------------------------------------
