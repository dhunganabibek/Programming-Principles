#ifndef vegetable_h
#define vegetable_h

//defining the structure
typedef struct vegetable{
  char name[20];             //name is vegetable
  double pricePerPound;      //price per pound
  double quantity;           //quantity
  struct vegetable *next;    //pointer to vegetable_t
}vegetable_t;

//function prototype for createLinkedList
/*
NAME:createLinkedList
INPUT PARAMETERS:int num
RETURN TYPE:vegetable_t
SPECIFICATION: This function takes int num and create the linked list of size num.
               This function also store the vegatable chain in tbat linked list.
*/
extern vegetable_t* createLinkedList(int num);

//function prototype for diaplayLinkedList
/*
NAME:displayLinkedList
INPUT PARAMETERS:vegetable_t* v
RETURN TYPE:vegetable_t
SPECIFICATION: This function takes address of first block of linked list
                and display all the element of linked list.
*/
extern void displayLinkedList(vegetable_t* v);

//function prototype for findLinkedList
/*
NAME:findLinkedList
INPUT PARAMETERS:vegetable_t *v
RETURN TYPE:int
SPECIFICATION:This function takes input from the user search that input in inventory. 
              And, update the inventory as user input.
*/
extern int findLinkedList(vegetable_t *v);


//function prototype for findLinkedList
/*
NAME:refundLinkedList
INPUT PARAMETERS:vegetable_t *v
RETURN TYPE:int
SPECIFICATION:This function takes input from the user search that input in inventory. 
              And, update/refund the inventory as user input.
*/
void refundLinkedList(vegetable_t *v);

#endif