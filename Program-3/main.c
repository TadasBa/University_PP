/// NAME: Tadas Baltrūnas
/// Group: 5
/// PROGRAM NR: 3.11
//--------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
//--------------------------------------------------------

#define MAX_SIZE 256

FILE *pointerToDataFile, *pointerToOutputFile;

int main()
{
//--------------------------------------------------------
    char dataFileName[50], outputFileName[50];
    char *pointerToData;
    int *stringLenght;
    char data[MAX_SIZE];
//--------------------------------------------------------
    printf("Hello,\nThis program can read text from one file and remove all words\nwhich has same, first and one before last, letters\nafter that edited text is printed in new file\n\nINSTRUCTIONS: Enter currently existing file name from which you want to remove words\nthen enter name of file in which you want to print edited text\nWord to be edited should have at least 3 letters\n\n");
//--------------------------------------------------------
    openDataFile(dataFileName, &pointerToDataFile);

    createOutputFile(outputFileName, &pointerToOutputFile);

    printf("\nData file successfully opened and output file successfully created\n");
//--------------------------------------------------------
    while(fgets(data, MAX_SIZE, pointerToDataFile))
    {
        deleteWords(data, &stringLenght);

        allocateMemory(&pointerToData, &stringLenght);

        print(&pointerToData, data, &stringLenght);

        fputs(pointerToData, pointerToOutputFile);

        free(pointerToData);

        stringLenght = 0;
    }
//--------------------------------------------------------
    closeFiles(&pointerToDataFile, &pointerToOutputFile);

    printf("\nProgram work was successful, edited text is printed in file %s\n\nThank you for using this program, have a great day!\n", outputFileName);

    return 0;
}
