// PROGRAM THAT USE QUEUE DATA STRUCTURE TO STORE AND MANIPULATE DATA 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// MACROS DEFINITION FOR THE CONSTANT DEFINITION
#define MAX_SIZE 50
#define EMPTY -1

typedef struct { // DECLARATION OF THE STRUCTURE
  int queue [MAX_SIZE];
  int front;
  int rear;
} QUEUE;
// FUNCTION PROTOTYPE 
void initialize_queue (QUEUE *);
bool is_queue_empty (QUEUE *);
bool is_queue_fulled (QUEUE *);
int size_of_queue (QUEUE *);
void enqueue (QUEUE *,int);
int dequeue (QUEUE *);
void display_menu ();
void process_menu (QUEUE *,int);
int peek (QUEUE *);
int bottom (QUEUE *);
void display (QUEUE *);
int valid_input ();

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
  QUEUE queue; // STRUCTURE VARIABLE DECLARATIONS
  QUEUE *q = &queue; // PASSING ADDRESS OF THE  STRUCTURE VARIABLE IN THE STRUCTURE POINTER 
  while (1) {
     display_menu (); // SHOWING MENU BAR TO THE USER
     value = valid_input (); // TAKE VALIDATE INPUT
    process_menu (); // PROCESS EACH MENU BY USER INPUT
  }
  return 0; // IT TERMINATE THE PROGRAM 
}
void initialize_queue (QUEUE *queue) { // FUNCTION THAT INITIALIZED QUEUE FRONT AND REAR AS -1

  queue->front = queue->rear = -1;
}
int valid_input () { // VALIDATE USER INPUT FOR INTEGER
  int val;
  printf ("\nPlease enter right value : ");
  while (1) {
    if (scanf ("%d",&val) != 1) {  // SCAN USER ENTER RIGHT INPUT OR NOT
      while (getchar () != '\n')
       printf ("\nIn-valid input. Please enter valid input. ");
      continue;
    }
    else  // STOP THE LOOP WHEN USER ENTER RIGHT INPUT
     break;
  }
  return val;
}
void display_menu () { // DISPLAY MENU BAR FOR HELP USER TO EXECUTE THIER RESPECTIVE PROGRAM
  printf ("\n*************** MAIN MENU ********************");
  printf ("\nEnter : 1 for insertion value in the queue : ");
  printf ("\nEnter : 2 for deletion value from the queue : ");
  printf ("\nEnter : 3 for get top most elemenet of the queue : ");
  printf ("\nEnter : 4 for get bottom most element of the queue : ");
  printf ("\nEnter : 5 for get total size of the queue : ");
  printf ("\nEnter : 6 for displaying each value of the queue : ");
  printf ("\nEnter task according main menu : ");
}
void process_menu (QUEUE *queue,int choice) { // PROCESS EACH OPERATIONS BASED ON THE CHOICE OF THE USER
  switch (choice) {
    case 1:
      printf ("\nPlease enter valid that you want to insert in the queue : ");

      printf ("\nInsertion is done !");
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
  }
}