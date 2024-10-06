// WRITE A PROGRAM THAT IMPLEMENT QUEUE IN CIRCULAR CONCEPTION 
#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#include <ctype.h>
#include <math.h>

// ENUMERATION FOR VALIDATION 
typedef enum {
  FULLED,
  NOT_FULLED,
  EMPTY,
  NOT_EMPTY,
  MAX_SIZE = 50,
} MESSAGE;
MESSAGE M; // GLOBALY DECLARATION OF THE ENUMERATION VARIABLE
// FOR STRUCTURE 
typedef struct {
    int array [MAX_SIZE];
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
void process_menu ();
int valid_input ();

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
   int value;
   Queue q;
   create_queue (&q); // INITIALIZATION OF THE QUEUE'S VARIABLES 
   while (1) {

   }
   printf ("\nProgram is ended now !");
   return 0;
}
void create_queue (Queue *queue) {
    queue->front = queue->rear = -1;
}
int queue_empty (Queue *queue) {
    if (queue->front == -1 && queue->rear) 
     return EMPTY;
    else 
      return NOT_EMPTY;
}