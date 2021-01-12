//Added case sensitivity

#include <stdio.h>
#include <stdlib.h>

int checkIfAlphabet(char letter)
{
        if( (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') )
        {
            return 1;
        }

        return 0;
}

int checkInUniqueArray(char isCaseSensitive, char letter,char *uniqCharsArray,int numberOfUniqChars)
{
    for(int index = 0; index < numberOfUniqChars; index++)
    {
            if(letter == uniqCharsArray[index])
            {
                    return 0;
            }

            if(isCaseSensitive == 'y')
            {
                if(checkIfAlphabet(letter) && ( (letter == (uniqCharsArray[index] + 32) ) || (letter == (uniqCharsArray[index] - 32) ) ) )
                {
                    return 0;
                }
            }

    }
    return 1;
}

int countNumberOfUniqChars (char isCaseSensitive,char* inputString,char* uniqCharsArray,int* positionsOfUniqChars)
{
    int numberOfUniqChars = 0;

    for(int index = 0; inputString[index]; index++)
    {
        if( checkIfAlphabet( inputString[index] ) && checkInUniqueArray(isCaseSensitive, inputString[index], uniqCharsArray, numberOfUniqChars) )
        {
            uniqCharsArray[numberOfUniqChars] = inputString[index];

            positionsOfUniqChars[numberOfUniqChars] = index+1;

            numberOfUniqChars++;
        }
    }


    return numberOfUniqChars;
}

void printArrows(char* inputString,int *positionsOfUniqChars, int numberOfUniqChars)
{
    int uniqCharIndex = 0;

    for(int index = 0; inputString[index] ; index++)
    {
        if( index == ((positionsOfUniqChars[uniqCharIndex])-1))
        {
            printf("^");
            uniqCharIndex++;
        }
        else
        {
            printf(" ");
        }
    }
}

void printPositionsOfUniqChars(int *positionsOfUniqChars,int numberOfUniqChars)
{

    printf("\nPositions of Unique characters..\n\n");
    for(int index = 0; index < numberOfUniqChars; index++)
    {
        printf(" %d\t",positionsOfUniqChars[index]);

    }
    printf("\n");
}

void  printUniqChars(char *uniqCharsArray, int numberOfUniqChars)
{
    printf("\nUnique characters..\n\n");
    for(int index = 0; index < numberOfUniqChars; index++)
    {
        printf(" %c\t",uniqCharsArray[index]);

    }
    printf("\n");

}

int main()
{
    char inputString[50],uniqCharsArray[26],isCaseSensitive;
    int numberOfUniqChars ,positionsOfUniqChars[20];

    printf("\nEnter string..\n\n");
    fgets(inputString,50,stdin);

    printf("\nCase sensitive? y : yes\t");

    isCaseSensitive = getchar();

    numberOfUniqChars = countNumberOfUniqChars (isCaseSensitive,inputString, uniqCharsArray, positionsOfUniqChars);

    printf("\n%s",inputString);
    printArrows(inputString,positionsOfUniqChars,numberOfUniqChars);

    printUniqChars(uniqCharsArray,numberOfUniqChars);

    printf("\nNumber of Unique Characters : %d\n",numberOfUniqChars);

    printPositionsOfUniqChars(positionsOfUniqChars,numberOfUniqChars);


    return 0;
}
