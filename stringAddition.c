#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getNumber(char* string)
{
    int temp = 0,index = 0;

    while(string[index])
    {
        temp = (temp*10)+ (string[index] - '0');
        index++;
    }

    return temp;
}


int main()
{
   char String1[10],String2[10];
   int sum,number1,number2;


   printf("\nEnter Number string 1\n");
   gets(String1);
   printf("\nEnter Number string 2\n");
   gets(String2);

    number1 = getNumber(String1);
    number2 = getNumber(String2);
    sum = number1 + number2;
   printf("\nSum = %d",sum);

}
