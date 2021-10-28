/*
AUTHOR: Bibek Dhungana
FILENAME: Lab2.c
SPECIFICATION: This program takes altitutue of satellite as input and 
output orbital speed of the satellite.
FOR: CS 1412 Programming Principles 2 Section 504
*/

/*importing all the required libaries*/
#include <stdio.h>
#include <math.h>

/*function prototype of orbitalVelocity*/
double orbitalVelocityCalculator(double gravitationalConstant , double totalMass, double orbitRadius);
     



int main(void) {
  
/*defining all the constant for the program*/
/*value of universal gravitational constant*/
const double gravitationalConstant = (6.673E-11); 

 /*value of mass of earth*/     
const double totalMass = (5.98E24);  

/*value of radius of earth*/    
const double radiusOfEarth = (6.37E6); 

 

  /*initializing all the required variable*/ 
  double satelliteAltitude;
  double orbitalVelocity;
  double orbitRadius;
  int roundedOrbitalVelocity;

   printf("Orbital speed Calculator\n");

  /*Taking input of altitude of satellite in km*/
  printf("Enter the altitude of the Satellite in km:");
  scanf("%lf",&satelliteAltitude);
 
  /*calculating the orbit radius in m*/
  orbitRadius =  radiusOfEarth + (satelliteAltitude * 1000);


  
  /*calling the orbital VelocityFunction*/
  orbitalVelocity = orbitalVelocityCalculator(gravitationalConstant, totalMass, orbitRadius);

  /*using ceil() function to round orbitalVelocity*/
  roundedOrbitalVelocity = ceil(orbitalVelocity);
  
  /*Printing out the result to user*/
  printf("The orbital speed of the satellite is %d m/s\n",roundedOrbitalVelocity);
  
  
  return 0;
}

/*
//function defination of orbital velocity
NAME: orbitalVelocity
INPUT: Gravitational constant (G), Mass of earth (M), Radius (r)
OUTPUT: orbitalVelocity(v)
SPECIFICATION: This function takes Gravitational constant (G), Mass of earth (M),                  Radius (r) as input perform following formula:
              velocity = √ (gravitational constant * total mass / orbit radius)
               and return oritalvelocity of the satellite
*/

double orbitalVelocityCalculator(double gravitationalConstant , double totalMass, double orbitRadius){

  return sqrt((gravitationalConstant * totalMass)/orbitRadius );
}

