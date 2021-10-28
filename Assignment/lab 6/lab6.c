/*to use scanf in Visual studio with our error*/
#define _CRT_SECURE_NO_WARNINGS

/*
AUTHOR: BIBEK DHUNGANA
DATE: MARCH 12, 2021
FILENAME: LAB6OUT.C
SPECIFICATION:This code takes input from the user and print yes if the input is palindrome
              and no if the input is not palindrome.
FOR: CS-1412-504 
*/

/*including all the required libraries*/
#include <stdio.h>
#include <string.h>

/*defining maximum size for the array*/
#define SIZE 100

/*declearing the function prototype for isPalindromeHelper*/
int isPalindromeHelper(char myStr[], int start, int end);

/*function prototype for isPallindrome*/
int isPalindrome(char myStr[]);


int main(void) {
    /*Initializing all the required variables*/
    char myString[SIZE];
    int is_palindrome;
    int length;
    
    /*reading input from the user*/
    printf("Enter the text:");
    gets(myString);

    /*finding length of string*/
    length = strlen(myString);

    /*calling is palindrome function*/
    is_palindrome = isPalindromeHelper(myString, 0,length - 1);

    /*printing out th result*/
    if (is_palindrome == 1) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }


}


/*
* NAME: isPalindrome
* INPUT ARGUMENTS: char[]
* RETURN TYPE: int
* SPECIFICATION: This function takes the character array.It return 1 if it is palindrome
*                 and return 0 is it is not palindrome.
*/
int isPalindrome(char myString[]) {

    int length = strlen(myString);

    if (length == 0) {
        return 1;
    }
    else { 
        return isPalindromeHelper(myString, 0, length - 1);
    }

}




/*
* NAME: isPalindromeHelper
* INPUT ARGUMENTS: char[](myString),int(start index),int(end index)
* RETURN TYPE: int
* SPECIFICATION: This function takes the character array,start index and end index.It return 1 if it is palindrome
*                 and return 0 is it is not palindrome.
*/
int isPalindromeHelper(char myString[], int start, int end) {
    if (start == end) {
        return 1;
    }
    if (myString[start] != myString[end]) {
        return 0;
    }
    if (start < end) {
        return isPalindromeHelper(myString, start + 1, end - 1);
    }

    return 1;
    
}

