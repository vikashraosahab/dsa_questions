// PROGRAM THAT IMPLEMENT QUEUE DATA STRUCTURE USING ARRAY
#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 50

int queue [MAXSIZE]; // ARRAY DECLARATIONS
int front,rear; // QUEUE VARIABLE 
// FUNCTION PROTOTYPE
void initialized (int *,int *);
void enqueue (int *,int);
void dequeue (int *);
int peek (int *);
int validInput ();

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
  initialized (&front,&rear); // CALLING INITIALIZED FUNCTION METHOD
  enqueue (queue,validInput()); // TAKE VALIDATE INPUT 
  // printf ("%d is the top of the queue",peek (queue));
  dequeue (queue);
 // printf ("%d is the top of the queue",peek (queue));
  return 0; 
}
void initialized (int *front,int *rear) // INITIALIZED QUEUE REAR AND FRONT VARIABLE WITH - 1
{
  *front = - 1,*rear = -1; // INITIALIZED FRONT AND REAR AS -1 
}
int validInput () // VALIDATE INTEGER INPUT IF INPUT VALUE NON INTEGER ASK FOR RE-ENTERING THE VALID DATA
{
  int val;
 while (1)
 {
  printf ("\nEnter value only integer value  :  ");
  if (scanf ("%d",&val) != 1)
  {
    while (getchar () != '\n')
      printf ("\nIn-valid input. Please enter valid ");
    continue;
  }
  else 
    break;
 }
  return val;
}
void enqueue (int *queue,int data) // INSERT DATA IN QUEUE AT THE REAR END OF THE 
{
  if (rear >= MAXSIZE)
  {
    printf ("\nQueue is fulled now !");
    return;
  }
  if (front == rear == -1)
  {
    front = rear = 0;
    queue [rear] = data; // INSERT NEW DATA WHEN QUEUE IS EMPTY
  }
  else 
  {
    queue [++rear] = data; // INSERT NEW DATA AT THE REAR END OF THE QUEUE
  }
}
void dequeue (int *queue) // DEQUEUE PERFORMS DELETION OF THE ELEMENT FROM TEH QUEUE 
{
  // CHECK UNDERFLOW CONDITION OF THE QUEUE 
  if (front == -1 && front >= rear) 
  {
    printf ("\nQueue is empty now !");
    exit (1); // TERMIANTED
  }

  int val = queue [front--]; // VALUE FROM THE FRONT IS DELETED NOW 
  printf ("\n%d value is deleted now !",val);
}
/*
int peek (int *queue)
{
  if (front == -1 && front >= rear)
  {
    printf ("\nQueue is empty !");
    return -1;
  }
  else
   return queue [rear]; // TOP OF THE QUEUE 
}
*/
