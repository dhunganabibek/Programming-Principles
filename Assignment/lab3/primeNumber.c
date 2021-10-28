/*
AUTHER: Bibek Dhungana
FILE NAME: primeNumber.c
SPECIFICATION: This program takes input from the user and print all the prime number upto that number
FOR: CS 1412 Programming Principles 2 Section 504
*/

/*importing all the required libraries*/
#include <stdio.h>

/* function prototype of isPrime*/
int isPrime(int);

/*function prototype of allPrime*/
void allPrime(int number);

int main(void){
    
    /*initializing all the required variables*/
    int numberEntered;

    /*Printing info about the program and taking input from the user and storing in variable*/
    printf("This program generate all the prime number upto the given input\n");
    printf("Please enter the positive number:");
    scanf("%d", &numberEntered);

    //calling the allPrime function to print all the prime number upto given input
    allPrime(numberEntered);
    return 0;
}



/*
Name: isPrime
INPUT: integer number n
OUTPUT: return 1 is number is prime and 0 is number is not prime
PRECONDITION: The input number must be greater than or equal to 2.
POSTCONITION: 
SPECIFICATION:This function takes an integer and check if the number is prime.
*/
int isPrime(int number){
    /*The number is prime if an only if it has only 2 dividor (1 and itself) If modulus is zero
    when divided by any number from 2 to n -1, the number is not prime.so return 0*/
    for (int i = 2; i <= number - 1; i++ ){
       if (number % i == 0){
           return 0;
       }
    }
    return 1; 
}

/*
Name: allPrime
INPUT: integer n 
OUTPUT: print all the prime number upto integer n
PRECONDITION: The number must be greater than or equal to 2.
POSTCONITION: It print the all the prime number upto n in colsole. 
SPECIFICATION: This function takes integer as input and print all the prime number upto n
*/
void allPrime(int number){
    for (int i = 2; i <= number; i++){
        /*Print the number is the number is prime*/
        if(isPrime(i) == 1){
            printf("%d\n",i);
        }

    }

}













