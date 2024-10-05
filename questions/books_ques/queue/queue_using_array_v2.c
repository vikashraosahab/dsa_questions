// PROGRAM THAT USE QUEUE DATA STRUCTURE TO STORE AND MANIPULATE DATA 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// MACROS DEFINITION FOR THE CONSTANT DEFINITION
#define MAX_SIZE 5
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
  int value; // OTHER VARIABLE DECLARATIONS
  initialize_queue (q); // INITIALIZED QUEUE 
  while (1) {
     display_menu (); // SHOWING MENU BAR TO THE USER
     value = valid_input (); // TAKE VALIDATE INPUT
     if (value == 7) break; // BREAK THE LOOP AND EXIT 
    process_menu (&queue,value); // PROCESS EACH MENU BY USER INPUT
  }
  printf ("\nProgram is exited now !");
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
  printf ("\nEnter : 7 for exit : ");
  printf ("\nEnter task according main menu : ");
}
void process_menu (QUEUE *queue,int choice) { // PROCESS EACH OPERATIONS BASED ON THE CHOICE OF THE USER
  int val;
  switch (choice) {
    case 1:
      printf ("\nPlease enter valid that you want to insert in the queue : ");
      val = valid_input (); // VALIDATED INPUT
      enqueue (queue,val); 
      printf ("\nInsertion is done !");
      break;
    case 2:
      printf ("\nValue is in processing to be delete !");
      printf ("%d",dequeue (queue));
      printf ("\nDeletion is done !");
      break;
    case 3:
      printf ("\nThe top most element of the queue is  : ");
      printf ("%d",peek (queue));
      printf ("\nProcess is done !");
      break;
    case 4:
      printf ("\nThe bottom most element of the queue is : ");
      printf ("%d",bottom (queue));
      printf ("\nProcess is done !");
      break;
    case 5:
      printf ("\nThere are elements are presented in the queue : ");
      printf ("%d",size_of_queue (queue));
      printf ("\nProcess is done !");
      break;
    case 6:
      printf ("\nAll elements are displaying : ");
      display (queue); // CALLING DISPLAY FUNCTION 
      printf ("\nProcess is done !");
      break;
  }
}
bool is_queue_empty (QUEUE *queue) { // CHECKING THE QUEUE IS EMPTY OR NOT 
  return queue->front = queue->rear == -1;
}
bool is_queue_fulled (QUEUE *queue) { // CHECKING THE QUEUE IS FULLED OR NOT
  return queue->rear == MAX_SIZE - 1;
}
int size_of_queue (QUEUE *queue) { // GET THE TOTAL SIZE OF THE QUEUE
  if (is_queue_empty (queue))
   return 0;
  else {
   int size, i = 0;
   for (i; i <= queue->rear; i++)
    size++;
  return size;
  }
}
void enqueue (QUEUE *queue, int value) { // METHOD THAT INSERT NEW ELEMNT AT THE REAR OF THE QUEUE
  if (is_queue_fulled (queue)) { // WHEN QUEUE IS FULLED 
    printf ("\nQUEUE IS FULLED NOW !");
    return;
  }
  else if (is_queue_empty (queue)) // CONDITION PERFORM OPERATIONS WHEN QUEUE IS EMPTY
    queue->rear = queue->front = 0;
  else 
    queue->rear++; 
  queue->queue [queue->rear] = value; // ASSIGN VALUE IN THE QUEUE 
}
void display (QUEUE *queue) { // DISPLAY EACH CHARACTER OF THE QUEUE 
  if (is_queue_empty (queue)) {
    printf ("\nQueue is empty !");
    return;
  }
  int i = queue->front;
  for (i; i <= queue->rear; i++) {
    printf ("\nElements of the queue : %d\n",queue->queue [i]);
  }
}
int dequeue (QUEUE *queue) {
  if (is_queue_empty (queue)) { // WHEN QUEUE IS EMPTY
    printf ("\nQueue is empty !");
    return -1;
  }
  int val = queue->queue [queue->front]; // VALUE THAT PRESENT AT THE TOP MOST OF THE QUEUE
  for (int i = queue->front; i < queue->rear; i++) {
    // SWAPPING METHOD USED FOR EFFICIENTLY USED FOR QUEUE AFTER DELETION
    queue->queue [i] = queue->queue [i + 1]; // SWAP VALUES I WITH I + 1 SO ALL THE VACENT POSITIONS SHOULD FILL WITH THE NEXT VALUES 
  }
  queue->rear--; // REDUCE REAR POINTER BY DECREMENT 1
  return val;
}
int peek (QUEUE *queue) { // GET PEEK ELEMENT OF THE QUEUE ADT
  if (is_queue_empty (queue)) { // WHEN QUEUE IS EMPTY
    printf ("\nQueue is empty !");
    return -1;
  }
  return queue->queue [queue->rear];
}
int bottom (QUEUE *queue) { // GET BOTTOM ELEMENT OF THE QUEUE ADT
   if (is_queue_empty (queue)) { // WHEN QUEUE IS EMPTY
    printf ("\nQueue is empty !");
    return -1;
   }
   return queue->queue [queue->front]; // RETURN BOTTOM MOST ELEMENT OF THE QUEUE
}