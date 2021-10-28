//This same problem can be done easier with array if suppose maaximum 
// number of element in the array is constant(like 100 or 50)

/*for Visual stusio 2019 to use scanf with out error*/
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

/*defining maximum size for the array*/
#define ARRAYSIZE 50




int main(void) {

	/*Initializing all the required variables*/
	int myArray[ARRAYSIZE];
	int arrayLength;

	/*Printing the information to the user*/
	printf("Print all unique elements of an array:\n");
	printf("------------------------------------------\n");

	/*asking the user to enter the length of array*/
	printf("Input the number of elements to be stored in the array:");
	scanf("%d", &arrayLength);



	/*taking input from the user and storing in the array myArray*/
	printf("Input %d elements in the array:\n", arrayLength);
	for (int i = 0; i < arrayLength; i++) {
		printf("element-%d:", i);
		scanf("%d", &myArray[i]);

	}

	/*Printing out the unique element of the array*/
	printf("The unique elements found in the array are:\n");
	for (int i = 0; i < arrayLength; i++)
	{
		int repeatedCounter = 0;
		for (int j = 0; j < arrayLength + 1; j++)
		{
			/*search for the duplicate*/
			if (i != j) {

				/*checking if duplicate exists*/
				if (myArray[i] == myArray[j])
				{
					repeatedCounter += 1;
				}
			}
		}
		/*Printing out the unique element in the array*/
		if (repeatedCounter == 0)
		{
			printf("%d ", myArray[i]);
		}
	}

	return (0);
}