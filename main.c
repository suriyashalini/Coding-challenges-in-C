#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *dayInWeek[10];

int turnToNumber(char a)
{

        return (a - '0');

}

int getDaysOfYear(int year)
{
        if(year % 4 == 0 || year % 400 == 0) { return 366;} return 365;
}

int getDaysOfMonth(int month, int year) {

    switch(month){
        case 1  : return 31;
        case 2  :
                  if(year % 4 == 0 || year % 400 == 0) { return 29; };
                  return 28;
        case 3  : return 31;
        case 4  : return 30;
        case 5  : return 31;
        case 6  : return 30;
        case 7  : return 31;
        case 8  : return 31;
        case 9  : return 30;
        case 10 : return 31;
        case 11 : return 30;
        case 12 : return 31;
    }
}



int getYear(char inputDate[10]) {

    int temp = 0;
    for(int i = 0; inputDate[i]; i++ )
    {
     if (isdigit(inputDate[i]))
     {
         temp = temp*10 + turnToNumber(inputDate[i]);
     }
     else break;

    }

    return temp;
}

int getMonth(char inputDate[10]) {

    int temp = 0;
    int key = 0;
    for(int i = 0; inputDate[i]; i++ )
    {
        if (isdigit(inputDate[i]) && key == 1)
        {
            temp = temp * 10 + turnToNumber(inputDate[i]);
        }
        else if(!isdigit(inputDate[i])) key = key + 1;

    }

    return temp;
}

int getDate(char inputDate[10]) {

     int temp = 0;
    int key = 0;
    for(int i = 0; inputDate[i]; i++ )
    {
       if (isdigit(inputDate[i]) && key == 2)
        {
            temp = temp * 10 + turnToNumber(inputDate[i]);
        }
        else if(!isdigit(inputDate[i])) key = key + 1;

    }

    return temp;

}


int validateYear(int year)
{
    if(year <= 0) { return 0;}
    return 1;
}

int validateMonth(int month)
{
    if(month <= 0 || month > 12)
    {
        return 0;
    }
    return 1;
}

int validateDate(int date,int month, int year)
{
    if(date <= 0 || date > getDaysOfMonth(month,year))
    {
        return 0 ;
    }
    return 1;
}
int validateInputDate(int year, int month,int date) {

    if(year == 0 || month == 0 || date == 0)
        {
            printf("\n Not valid date\n");
            return 1;
        }
    if(!validateYear(year)) { printf("\nYear not valid\n"); return 1; }
    if(!validateMonth(month)) { printf("\nMonth not valid\n"); return 1; }
    if(!validateDate(date,month,year)) { printf("\nDate not valid\n"); return 1 ; }
    return 0;
}

int addLeap(int input) {

    int leap = 0;
    if(input > 0) leap = leap + 1;
    leap = leap + ( input / 4 );
    return leap;
}


int yearDifferenceInDays(int year)
{
    int daysInYear = 0;
    if (year > 2000)
    {
       for (int i = 2000; i < year ; i++)
       {
           daysInYear = daysInYear + getDaysOfYear(i);
       }
    }
    if (year < 2000)
    {
        for (int i = year; i < 2000 ; i++)
       {
           daysInYear = daysInYear + getDaysOfYear(i);
       }
    }
    if (year == 2000)
    {
        return 0;
    }

    return daysInYear;
}

int monthDifferenceInDays(int date,int month, int year)
{
    int temp = 0;
    for(int i = 1; i < month ; i++)
    {
        temp = temp + getDaysOfMonth(i,year);

    }
    temp = temp + (date - 1) ;
    if(year < 2000) temp = -temp;

    return temp;
}

void stringCopy(char* arr1, char* arr2)
{
    for(int i = 0; arr2[i]; i++)
    {
        if(isalpha(arr2[i]))
        arr1[i] = arr2[i];
    }

}


