/*******************************************************************************
48430 Embedded C - Assignment 2
Name: Menka Mehta
Student ID: 12195032
Date of submission: 30th September 2016
A brief statement on what you could achieve (less than 50 words):


A brief statement on what you could NOT achieve (less than 50 words):


*******************************************************************************/

/*******************************************************************************
List of header files - do NOT use any other header files. Note that stdlib and
cstring are included in case you want to use any of the functions in there.
However the task can be achieved with stdio only.
*******************************************************************************/
#include <stdio.h>/*printf, fgets, scanf*/
#include <stdlib.h>/*strtol*/
#include <string.h>


/*******************************************************************************
List preprocessing directives - you may define your own.
*******************************************************************************/
/* Maximum number of students in the class */
#define MAX_CLASS_SIZE 5
/* Maximum length of the string - student name. Note that all strings in C are
NULL terminated i.e. '\0' at the end of the string. Hence the length of the
actual name can be 10 characters at most*/
#define MAX_NAME_SIZE 11 
/* Static file name of the text file where student list is stored */
#define DB_FILE_NAME "database"


/*******************************************************************************
List structs - you may define struct date and struct student only. Each struct
definition should have only the fields mentioned in the assignment description.
*******************************************************************************/
struct date
{
    unsigned int day;
	unsigned int month; 
	unsigned int year; 
};

struct student
{ 
	char name[MAX_NAME_SIZE]; 
	float gpa; 
	struct date bday; 
};

typedef struct student student_t; 
/*******************************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
*******************************************************************************/
void printmenu(void); 
void selectMenu(student_t[], int*, int); 
void add_Student(student_t[],int*); 
void delete_Student(int*); 
void displayList(student_t[], int*); 
void saveList(student_t [], int*); 
void readList(student_t[], int*); 

/*******************************************************************************
Main
*******************************************************************************/
int main(void)
{
	/* TODO */
	student_t studentlist[MAX_CLASS_SIZE]; 
	int choice = 0;	
	int listSize = 0; 
	char userInput[64]; 
	
	do{
		printmenu(); 
		/*Prints the menu*/
		fgets(userInput, 63, stdin);
	/* Take user's input as stardard input and place it in array 'userInput' */
	
		if (sscanf(userInput, "%d", &choice) !=1 || strlen(userInput) < 2 
		/* Place user's input from 'userInput' into  'choice' */
		|| strlen(userInput) > 2 ||  choice < 1 || choice > 6) 
		{ 
			
			choice =0; 
		/* Set choice to 0 if any comparasion above is true */
		}
		selectMenu(studentlist, &listSize, choice); 
		/* Call function 'selectMenu' by passing appropriate data type */
	}while(choice != 6); 
	/* Keep looping if choice is not equal to 6 */
    return 1;
}
/*******************************************************************************
MY PROGRAM
*******************************************************************************/
/*******************************************************************************
Function "SelectMenu" - selection choice that allows the user to select a number
from 1 to 6.
*******************************************************************************/
void selectMenu(student_t studentlist[], int* listSize,int choice)
{ 
/* Receive data input from main */
	switch(choice) 
	{ /* Check choice */
		case 1: /* If choice is 1 add student*/
			add_Student(studentlist, listSize);
			 break;
		case 2: /* If choice is 2 delete last student */
			delete_Student(listSize);
			 break; 
		case 3: /* If choice is 3 display the List of students */
			displayList(studentlist, listSize); 
			break; 
		case 4: /* If choice is 4 save the studenlist to the database */
			saveList(studentlist, listSize);
			 break;
		case 5: /* If choice is 5 read the student list from the database*/
			readList(studentlist, listSize); 
			break;
		case 6:
			exit(0); /* Exit the program */
		default:	
			printf("Invalid choice."); 
/*display invalid input for any number out of the given choices*/
	}

}


