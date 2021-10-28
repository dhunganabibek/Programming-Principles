//including all the required libraries
#include "vegetable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//define macro
#define SIZE 20

//implementing displayLinkedList to display all the vegetables info
  void displayLinkedList(vegetable_t* v){
    printf("\nThe inventory is as follow:\n");
    printf("---------------------------------------\n");
    while(v!= NULL){
       printf("Vegetable Name:%s\n",v->name);
       printf("pricePerPound:%.2f\n",v->pricePerPound);
       printf("Quantity:%.2f\n\n\n",v->quantity);
       v = v->next;
    }
    printf("---------------------------------------\n");
  }

 //implementing createLinkedList function
  vegetable_t* createLinkedList(int num){

    //taking the input and creating the linked list
    int i;                      //counter variable
    vegetable_t *first = NULL;  //point to the first vegetable_t structure in linked list
    vegetable_t *last = NULL;   //point to the last vegetable_t structure in linked list
    vegetable_t *temp;          //temp pointer variable to build linked list
    
    //creating first node in linked list
    first = (vegetable_t*)malloc(sizeof(vegetable_t));
    printf("Enter the vegetable name, price per pound and quantity separated by space\n");
    scanf("%s %lf %lf", first->name, &first->pricePerPound, &first->quantity);
    first->next = NULL;
    last = first;
    
    //adding remaining node to linked list
    for (i = 1; i < num; i++){
      temp = (vegetable_t*)malloc(sizeof(vegetable_t));
      printf("Enter the vegetable name, price per pound and quantity separated by space\n");
      scanf("%s %lf %lf", temp->name, &temp->pricePerPound, &temp->quantity);
      temp->next = NULL;
      last-> next = temp;
      last = temp;
    }
    return first;

  }


  //implementing the function findLinkedList
	int findLinkedList(vegetable_t *v){
	//creating temp variable to store the address
	vegetable_t* temp = v;

  //initializing the variables
  int totalItemBought = 0;
  char item[SIZE];
  char mystr[SIZE] = "yes";
  double weight;
  double total = 0.0;
  double grandTotal= 0.0;

  //variable to track item name and its quantity
  char itemBought[SIZE][SIZE];
  double quantityBought[SIZE];
 
  //using strcmp function to check the user input
  while(strcmp(mystr,"yes") == 0){
		//taking user from input
    printf("what do you want to sell to customer?");
    scanf("%s",item);
    printf("How much pounds do you want?");
    scanf("%lf",&weight);
    
		//checking if v is null
		v = temp;
    while(v!= NULL){
      if(strcmp(v->name,item) == 0 ){
				//building the array to print the receipt
        strcpy(itemBought[totalItemBought],item);
        quantityBought[totalItemBought] = weight;
        totalItemBought++;
				printf("Total item sold:%d",totalItemBought);


				//calculating the grand total price  
        v->quantity = v->quantity - weight;
        total = weight * v->pricePerPound;
        grandTotal = grandTotal + total;
      }
			//moving to next block.
      v = v->next;
    }
		//taking user from the input
    printf("\nDo you want to buy anything else?Enter 'yes' or 'no':");
    scanf("%s",mystr);
	}
 
  //printing out the receipt
  printf("\nYour receipt is\n");
	printf("\n---------------------BILL----------------------------------------\n");
	printf("\n-----------------------------------------------------------------\n");
	printf("Items                            Pounds\n");

	for (int j = 0; j < totalItemBought; j++){
		printf("%s                             %.2f\n",itemBought[j],quantityBought[j]);
	}
	printf("\nGRAND TOTAL:%.2f\n",grandTotal);
	printf("\n-----------------------THANK YOU----------------------------------\n");
	printf("\n------------------------------------------------------------------\n");
	return 1; 
}


void refundLinkedList(vegetable_t *v){
		//creating temp variable to store the address
		vegetable_t* temp = v;

		//initializing the variables
		char item[SIZE];
		char mystr[SIZE] = "yes";
		double weight;
		
		//using strcmp function to check the user input
		while(strcmp(mystr,"yes") == 0){
			//taking user from input
			printf("what do you want to as refund?");
			scanf("%s",item);
			printf("How much pounds do you want to refund?");
			scanf("%lf",&weight);
			
			//checking if v is null
			v = temp;
			while(v!= NULL){
				if(strcmp(v->name,item) == 0 ){
					//refund operation
					v->quantity = v->quantity + weight;
				}
				//moving to next block.
				v = v->next;
			}
			//taking user from the input
			printf("\nDo you want to refund anything else?Enter 'yes' or 'no':");
			scanf("%s",mystr);
	}

}

 

