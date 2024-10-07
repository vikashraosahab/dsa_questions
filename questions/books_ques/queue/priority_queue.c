// CREATION OF THE PRIORITY QUEUE BY USING ARRAY
/*
 *  Priority BASED ON LARGEST NUMBER 
 *  MEANS DESCENDING ORDER DELETE LARGEST NUMBER FIRST 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef enum { //  TYPEDEFINTION ENUMBERATION DECLARAE
  EMPTY,
  NOT_EMPTY,
  FULLED,
  NOT_FULLED,
  MAX_SIZE = 50,
} MESSAGE;
MESSAGE M; // ENUMERATION VARIABLE DECLARATIONS

typedef struct { // TYPEDEFINITION STRUCTURE DECLARATIONS WITH PRIORITY_QUEUE ARRAY AND FRONT AS WELL AS REAR VARIABLE LABEL
    int priority_queue [MAX_SIZE];
    int front,rear;
} Queue;

// FUNCTION PROTOTYPE THAT ALLOW USER 
// MODULARITY BASED PROGRAMS LIKE SHOW_MENU,PROCESS_MENU ETC
void show_menu (); // SHOW MENU 
void process_menu (Queue *,int); // PROCESS OF THE MENU
int valid_input (); // FOR VALIDATION OF THE USER INPUT ONLY INTEGER ALLOWED
// QUEUE RELATED FUNCTIONS FOR MANIPULATED QUEUE
void create_queue (Queue *); // FOR CREATION OF THE QUEUE ADT
void enqueue (Queue *,int); // INSERT NEW VALUE IN THE PRIORITY QUEUE
void dequeue (Queue *); // REMOVE VALUE FROM THE PRIORITY QUEUE
int peek  (Queue *); // GET VALUE OF THE REAR 
int bottom (Queue *); // GET VALUE OF THE FRONT 
void display (Queue *); // DISPLAY EACH CHARACTER OF THE QUEUE
int queue_empty (Queue *); // CHECK QUEUE IS EMPTY OR NOT
int queue_fulled (Queue *); // CHECK QUEUE IS FULLED OR NOT

// MAIN FUNCITON  OF THE PROGRAM 
int main (int argc, char * argv[]) {
  Queue q; // VARIABLE DECLARTION OF THE QUEUE DATA STRUCTURE
  create_queue (&q); // CALLING CREATE QUEUE METHOD FOR 
  int value;
  while (1) {
    show_menu (); // CALLING SHOW MENU FOR DISPLAY EACH USER RELATED PROMPT 
    value = valid_input (); // INPUT TAKEN 
    if (value == 6) break; // WHEN VALUE IS EQUAL 6 THEN TERMINATE THE PROGRAM
    process_menu (&q,value); // FUNCTION CALLING FOR THE PERFORM BY USER INPUT THAT GIVEN IN MENU BAR
  }
  printf ("\nProgram is ended now !");
  return 0; // TERMINATE PROGRAM SUCCESSFULLY AFTER EXECUTION
}
  // FUNCTION PROTOTYPES
void create_queue (Queue *q) {// CREATION QUEUE MEANS INITIALIZED - 1 TO FRONT AND REAR LABEL OF THE QUEUE
  q->rear = q->front = -1; // INITIALIZED - 1 TO BOTH REAR AS WELL AS FRONT
}
void show_menu () { // FOR SHOWING MENU RELATED PROMPTS TO THE SUER
   printf ("\n*********** MENU BAR *************");
   printf ("\nEnter : 1 for insertion : ");
   printf ("\nEnter : 2 for deletion : ");
   printf ("\nEnter : 3 for peek value : ");
   printf ("\nEnter : 4 for bottom value : ");
   printf ("\nEnter : 5 for display each value : ");
   printf ("\nEnter : 6 for exit");
   printf ("\nEnter task according main menu : ");
}
int valid_input () {// INPUT VALIDATED FOR INTEGER ONLY 
  int value;
  while (1) {
    // CHECK VALUE THAT ENTERED BY USER IS INTEGER VALUE OR NOT 
    if (scanf ("%d",&value) != 1) {
      while (getchar () != '\n') // NEWLINE CHARACTER NOT CONSIDERED FOR ANYTHING
        printf ("\nIn-valid input. Please enter valid input : "); // ERROR PROMPT 
      continue;
    }
    else  // WHEN VALUE IS INTEGER VALUE
      break;
  }
  return value;
}
void process_menu (Queue *q,int task) {// FUNCTION THAT PERFROM TASK ACCORDING USER INPUT 
 switch (task) {
    case 1:
     printf ("\nInsertion is in process........");
     printf ("\nEnter value that you want to insert in the queue : ");
     int value = valid_input (); // TAKE INPUT FROM THE USER

     printf ("\nDone !");
     break;
    case 2:
     printf ("\nDeletion is in process..........");

     printf("\nDone !");
     break;
    case 3:
     
    case 4:
    case 5:
     break;
    default :
     printf ("\nEntered value is not matched values with the menu bar values !");
    break;
  }
}
