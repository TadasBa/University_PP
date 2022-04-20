/// NAME: Tadas Baltrūnas
/// Group: 5
/// PROGRAM NR: 2.2
//--------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------
int sizeOfArray(int *n)
{
    /* GETTING THE NUMBER OF ELEMENTS USER IS GOING TO ENTER */

    while(1)
    {

        int var;
        char endline;

        printf("Please enter the size of your array: ");
        var = scanf("%lld%c", &n, &endline);

        if(var != 2 || endline != '\n')
        {
            printf("\nERROR: Input is not acceptable, please try again: \n\n");
            scanf("%*[^\n]");
        }
        else
        {
            break;
        }
    }
    return n;
}
//--------------------------------------------------------
void arrayElements(int N, int array[], int elementsOcurance[])
{
    /* SAVING NUMBERS USER HAS ENTERED */

    int var;
    char endline;

    for(int i=0; i<N; i++)
    {
        printf("\n-> Please enter number %d of your array: ", i + 1);
        var = scanf("%d%c", &array[i], &endline);

        if(var != 2 || endline != '\n' && endline != ' ')
        {

            printf("\nERROR: Input is not acceptable, please try again: \n");
            scanf("%*[^\n]");
            i--;
        }
        elementsOcurance[i] = -1;
    }
}
//--------------------------------------------------------
void mostReapetedElement(int N, int array[], int elementsOcurance[], int mostTimesReapetedNumber, int times)
{
    /* FINDING HOW MANY TIMES EACH ELEMENT HAS BEEN REAPED AND THEN FINDING ELEMENT WHICH WAS REAPETED THE MOST */

    int count; // integer to temporary store the value of how many times each entered element has been reapeted

    for(int i=0; i<N; i++)
    {
        count = 1;
        for(int j=i+1; j<N; j++)
        {
            if(array[i] == array[j])
            {
                elementsOcurance[j] = 0;
                count++;
            }
        }
        if(elementsOcurance[i] != 0)
        {
            elementsOcurance[i] = count;
        }
    }
    for(int i=0; i<N; i++)
    {
        if(elementsOcurance[i] != 0)
        {
            printf("\nElement %d ocured in your array %d times \n", array[i], elementsOcurance[i]);
        }
    }

    times = elementsOcurance[0];
    mostTimesReapetedNumber = array[0];

    for(int i=0; i<N; i++)
    {
        if(elementsOcurance[i] > times)
        {
            times = elementsOcurance[i];
            mostTimesReapetedNumber = array[i];
        }
    }

    int check = 0; // integer to check if where is one most times reapeted number

    for(int i=0; i<N; i++)
    {
        if(times == elementsOcurance[i])
        {
            check++;
        }
    }
    if(check == 1)
    {
        printf("\nMost times reaped number is: %d", mostTimesReapetedNumber);
    }
    else
    {
        printf("\nThere isn't one number which was reaped most times");
    }
}
//--------------------------------------------------------
void printArray(int N, int array[], int elementsOcurance[])
{
    /* PRINTING ALL NUMBER USER HAS ENTERED */

    printf("This is your array: ");

    for(int i=0; i<N; i++)
    {
        printf("%d ", *(array+i));
    }

}
//--------------------------------------------------------
int main()
{
    int N; // integer defining how much numbers will be entered
    int n;

    int mostTimesReapetedNumber; // integer which in which will be saved most times reapeted number value
    int times; // integer in which will be saved value of how many times most times reapeted element occured

    printf(" Hello, thanks for using my program\n This program can create an array and find most times reapeted number if there is one\n You can enter any whole decimal number\n You can not enter any characters or letters, if you do so program will warn you\n");

    printf("------------------------------------\n");

    N = sizeOfArray(&n);

    long long array[N]; // the array where entered numbers will be saved
    long long elementsOcurance[N]; // array where will be saved occurance of entered elements

    printf("------------------------------------\n");

    printf("Your array is going to have %d numbers\n", N);

    printf("------------------------------------\n");

    arrayElements(N, array, elementsOcurance);

    printf("\n------------------------------------\n");

    printArray(N, array, elementsOcurance);

    printf("\n------------------------------------\n");

    mostReapetedElement(N, array, elementsOcurance, mostTimesReapetedNumber, times);

    printf("\n");
    return 0;
}

/*
Ataskaita: Rašiau 2 programos 2 užduotį.
Man reikėjo surasti dažniausiai pasikartojantį skaičių iš naudotojo sukurto masyvo.
Programa buvo suprantama ir įdomi. Naudojau daug funkcijų padidinti kodo skaitomumą.
Validacija pavyko padaryti geriau nei pirmoje programoje.
Didžiausias sunkumas buvo sugalvoti, kaip surasti dažniausiai pasikartojantį skaičių.
Programos rašymui prireikė apie 3 valandų.
*/
