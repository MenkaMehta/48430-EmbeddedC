/*******************************************************************************
48430 Embedded C - Assignment 1
Name: MENKA MEHTA
Student ID: 12195032
Date of submission: 2nd September 2016
A brief statement on what you could achieve (less than 50 words):

A brief statement on what you could NOT achieve (less than 50 words):


*******************************************************************************/

/*******************************************************************************
List of header files - do NOT use any other header files.
<stdio.h> - standard input output header
due to this header we can use the printf() and scanf() functions
printf() is a standard output function
scanf() is a standard input function
*******************************************************************************/
#include <stdio.h> /*printf(), scanf()*/



/*******************************************************************************
List preprocessing directives (if applicable) - you may define your own.
*******************************************************************************/



/*******************************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
Function Prototype - declaration of functions and their types.
*******************************************************************************/
void printMenu(void); 
int isOdd();
int triangularNumber();
void printTriangularNumber();
int isEvnTria();
void printEvnTriangular();
void printOdd();
void printStars();


/*******************************************************************************
Main
*******************************************************************************/
int main(void){
	/* TODO */

	int number = 0;
	int menu_number = 0;
	
	/*Printf - Prints a statement to ask the user to enter a non negative number*/
	printf("Enter a non-negative integer>"); 
	/*Scanf -  takes an integer input from the user*/
	scanf("%d", &number);
	
	if (number < 0)
	{
		/*prints "invalid input" if user enters number less than zero*/
		printf("Invalid input\n");
	}
	else
	{
		/*do the following if user enters number greater than zero*/
		printMenu(); /*print the menu*/
		scanf("%d", &menu_number);/*user enters the menu_number*/
	
	while(menu_number != 5)
	{
		/*exit, when user enters menu_number = 5*/
		switch(menu_number)
		{
			case 1: /*menu_number == 1*/
			printOdd(number);/*calling printOdd() funtion*/
			printMenu();
			scanf("%d", &menu_number);
			break;
			
			
			case 2: /*menu_number == 2*/
			printTriangularNumber(number); /*calling isTriangularNumber() function*/
			printMenu();
			scanf("%d", &menu_number);
			break;
			
			
			case 3: /*menu_number == 3*/
			printEvnTriangular(number); /*calling printEvnTriangular() function*/
			printMenu();
			scanf("%d", &menu_number);
			break;
			
			case 4: /*menu_number == 4*/
			printStars(number);/*calling printStars() function*/
			printMenu();
			scanf("%d", &menu_number);
			break;
				
			default:
			/*If user enters menu_number > 5 0r < 1*/
			printf("Invalid Input"); 
			printMenu();
			scanf("%d", &menu_number);
			break;
		}	
	}
	
     }

	
	return 0;
	
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
void printMenu(void) 
{
	/*Prints a menu for the user*/
	printf("\n\n"
	"1. is odd?\n"
	"2. is triangular?\n"
	"3. is even and triangular?\n"
	"4. print a triangle\n"
	"5. exit the program\n"
	"Enter your choice>");
}

/*******************************************************************************
isOdd
This is a function that takes checks if a number is odd or even. Hence, return 0:
if the number is even and returns 1: if the number is odd.
input - number
output - returns (0 or 1)
*******************************************************************************/
int isOdd(int number)/*A number is passed in*/
{
	
		if(number%2 == 0) /*Divide the number by 2*/
		{
       		
       			return 0; /*Return zero if remainder==0*/
       		}
   		 else
   		 {
        		
        		return 1; /*Return one if remainder != 0*/
        	}
        		
}

/*******************************************************************************
printOdd
This is a function that print trues if it is an odd number
and prints false if not an odd number
input - number
output- printf statements (true/false)
*******************************************************************************/
void printOdd(int number)/*A number is passed in*/
 {
 	if(isOdd(number) == 1 ) 
	{
		printf("True\n"); /*Print true if function isOdd returns 1*/
	}
	else
	{
		printf("False\n"); /*Print false if function isOdd returns 0*/
	}
 }



/*******************************************************************************
triangularNumber
This is a function that checks if a number is a trinagular number or not,
therefore return 1 if number is triangular and returns 0 viceversa.
input - number
output - returns (0/1)
*******************************************************************************/

int triangularNumber (int number)/*A number is passed in*/ 
{
    int triangle = 0;
    int i;
    
    for (i = 1; i <= number; i++) /*A for loop that loops from i=1 upto i=number*/
    {
        triangle += i; /*triangle = triangle + i*/
        if(triangle == number) 
        {
        /*while looping if triangle is equal to the passed in number,then do the 
        following.*/
        return 1; /*Returns 1 if the number is a triangular number*/
        }
    }
   
    return 0;/*Returns 0 if the number is not a triangular number*/
    
}

/*******************************************************************************
printTriangularNumber
This is a function that prints true or false on the basis of returned number from
triangularNumber function
input - number
output - printf statements (true/false)
*******************************************************************************/
 void printTriangularNumber(int number)
 {
 	if(triangularNumber(number) == 1 )
	{
		printf("True\n");
		/*Print true if trinagularNumber funtion returns 1*/
	}
	else
	{
		printf("False\n");
		/*prints false if triangularNumber function returns 0*/
	}
 }


/*******************************************************************************
isEvnTria - means is even and triangular
This is a function that checks if the number is even as well as triangular.
input -number
output - returns (o/1)
*******************************************************************************/
int isEvnTria(int number)/*A number is passed in*/
{
	if(triangularNumber(number) == 1 && isOdd(number) == 0) 
	{
		/*checks if 1)triangularNUmber function returns 1
		            2) isOdd function returns 0 (even)
		If both are true then this function returns 1*/
	 	return 1;
	}
	 
	return 0;/*else it returns 0*/
}

/*******************************************************************************
printEvnTriangular 
This is a function that print true if the number is both even and triangular
input -number
output - printf statements (true/false)
*******************************************************************************/
void printEvnTriangular(int number)
{
	if(isEvnTria(number) == 1)
	{
		printf("True\n");
		/*prints true if isEvnTria function returns 1*/
	}
	else 
	{
		printf("False\n");
		/*prints false if isEvnTria function returns 0*/
	}
	
}
	
/*******************************************************************************
printStars
This is a function that prints stars/asteriks
-It prints perfect triangle if the number is triangular
-It prints imperfect triangle if the number is not triangular
input - number
outputs - stars and printf statements stating perfect/imperfect triangles
*******************************************************************************/	
void printStars(int number)/*A number is passed in*/
{
	if(triangularNumber(number)==1)/*if triangularNUmber function returns 1*/
	{
		printf("Input %d is triangular." , number); 
		printf("Printing a perfect triangle of %d stars\n", number);
	}
	else /*if triangularNumber function returns*/
	{
		printf("Input %d is not triangular.",number); 
		printf("Printing an imperfect triangle of %d stars\n", number);
	}

	int count = 0, row_element =0, row_max =1;
	/*Nested while loops*/
	while(count < number)
	{
		while(row_element < row_max && count < number)
		{
			printf("* ");/*print the star with a space after it*/
			++row_element;/*increment row_element, then use*/
			++count;/*increment count, then use*/
			
		}
		
		printf("\n");
		row_element = 0;
		++row_max;/*increment row_max, then use*/
	}
}		
     	
















