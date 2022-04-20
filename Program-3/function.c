//--------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
//--------------------------------------------------------
#define MAX_SIZE 255

//--------------------------------------------------------
void openDataFile(char dataFileName[], FILE **pointerToDataFile)
{
    /* GETTING DATA FILE NAME FROM USER */

    printf("Enter your data file name: ");

    gets(dataFileName);

    printf("\nYou will be reading data from file %s\n", dataFileName);

    /* OPENING DATA FILE FOR READING */

    * pointerToDataFile = fopen(dataFileName, "r");

    if(*pointerToDataFile == NULL)
    {
        printf("\nFAILED TO OPEN DATA FILE\n");

        exit(1);
    }
}
//--------------------------------------------------------
void createOutputFile(char outputFileName[], FILE **pointerToOutputFile)
{
    /* GETTING OUTPUT FILE NAME FROM USER */

    printf("\nEnter your output file name: ");

    gets(outputFileName);

    printf("\nYou will be printing data to file %s\n", outputFileName);

    /* CREATING FILE FOR OUTPUT */

    * pointerToOutputFile = fopen(outputFileName, "w");

    if(*pointerToOutputFile == NULL)
    {
        printf("FAILED TO CREATE OUTPUT FILE\n");

        exit(0);
    }
}
//--------------------------------------------------------
void deleteWords(char data[], int *stringLenght)
{
    /* READING DATA STORED IN MEMORY AND REMOVING WORDS WHICH HAS SAME FIRST AND ONE BEFORE LAST LETTERS */

    *stringLenght = strlen(data);

    int wordLenght = 0;
    int firstLetter;
    int oneBeforeLastLetter;

    for(int i=0; i<*stringLenght; i++)
    {
        if(i == 255)
        {
            break;
        }
        if(data[i] != ' ' && data[i] != '\n') // READIND DATA TILL WORD ENDS
        {
            wordLenght++;
        }
        else if(wordLenght > 1) // CHECKING IF WORD HAS AT LEAST 2 LETTERS
        {
            firstLetter = i - wordLenght;
            oneBeforeLastLetter = i-2;

            if(data[firstLetter] == data[oneBeforeLastLetter]) // CHECKING IF FIRST AND ONE BEFORE LAST LETTERS MACH
            {
                *stringLenght = *stringLenght - wordLenght;

                for(int r=i-wordLenght; r<*stringLenght; r++) // REMOVING WORD
                {
                    data[r] = data[r+wordLenght+1];
                }
                i -= wordLenght; // PLACING CURSOR IN RIGHT POSITION
                i--;
                wordLenght = 0; // GETTING READY TO READ NEXT WORD
            }
            else
            {
                wordLenght=0; // IF FIRST AND ONE BEFORE LAST LETTERS DOES NOT MACH MOVING TO READ OTHER WORD
            }
        }

    }
}
//--------------------------------------------------------
void allocateMemory(char **pointerToData, int *stringLenght)
{
    /* ALLOCATING SPACE IN MEMORY TO STORE DATA FROM ARRAY */

    *pointerToData = (char*)calloc(*stringLenght,sizeof(char));

    if(*pointerToData == NULL)
    {
        printf("\nFAILED TO ALLOCATE MEMORY\n");
        exit(0);
    }
}
//--------------------------------------------------------
void print(char **pointerToData, char data[], int *stringLenght)
{
    /* SAVING DATA FROM ARRAY TO MEMORY */

    for(int i=0; i<*stringLenght; i++)
    {
        (*pointerToData)[i] = data[i];
    }

}
//--------------------------------------------------------
void closeFiles(FILE **pointerToDataFile, FILE **pointerToOutputFile)
{
    /* CLOSING FILES */

    fclose(*pointerToDataFile);
    fclose(*pointerToOutputFile);
}
