#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Function to print available options to the user
int options()
{
    int option;
    printf("\nYou can select from the options below (By entering it's number): \n");
    printf("\n- 1. Printing the list\n");
    printf("\n- 2. Adding a new member to list\n");
    printf("\n- 3. Searching for a given blood group, warning the member found in the list by sending her / him an email.\nIncrementing the number of blood notations of the person in the list and overwriting her / his date of \nlast blood notation in both the structure array and the file.\n\n");
    printf("Your Choice: ");
    scanf(" %d", &option);
    system("clear");
    return option;
}


//Funtion to add one more new donor
int oneMoreMember()
{
    char addAgain;
    printf("\n one more new member? (y / n): ");
    scanf(" %c", &addAgain);
    if (addAgain == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Function to copy
void copy(char *fromHere, char *toHere)
{
    int i = 0;
    while (fromHere[i])
    {
        toHere[i] = fromHere[i];
        i++;
    }
    toHere[i] = 0;
}



//Function to check the string length
int str_length(char str[])
{
    int i;
    int count = 0;

    for (i = 0; str[i] != 0; i++)
    {
        count++;
    }
    return count;
}


//Function to check date format validity
int dateCheck(char *dTemp)
{
    int i = 0;
    int yearDotIndex, monthDotIndex, dayDotIndex, dotIndex;
    int numberOfDots = -3;

    int count;
    count = str_length(dTemp);

    if (count == 11)
    {
        for (int i = 0; i < count; i++)
        {
            if (dTemp[i] == '.')
            {
                if (i == 4)
                {
                    yearDotIndex = i;
                }
                if (i == 7)
                {
                    monthDotIndex = i;
                }
                if (i == 10)
                {
                    dayDotIndex = i;
                }
                numberOfDots++;
                dotIndex = i;
            }
        }
        if (numberOfDots)
        {
            printf("Invalid date!\n");
            return 1;
        }

        if (yearDotIndex != 4 || monthDotIndex != 7 || dayDotIndex != 10 || !dotIndex)
        {
            printf("Invalid date!\n");
            return 1;
        }
    }
    else if (count < 11)
    {
        printf("Invalid date!\n");
        return 1;
    }
    else if (count > 11)
    {
        printf("Invalid date!\n");
        return 1;
    }
    else{ return 0; }

    return 0;
}


//Function to check email format validity
int emailCheck(char *eTemp)
{
    int i = 0, dotIndex, atIndex, numberOfDots = -1, numberOfAts = -1, diff;

    while (eTemp[i])
    {
        if (eTemp[i] == '.')
        {
            dotIndex = i;
            numberOfDots++;
        }
        if (eTemp[i] == '@')
        {
            atIndex = i;
            numberOfAts++;
        }
        i++;
    }

    if ((diff = dotIndex - atIndex) < 0)
    {
        printf("Invalid email!\n"); return 1;
    }
    if (numberOfDots || numberOfAts)
    {
        printf("Invalid email!\n"); return 1;
    }
    if (!dotIndex || !atIndex || dotIndex == i - 1 || atIndex == i - 1 || diff == 1)
    {
        printf("Invalid email!\n"); return 1;
    }

    return 0;
}


//Funtion to offer option of repeating the process
int overAgain()
{
    char again;
    printf("\nDo you want to try again? (y / n): ");
    scanf(" %c", &again);
    if (again == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Function to continue or end program
int continueProgram()
{
    char keepRunning;
    printf("\nDo you want to keep the program running ? (y/n) ");
    scanf(" %c", &keepRunning);

    if (keepRunning == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Function to Replace the '.' in the date String to '-' .  
void replace_char(char *string, char replace, char new)
{
   int stringLength = str_length(string);

   for (int i = 0; i < stringLength; i++)
   {
    if (string[i] == replace && i != (stringLength - 1))
    {
        string[i] = new;
    }
   }
}

// The formulas for a and m can be distilled down to these tables.
int Julian_A[12] = {1, 1, 0};
int Julian_M[12] = {10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int julian_day(struct tm *date)
{
    int a = Julian_A[date->tm_mon];
    int m = Julian_M[date->tm_mon];
    int y = date->tm_year + 1900 + 4800 - a;

    return date->tm_mday + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
