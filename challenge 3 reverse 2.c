#include <stdio.h>
#include <stdlib.h>

int inputArray[10],numberOfElements;

void reverseArray()
{

    int n = numberOfElements - 1,temp;

    for(int i = 0; i < numberOfElements/2; i++)
    {
        temp = inputArray[i];
        inputArray[i] = inputArray[n];
        inputArray[n] = temp;
        n--;
    }
}


void printArray()
{

    printf("\nReversed Array\n");
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d\t",inputArray[i]);
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
