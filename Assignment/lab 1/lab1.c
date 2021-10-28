//AUTHOR: Bibek Dhungana
//FILENAME: Lab1.c
//SPECIFICATION: This program calculate the tip and total amount each person should pay for the given bill.
//FOR: CS 1412 Programming Principles 2 Section 504

//importing all the required libary
#include <stdio.h>

//function prototype for tipCalculator
void tipCalculator(double totalBill, int tipPercent, int numberOfPeople);

int main(void){
    printf("TIP CALCULATOR\n");

    //initialing the required variables
    double totalBill;
    int tipPercent;
    int numberOfPeople;
    
    
    //taking total bill amount input;
    printf("Enter the bill: ");
    scanf("%lf", &totalBill);

    //taking percentage of the tip as input
    printf("Enter the percentage of the tip: ");
    scanf("%d", &tipPercent);

    //taking number of people as input
    printf("Enter the number of the people: ");
    scanf("%d", &numberOfPeople);

    //calling the function to calculate the tips
    tipCalculator(totalBill, tipPercent, numberOfPeople);

    

    return 0;
}

//defining the function tipCalculator
//Name: tipCalculator
//INPUT: double totalBill, int tipPercent, int numberofPeople
//OUTPUT: void (just print the information as side effects)
// This function calculate the tips and total amount each person pay from the bill
void tipCalculator(double totalBill, int tipPercent, int numberOfPeople){
    double totalPerPerson;
    double tipPerPerson;
    double totalTips;

    totalTips = totalBill * (tipPercent/100.0);
    tipPerPerson = totalTips /numberOfPeople;
    totalPerPerson = (totalTips + totalBill)/numberOfPeople;

    printf("Tip per person is $%.2lf and total per person is $%.2lf\n",tipPerPerson, totalPerPerson);

    

}