/*******************************************************************************
ADD STUDENT
*******************************************************************************/
void add_Student(student_t studentlist[], int* listSize) 
{ 

	int valid_choice = 0; 
	/*Initialising variable valid_choice*/
	char userInput[64];
	char * pEnd;
	int number;
	
	if(*listSize < MAX_CLASS_SIZE)/* Check if studentlist is full */ 
	{ 
	
	/*STUDENT NAME */
		printf("Enter name>"); 
		/* Ask the user to enter student's  name */
fgets(studentlist[*listSize].name, sizeof(studentlist[*listSize].name), stdin);
/*gets the input from the user*/
		char *pos; /* Declare pointer 'pos' */
		if ((pos=strchr(studentlist[*listSize].name, '\n')) != NULL) 
		/* Check for '\n' position in string */
			*pos = '\0'; /* Set '\n' to null */
		fflush(stdin); /* Clear input buffer*/
		
	
		/*STUDENT BIRTHDAY: DAY*/
		do
		{ 
			printf("Enter birthday: day>"); 
			/*print statement to ask the user to enter student's birthday day*/
			fgets(userInput, 63, stdin);
			 /* Take user's input as string and save it in 'userInput */
			 
			 
	/*valid_choice = sscanf(userInput, "%d", &studentlist[*listSize].bday.day);*/
	number = strtol (userInput , &pEnd, 10 );
	valid_choice = (*pEnd == '\n');
	
	/* Set value return from sscanf to 'valid_choice' */
			if (valid_choice!= 1 || strlen(userInput) < 2 
			 || strlen(userInput) > 3 || number < 1 
			 || number > 31)
			 { /*checking lenghts of the variables*/ 
			 	
				printf("Invalid day. "); 
				/* print "invalid day" if the conditions are met*/
				valid_choice = 0; 
				 /* Set valid_choice to 0 if any condition above is met */
				 
			 }
			 
			else if(!(userInput[0] >= '0' && userInput[0] <= '9'))
			 {
			 	printf("Invalid day. "); 
				/* print "invalid day" if the conditions are met*/
				valid_choice = 0; 
			 }
			 
			 else 
			 {
			 	valid_choice = 1;
			 	studentlist[*listSize].bday.day = number;
			 }
			
		} while(valid_choice != 1); 
		/* Keep looping when variable is not equal to 1 */
		

		/*STUDENT BIRTHDAY MONTH*/
		do
		{ 
			printf("Enter birthday: month>"); 
			/*print statement to ask the user enter student's birthday month*/
			fgets(userInput, 63, stdin); 
			/*get the inputs from user and store them as user input*/
/*valid_choice = sscanf(userInput, "%d", &studentlist[*listSize].bday.month);*/
	number = strtol (userInput , &pEnd, 10 );
	valid_choice = (*pEnd == '\n');
	
			if (valid_choice!= 1 || strlen(userInput) < 2 || 
			strlen(userInput) > 3 || number< 1 
			|| number > 12)
			{ /*if the above conditions are met, do the following*/
				printf("Invalid month. ");
				valid_choice = 0;
			}
			
			else if(!(userInput[0] >= '0' && userInput[0] <= '9'))
			 {
			 	printf("Invalid month. "); 
				/* print "invalid day" if the conditions are met*/
				valid_choice = 0; 
			 }
			
			else
			{
				valid_choice = 1;
			 	studentlist[*listSize].bday.month = number;
			}
		} while(valid_choice != 1);
		 /* Exit loop if condition is met */
		
		
		/*STUDENT BIRTHDAY YEAR*/
		do
		{
			printf("Enter birthday: year>");
			/*print statement to ask the user to enter student's birthday year*/
			fgets(userInput, 63, stdin);
	valid_choice = sscanf(userInput, "%d", &studentlist[*listSize].bday.year); 
	
			if (valid_choice != 1 || strlen(userInput) < 2 || 
			strlen(userInput) > 5 || studentlist[*listSize].bday.year < 1800 || 
			studentlist[*listSize].bday.year > 2016)
			{ /* Check if any condition is met then do the following */
				printf("Invalid year. ");
				valid_choice = 0;
			}
		}while (valid_choice != 1);
		
		
		
		/*STUDENT'S GPA*/
		do
		{
			printf("Enter GPA>");
			/*print statement to ask the user to enter student's GPA*/
			fgets(userInput, 63, stdin);
			
		 double number = strtod (userInput , &pEnd);
		valid_choice = (*pEnd == '\n');
	/*valid_choice = sscanf(userInput, "%f", &studentlist[*listSize].gpa ); */
	/* Place user's input from 'userInput' into 'studentlist[*listSize].gpa' */
			if (valid_choice != 1 || strchr(userInput, ' ') != NULL || 
			strlen(userInput) < 2 ||number < 0 
			|| number > 4)
			{ /* strchr(userInput, ' ') check for any space in 'userInput' */
				printf("Invalid GPA. ");
				valid_choice = 0;
			}
			else
			{
				valid_choice = 1;
				studentlist[*listSize].gpa = number;
			}
		}while (valid_choice != 1);
		
		*listSize+= 1; /* Access value in pointer and add 1 to it */ 
	
	}
	
	
	else
		printf("Class is full\n");
		 /*Print this message when student list is full*/
	}
	
	


