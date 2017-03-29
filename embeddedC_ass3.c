/**********************************************************************
48430 Embedded C - Advanced Assignment
Name:Menka Mehta
Student ID:12195032
Date of submission:
A brief statement on what you could achieve (less than 50 words):


A brief statement on what you could NOT achieve (less than 50 words):


**********************************************************************/

/**********************************************************************
List of header files - you may not use any other C libraries.
List structs - you may define struct node only.
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>

/* struct node - contains
	c - a char to store an input character
	next - pointer to the next struct node or NULL (this pointer can be
	       used to construct the linked list)
Note: end of the list is indicated by a NULL pointer.
*/
struct node{
	char c;
	struct node * next;
};

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
void openMenu(struct node * head);
void addToLinkedList(struct node * head, char string[]);
void printmenu();
void printlinkedlist(struct node * head);
int delhead(struct node ** head);
int delvowels(struct node ** head);
char isvowel(char c);

int readValidInt();
char containsStringAtStart(char [], char []);
void readString(char[], int, FILE*);
void emptyLine(char string[],int size,FILE*stream);

/**********************************************************************
Main
**********************************************************************/
int main(int argc, char *argv[]){
	/*checks that the user parsed words when the program was executed*/
	/*if not the program is closed*/
	if(argc==1){
		printf("Parse a sentence\n");
		return 1;
	}
	/*initialised the linked list to store the characters in*/
	struct node * head = NULL;
	/*allocates the pointer to a block of memory*/
	head = malloc(sizeof(struct node));
	/*sets the charcter to a null terminator*/
	head->c = '\0';
	/*sets the node to point to nothing*/
	head->next = NULL;
	/*sets up a counter to step through each argument sent in argv*/
	int i = 1;
	/*adds each word into the linked list*/
	while(i<argc){
		addToLinkedList(head,argv[i]);
		i++;
	}
	/*opens the menu to let the user interact with the linked list*/
	openMenu(head);
	return 1;	
}

void openMenu(struct node * head){
	/*an integer to hold the user input*/
	int choice = 0;
	/*the menu will loop until the user enters 4 to exit*/
	while(choice != 4){
		/*prompts the user with menu options*/
		printmenu();
		/*prompts the user to enter input*/
		printf("Enter your choice>");
		/*reads the next line of input and stores it in choice if the input is valid*/
		choice = readValidInt();
		switch(choice){
			/*prints the linked list if the user enters '1'*/
			case 1: printlinkedlist(head);break;
			/*deletes the first character is the user enters 2*/
			case 2: if (delhead(&head))
						printf("Pop failed.\n");
					break;
			/*removes all the vowels if the user enters 3*/
			case 3 : if(delvowels(&head))
						printf("Del failed.\n");
					 break;
		    /*does nothing if the user wants to exit the program*/
			case 4 : break;
			/*prints an error message if other input is entered*/
			default : printf("Invalid choice.\n");
		}
	}
	
}

/**********************************************************************
  Adds the specified string to the end of a linked list
***********************************************************************/
void addToLinkedList(struct node * head,/*the head of the linked list */
				     char string[]){/*the string to add*/
	/*holds the head of the linked list*/
	struct node * temp = head;
	/*holds a node that will step through the list*/
	struct node * current = head;
	/*a counter that steps through each character of the string*/
	int i = 0;
	/*moves to the end of the list*/
	while(current->c != '\0'){
		current = current->next;
	}
	/*adds each character in the string to the list adding new nodes */
	while(string[i] != '\0'){
		/*copies the current character to a node*/
		current->c = string[i];
		/*assignes memory to the next node for the next charcetr*/
		current->next = malloc(sizeof(struct node));
		/*steps through to the next node*/
		current = current->next;
		i++;
	}
	/*adds a null terminating character to the end of the list*/
	current->c = '\0';
	current->next = NULL;
	/*insures all node 'head' still points to the firs character*/
	head = temp;
}

/**********************************************************************
Print 2 empty lines followed by the choices menu. Do NOT change this
function definition.
**********************************************************************/
void printmenu(void){
	printf("\n\n"
		"1. print input arguments (no spaces)\n"
		"2. remove first character\n"
		"3. remove vowels\n"
		"4. exit program\n");
}

/**********************************************************************
Print all nodes in a linked list of struct node type. Follow the print
format of the executable provided. Pass ONLY ONE PARAMETER to this
function.
**********************************************************************/
void printlinkedlist(struct node *head){
	/*creates a node to step through each charcater in the list*/
	struct node * current = head;
	/*prints a character and then moves current to point to
	  the next node until the last character is reached*/
	while(current->c != '\0'){
		printf("%c", current->c);
		current = current->next;
	}
	printf("\n");
}


