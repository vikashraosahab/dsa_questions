// PROGRAM THAT IMPLEMENT QUEUE DATA STRUCTURE USING ARRAY
#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 50

int queue [MAXSIZE]; // ARRAY DECLARATIONS
int front,rear; // QUEUE VARIABLE 
// FUNCTION PROTOTYPE
void initialized (int *,int *);
void enqueue (int *,int);
void dequeue (int []);
int peek (int *);
int validInput ();

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
  initialized (&front,&rear); // CALLING INITIALIZED FUNCTION METHOD
  int val = validInput ();
  printf ("%d",val); 
  return 0; 
}
void initialized (int *front,int *rear) // INITIALIZED QUEUE REAR AND FRONT VARIABLE WITH - 1
{
  front = rear = -1; // INITTIALIZED BOTH VARIABLE WITH - 1
}
int validInput () // VALIDATE INTEGER INPUT IF INPUT VALUE NON INTEGER ASK FOR RE-ENTERING THE VALID DATA
{
  int val;
  printf ("\nEnter value only integer value  :  ");
  if (scanf ("%d",&val) != 1)
  {
    while (getchar () != '\n')
      printf ("\nIn-valid input. Please enter valid ");
    continue;
  }
  else 
    break;
  return val;
}
void enqueue (int *ary,int data) // INSERT DATA IN QUEUE AT THE REAR END OF THE 
{
  if (front == rear == -1)
  {
    front = rear = 0;
    queue [rear] = data;
  }
  else 
  {
    queue [++rear] = data;
  }
}