void selectDay(char* dayInWeek, int day)
{

        switch(day){

            case 0:  stringCopy(dayInWeek,"Saturday"); break;
            case 1: stringCopy(dayInWeek,"Sunday");break;
            case 2: stringCopy(dayInWeek,"Monday");break;
            case 3: stringCopy(dayInWeek,"Tuesday"); ;break;
            case 4: stringCopy(dayInWeek,"Wednesday"); ;break;
            case 5: stringCopy(dayInWeek,"Thursday");break;
            case 6: stringCopy(dayInWeek,"Friday");break;
            default : stringCopy(dayInWeek,"success");

        }


}

void findDay(int days, int year)

{


    int day = days % 7;

    if(year < 2000)
    {
            day = (7 - day) % 7;
           selectDay(dayInWeek,day);
    }
    if(year >= 2000)
    {
        selectDay(dayInWeek,day);
    }

}

void getNameOfMonth(char* nameOfMonth, int month)
{
    switch(month)
    {
        case 1  : stringCopy(nameOfMonth,"Jan"); break ;
        case 2  : stringCopy(nameOfMonth,"Feb"); break ;
        case 3  : stringCopy(nameOfMonth,"Mar"); break ;
        case 4  : stringCopy(nameOfMonth,"Apr"); break ;
        case 5  : stringCopy(nameOfMonth,"May"); break ;
        case 6  : stringCopy(nameOfMonth,"Jun"); break ;
        case 7  : stringCopy(nameOfMonth,"Jul"); break ;
        case 8  : stringCopy(nameOfMonth,"Aug"); break ;
        case 9  : stringCopy(nameOfMonth,"Sep"); break ;
        case 10 : stringCopy(nameOfMonth,"Oct"); break ;
        case 11 : stringCopy(nameOfMonth,"Nov"); break ;
        case 12 : stringCopy(nameOfMonth,"Dec");
    }
}

void makeCalendar(int days, int date, int month, int year)
{
    char* nameOfMonth[3];
   int temp = 0;
    for(int i = 1; i < month ; i++)
    {
        temp = temp + getDaysOfMonth(i,year);

    }
     if(year < 2000) temp = -temp;
     days = days + temp;

     days = days % 7;
     if(year < 2000)
     {
        days = (7 - days) % 7;
     }
    getNameOfMonth(nameOfMonth,month);
    printf("\n\t\t     %s \\ %d\n",nameOfMonth,year);
    printf("\n\tsat  sun  mon  tue  wed  thu  fri\n\n");


     int k = 1;
     for(int i = 0; k <= getDaysOfMonth(month,year); i++)
     {
         printf("\t");
         for(int j = 0; j < 7 && k <= getDaysOfMonth(month,year); j++ )
        {

            if( i == 0 && j < days)
                 printf("     ");

            else if(k == date)
            {
                if (k < 10)
                    printf("> %d  ",k);
                else
                    printf(">%d  ",k);
                k++;
            }

            else if(k < 10)
            {
                printf(" 0%d  ",k);
                k++;
            }
            else
               {
                 printf(" %d  ",k);
                 k++;
                }
        }
        printf("\n");
     }
}

int calculateDiffInDays(char inputDate[10]) {

    int year = getYear(inputDate);
    int month = getMonth(inputDate);
    int date = getDate(inputDate);

    int days = 0;
    int key = validateInputDate(year,month,date);
    if(key)return 0;

    days = days + yearDifferenceInDays(year);

    makeCalendar(days, date, month, year);

    days = days + monthDifferenceInDays(date,month,year);

    findDay(days,year);



    return 1;

}



void main()
{
    int key ;
    char inputDate[10];
    printf("Enter Date in this format... YYYY/MM/DD  \n");
    scanf("%s",inputDate);

    key = calculateDiffInDays(inputDate);
    if (key != 0)printf("\n\t\t%s is %s\n",inputDate,dayInWeek);

    getch();
}
