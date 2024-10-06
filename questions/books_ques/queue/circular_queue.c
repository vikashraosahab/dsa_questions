// WRITE A PROGRAM THAT IMPLEMENT QUEUE IN CIRCULAR CONCEPTION 
#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#include <ctype.h>
#include <math.h>

// ENUMERATION FOR VALIDATION 
typedef enum {
  FULLED = 1,
  NOT_FULLED = 0,
  EMPTY = 1,
  NOT_EMPTY = 0,
  MAX_SIZE = 5,
} MESSAGE;
MESSAGE M; // GLOBALY DECLARATION OF THE ENUMERATION VARIABLE
// FOR STRUCTURE 
typedef struct {
    int queue [MAX_SIZE];
    int front,rear;
} Queue;

// FUNCTION PROTOTYPES
void create_queue (Queue *);
int queue_empty (Queue *);
int queue_fulled (Queue *);
void enqueue (Queue *,int);
void dequeue (Queue *);
int peek (Queue *);
int bottom (Queue *);
void display (Queue *);
void menu_bar ();
void process_menu (Queue *,int);
int valid_input ();

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
   int value;
   Queue q;
   create_queue (&q); // INITIALIZATION OF THE QUEUE'S VARIABLES 
   while (1) {
     menu_bar (); // CALLING MENU BAR FUNCTION FOR OUTPUT USER PROMPT
     value = valid_input (); // USER RESTRICTED INPUT ONLY INTEGER ALLOW 
     if (value == 6) break; // BREAK LOOP WHEN EVER USER ENTER 6 AS INPUT
     process_menu (&q,value); // PERFROM TASK ACCORDING USER 
   }
   printf ("\nProgram is ended now !");
   return 0;
}
void menu_bar () {// DISPLAYING MENU BAR SO USER EASILY PERFORM
 printf ("\n************** MENU BAR *****************");
 printf ("\n1 : INSERTION\n2 : DELETION\n3 : REAR VALUE \n4 : FRONT VALUE \n5 : DISPLAY \n6 : EXIT ");
 printf ("\nEnter task according the menu bar : ");
}
void process_menu (Queue *queue,int task) { // PERFORM EACH USER DEFINED TASK 
  switch (task) {
    case 1:
      printf ("\nInsertion is in process.....\nPlease enter value that you want to insert : ");
      int val = valid_input ();
      enqueue(queue,val); // ENQUEUE IS PERFORMING FOR INSERTION THE QUEUE
      printf ("\nDone !");
      break;
    case 2:
      printf ("\nDeletion is in process..... \n");
      dequeue (queue); // DEQUEUE IS PERFORMING FOR DELETION OF THE VALUE FROM THE QUEUE
      printf ("\nDone !");
      break;
    case 3:
      queue_empty (queue) == 1 ? printf ("\nQueue is empty !"):
      printf ("Value at top is : %d",peek (queue));
      break;
    case 4:
      queue_empty (queue) == 1 ? printf ("\nQueue is empty !") :
      printf ("Value at bottom is : %d",bottom (queue));
      break;
    case 5:
      break;
  }
}
int valid_input () {// VALIDATE INPUT FOR USER
 int value;
 while (1) {
   if (scanf ("%d",&value) != 1) {
   while (getchar () != '\n')
    printf ("\nIn-valid input. Please enter valid input.");
   continue;
  }
  else 
   break; 
 }
 return value;
}
void create_queue (Queue *queue) { // INITIALIZED QUEUE VARIABLE FRONT AND REAR WITH -1
    queue->front = queue->rear = -1;
}
int queue_empty (Queue *queue) { // CHECK THAT QUEUE IS EMPTY OR NOT EMPTY
  if (
     queue->front == -1 || queue->rear == -1
    ) 
    return EMPTY;
  else
    return NOT_EMPTY;   
}
int queue_fulled (Queue *queue) {//QUEUE IS FULLED 
  if ( 
     (queue->rear == MAX_SIZE - 1 && queue->front == 0)  ||
     (queue->rear == queue->front - 1 && queue->front > queue->rear && queue->rear != queue->front)
    )
     return FULLED;
  else 
     return NOT_FULLED;
}
void enqueue (Queue *queue,int value) {// INSERT NEW VALUE IN THE QUEUE
 if (queue_fulled (queue)) {
        printf ("\nQueue is fulled !");
        return;
 }
 if (queue_empty (queue)) { // WHEN QUEUE IS EMPTY 
   queue->front = queue->rear = 0;
   queue->queue [queue->rear] = value;
 }
 else if (queue->front != 0 && queue->rear == MAX_SIZE - 1) {
    queue->rear = 0;
    queue->queue [queue->rear] = value;
 }
 else  { 
    queue->rear++;
    queue->queue [queue->rear] = value;
   }
 printf ("\nValue %d is inserted at the position",value);
}
void dequeue (Queue *queue) { // DELETE VALUE FROM THE FRONT SIDE
 if (queue_empty (queue)) { // IF QUEUE IS EMPTY
  printf ("\nQueue is empty !");
  return;
 }
 if (queue->front == MAX_SIZE - 1 && queue->rear < MAX_SIZE - 1) {
   queue->front = 0;
   return; // STOP HERE
 } 
 else if (queue->front == MAX_SIZE - 1) {
   queue->front = 0;
 }
 else if (queue->front == queue->rear) {
  queue->front = queue->rear = -1;
 }
 queue->front += 1;
}
int peek (Queue *queue) { // GET TOP MOST ELEMENT 
  return queue->queue[queue->rear];
}
int bottom (Queue *queue) {// GET BOTTOM MOST ELEMENT 
  return queue->queue [queue->front];
}
