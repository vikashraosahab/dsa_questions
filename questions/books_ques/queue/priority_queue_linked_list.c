// IMPLEMENTATION OF THE PRIORITY QUEUE BY USING LINKED LIST 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// ENUMERATION FOR HANDLING
typedef enum {
    EMPTY,
} VALID_MESS;
VALID_MESS ERROR_MESSAGE; // VARIABLE DECLARTION OF THE ENUMERATIONS STRUCTURE
// DECLARATION OF THE NODE STRUCTURE WITH RESPECTIVE DATA MEMBERS POINTER VARIALBES
// THIS IS DOUBLE LINKED LIST 
typedef struct node {
   int priority_tag; // PRIORITY TAG WITH HIGHTEST AND LOWEST VAUES
   char data; // ACTUALL DATA 
   struct node *next; // NEXT POINTER THAT POINTED TO NEXT NODE NULL AT THE END
   struct node *pre; // PRE POINTER THAT POINTED TO PRE NODE OR NULL AT THE BEGGINNING
} Node;
typedef struct { // LINKED LIST QUEUE
  Node *front; // FRONT POINTER VARIABLE FOR DELETION
  Node *rear; // REAR POINTER VARIALBE FOR INSERTION
}Queue;

// FUNCTION PROTOTYPES FOR MANIPULATION OF THE QUEUE DATA STRUCTURE
void create_queue (Queue *); // INITIALIZE REAR AND FRONT TO NULL 
void menu_bar (); // SHOW EACH MENU TO THE USER
void process_bar (Queue *); // PEROFRM EACH OPERATION ON USER INSTRUCTUIONS
int valid_int_input (); // METHOD CHECK THAT VALUE MUST RETURN IN INTEGER ONLY 
void enqueue (Queue *); // PERFROM INSERTION FROM THE REAR SIDE OF THE LINKED LIST BUT PRIORITY ALSO CHECKS
void dequeue (Queue *); // PERFORM DELETION OF THE NODE FROM THE FRONT SIDE OF THE LINKED LIST
int queue_empty (Queue *); // CHECK QUEUE IS EMPTY OR NOT EMPTY
int peek (Queue *); // GET NODE FROM THE PEEK OR REAR SIDE
int bottom (Queue *); // GET NODE FROM THE BOTTOM OR FRONT SIDE 
void display (Queue *); // FOR DISPLAYING EACH CHARACTER FROM THE LINKED LIST
// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[]) {
    Queue *q = (Queue *) malloc (sizeof (Queue)); // DYANMIC ALLOCATION 
    if (q != NULL) { // CHECK MEMORY ALLOCATED TO THE QUEUE OR NOT 
       create_queue (q); // INITIALIZE FRONT AND REAR POINTER TO THE NULL 
       int val; // VARIABLE DECLARATIONS
       while (1) {
         printf ("\nHello,World");
       }   
    }
    else { // SHOW MESSAGE WHEN DYNAMIC MEMORY NOT ALLOCATED TO THE QUEUE STRUCTURE
        printf ("\nError : ");
        printf ("\nThere is no dynamic memory allocation for the queue data structure : ");
    }
    return 0; // TERMINATION
}
void menu_bar () { // DISPLAY EACH INSTRUCTION MENU TO THE USER
  printf ("\n*********** MENU BAR *************");
  printf ("\n1 : Insertion \n2 : Deletion\n3 : Peek \n4 : Bottom \n5 : Display \n6 : Exit");
  printf ("\nEnter task only in number according to the user menu : ");
}
void create_queue (Queue *q) { // METHOD INITIALIZE FRONT AND QUEUE AS NULL 
    if (q == NULL) {
        q->front = q->rear = NULL; // INITIALIZATION NULL TO THE REAR AND FRONT WHERE THERE IS NO ELEMENT IN THE QUEUE
    }
}
int queue_empty (Queue *q) { // CHECK QUEUE IS EMPTY OR NOT EMPTY
  return (q->front == NULL && q->rear == NULL) ? EMPTY : !EMPTY; // WHEN FRONT AND REAR ARE NULL THE RETURN EMPTY OTHERWISE RETURN NOT EMPTY
}