/**********************************************************************
Delete the head (first node) of a linked list of type struct node. Pass
ONLY ONE PARAMETER to this function.
return 0 - if the head of the linked list could be deleted successfully
return 1 - otherwise
**********************************************************************/
int delhead(struct node ** head){
	/*checks if the head is the only charcter and returns one
	  to indicate the head could not be removed*/
	if((*head)->c == '\0')
		return 1;
	/*changes the head to point to the next node loosing the first character*/
	*head = (*head)->next;
	return 0;
}

/**********************************************************************
Delete the vowels (a,e,i,o,u) in a sentence. Pass ONLY ONE PARAMETER to
this function.
return 0 - if all vowels were removed successfully
return 1 - otherwise
**********************************************************************/
int delvowels(struct node ** head){
	/*returns 1 if the linked list is empty*/
	if((*head)->c == '\0')
		return 1;
	/*checks if the head is a vowel and 
	  keeps removing the head until the head is not a vowel*/
	while(isvowel((*head)->c)){
		delhead(head);
	}
	/*creates a new node that will step through the linked list*/
	struct node * current = (*head);
	while(current->c != '\0'){
		/*checks if the next character is a vowel*/
		if(isvowel(current->next->c)){
			/*changes next to point to the character after the next*/
			current->next = current->next->next;
		}
		else{
			/*moves to the next node*/
			current = current->next;
		}
	}
	return 0;
}

/**********************************************************************
 returns 0 if the specified character is a vowel
 otherwise returns 1
 *********************************************************************/
char isvowel(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}
/**********************************************************************
 reads a string from the user and returns the input as a integer
 if the input is not an integer the value -1 is returned
**********************************************************************/
int readValidInt(){
	/*holds the string the user enters*/
	char inputAsString[1024];
	/*holds the user input as an integer*/
	int inputAsInt;
	/*holds the integer format as a string to check for errors*/
	char stringConverted[1024];
	/*reads in a line of user input as a string*/
	readString(inputAsString, 1024, stdin);
	/*converts input into an integer*/
	inputAsInt = atoi(inputAsString);
	/*converts the new integer back into a string*/
    snprintf(stringConverted, 1024, "%d", inputAsInt);
    /*checks if the converted integer matches the use input*/
	if(containsStringAtStart(inputAsString, stringConverted))
		return inputAsInt;
	return -1;
}

/**********************************************************************
 Checks if  the sequence of characters in the first string matches 
 the sequence at the start of the second string
 returns 1 if one string contain the other
 returns 0 otherwise
**********************************************************************/
char containsStringAtStart(char first[],/*the first string*/
                           char second[]){/*the second string*/
                           
	/*A counter to increment through each character in the strings*/
	int i =0;
	/*checks if each character in first is in second*/
	while(first[i] != '\0'){
		/*exits function and returns false if there is a mismatch*/
		if(first[i] != second[i])
			return 0;
		i++;
	}
	/*returns true if there is a match*/
    return 1;
}

/**********************************************************************
 Reads a line from the specified stream and returns a string containing
 a line of input. 
**********************************************************************/
void readString(char str[],/*the string the input is to be stored in*/
                int size,/*the number of elements in str*/
			    FILE * stream){/*the strem the input is read from*/
	/*holds a line of input as a string*/
	char inputString[1024];
	/*stores the next line of input into the string*/
	fgets(inputString, 1024, stream);
	/*consumes any remaining characters in the line*/
	emptyLine(inputString,size,stream);
	/*a counter to step through each character of the string str*/
	int i;
	/*copies inputString into str upto it's max length.*/
	for(i=0; i<size;i++){
		/*cuts the string off at any newline characters*/
		if(inputString[i] == '\n')
			str[i] = '\0';
		else
			str[i] = inputString[i];
	}
	/*ends the string with a NUL terminator*/
	str[size-1] = '\0';
}
/**********************************************************************
Checks if the specified string contains a newline. If not then the rest
of the line in the specified stream will be consumed
**********************************************************************/
void emptyLine(char string[],/*the string that holds the last input 
                               from a stream*/
               int size,     /*the size of the string*/
			   FILE*stream){ /*the stream inputting from from*/
	/*a flag to check if the '\n' character has been consumed*/
	char endLine=0;
	/*stores any additonal characters to be consumed*/
	char temp[size];
	/*a counter to step through each character of the strings*/
	int i=0;
	/*checks if the string alrady contains the newline character*/
	while(string[i] != '\0'){
		if(string[i] == '\n')
			endLine = 1;
		i++;
	}
	/*keeps reading from the stream until the newline character if read*/
	while(!endLine){
		/*stores the next byte of characters in a temperary string*/
		fgets(temp,size,stream);
		/*resets counter to loop through the string again*/
		i=0;
		/*checks the new string for the endline character*/
		while(temp[i] != '\0'){
			if(temp[i] == '\n')
				endLine = 1;
			i++;
		}
	}
}
