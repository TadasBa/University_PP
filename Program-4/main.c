/// NAME: Tadas Baltrūnas
/// Group: 5
/// PROGRAM NR: 4.01
//--------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_SIZE 255
//--------------------------------------------------------
void menu(int option, FILE *pointerToDataFile, char dataFileName[], int n, List *root, int fileCount)
{
    while(1)
    {
        printf("Enter your option here: ");

        /* CHECKING IF OPTION IS VALIDS*/

        while(1)
        {
            int  checkOption;
            char endLine;

            checkOption = scanf("%d%c", &option, &endLine);

            if(checkOption != 2 || endLine != '\n')
            {
                printf("\nERROR: Wrong input, please chose options from menu\n\nEnter your option here: ");
                scanf("%*[^\n]");
            }
            else
            {
                break;
            }
        }

        /* Menu */
///--------------------------------------------------------------------------------
        if(option == 1) /* USER CHOSE TO OPEN FILE */
        {
            if(fileCount > 0)
            {
                clearList(&root);
            }
            openDataFile(&pointerToDataFile, dataFileName);

            fileCount++;

            printf("\nData file successfully opened\n\n");
            break;
        }
///--------------------------------------------------------------------------------
        if(option == 2) /* USER CHOSE TO CREATE LINKED LIST */
        {
            /* READING ELEMENTS FROM FILE */

            if(fileCount == 0)
            {
                printf("\nERROR: Linked list can not be created, please open data file first\n\n");
            }
            else
            {
                constructList(&pointerToDataFile, &root);

                List* curr = root;

                while(curr != NULL)
                {
                    curr = curr->next;
                    n++;
                }
                printf("\nLinked list successfully created\n\n");
            }
            break;
        }
///--------------------------------------------------------------------------------
        if(option == 3) /* USER CHOSE TO PRINT LINKED LIST */
        {
            if(n == 0)
            {
                printf("\nThis is your linked list: NULL\n\n");
            }
            else
            {
                printf("\nThis is your linked list: ");
                printList(root);
                printf("NULL\n\n");
            }

            break;
        }
///--------------------------------------------------------------------------------
        if(option == 4) /* USER CHOSE TO INSERT ELEMENT IN SPECIFIED PLACE */
        {
            if(n == 0)
            {
                printf("\nERROR: Your linked list is empty and for this function at least one element is needed\n\n");
            }
            else
            {
                int  insertBefore;
                int  elementToInsert;

                printf("\nEnter element from list before which you want to insert your new element: ");

                /* CHECKING IF ELEMENT SPECIFIED TO INSERT BEFORE EXIST */

                List *temp = root;
                int found=0;

                while(1)
                {
                    scanf("%d", &insertBefore);

                    List *temp1 = root;

                    while(temp1 != NULL)
                    {
                        if(temp1->x == insertBefore)
                        {
                            found++;
                            break;
                        }
                        if(temp1->next == NULL)
                        {
                            printf("\nERROR: Linked list does not contain such element\n\nPlease try again: ");
                            temp1 = root;
                            break;
                        }
                        temp1 = temp1->next;
                    }
                    if(found > 0)
                    {
                        break;
                    }
                }

                printf("\nEnter element you want to insert: ");
                scanf("%d", &elementToInsert);

                insertElement(&root, elementToInsert, insertBefore);
                n++;
                printf("\nElement successfully inserted\n\n");
            }

            break;
        }
///--------------------------------------------------------------------------------
        if(option == 5) /* USER CHOSE TO CLEAR LINKED LIST */
        {
            if(n == 0)
            {
                printf("\nERROR: Your linked list is empty, nothing to clear\n\n");
            }
            else
            {
                clearList(&root);
                n=0;
                printf("\nYour linked list has been successfully cleared\n\n");
            }
            break;
        }
///--------------------------------------------------------------------------------
        if(option == 6) /* USER CHOSE TO REVERSE LINKED LIST */
        {
            if(n == 0)
            {
                printf("\nERROR: Your linked list is empty, nothing to reverse\n\n");
            }
            else
            {
                reverseList(&root);
                printf("\nThe order of your linked list has been successfully reversed\n\n");
            }
            break;
        }
///--------------------------------------------------------------------------------
        if(option == 7) /* USER CHOSE EXIT THE PROGRAM */
        {
            printf("\nProgram exited\n");
            exit(1);
        }

        else /* USER CHOSE NOT SPECIFIED OPTION */
        {
            printf("\nERROR: No such option on menu, please try again\n");
            break;
        }
    }
    menu(option, pointerToDataFile, dataFileName, n, root, fileCount);
}
//--------------------------------------------------------
int main()
{
//--------------------------------------------------------
    FILE  *pointerToDataFile = NULL;     // DATA FILE POINTER
    char  dataFileName[MAX_SIZE]; // DATA FILE NAME SPECIFIED BY THE USER
    int   option=0;                 // MENU OPTION
    int   n = 0;                  // NUMBER OF ELEMENTS IN FILE
    int   fileCount = 0;          // NUMBER OF FILES OPENED
    List  *root = NULL;           // FIRST ELEMENT OF LINKED LIST
//--------------------------------------------------------
    printf("Welcome,\n\nCurrently you are using a program written by Tadas Baltrunas\n");
    printf("This program is used to work with a linked list, below you can find functions menu\n\n");
    printf(".......................................................................\n");
    printf("MENU:\nEnter 1 to open data file\nEnter 2 to create linked list\nEnter 3 to print linked list\n");
    printf("Enter 4 to insert a new element is specific position of a linked list\n");
    printf("Enter 5 to clear your linked list\n");
    printf("Enter 6 to reverse the order of your linked list\nEnter 7 to exit the program\n");
    printf(".......................................................................\n\n");

    menu(option, pointerToDataFile, dataFileName, n, root, fileCount);

    return 0;
}

