Blood Givers Register
=======================
The Blood Givers Register is a command-line program written in C that facilitates the management of blood donor information. This system allows users to maintain a register of blood donors, including their names, blood group types, contact emails, donation notations, and dates of last donations.

## Overview
The Blood Giver Register program is designed to facilitate the management of a register of blood donors. Users can perform various operations such as listing all blood donors, adding new donors to the register, and searching for donors based on blood group types. Additionally, the program includes features for validating email addresses and date formats, as well as calculating the eligibility of donors based on the date of their last donation.


### User Stories
0. The list is stored in a **textfile** consisting of 6 columns:

| Primary Keys | Names | Blood Groups | E-mail | Addresses | No. of blood donations | Date of the last donation |
|--------------|-------|--------------|--------|-----------|------------------------|---------------------------|
|              |       |              |        |           |                        |                           |
|              |       |              |        |           |                        |                           |
|              |       |              |        |           |                        |                           |

1. Parts of your program has to be stored in different files (e.g functions in a file called functions.c, the type of functions in functions.h and finally, function main in main.c). In case of an error, each block has to inform the user and offer a possibility of another trial. 
2. The program has to be given the name of the file (to be handled) in command line. 
3. The program has to check the number of the persons in the list (in the text file) and allocate an area in the memory with a proper size for the *dynamic structure array*. 
4. The program has to fill the array with data from the text file. 
5. The program has to inform the user about these events. 
6. The program has to enumerate its possibilities
   * printing the list
   * Adding a new member to the list
   * Searching for a given blood group, warning the member found in the list by sending her/him an e-mail. Incrementing the number of blood donations in the list and overwriting the date of blood donation in both the structure array and the file. 
7. It has to execute the selected option. 
8. It has to offer an option to continue the program, and in case of a "y" answer, it has to show the options again. 
9. E-mail addresses have to be checked (considering . and @ characters and their positions). If there is a mistake in the file, the program has to inform the user. 
10. The date has to be stored in one piece of string, its valid: **2019.04.03.** Only this format can be accepted! In case of finding a mistaken date format in the file, the program has to inform the user. 
11. Only those blood givers whose last date of donation is older than 90 days may give blood! Calculate the date between the actual date and the date of the last donation. Inbuilt functions (form *string.h* and *math.h* can't be used for this part of the task, where the number (in the string) has to be converted to an int type variable. Write your own function for this operation !!)


Features
--------
- **Listing Blood Donors:** View a list of all registered blood donors.
- **Adding New Donors:** Add new donors to the register, including their personal information.
- **Searching for Donors:** Search for donors based on their blood group types and eligibility for donation.
- **Date Calculations:** Calculate the eligibility of donors based on the date of their last donation.

File Structure
--------------
The project consists of the following files:

- `main.c`: The main program file containing the logic for user interaction and file handling.
- `functions.h`: A header file containing function declarations used in the program.
- `functions.c`: A source file containing the implementations of various utility functions.
- `BloodDonerList.txt`: A sample text file containing donor information.

## Program Workflow

1. **User Input:**
   - The user enters the name of the program and the text file as command-line arguments.

2. **Date Prompt:**
   - The program prompts the user for the current date.
   - The user enters the current date. (Note: Date format required)

3. **File Reading:**
   - The program reads the file into memory and notifies the user of the processes it has undertaken.

4. **Option 1: List Registered Blood Donors:**
   - The user selects the first option.
   - The program prints the list of registered blood donors and asks the user whether to continue.

5. **Option 2: Add a New Donor:**
   - The user selects the second option.
   - The user adds a new donor.
   - The program asks the user whether to add another donor and adds one more donor.
   - The user either accepts or declines the option to add another donor.
   - The program asks the user whether or not to continue.

6. **Checking the Augmented List**
   - The user picks the first option.
   - The program prints out the augmented list with the added donors.
   - The user agrees to continue the program by selecting *y*.

7. **Option 3: Search for Donors:**
   - The user picks the third option.
   - The user enters the blood group they need.
   - The program prints the list of the available donors and who can/cannot donate.
   - The user chooses to continue with the program by selecting 'y'.

8. **Update Donor Information:**
   - The user selects the first option.
   - The program prints the updated list with the last donation date updated and donation count incremented.
   - The user declines the option to continue with the program by selecting 'n'.

9. **Program Termination:**
   - The program quits.

## Asumptions
An eligible donor is assumed to have donated blood.

## Future Plans
Update the date difference calculation to handle leap years and to consider the maximum values of the months and days. Currently, each month is considered as a 30-days-month.
Blood donors with an anniversary should be filtered and can be prized.
Analyze the statistics: How often the members give blood, who donated the most blood, etc.
