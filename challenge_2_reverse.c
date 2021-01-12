#include <stdio.h>
#include <stdlib.h>

int inputArray[10],outputArray[10],numberOfElements;

void reverseArray()
{
    int n = numberOfElements;
    for(int i = 0; i < numberOfElements; i++)
    {
        outputArray[i] = inputArray[n];
        n--;
    }
}


void printArray()
{
    printf("\nInput Array\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d\t",inputArray[i]);
    }
    printf("\nReversed Array\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d\t",outputArray[i]);
    }
}

int main() {

    printf("\nEnter no of elements\t");
    scanf("%d",&numberOfElements);

    for(int i = 0; i < numberOfElements; i++)
    {
        scanf("%d",&inputArray[i]);
    }

    reverseArray();
    printArray();

    return 0;
}
