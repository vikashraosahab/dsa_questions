// CREATE QUEUE USING LINKED LIST 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ENUMBERATION FOR USING CONSTANT THAT USED FOR VALIDATION
typedef enum {
    NOT_EMPTY,
    EMPTY,
} MESSAGE;
MESSAGE m; // DECLARATION OF THE GLOBAL ENUMBERATION MESSAGE VARIABLE 
typedef struct node {// FOR CREATE A PARTICULAR NODE 
  int value;
  struct node *next; // NEXT POINTER
} Node;
typedef struct queue {// FOR CREATION OF THE QUEUE ADT
  Node *front,*rear;
} QUEUE;

// FUNCTION PROTOTYPE
int empty (QUEUE *); // for checking that queue is or not
Node *create_node (int value); // FOR CREATE A PARTICULAR NODE 
QUEUE *create_queue (); // FOR CREATING OF THE QUEUE ADT AND INITIALIZED IT'S POINTER
QUEUE *enqueue (QUEUE *,int); // FOR INSERTION OF THE NEW NODE IN THE LINKED LIST 
QUEUE *dequeue (QUEUE *); // FOR DELETION OF THE NODE AT STAND AT THE FRONT SIDE
int peek (QUEUE *); // FOR GET TOP MOST NODE OF THE QUEUE 
int bottom (QUEUE *); // FOR GET BOTTOM MOST NODE OF THE QUEUE
QUEUE *display (QUEUE *); // FOR SHOWING EACH NODE OF THE QUEUE FROM FRONT TO REAR
int valid_input (); // FOR VALIDATE VALUE ONLY INTEGER ARE ALLOWED 
void process_menu (QUEUE *,int); // FOR FORMING OPERATIONS ACCORDING TO THE USER VALUE
void menu_bar (); // FOR SHOWING MENU BAR 
// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[]) {
    int value; // VALUE FOR STORE VALIDATE INPUT THAT GIVE USER
    QUEUE *q = create_queue (); // FOR CREATION OF THE QUEUE IN THE MEMORY
    while (1) {
       
       menu_bar (); // CALL FUNCTION THAT SHOW OUPUT PROMPT THAT HELP USER'S TO PERFORM THEIR OPERATION
       value = valid_input (); // CALLING VALID_INPUT THAT HAVE VALIDATED INPUT FROM THE USER AS INTEGER
       if (value == 6) break;
       process_menu (q,value); // CALLING FUNCTION THAT PERFORM OPERATION  BASED ON THE USER INPUT ACCORDING THE MENU BAR
    }
    printf ("\nProgram is existed now !");
    return 0;
}
// FUNCTION DEFINTIONS
void menu_bar () {// DISPLAY EACH PROMPT THAT HELP USER TO PREFORM THEIR OPERATIONS
  printf ("\n************* MENU BAR *****************");
  printf ("\nEnter : 1 for insert new node in the linked list : ");
  printf ("\nEnter : 2 for remove node from the front side of the linked list : ");
  printf ("\nEnter : 3 for get value from the top most of the linked list : ");
  printf ("\nEnter : 4 for get value from the bottom most of the linked list : ");
  printf ("\nEnter : 5 for display each value from the front to rear of the queue : ");
  printf ("\nEnter : 6 for exit : ");
  printf ("\nEnter task according the menu bar : ");
}
void process_menu (QUEUE *queue,int task) { // FUNCTION THAT PERFORM USER TASK ACCORDING MENU AND TASK VALUE
 switch (task) {
    case 1:
      printf ("\nEnter value that you want to insert in the linked list : ");
      int value = valid_input (); // ENTER VALUE ONLY IN INTEGER 
      queue = enqueue (queue,value); // ENQUEUE FUNCTION IS PERFORMED
      printf ("\nInsertion of value %d is done !",value);
      break;
    case 2:
      printf ("\nDeletion of first node is in process ........\n");
      queue = dequeue (queue); // DEQUEUE FUNCTIONS IS PERFORMED 
      printf ("\nDeletion is done !");
      break;
    case 3:
       empty (queue) == 1 ? 
       printf ("\nQueue is empty !")
      :printf ("\nTop most value of the queue is : %d",peek (queue));
      break;
    case 4:
      empty (queue) == 1 ?
      printf ("\nQueue is empty !")
      :printf ("\nBottom most value of the queue is : %d",bottom (queue));
      break;
    case 5:
       empty (queue) == 1 ?
       printf ("\nQUEUE is empty !")
      :printf ("\nDisplaying each value of the linked list : ");
      queue = display (queue);
      printf ("\nDone !");
      break;
     default :
      printf ("\nEntered value is in-valid.\t Not ! found in Menu bar\nPlease enter valid input : ");
      break;
 }
}
int valid_input () {// FUNCTION THAT VALIDATE GIVEN USER INPUT 
 int value;
 while (1) {
     if (scanf ("%d",&value) != 1) {
    while (getchar () != '\n')
     printf ("\nIn-valid input. Please enter valid input : ");
    continue;
   }
   else 
    break; // STOP WHILE WHEN USER ENTER RIGHT 
 }
 return value;
}
int empty (QUEUE *queue) {// FOR CHECKING QUEUE IS EMPTY OR NOT EMPTY 
  if (queue->front == NULL && queue->rear == NULL)
    return EMPTY;
  else 
    return NOT_EMPTY;
} 
QUEUE *create_queue () {// FOR CREATION OF THE QUEUE ADT
  QUEUE *queue = (QUEUE *) malloc (sizeof (QUEUE)); // DYNAMIC ALLOCATION
  if (queue != NULL)  {
    queue->front = queue->rear = NULL; // INITIALIZED FRONT AND REAR AS - 1
  }
  else 
    printf ("\nError : Queue ADT is not created");
 return queue;
}
Node *create_node (int value) {// FOR CREATION OF THE NODE 
  Node *node = (Node *) malloc (sizeof (Node));  // DYNAMIC ALLOCATION OF THE NODE 
  if (node != NULL) {
    node->value = value; // INSERT VALUE IN THE NODE 
    node->next = NULL; // POINT TO THE NULL 
  }
  return node;
}
QUEUE *enqueue (QUEUE *queue,int value) {// FUNCTION THAT ALLOW USER TO INSERT VALUE IN THE QUEUE
  Node *new_node = create_node (value); // CALLING CREATE_NODE FUNCTION THAT CREATE A NEW NODE EACH TIME WHEN ENQUEUE FUNCTION ALLING
  if (new_node != NULL)  {
     if (empty (queue)) { // WHEN QUEUE IS EMPTY
    queue->front = queue->rear = new_node;  // INSERT NEW_NODE AT THE POSITION OF THE FRONT AND REAR
    queue->rear->next = NULL; // REAR POINTER POINTED TO THE NULL
  }
  else  {
    /*
   queue->rear->next = new_node; // POINTED REAR POINTER TO THE NEW_NODE FOR CREATING A CHAIN THAT CONNECTED WITH THE FRONT
   queue->rear = new_node; // INCREMENT REAR POINTER AND SEND IT TO THE NEW_NODE POSITION
   queue->rear->next = NULL; // AFTER RE-POSITION REAR AGAIN POINTER TO THE NULL
   */
  new_node->next= queue->rear->next;
  queue->rear->next = new_node;
  queue->rear = new_node;
  }
 }
 else {
    printf ("\nNEW NODE IS NOT ALLOCATED !");
 }
  return queue;
}
QUEUE *dequeue (QUEUE *queue) {// FUNCITON THAT USED FOR DELETION OF THE NODE FROM THE FRONT SIDE
   if (empty (queue))  {
    printf ("\nQueue is already empty");
   }
   else {
    Node *ptr = queue->front;
    if (ptr != NULL) {
         queue->front = queue->front->next; // SHIFT FRONT OF THE QUEUE TO THE NEXT OF FRONT CURRENT POSITION
    if (queue->front == NULL) {// WHEN DELETE ALL VALUES FROM THE LINKED LIST 
      queue->rear = NULL; // THEN  INITIALIZE REAR POINTER TO NULL SO ALL VALUES IS DELETED EFFICIENTLY
    }
    printf ("First node is deleted that have value %d",ptr->value); // INFORMATION PROMPT
    free (ptr); // REMOVE FIRST NODE FROM THE LINKED LIST
    }
    else {
        printf ("\nSome error occupied !");
    }
   }
   return queue;
}
int peek (QUEUE *queue) {// RETURN TOP MOST (REAR) NODE'S VALUE OF THE QUEUE
 return queue->rear->value;
}
int bottom (QUEUE *queue) {// RETURN BOTTOM MOST (FRONT) NODE'S VALUE OF THE QUEUE
 return queue->front->value;
}
QUEUE *display (QUEUE *queue) {// SHOWING ELEMENT OF THE LINKED LIST
   Node *ptr = queue->front;
   printf ("\nValue are presented now : ");
   while (ptr != NULL) {
    printf ("%d ",ptr->value);
    ptr = ptr->next;
   }
   return queue;
}