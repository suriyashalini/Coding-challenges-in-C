
//Entering NON Numerical values as input may cause unexpected behaviours

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long int input;

int inputArray [30],numberOfDigits,rotation = 0;

long int output;

int splitNumber()
{

    long int quotian = input;
    int temp[30],n;

    numberOfDigits = 0;

    while(quotian != 0)
    {
        temp[numberOfDigits] = quotian % 10;

        quotian = quotian / 10;

        numberOfDigits++;


    }

    n = numberOfDigits - 1;

    for(int i = 0; i < numberOfDigits; i++)
    {
       inputArray[i] = temp[n];
       n--;
    }

    return 0;
}
int increaseDigits(int pos)
{
    inputArray[pos] = 0;
    pos--;
    inputArray[pos]++;

    if( inputArray[pos] > 9 )
    {
        increaseDigits(pos);
    }
    return 0;
}

int makeEquals(int front, int back)
{
    while(inputArray[front] != inputArray[back])
    {
        inputArray[back]++;

        if(inputArray[back] > 9)
        {
            increaseDigits(back);
        }
    }


    return 0;
}
int findPalindrome()
{
    int n = numberOfDigits - 1;

    for(int i = 0; i < (numberOfDigits / 2); i++ )
    {
        makeEquals(i,n);
        n--;
    }

    return 0;
}

int joinNumber()
{
    for(int i = 0; i < numberOfDigits; i++)
    {
        output = output * 10 + inputArray[i];
    }
    return 0;
}

int printPalindrome()
{
    if(input == output)
    {
        printf("\n||||  ----------- ------------ ------------");
        if(rotation == 0)
        {
            printf("\n||||\n||||  %ld is a palindrome",input);
            printf("\n||||\n||||  ----------- ------------ ------------");
            return 0;


        }

    }
    else
    {
        printf("\n||||  ----------- ------------ ------------");
        if(rotation == 0)
        {
            printf("\n||||  %ld is not a palindrome",input);
            printf("\n||||  ----------- ------------ ------------");
        }
        printf("\n||||\n||||  Next biggest palindrome : %ld",output);
        printf("\n||||\n||||  ----------- ------------ ------------");
    }

    return 0;
}

int mainMenu()
{
    do
    {

    splitNumber();
    findPalindrome();
    joinNumber();
    printPalindrome();
    printf("\n||||  Find next..? [y] : yes \t ");

    input = output + 1;
    output = 0;
    rotation++;
    }while(getch() == 'y');

    return 0;
}


int main()
{

    do
    {
    system("cls");
    printf("\n||||\t\t----------- ------------ ------------\t\t||||");
    printf("\n||||\t\t----------- ------------ ------------\t\t||||");

    printf("\n\n Enter Number to check if palindrome...\t ");
    scanf("%ld",&input);

    while( (getchar() != '\n') );

    if(input <= 9)
    {
        system("cls");
        printf("\n||||\t\t----------- ------------ ------------\t\t||||");
        printf("\n||||\t\t----------- ------------ ------------\t\t||||");
        printf("\n\n Single digit input not allowed..:(");

        printf("\n\n||||  Try with Another number...? [y] : yes \t ");
        continue;


    }
    else
    {
         mainMenu();
    }



    output = 0;
    input = 0;
    rotation = 0;

    system("cls");
    printf("\n||||\t\t----------- ------------ ------------\t\t||||");
    printf("\n||||\t\t----------- ------------ ------------\t\t||||");
    printf("\n\n||||  Try with Another number...? [y] : yes \t ");

    }while(getch() == 'y');

}
