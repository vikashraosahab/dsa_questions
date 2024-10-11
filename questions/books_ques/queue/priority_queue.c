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
  EMPTY = 1,
  NOT_EMPTY = 0,
  FULLED = 1,
  NOT_FULLED = 0,
  MAX_SIZE = 5,
} MESSAGE;
MESSAGE M; // ENUMERATION VARIABLE DECLARATIONS

typedef struct { // TYPEDEFINITION STRUCTURE DECLARATIONS WITH PRIORITY_QUEUE ARRAY AND FRONT AS WELL AS REAR VARIABLE LABEL
    int priority_queue [MAX_SIZE];
    int front,rear;
    int count;
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
  q->count = 0;
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
int queue_empty (Queue *q) {
  return  (q->rear == -1 && q->front == -1) ? EMPTY : !EMPTY; 
}// METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY
int queue_fulled (Queue *q) {
  return q->rear == MAX_SIZE -1 ? FULLED :!FULLED;
}
void process_menu (Queue *q,int task) {// FUNCTION THAT PERFROM TASK ACCORDING USER INPUT 
 switch (task) {
    case 1:
     printf ("\nInsertion is in process........");
     printf ("\nEnter value that you want to insert in the queue : ");
     int value = valid_input (); // TAKE INPUT FROM THE USER
     enqueue (q,value); // PERFORM ENQUEUE FUNCTION THAT INSERT IN THE QUEUE 
     queue_fulled(q) == 0 ? printf ("\nValue %d is inserted..!",value) : printf ("");
     break;
    case 2:
     printf ("\nDeletion is in process..........\n");
     dequeue (q); // VALUE IS DELETED NOW !
     printf("\nDone !");
     break;
    case 3:
     printf ("Peek value is %d ",peek (q)); // GET VALUE AT THE TOP OF THE REAR
     break;
    case 4:
     printf ("\nBotton value is %d",bottom (q)); // GET VALUE AT THE TOP OF THE FRONT
     break;
    case 5:
    queue_empty (q) == 0 ? display (q) : printf ("\nQueue is empty !");
     break;
    default :
     printf ("\nEntered value is not matched values with the menu bar values !"); // USER PROMPT
    break;
  }
}

void enqueue(Queue *q, int value) {
    // Check if the queue is full
    if (queue_fulled(q)) {
        printf("\nQueue is full! Cannot insert new value.\n");
        return;
    }

    // If the queue is empty, insert at position 0
    if (queue_empty(q)) {
        q->priority_queue[0] = value;  // INSERT AT THE O POSITION 
        q->rear = q->front = 0; // INITIALIZING REAR AND FRONT WITH 0
        return;
    }

    // Find the correct position to insert in descending order
    int i;
    for (i = q->rear; (i >= 0 && q->priority_queue[i] < value); i--) {
        q->priority_queue[i + 1] = q->priority_queue[i];
    }
    
    // Insert value at the found position
    q->priority_queue[i + 1] = value;
    q->rear++;
}
void dequeue (Queue *q) {
  if (queue_empty (q)) { // WHEN QUEUE IS EMPTY 
    printf ("\nQueue is empty !"); // OUTPUT PROMPT
    return;
  }

  int val = q->priority_queue [q->front]; // VALUE THAT WILL BE DELETED 
    for (int i = q->front; i <= q->rear; i++) { // REPLACE FIST POSITION VALUES WITH MOVING ARRAY I - 1 POSITION
      if (q->rear == 0 && q->front == 0) {
        q->front = q->front - 1; // WHEN REAR AND FRONT IS EQUAL TO -1 OR NULL
      }
      else
        q->priority_queue [i] = q->priority_queue [i + 1]; // insertion each i+ 1 with in i position values
    }
    q->rear = q->rear - 1; // DECREMENT REAR BY 1
    printf ("value is %d deleted now !",val); // OUTPUT PROMPT
}
// PEEK VALUE OF THE ARRAY FROM THE REAR END 
int peek (Queue *q) {
  return q->priority_queue [q->rear];
}
// BOTTOM VALUE OF THE ARRAY FROM THE FRONT END
int bottom (Queue *q) {
  return q->priority_queue [q->front];
}
void display (Queue *q) { // DISPLAY OR PRINTING EACH CHARACTER OF THE QUEUE ONE BY ONE 
  printf ("\nElements are : ");
  for (int i = q->front ; i <= q->rear; i++) { // START FROM FRONT TO REAR
    printf ("%d,",q->priority_queue [i]); // DISPLAYING 
  }
 }