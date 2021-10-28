/*
//AUTHOR: Bibek Dhungana
//FILENAME: Lab2.c
//SPECIFICATION: program that asks the user to enter a temperature in Fahrenheit 
and convert the temperature to Kelvin
//FOR: CS 1412 Programming Principles 2 Section 504
*/

//importing all the required libaries
#include <stdio.h>

/*function prototype for fahrenheitToKelvin function*/
double fahrenheitToKelvin(double fahrenheitTemp);

int main(void) {
    /*initialing the variables to store kelvin temperature and fahrenhiet temperature*/
    double kelvinTemp;    
    double fahrenheitTemp;

    /*taking fahrenheit temperature from user as input*/
    printf("Please enter the temperature in Fahrenheit:");
    scanf("%lf",&fahrenheitTemp);

    /*calling the fahrenheitToKelvin function*/
    kelvinTemp = fahrenheitToKelvin(fahrenheitTemp);

    /*Printing the output to the user*/
    printf("The temperature in Kelvin is %.2f\n",kelvinTemp);
    
 

return 0;
}

/*
//function declearation of fahrenheitToKelvin
//NAME: fahrenheitToKelvin
//INPUT: Double (temperature in fahrenheit)
//OUTPUT: Double (temperature in Kelvin)
//SPECIFICATION:function to convert fahrenheit to Kelvin 
*/
double fahrenheitToKelvin(double fahrenheitTemp){
    double kelvin;
    kelvin =  (fahrenheitTemp - 32.0) * (5.0/9.0) + 273.5;
    return kelvin;
}
