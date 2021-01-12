//Tried not to use switch but there's if :(

#include <stdio.h>
#include <stdlib.h>

char vowelsArray[] = "aeiouAEIOU";


int checkIfVowel(char letter)
{
        for(int index = 0; vowelsArray[index]; index++ )
        {
            if(letter == vowelsArray[index])
            {
                return 1;
            }
        }

        return 0;
}


int countNumberOfVowels(char* inputString, int* positionsOfVowels)
{
    int numberOfVowels = 0;

    for(int index = 0; inputString[index]; index++)
    {
        if( checkIfVowel( inputString[index] ) )
        {
            positionsOfVowels[numberOfVowels] = index+1;
            numberOfVowels++;
        }
    }


    return numberOfVowels;
}

void printArrows(char* inputString,int *positionsOfVowels, int numberOfVowels)
{
    int vowelIndex = 0;

    for(int index = 0; inputString[index]; index++)
    {
        if( index == (positionsOfVowels[vowelIndex]-1))
        {
            printf("^");
            vowelIndex++;
        }
        else
        {
            printf(" ");
        }
    }
}

void printPositionsOfVowels(int *positionsOfVowels,int numberOfVowels)
{

    printf("\nPositions of vowels..");
    for(int index = 0; index < numberOfVowels; index++)
    {
        printf("\n%d",positionsOfVowels[index]);
    }
}

int main()
{
    char inputString[30];
    int numberOfVowels ,positionsOfVowels[20];

    printf("\nEnter string to count vowels\n\n");
    fgets(inputString,100,stdin);

    numberOfVowels = countNumberOfVowels( inputString, positionsOfVowels);

    printf("\nNumber of vowels : %d\n",numberOfVowels);

    printPositionsOfVowels(positionsOfVowels,numberOfVowels);

    printf("\n\n%s",inputString);

    printArrows(inputString,positionsOfVowels,numberOfVowels);


    return 0;
}

/*
  --SAMPLE OUTPUT--
  Enter string to count vowels

  I love coding, By Edward

  Number of vowels : 7

  Positions of vowels..
  1
  4
  6
  9
  11
  19
  22

  I love coding, By Edward
  ^  ^ ^  ^ ^       ^  ^
                            */


