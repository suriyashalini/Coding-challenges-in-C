#include <stdio.h>
#include <stdlib.h>

void generateArray(int startNumber,int difference,int lengthOfArray,int *APList)
{
    int temp = startNumber;
    for(int index = 0; index < lengthOfArray; index++)
    {
        APList[index] = temp;
        temp += difference;
    }
}

void printArray(int* APList,int lengthOfArray)
{
     for(int index = 0; index < lengthOfArray; index++)
    {
        printf("%d\n",APList[index]);
    }

}

int main()
{
    int startNumber,difference,lengthOfArray,APList[20];

    printf("\nEnter the Starting number\t");
    scanf("%d",&startNumber);

    printf("\nEnter the Diffence value\t");

    scanf("%d",&difference);
    printf("\nEnter the length of series");
    scanf("%d",&lengthOfArray);

    generateArray(startNumber,difference,lengthOfArray,APList);

    printf("\nThe AP series\n");
    printArray(APList,lengthOfArray);





    return 0;
}
