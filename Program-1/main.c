#include <stdio.h>
#include <stdlib.h>

int main()
{
    // kintamieji reikalingi atlikti veiksmams su skaiciu seka
    int numbers=1;      // kintamasis kuriame issaugoma informacija kiek nariu turi skaiciu seka
    int smallestNumber; // kintamasis kuriame issaugoma informacija koks yra maziausias sekos skaicius
    int biggestNumber;  // kintamasis kuriame issaugoma informacija koks yra maziausias sekos skaicius
    int newNumber;      // kintamasis kuriame issaugoma naujai ivesto skaiciaus reiksme

    // kintamieji reikalingi programos validavimui
    int arSkaicius1;
    int arSkaicius2;
    char ch1;
    char ch2;

    printf("pirmas skaicius: ");
    arSkaicius1 = scanf("%d%c", &smallestNumber, &ch1);
    biggestNumber = smallestNumber;

    if(smallestNumber>0 && arSkaicius1==2 && ch1=='\n')
    {
        for(int i=0; i<=numbers; i++)
        {
            printf("sekantis skaicius: ");
            arSkaicius2 = scanf("%d%c", &newNumber, &ch2);

            if(newNumber>0 && arSkaicius2==2 && ch2=='\n')
            {
                if (newNumber<smallestNumber)
                {
                    smallestNumber=newNumber;
                }
                if(newNumber>biggestNumber)
                {
                    biggestNumber=newNumber;
                }
                if(biggestNumber>=(smallestNumber*2) && arSkaicius2==2)
                {
                    numbers++;
                    break;
                }
                numbers++;
            }
            else
            {
                printf("Please enter only positive, whole integer!\n");
                i--;
                continue;
            }
        }
        printf("------------------------------------\n");
        printf("Maziausias sios sekos skaicius yra: %d\n", smallestNumber);
        printf("Didziausias sios sekos skaicius yra: %d\n", biggestNumber);
        printf("Sekos nariu skaicius yra: %d\n", numbers);
        printf("------------------------------------\n");
    }
    else
    {
        printf("Please enter only positive, whole integer!\n");
    }

    return 0;
}

///ataskaita:
/*
Sveiki, atlikin??jau 4 u??duot??.
U??duotis buvo tikrai suprantama ir ne per daug komplikuota,
ta??iau teko praleisti prie jos gana nema??ai laiko,
ra??ant program?? sunkiausia asmeni??kai buvo nepasiklysti tarp if s??lyg?? ir teisingai atlikti validavim??
. Iki galo para??yti program?? manau pritr??ko bazini?? ??g??d??i?? ir informacijos/konsultacijos
k?? daryti u??strigus tam tikrose vietose stygius.
*/
