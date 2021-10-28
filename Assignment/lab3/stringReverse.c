/*
NAME: Bibek Dhungana
FILE NAME: stringReverse.c
SPECIFICATION: This program take the string as user input and reverse the string and print it
FOR: CS 1412 Programming Principles 2 Section 504
*/

/*including all the required libarary*/
#include <stdio.h>

/*defining macro for size of array*/
#define MAX_CHAR_ARRAY 50

/*function prototype for string Length*/
int stringLength(char *);

/*function prototype for stringReverse*/
void stringReverse(char *, int );



int main(void){
    /*initializing all the required variable*/
    char myString[MAX_CHAR_ARRAY];
    int lengthOfString;
    
    /*taking string input from the user and assigning it to myString*/
    printf("Please enter the string upto 50 character:");
    fgets(myString,MAX_CHAR_ARRAY,stdin);

    /* calling lengthOfString function to calculate the length of  char array*/
    lengthOfString = stringLength(myString);
    
    /*calling the stringReverse function to reverse the given string*/
    stringReverse(myString,lengthOfString);

    /*printing the reversed string to the user*/
    printf("The reversed string is:%s\n",myString);
    return 0;
}

/*
NAME:stringLength
INPUT: array of character char (char [])
OUTPUT: return length of that character array (int)
PRECONDITION: The char array must be greater than 0.
POSTCONDITION: do not change that original array. 
SPECIFICATION: This function take char array and return the length of that array.
*/
int stringLength(char* myString){
   int i = 0;
   int length = 0;
   /*using while loop the find the length of the character array*/
   while(myString[i]){
       length++;
       i++;
   }
   return length;
}




/*
NAME:stringReverse
INPUT: takes character array (char []) and length of the array.(int)
OUTPUT: Do not return anything. It change the original array.
PRECONDITION: The length char array and length must be equal to zero.
POSTCONDITION: The original array is changed. 
SPECIFICATION: This function take character array and length of that array and return the char array in reverse.
*/
void stringReverse(char* myString, int length){
    for(int i = 0; i < length/2; i++){
        char temp;    /*temporary char variable to swap the character*/

        /*swaping character by character to reverse the string*/  
        temp = myString[i];
        myString[i] = myString[length -i-1];
        myString[length - i -1] = temp;
    }
}



/*alternative function for reversing the string*/
/*
NAME:stringReverse1
INPUT: takes character array (char []) and length of the array.(int)
OUTPUT: Do not return anything. It change the original array.
PRECONDITION: The length char array and length must be equal to zero.
POSTCONDITION: The original array is changed. 
SPECIFICATION: This function take character array and length of that array and return the char array in reverse.
*/

void stringReverse1(char * myString, int length){
    /*pointer to begining and end of the string*/
    char* begin;
    char* end;

    /*pointing begin to begining of string*/
    begin = myString;

    /*pointing end to end of the string*/
    end = myString + (length -1);

    /*using loop to reverse the string*/
    for (int i = 0; i < length/2; i++){
        char temporary;
        /*swaping the character*/
        temporary = *end;
        *end = *begin;
        *begin = temporary;
        
        /*increasing begin pointer by one unit*/
        begin = begin + 1;
        /*decreasing end pointer by one unit*/
        end = end -1;
    }


}