#include <stdio.h>
#include <stdlib.h>

int inputArray[10],outputArrayEven[10],outputArrayOdd[10],numberOfElements;
int i=0,j=0,k=0;

void splitArray()
{



    for(i = 0; i < numberOfElements; i++)
    {
        if((inputArray[i] % 2 == 0))
        {
            outputArrayEven[j]=inputArray[i];
            j++;
        }
        else
        {
            outputArrayOdd[k]=inputArray[i];
            k++;
        }
    }
}

void printArray()
{
    printf("\nOdd Number Array\n");
    for (i = 0; i < j; i++)
    {
        printf("\t%d",outputArrayOdd[i]);
    }
    printf("\nEven Number Array\n");
    for (i = 0; i < k; i++)
    {
        printf("\t%d",outputArrayEven[i]);
    }
}

int main() {

    printf("\nEnter no of elements\t");
    scanf("%d",&numberOfElements);

    for(int i = 0; i < numberOfElements; i++)
    {
        scanf("%d",&inputArray[i]);
    }

    splitArray();
    printArray();

    return 0;
}
