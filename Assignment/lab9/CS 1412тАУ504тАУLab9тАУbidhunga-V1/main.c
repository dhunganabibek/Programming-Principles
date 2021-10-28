/*
AUTHOR: BIBEK DHUNGANA
DATE:APRIL 9, 2021
FILENAME:LAB9
SPECIFICATION:This program manage inventory for small vegetable store owner.The program takes input
              from the customers and generates a bill. After each sale the program also increments
							/decrementsinventory
FOR:CS 1412 
*/

//including all the required libarary
#include <stdio.h>
#include "vegetable.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//defining macro 
#define SIZE 20

int main(void){
	//initializing all the required variables.
  int num;
  char input;
  vegetable_t *myLinkedList;
  
	//while loop
  while(true){
    //asking user for what operation they wanted to perform
    printf("Enter 'a' to add inventory, 's' to sell product and 'd' to display status of inventory, 'r' for refund and 'q' to quit\n");
    fgets(&input, 50, stdin);
  
	  //if input is add
    if(tolower(input) =='a') {
      //asking info with the user
      printf("\nHow many vegetables you want to enter to your inventory?");
      scanf("%d",&num);

      //creating linked list of size num and storing base address at myLinkedList
      myLinkedList = createLinkedList(num);
    }
    
		//input is d
    if (tolower(input) =='d'){
      //printing out the entire element of linked list.
      displayLinkedList(myLinkedList);
    }

		//input is d
    if (tolower(input) =='r'){
      //printing out the entire element of linked list.
      refundLinkedList(myLinkedList);
    }
    
		//if input is s
    if (tolower(input) =='s'){
      //sell the product 
      findLinkedList(myLinkedList);
		}
    
		//if input is q
    if (tolower(input) =='q'){
      //sell the product 
      printf("\nThank you for your business\n");
      break;
		}
	}
  return 0;
}