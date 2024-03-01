#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// Defining Blood donor struct
typedef struct bloodDoner
{
    char name[20];
    char bloodgroup[10];
    char email[20];
    int notations;
    char date_of_last_notation[20];
} bloodDoner;

int readFile(bloodDoner **c, char *fName, int *l);
void list(bloodDoner *c, int l);
int newClient(bloodDoner **c, int *l);
int searchBloodGroup(bloodDoner *c, int l, char *datecopy);
int search(bloodDoner *c, int l, char *bloodgroup);

int main(int argc, char *argv[])
{
    bloodDoner *bloodDoners = NULL;
    int length = 0, again;
    char dateString[15];
    char dateCopy[15];

    // Get name of the file as a command line argument
    if (argc == 2)
    {
        char *fileName = NULL;
        fileName = argv[1];

        while ((again = readFile(&bloodDoners, fileName, &length)))
        {
            if (again == 2)
            {
                return 0;
            }
        }

        printf("\nThis program helps you to calender the blood doners\n\n");

        do
        {
            printf("Please Enter the current date (e.g. YYYY.MM.DD. and press <ENTER> ): ");
            scanf("%s", dateString);
        } while (dateCheck(dateString));

        copy(dateString, dateCopy);

        printf("\n- Program name: %s, file to be processed (%s) is open.\n", argv[0], argv[1]);
        printf("\n- Number of blood donors in the list is checked. \n");
        printf("\n- Memory block required for the structure array has been allocated.\n");
        printf("\n- The content of the file (called \"%s\") has been read into the structure array.\n ", argv[1]);

        do
        {
            switch (options())
            {
            case 1:
                list(bloodDoners, length);
                break;

            case 2:
                do
                {
                    newClient(&bloodDoners, &length);
                } while (oneMoreMember());
                break;

            case 3:
                while (searchBloodGroup(bloodDoners, length, dateCopy))
                    ;
                break;

            default:
                printf("\nInvalid option. There are 3 options only. Please try again\n\n");
            }
        } while (continueProgram());

        FILE *fp = NULL;
        int i;

        fp = fopen(fileName, "w");

        for (i = 0; i < length; i++)
        {
            fprintf(fp, "%-20s \t%-15s \t\t%-20s   \t\t %d \t\t\t\t %-20s\n", bloodDoners[i].name, bloodDoners[i].bloodgroup, bloodDoners[i].email, bloodDoners[i].notations, bloodDoners[i].date_of_last_notation);
        }

        fflush(fp);
        fclose(fp);
        free(bloodDoners);

        printf("Program quits. Have a nice day!\n");

        return 0;
    }

    else if (argc > 2)
    {
        printf("You supplied too many arguments. \n");
        return 0;
    }
    else
    {
        printf("Pass the name of the file as a command line argument. \n");
        return 0;
    }
}