/*******************************************************************************
DELETE A STUDENT
*******************************************************************************/

void delete_Student (int* listSize) 
{
	if (*listSize > 0)
	 { /* Check if array contain anything or is empty?*/
		*listSize -= 1; 
		/*Access value in pointer minus 1*/
	 }
	else
		printf("Class is empty\n");
	/* Print message if array does not contain any variable anything*/
}
/*******************************************************************************
DISPLAY LIST OF STUDENTS
*******************************************************************************/
void displayList(student_t studentlist[], int* listSize)
{
	int i; /* Declare 'i' as a counter */
	if (*listSize == 0) /* Check if array studentlist is empty */
		printf("Class is empty\n"); /* Display message */
	else 
	{ /* If array is not empty */
		printf("Name       Birthday   GPA\n");
		printf("---------- ---------- ------\n"); 
		for (i = 0; i < *listSize; i++)
		{ /*for loop to keep looping till the counter reaches the end */
			printf("%-10.10s %02d-%02d-%4d %-.4f\n", 
			studentlist[i].name, studentlist[i].bday.day, 
			studentlist[i].bday.month, studentlist[i].bday.year, 
			studentlist[i].gpa); 
			/*This displays the student information*/
		}
	}
}

/*******************************************************************************
SAVE LIST OF STUDENTS
*******************************************************************************/

void saveList(student_t studentlist[], int* listSize)
{
	FILE* database = fopen(DB_FILE_NAME, "w"); 
	/*create a database and write in it*/
	int i; 
	/* Declare 'i' as a counter */
	for (i = 0; i < *listSize; i++)
	{ /*for loop to keep looping till the counter reaches the end */
		fprintf(database, "%11s %02d-%02d-%4d %.4f\n",
		 studentlist[i].name, studentlist[i].bday.day, 
		 studentlist[i].bday.month, studentlist[i].bday.year, 
		 studentlist[i].gpa); 
	/* Print information from current array studentlist into database file */
	}
	
	fclose(database); /* Close database file */
}

/*******************************************************************************
READ LIST OF STUDENTS
*******************************************************************************/
void readList(student_t studentlist[], int* listSize)
 {
	FILE* database = fopen(DB_FILE_NAME,"r" ); 
	/* Open database file and read it */
	int i = 0; 
	/* Declare 'i' as a counter */

	if(ftell(database)!= 0) 
	/* Check if database file exist */
		printf("Read error\n");
		 /* Print the error message if database file does not exist */
	else
		while (fscanf(database, 
		"%10s %02d-%02d-%4d %f", studentlist[i].name,
		 &studentlist[i].bday.day, &studentlist[i].bday.month, 
		 &studentlist[i].bday.year, &studentlist[i].gpa)!= EOF) 
		 { /* Scan data from database till end of file */
				i++;
		 } /* Read information from database file */	
	fclose(database); /* Close database file */
	*listSize = i; /* Overwrite current array */
}



/*******************************************************************************
printMenu
This function prints the initial menu with all instructions on how to use this
program.
inputs:
- none
outputs:
- none
*******************************************************************************/
void printmenu(void)
{
	printf("\n\n"
	"1. add student\n"
	"2. delete last student\n"
	"3. display student list\n"
	"4. save the student list to the database\n"
	"5. read the student list from the database\n"
	"6. exit the program\n"
	"Enter your choice>");
}

