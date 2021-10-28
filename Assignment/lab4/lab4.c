/*for Visual stusio 2019 to use scanf with our error*/
#define _CRT_SECURE_NO_WARNINGS
/*
* 
* AUTHOR: Bibek Dhungana
* FILENAME: lab4.c
* DATE: 2/26/2021
* SPECIFICATION: This program prints out the unique numbers in a array.
* FOR: CS 1412 Programming Prnciple 2 Section 504
*/

/*Importing all the required library*/
#include <stdio.h>
#include <stdlib.h>



/*Function prototype for uniqueElement array*/
int* uniqueElementArray(int* myArray, int length, int* finalArrayLength);

int main(void) {

	/*Initializing all the required variables*/
	int arrayLength;
	int uniqueArrayLength;

	/*Printing the information to the user*/
	printf("Print all unique elements of an array:\n");
	printf("------------------------------------------\n");

	/*asking the user to enter the length of array*/
	printf("Input the number of elements to be stored in the array:");
	scanf("%d",&arrayLength);

	/*Dynamically allocating the memory for storing element in the array*/
	int* givenArray = (int*)calloc(arrayLength, sizeof(int));

	/*taking input from the user and storing in the array myArray*/
	printf("Input %d elements in the array:\n", arrayLength);
	for (int i = 0; i < arrayLength; i++) {
		printf("element-%d:", i);
		scanf("%d",(givenArray + i));

	}

	/*calling unique element function to get unique element array from given array*/
	int* finalArray = uniqueElementArray(givenArray, arrayLength,&uniqueArrayLength);

	
	
	
	/*Printing out the unique element of the array*/
	printf("The unique elements found in the array are:\n");
	for (int i = 0; i < uniqueArrayLength; i++) {
		printf("%d ", *(finalArray + i));
	}
	printf("\n");

	return 0;
}

/*
NAME: UniqueElementArray
FORMAL ARGUMENTS: myArray (pointer to array)
                  length (length of that array) 
				  uniqueArrayLength (pointer to the integer)
RETURN TYPE: int* (address to the integer array)
POSTCONDITION: The array reurn the address of uniqueElementArray formed
               by dyanmic memory allocation.
SPECIFICATION: This function uniqueElementArray takes the original array and return
               array with unique element. Since, we do not know size of array until
			   user input the size. We allocate the memory using dynamic memory
			   allocation.


*/
int* uniqueElementArray(int* myArray, int length, int* uniqueArrayLength) {

	/*dynamically allocating memory for new array*/
	int* uniqueArray = (int*)calloc(length, sizeof(int));
	int arrayLength = 0;
	
	
	
	/*using for loop to access each eleement in the array*/
	for (int i = 0; i < length; i++) {

		/*variable to store number of occurance*/
		int counter = 0;

		/*if element is already present in uniqueArray. Do not add uniqueArray
		add if the element is not present*/
		for(int j = 0; j < length; j++){
			 
			/*checking if element is unique*/
			if (i != j) {
				if (*(myArray + i) == *(myArray + j)) {
					counter = counter + 1;
				}
			}

		}
	    /*Performing the following operation if the operation is unique*/
		if (counter == 0) {
			
			*(uniqueArray + arrayLength) = *(myArray + i);
			arrayLength++;


		}
	}
    /*passing the length of new array with unique element to main function*/
	*(uniqueArrayLength) = arrayLength;
return uniqueArray;
}













