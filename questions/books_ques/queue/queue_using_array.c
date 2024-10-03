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
int bottom (int *);
int validInput ();
void print (int *);
// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
  initialized (&front,&rear); // CALLING INITIALIZED FUNCTION METHOD
  while (1)
  {
    printf ("\n*********** MAIN MENU **************");
    printf ("\nEnter : 1 for insert new element in the queue!");
    printf ("\nEnter : 2 for delete element from the queue!");
    printf ("\nEnter : 3 for check value at the top of the queue !");
    printf ("\nEnter : 4 for check value at the bottom of the queue!");
    printf ("\nEnter : 5 for display every element of the queue !");
    printf ("\nEnter : 6 for exit");
    printf ("\nEnter value according to the main menu : ");
    top:switch (validInput ())
    {
      case 1:
       printf ("\nPlease enter value (only integer ) for insertion : ");
       enqueue (queue,validInput()); // CALLING ENQUEUE METHOD OF THE QUEUE FOR INSERTION NEW ELEMENT IN THE QUEUE
       printf ("\nValue is inserted now !");
       break;
      case 2:
       printf ("\nDeletion is in processing !");
       dequeue (queue);
       printf ("\nProcess completed now !");
       break;
      case 3:
       printf ("\nTop most element of the queue is %d",peek (queue));
       break;
      case 4:
       printf ("\nTop low element of the queue is %d",bottom (queue));
       break;
      case 5:
       printf ("\nAll the elements of the stack are displaye : ");
       print (queue);
       break;
      case 6:
        goto lable;
       break;
      default:
       printf ("\nTask isn't found in the main menu!");
       goto top;
       break;
    }
  }
   lable:printf ("\nProgram is ended now !");
   return 0; 
}
void initialized (int *front,int *rear) // INITIALIZED QUEUE REAR AND FRONT VARIABLE WITH - 1
{
  *front = - 1,*rear = -1; // INITIALIZED FRONT AND REAR AS -1 
}
int validInput () // VALIDATE INTEGER INPUT IF INPUT VALUE NON INTEGER ASK FOR RE-ENTERING THE VALID DATA
{
  int val; // VARIABLE DECLARATIONS
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
  if (front == -1 && rear <= -1)
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
  if (front == -1 || front >= rear) 
  {
    printf ("\nQueue is empty now !");
    // exit (1); // TERMIANTED
  }

  int val = queue [front++]; // VALUE FROM THE FRONT IS DELETED NOW 
  printf ("\n%d value is deleted now !",val);
}
int peek (int *queue) // GET THE TOP MOST ELEMENT OF THE QUEUE
{
  if (front == -1 && front >= rear) // WHEN QUEUE IS EMPTY (UNDERFLOW CONDITION)
  {
    printf ("\nQueue is empty !");
    return -1;
  }
  else
   return queue [rear]; // TOP OF THE QUEUE 
}
int bottom (int *queue)
{
  if (front == -1 || front >= rear)
  {
    printf ("\nQueue is empty !");
    return -1;
  }
  return queue [front];
}
void print (int *queue) // DISPLAY EACH CHARACTER FOR THE QUEUE 
{
  if (front == -1 || front >= rear) // WHEN QUEUE IS EMPTY (UNDERFLOW CONDITION)
    printf ("\nQueue is empty now !");
  else 
  {
    int i = front;
    for (i; i <= rear; i++)
      printf ("\nElement of the queue is %d",queue [i]);
  }
}
