//including all the required libraries
#include <stdio.h>
#define SIZE 100
int main() {

   char myString[SIZE];
   
   //asking input from the user
   printf("Enter string you want to modify: ");
   fgets(myString, sizeof(myString), stdin); 

    //running loop to access each character
   for (int i = 0, j; myString[i] != '\0'; ++i) {

      //checking if chracter is except alphabet
      while (!(myString[i] >= 'a' && myString[i] <= 'z') && !(myString[i] >= 'A' && myString[i] <= 'Z') && !(myString[i] == '\0')) {
         for (j = i; myString[j] != '\0'; ++j) {

            //removing non alphabet character
            myString[j] = myString[j + 1];
         }
         
         myString[j] = '\0';
      }
   }

   //printing out the string to the user
   printf("Final modified String: ");
   puts(myString);
   return 0;
}