// Function to print the list of donors in text file
void list(bloodDoner *c, int l)
{
    int i;
    printf("\nLIST OF OUR BLOOD GIVERS' FILE: \n");

    printf("\nID \t NAME \t\t\tBLOODGROUP \t\t\tEMAIL \t\t\t\tDONATIONS \t\t\tDATE OF LAST DONATION\t\t\t\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < l; i++)
    {
        printf("%d \t %-20s \t%-15s \t\t%-20s   \t\t %d \t\t\t\t %-20s\n", i + 1, c[i].name, c[i].bloodgroup, c[i].email, c[i].notations, c[i].date_of_last_notation);
    }
}

// Function to add a new donor to the list
int newClient(bloodDoner **c, int *l)
{
    char emailTemp[20], dateTemp[20];

    printf("\n Adding a new member: \n\n");

    printf("Name: ");
    scanf("%s", (*c)[*l].name);

    printf("Blood group: ");
    scanf("%s", (*c)[*l].bloodgroup);

    do
    {
        printf("Email: ");
        scanf("%s", emailTemp);
    } while (emailCheck(emailTemp));
    copy(emailTemp, (*c)[*l].email);

    printf("Number of blood donations: ");
    scanf("%d", &(*c)[*l].notations);

    do
    {
        printf("Date of last blood donation: ");
        scanf("%s", dateTemp);
    } while (dateCheck(dateTemp));
    copy(dateTemp, (*c)[*l].date_of_last_notation);

    if (!(*c = (bloodDoner *)realloc(*c, ++(*l) * sizeof(bloodDoner))))
    {
        printf("ERROR: there is not enough memory \n");
        if (overAgain())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int search(bloodDoner *c, int l, char *bloodgroup)
{
    int i, j, bloodgroupLength = str_length(bloodgroup);

    for (i = 0; i < l; i++)
    {
        if (bloodgroupLength == str_length(c[i].bloodgroup))
        {
            j = 0;
            while (j < bloodgroupLength && bloodgroup[j] == c[i].bloodgroup[j])
            {
                j++;
            }
            if (j == bloodgroupLength)
            {
                return i;
            }
        }
    }

    return -1;
}

// Function to search for blood group type from the list
int searchBloodGroup(bloodDoner *c, int l, char *dateCopy)
{
    char bloodgroup[5];
    int bloodgroupIndex;
    int dateDifference;
    char lastDDCopy[15];
    char *donationstatus;
    struct tm lastDate, currentDate;
    char *strptime(const char *s, const char *f, struct tm *tm);

    int i, j;

    printf("\nWhich blood Group do you need: ");
    scanf(" %s", bloodgroup);

    int bloodgroupLength = str_length(bloodgroup);

    if ((bloodgroupIndex = search(c, l, bloodgroup)) == -1)
    {
        printf("ERROR: Blood group cannot be found.\n");
        if (overAgain())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    printf("\nLIST OF MATCHES: \n\n");
    /*printf("\nID \t NAME \t\t\tBLOODGROUP \t\t\tEMAIL \t\t\t\tDONATIONS \t\t\tDATE OF LAST DONATION\t\t\t\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");*/

    for (i = 0; i < l; i++)
    {
        if (bloodgroupLength == str_length(c[i].bloodgroup))
        {
            j = 0;
            while (j < bloodgroupLength && bloodgroup[j] == c[i].bloodgroup[j])
            {
                j++;
            }
            if (j == bloodgroupLength)
            {
                copy(c[i].date_of_last_notation, lastDDCopy);

                replace_char(dateCopy, '.', '-');
                replace_char(lastDDCopy, '.', '-');

                strptime(dateCopy, "%F", &currentDate);
                strptime(lastDDCopy, "%F", &lastDate);

                dateDifference = julian_day(&currentDate) - julian_day(&lastDate);

                if (dateDifference >= 90)
                {
                    donationstatus = "";
                }
                else
                {
                    donationstatus = "Cannot donate.";
                }

                printf("\n%d \t %-20s \t%-15s \t\t%-20s   \t\t %d \t\t\t\t %-20s\t\t%s\n", i + 1, c[i].name, c[i].bloodgroup, c[i].email, c[i].notations, c[i].date_of_last_notation, donationstatus);

                c[i].notations++;
                replace_char(dateCopy, '-', '.');
                copy(dateCopy, c[i].date_of_last_notation);
            }
        }
    }

    printf("\nE-mail(s) has been sent, number of blood donations have been incremented in \nboth the structure array and the file.\n");

    return 0;
}

// Function to read the file
int readFile(bloodDoner **c, char *fileName, int *l)
{
    char ch;
    int i;

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            (*l)++;
        }
    }

    if (!(*c = (bloodDoner *)malloc(*l * sizeof(bloodDoner))))
    {
        printf("ERROR: there is no memory enough.\n");
        if (overAgain())
        {
            return 1;
        }
        else
        {
            printf("Program exits.\n");
            return 2;
        }
    }

    rewind(fp);

    for (i = 0; i < *l; i++)
    {
        fscanf(fp, "%s %s %s %d %s", (*c)[i].name, (*c)[i].bloodgroup, (*c)[i].email, &(*c)[i].notations, (*c)[i].date_of_last_notation);
    }

    fclose(fp);

    return 0;
}