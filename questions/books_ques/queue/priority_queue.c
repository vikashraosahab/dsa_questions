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
void process_menu (Queue *q,int task) {// FUNCTION THAT PERFROM TASK ACCORDING USER INPUT 
 switch (task) {
    case 1:
     printf ("\nInsertion is in process........");
     printf ("\nEnter value that you want to insert in the queue : ");
     int value = valid_input (); // TAKE INPUT FROM THE USER
     enqueue (q,value); // PERFORM ENQUEUE FUNCTION THAT INSERT IN THE QUEUE 
     printf ("\nValue %d is inserted..!",value);
     break;
    case 2:
     printf ("\nDeletion is in process..........");
     dequeue (q);
     printf("\nDone !");
     break;
    case 3:
     printf ("Peek value is %d ",peek (q));
     break;
    case 4:
     printf ("\nBotton value is %d",bottom (q));
     break;
    case 5:
     display (q);
     break;
    default :
     printf ("\nEntered value is not matched values with the menu bar values !");
    break;
  }
}
int queue_empty (Queue *q) { // CHECK QUEUE IS EMPTY OR NOT 
  if (q->front == -1 && q->rear == -1 && q->count == 0) {
    return EMPTY;
  }
  else 
    return NOT_EMPTY;
}
int queue_fulled (Queue *q) { // CHECK QUEUE IS FeLLED OR NOT 
  if (q->front == 0 && q->rear == MAX_SIZE - 1 && q->count == MAX_SIZE && (q->front = q->rear - 1 && q->rear == MAX_SIZE))
    return FULLED; // WHEN QUEUE ARRAY IS FULLED 
  else 
    return NOT_FULLED;
}
void enqueue (Queue *q, int value) { // INSERT NEW VALUE IN THE PRIORITY_QUEUE IN DESCENDING ORDER 
  if (queue_fulled (q)) { // WHEN QUEUE GET FULLLED 
    printf ("\nQueue is fulled now !");
    return;
  }
  if (queue_empty (q)) {
    q->front++,q->rear++;
    q->priority_queue [q->rear] = value;
    q->count++; // INCREMENT COUNT BY 1 
  }
  else {
    int k = q->count - 1;
    for (k; k >= 0; k--) {
      if (k == 0 && q->priority_queue [k] < value) {
        int move = q->count;
        while (move > 0) {
          q->priority_queue [move] = q->priority_queue [move - 1];
          move = move - 1;
        }
        q->rear = q->count;
        q->priority_queue [q->front] = value; // INSERT VALUE AT THE 0 TH POSITIONUUU
        q->count = q->count + 1;// INCREMENT BY 1
      }
      else if (k == q->count - 1 && q->priority_queue [k] > value) {
        q->rear++;
        q->count++;
        q->priority_queue [q->rear] = value;
        break;
      }
      else if (q->priority_queue [k] > value) {
        int pos = k;
        int move = q->rear++;
        while (move > k) {
          q->priority_queue [move] = q->priority_queue [move -1];
          move = move - 1; // DECREMENT MOVE BY 1
        }
       q->priority_queue [pos] = value;
       q->count = q->count + 1; // INCREMENT TOTAL SIZE OF THE ARRAY BY 1
      }
    }
  }
}
void display (Queue *q) {
  if (queue_empty (q)) {
    printf ("\nQueue is empty !");
    return;
  }
  int i = q->front;
  for (i; i <= q->rear; i++) 
  {
    printf ("Values : %d\n",q->priority_queue [i]);
  }
 }
int peek (Queue *q) {// GET VALUE THAT IS AT THE PEEK 
  if (queue_empty (q)) {
    printf ("\nQueue is empty !");
    return EMPTY;
  }  
  
  return q->priority_queue[q->rear];
}
int bottom (Queue *q) {
  if (queue_empty (q)) {
    printf ("\nQueue is empty now !");
    return EMPTY;
  }
  return q->priority_queue [q->front];
}
void dequeue (Queue *queue) {
  if (queue_empty (queue) == EMPTY) {
    printf ("\nQueue is empty");
    return;
  }
  int val = queue->priority_queue[queue->front];
  queue->priority_queue [queue->front++];
  queue->count +=-1; // DECREEMENT TOTAL SIZE OF THE QUEUE ELEMENTS
  printf ("\n%d value is deleted now !",val);
  if (queue->count == MAX_SIZE && queue->front == queue->rear) {
    queue->rear = queue->front = -1;
    printf ("\nQueue is completely deleted or cleaned !");
  }
}