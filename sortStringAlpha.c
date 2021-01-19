#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char* inputString1, char* inputString2, char* sortedString)
{
    int sortedIndex = 0, string1Index = 0, string2Index = 0, maxDigits;
    maxDigits = strlen(inputString1) + strlen(inputString2);
    for(int i = 0; i < maxDigits ; i++)
    {
        if(inputString1[string1Index ] != '\0' && inputString2[string2Index ] != '\0')
        {
                if(inputString1[string1Index ] <= inputString2[string2Index] )
                {
                    sortedString[sortedIndex] = inputString1[string1Index];
                    string1Index++;
                    sortedIndex++;
                }
                else{
                    sortedString[sortedIndex] = inputString2[string2Index];
                    string2Index++;
                    sortedIndex++;
                }
        }
        else if(inputString1[string1Index ] == '\0')
        {
                    sortedString[sortedIndex] = inputString2[string2Index];
                    string2Index++;
                    sortedIndex++;
        } else if(inputString2[string2Index ] == '\0')
        {
                    sortedString[sortedIndex] = inputString1[string1Index];
                    string1Index++;
                    sortedIndex++;

        }
    }
    sortedString[sortedIndex] = '\0';
}


int main()
{
   char inputString1[10],inputString2[10],sortedString[10];

   printf("\nEnter string 1\n");
   gets(inputString1);
   printf("\nEnter string 2\n");
   gets(inputString2);

   sortString(inputString1,inputString2, sortedString);
   printf("\nSorted Array\n %s",sortedString);

}
