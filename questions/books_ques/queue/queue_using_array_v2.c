// PROGRAM OF IMPLEMENTATION OF THE QUEUE USING ARRAY AND STRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// MACROS DEFINITION FOR THE CONSTANT 
#define MAXIMUM 5// MAXSIZE FOR MAXIMUM LENGTH OF THE QUEUE
#define EMPTY -1 // EMPTY CONSTANT FOR EMPTY THE QUEUE

typedef struct 
{
  int queue [MAXIMUM];
  int front; // FOR DELETION OF THE FIRST ELEMENT FROM THE QUEUE (FIFO)
  int rear; // FOR INSERTION OF THE NEW ELENENT IN THE QUEUE
}QUEUE;

// FUNCTIONS PROTOTYPES FOR MODULARITY
void initialized_queue (QUEUE *); // METHOD THAT INITIALIZED QUEUE'S VARIABBLE FRONT AND REAR AS -1
bool is_queue_empty (QUEUE *); // METHOD THAT CHECK QUEUE IS EMPTY OR NOT
bool is_queue_fulled (QUEUE *); // METHOD THAT CHECK QUEUE IS FULLED OR NOT
void enqueue (QUEUE *,int); // METHOD THAT INSERT NEW ELEMENT IN THE QUEUE 
void dequeue (QUEUE *); // METHOD THAT DELETE ELEMENT FROM THE QUEUE
int peek (QUEUE *); // METHOD THAT RETURN TOP MOST ELEMENT OF THE QUEUE THAT PRESENT AT THE REAR
int bottom (QUEUE *); // METHOD THAT RETURN BOTTOM MOST ELEMENT OF THE QUEUE THAT PRESENT AT THE FRONT
void display_menu (); // METHOD THAT DISPLAY MENU OF THE TASK
void menu_task (QUEUE *,int); // METHOD THAT PERFORM EACH TASK OF THE MENU BY USER INPUT
int valid_input (); // METHOD THAT VALIDATE INPUT FROM USER AND ALLOW ONLY INTEGER AS INPUT AND REFUSE OTHER DATA TYPE LIKE CHARACTER OR STRING , FLOAT ETC

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[])
{
  QUEUE queue; // VARIABLE DECLARATIONS OF THE QUEUE ADT
  initialized_queue (&queue);
  while (1)
  {
    int val;
    display_menu (); // SHOWING MENU CARD
    val = valid_input (); // INPUT STATEMENT BY CALLING VALID_INPUT METHOD
    if (val == 6) goto finish;
    menu_task (&queue,val);
  }
  finish:printf ("\nProgram is ended now !");
  return 0; // TERMINATE THE PROGRAM AFTER SUCCESSFULLY EXECUTION 
}
void initialized_queue (QUEUE *queue) // FUNCTION THAT INITTIALIZED QUEUE ADT
{
  queue->front = queue->rear = -1; // INITTIALIZED FRONT AND REAR BY -1
}
bool is_queue_empty (QUEUE *queue) // CHECK THAT QUEUE IS EMPTY OR NOT 
{
  if (queue->front == -1 || queue->front >= queue->rear)
    return true; // WHEN QUEUE IS EMPTY
  else 
    return false;
}
bool is_queue_fulled (QUEUE *queue) // CHECK THAT QUEUE IS FULLLED OR NOT
{
  if (queue->rear >= MAXIMUM)
    return true; // WHEN QUEUE IS FULLED 
  else 
    return false; // WHEN QUEUE IS EMPTY
}
void display_menu () // SHOWING MENU BAR WITH THEIR RESPECTIVE WORKING
{
  printf ("\n************** MAIN MENU **************");
  printf ("\nEnter : 1 for insert new element in the queue!");
  printf ("\nEnter : 2 for remove element from the queue!");
  printf ("\nEnter : 3 for getting top most element of the queue!");
  printf ("\nEnter : 4 for getting bottom most element of the queue!");
  printf ("\nEnter : 5 for display the element of the queue!");
  printf ("\nEnter : 6 for exit the program!");
  printf ("\nEnter the value according to the menu for perform the task : ");
}
int valid_input () // TAKE ONLY INTEGER AS INPUT
{
  int val;
  while (1)
  {
    if (scanf ("%d",&val) != 1) // WHEN VALUE IS NOT INTEGER 
    {
      while (getchar () != '\n'); // IF CHARACTER IS NOT NEW LNE 
       printf ("\nIn-valid input. Pleaes re-enter integer value again : ");
      continue;
    }
    else  //  WHEN VALUE IS INTEGER 
      break;
  }

  return val;
}
void menu_task (QUEUE *queue, int choice) // OPERATIONS ARE PEROFORMED ACCORDING USER INPUT
{
  int value;
  switch (choice) // PERFORM OPERATIONS BAESD ON USER INPUT
  {
    case 1:
      printf ("\nInsert new element in the queue !");
      value = valid_input (); // TAKE INPUT ONLY INTEGER
      enqueue (queue,value); 
      printf ("\nInsertion is done !");
      break;
    case 2:
      printf ("\nDeletion is in process");
      dequeue (queue);
      printf ("\nDeletion is done !");
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
  }
}
void enqueue (QUEUE *queue, int value) // INSERT NEW VALUE IN THE QUEUE
{
  if (is_queue_fulled(queue) == true) // WHEN QUEUE GET FULLLED
  {
    printf ("\nQueue is fullled !");
    return;
  }
  if (is_queue_empty (queue) == false) // WHEN QUEUE IS EMPTY 
  {
    queue->front = 0;
    queue->rear = 0;
  }
  else  // WHEN QUEUE EITHER FULLED OR EMPTY
    queue->rear = queue->rear + 1;
  
  queue->queue[queue->rear] = value;
}
void dequeue (QUEUE *queue) // REMOVE ELEMENT FROM THE QUEUE
{
  if (is_queue_empty (queue) == true)
  {
    printf ("\nQueue is empty !");
    return;
  }
  int val = queue->queue [queue->front++];
  printf ("\n%d is deleted now !",val);
}

