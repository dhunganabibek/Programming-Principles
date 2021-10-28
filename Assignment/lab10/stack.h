
//defining the structure
struct Stack
{
    int head;
    int size;
    int* chain;
};

//type aliasing the structure Stack with name stack.
typedef struct Stack Stack;

/*
NAME:createStack
INPUT: int
RETURN TYPE:Stack*
SPECIFICATION: This function takes int as input argument and return Stack pointer.
*/
extern Stack* createStack(int size);


/*
NAME: isEmpty
INPUT:Stack*
RETURN TYPE: int
SPECIFICATION: This function takes Stack* and check if the linked list is empty
*/
extern int isEmpty(Stack* stack);


/*
NAME:pop
INPUT:Stack*
RETURN TYPE:int
SPECIFICATION:This function takes Stack* as input and return the top element of the stack
*/
extern int pop(Stack* stack);


/*
NAME:push
INPUT:Stack*, int
RETURN TYPE:void
SPECIFICATION: This function takes Stack* and int. Then it pushes that int at top of linked list.
*/
extern void push(Stack* stack,int op);
