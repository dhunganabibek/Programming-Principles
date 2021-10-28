/*
FILENAME: lab7.c
AUTHOR:Bibek Dhungana
DATE:3/23/2021
SPECIFICATION: This program takes input from the txt file, read the content of that txt file
              in array of structure and search the input string in that array  and print out
              the information in readable format.
PURPOSE: FOR CS 1412 Spring 2021
*/


//importing all the required libraries
#include <stdio.h>
#include <string.h>

// defining the file name.
#define FILENAME "data.txt"

//defining the maximuym size
#define MAX_SIZE 30

//defining the structure mpn and using typedef to alias name it mpn
typedef struct {
  char positivesTriplet[6];
  int mostProbableNumber;
  int lowerBound;
  int upperBound;
} mpn_t;

//function prototype for load_Mpn_Table
int load_Mpn_Table(char filename[], mpn_t mpn_table[], int size);

//function prototype for search
int search(mpn_t mpn_table[], int size, char positivesTriplet[6]);

int main(void)
{
  //creating array for mpn entrees that is read from file data.txt
  mpn_t mpn_table[MAX_SIZE];

  //charcter array to store positives triplet
  char positivesTriplet[6];

  //declaring the required variables
  int size;
  int positionOnArray;
  mpn_t mpn;

  //calling the function
  size = load_Mpn_Table(FILENAME, mpn_table, MAX_SIZE);

  //getting positives triplet from the user
  printf("Please enter triplet combination:");
  gets(positivesTriplet);

  //while loop until positivesTriplet in NULL
  while (positivesTriplet != NULL) {
    //calling the search function
    positionOnArray = search(mpn_table, size, positivesTriplet);
    if (positionOnArray == -1) {
      printf("The positive Triplet combination can not be found\n");
    } else {
      mpn = mpn_table[positionOnArray];
      printf("For %s, MPN = %d; 95 percent of samples contain between %d and %d bacteria/100 ml.\n",
      mpn.positivesTriplet, mpn.mostProbableNumber, mpn.lowerBound, mpn.upperBound);
    }
    printf("Please enter triplet combination:");
    gets(positivesTriplet);
  }

  return 0;
}

/*
NAME:load_Mpn_table
INPUT PARAMETERS:char[] (filename) ,
                 mpn_t[] (array of mpn_t structure)
                 int (size)
OUTPUT PARAMETERS:N/A.
RETURN TYPE: int (actual array size)
SPECIFICATION: Thus function takes  parameters as the input
               file, the mpn_table array and its maximum size.
                It  opens the file,fills the mpn_table array,and closes the file.
               Then it returns the actual array size as the function result.
*/
int load_Mpn_Table(char filename[], mpn_t mpn_table[], int size){
  FILE *inputFilePointer;
  int i;
  int inputResult;
  mpn_t mpn;
  
  //opening file in read mode
  inputFilePointer = fopen(filename, "r");

  i = 0;
  inputResult = fscanf(inputFilePointer, "%[^,],%d,%d,%d\n", mpn.positivesTriplet, &mpn.mostProbableNumber,
  &mpn.lowerBound, &mpn.upperBound);
  mpn_table[i] = mpn;

  while (inputResult == 4) {
  i++;
  if (i >= size) {
  printf("**Warining: some data has been ignored.\n");
  break;
  }
  inputResult = fscanf(inputFilePointer, "%[^,],%d,%d,%d\n", mpn.positivesTriplet, &mpn.mostProbableNumber,
  &mpn.lowerBound, &mpn.upperBound);
  mpn_table[i] = mpn;
  }

  fclose(inputFilePointer);

  return i;
}

/*
NAME:search
INPUT PARAMETERS: mpn_t[] (array of structure mpn_t
                int (size)
                char[] : string representing combination of positive triplet.
                   
OUTPUT PARAMETERS:N/a
RETURN TYPE:int (return subscript of matching combination of positive of structure.
                and 1 if not found.
SPECIFICATION: This function takes mpn_table array, its actual size, and a target string                      representing a combination-of-positives triplet. Returns the subscript of the                  structure whose combination-of-positives component matches the target or 1 if not              found.

*/
int search(mpn_t mpn_table[], int size, char positivesTriplet[6]){
  int i;

  for (i = 0; i < size; i++) {
  if (strcmp(mpn_table[i].positivesTriplet, positivesTriplet) == 0) {
  return (i);
  }
  }

  return (-1);
}

