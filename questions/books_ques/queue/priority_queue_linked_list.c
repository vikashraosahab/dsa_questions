// IMPLEMENTATION OF THE PRIORITY QUEUE USING LINKED LIST 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h> 

// DEFINITION OF THE ENUMERATION FOR HANDLING ERRORS
typedef enum {
  EMPTY = 1, // DATA MEMBER OF THE ENUMERATION DATA TYPE
}EXCEPTION; // NAME OF THE ENUMERATION TYPEDEFINE DATA TYPE
EXCEPTION EXP; // VARIABLE DECLARATION OF THE EXCEPTION HANDLING 
typedef struct node { // DECLARATION OF THE STRUCTURE FOR THE NODE THAT HAVE STORE DATA AND WRAP ALL DATA MEMBER AND LINKED POINTER TOGETHER IN THE MEMORY
  int priority_tag;
  int data;
  struct node *next; // NEXT POINTER IS USED TO POINT NEXT NODE OF THE CURRENT NODE IF NEXT IS NULL IT'S THERE IS NO NODE IN THE LINKED OR IT'S TAIL OF THE LINKED END
  struct node *pre; // PRE POINTER IS USED TO POINT PRE NODE OF THE CURRENT NODE IF PRE IS NULL IT'S CURRENT NODE IS FIRST NODE
}Node; // NAME OF THE TYPEDEFINE STRUCTURE
typedef struct { //DECLARATION OF THE QUEUE STRUCTURE WITH IT'S PRIMARY TWO POINTER VARIABLE FRONT ND REAR
  Node *front; // FRONT POINTER IS USED TO DELETE NODE FROM THE FRONT SIDE OR STARTING SIDE 
  Node *rear; // REAR POINTER IS USED TO INSERT NODE FROM THE REAR SIDE OF THE LINKED LIST OR END OF THE LINKED LIST
}Queue; // QUEUE STRUCTURE NAMED 

// FUNCTION PROTOTYPES
void menu (); // MENU DISPLAY INSTRUCTIONS THAT HELP USER TO PERFORM THEIER SPECIFIC TASK
void process_menu (Queue *,int); // PROCESS MENU METHOD USED FOR PERFORM TASK ACCORDING TO THE USER INPUT 
int input_int (); // INPUT_INT METHOD RESOLVE EXCEPTION LIKE ONLY INTEGER ALLOWED NO OTHER VALUE USER CAN ENTER 
void create_queue (Queue *); // METHOD THAT CREATE QUEUE STRUCTURE IN THE MEMORY
Node *make_node (); // MAKE PARTICULAR NODE THAT STORE IT'S OWN DATA MEMBERS
void enqueue (Queue *); // METHOD THAT INSERT NEW NODE IN THE LINKED LIST
void dequeue (Queue *); // METHOD THAT REMOVE OR DELETE NODE FROM THE FRONT SIDE 
void peek (Queue *); // GET VALUE OF THE QUEUE FROM THE REAR SIDE
void bottom (Queue *); // GET VALUE OF THE QUEUE FROM THE FRONT SIDE
bool queue_empty (Queue *); // METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY
void display_queue (Queue *); // METHOD THAT DISPLAY ALL DATA OF THE LINKED LIST
// MAIN FUNCTION OF THE PROGRAM 
// ENTRY POINT OF THE PROGRAM
int main (int argc, char * argv[]) {
  Queue q;  // STRUCTURE POINTER VARIABLE DECLARATIONS
  create_queue (&q); // ALLOCATING MEMORY FOR THE QUEUE STRUCTURE
  int val;
  while (1) {
    menu (); // CALLING MENU METHOD FOR DISPLAYING EACH INSTRUCTIONS TO THE USER EVERY TIME
    val = input_int (); // INPUT PROMPT
    if (val == 6) break; // WHEN USER INPUT VALUE 6 THEN ACCORDING TO THE MENU TERMINATE THE LOOP
    process_menu (&q,val); // 
  }
  printf ("\nProgram is ended now !"); // END STATEMENT OF THE PROGRAM
  return 0; // TERMINATE
}
// FUNCTION PROTOTYPES
void menu () { // METHOD THAT DISPLAY INSTRUCTIONS MENU 
  printf ("\n*********** MAIN MENU ***************");
  printf ("\n1 : Insertion \n2 : Deletion \n3 : Peek \n4 : Bottom\n5 : display \n6 : Exit");
  printf ("\nEnter task according the menu of instructions : ");
}
int input_int () { // VALID VALUE ONLY INTEGER ALLOWED 
  int value;
  while (1) {
    printf ("\nEnter value : ");
    // CHECKING THAT USER ENTER INTEGER OR SOMETHING ELSE 
    if (scanf ("%d",&value) != 1) {
      while (getchar () != '\n')
        printf ("\nRe-enter value : ");
      continue;
    }
    else  // STOP LOOP WHEN USER ENTER RIGHT INPUT
      break;
  }
  return value;
}
void process_menu (Queue *q,int task) { // METHOD THAT PERFORM USER INSTRUCTED OPERATIONS BASED ON MENU INSTRUCTION 
 switch (task) {
    case 1: // PERFORM INSERTION OR SECTION WHERE ENQUEUE METHOD CALLED 
     printf ("\nInsert new node in the linked list : ");
     enqueue (q); // ENQUEUE METHOD CALLING 
     printf ("\nDone !");
    break;
    case 2: // SECTION WHERE DEQUEUE METHOD CALLED 
     printf ("\nDeletion of node is in process .........");
     dequeue (q); // DEQUEUE METHOD IS CALLING 
     break;
    case 3:
     peek (q); // CALLING PEEK METHOD 
     break;
    case 4:
     bottom (q); // CALLING BOTTOM METHOD
     break;
    case 5:
     display_queue (q);
     break;
    default:
     printf ("\nValue %d is not associated with any task in menu instructions !");
     break;
  }
}
void create_queue (Queue *q) { // METHOD THAT INITIALIZE REAR AND FRONT TO NULL SO THEY CAN ACTIVE FOR STORE DATA IN THE QUEUE
  q->rear = NULL;
  q->front = NULL;
}
bool queue_empty (Queue *q) { // METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY 
  return (q->rear == NULL && q->front == NULL) ? EMPTY : !EMPTY;
}
Node *make_node () { // METHOD THAT HANDLES NODE CREATION FUNCTION
  Node *node = (Node *) malloc (sizeof (Node)); // DYNAMIC MEMORY ALLOCATION
  if (node != NULL) {
    int val,tag;
    printf ("\nEnter priority of the data : "); // OUTPUT PROMPT
    tag = input_int (); //TAKE VALIDATED INPUT ONLY INTEGER ARE ALLOWED
    getchar (); // GETCHAR HANDLES SEPARATION BETWEEN CHARARACTER AND INPUT CHARACTER
    printf ("\nEnter data : ");
    scanf ("%c",&val); // TAKE CHARACTER AS INPUT 
    node->data = val;
    node->priority_tag = tag;
    node->next = NULL;
    node->pre = NULL;
  }
  else {
    printf ("\nNo dynamic memory allocated for the node !");
  }
  return node;
}
void enqueue (Queue *q) { // METHOD THAT INSERT NODE IN THE LINKED
  Node *new_node = make_node (); // MAKE_NODE HANDLES INSERT VALUE AND PRIORITY TAG IN THE NODE DATA SECTIONS AND ALSO INSERT BOTH POINTER PRE AND NEXT
  if (queue_empty (q)) { // WHEN LINKED LIST IS EMPTY 
    q->rear = q->front = new_node;
    q->rear->next = NULL;
    q->front->pre = NULL;
  }
  else { // INSERT NODE WHEN THERE IS AT LEAST ONE NODE AREADY AVAIABLE IN THE LINKED LIST
   Node *node = q->front, *pre = NULL; 
   while (node->next != NULL && node->priority_tag < new_node->priority_tag) {
     pre = node;
     node = node->next;
   }
   if (node->next->priority_tag < new_node->priority_tag) {
      node->next = new_node;
      new_node->pre = node;
      q->rear = new_node;
   }
   else 
   if (pre == NULL) { // WHEN NEW_NODE HAVE LESS PRIORITY THAN ALL } {
    pre = new_node;
    new_node->next = q->front;
    q->front->pre = new_node;
    q->front = new_node;
   }
   else { // PERFROM INSERTION WHEN THERE IS ALREADY LOW PRIORITY NODE ARE IN THE LINKED LIST 
      pre->next = new_node;
      new_node->pre = pre;
      pre = new_node;
      new_node->next = node;
      node->pre = new_node;
    }
  }
}
void peek (Queue *q) { // PRINT VALUE THAT IS AT THE TOP OF THE QUEUE 
  if (queue_empty (q)) {
    printf ("\nQueue is empty !"); 
    return;
  }
  printf ("\nData of the node at is the rear : \n");
  Node *node = q->rear; // GET POSITION OF THE PEEK OF THE QUEUE MEANS POSITION OF THE REAR 
  printf ("Priority tag : %d",node->priority_tag);
  printf ("\nData of the queue : %c",node->data);
}
void bottom (Queue *q) { // PRINT VALUE OF NODE THAT IS AT THE FRONT POSITION 
 if (queue_empty (q)) { // CHECK QUEUE IS EMPTY OR NOT EMPTY
    printf ("\nQueue is empty !");
    return;
  }
  printf ("\nData of the node at is the front : ");
  Node *node = q->front; // GET POSITION OF THE BOTTOM OF THE QUEUE 
  printf ("\nPriority tag : %d",node->priority_tag);
  printf ("\nData of the queue : %c",node->data);
}
void display_queue (Queue *q) { // METHOD THAT DISPLAY EACH NODE DATA 
 if (queue_empty (q)) { // CHECK QUEUE IS EMPTY 
    printf ("\nQueue is empty !");
    return;
  }
  printf ("\nDisplay each node data : "); // OUTPUT PROMPT
  Node *node = q->front; // SET FRONT POSITION OF THE QUEUE 
  while (node != NULL) {
    printf ("\nPriority : %d \nData : %c",node->priority_tag,node->data);
    node = node->next; // INCREMENT NODE UNTIL NODE NOT REACH AT THE REAR POSITION
  }
}
void dequeue (Queue *q) { // METHOD THAT REMOVE NODE FORM THE FRONT OF THE LINKED LIST 
  if (queue_empty (q)) { // CHECK THAT QUEUE IS EMPTY OR NOT EMPTY
    printf ("\nQueue is empty !");
    return;
  }
  Node *node = q->front;
  if (q->front == q->rear) {
    q->front = NULL;
    q->rear = NULL;
  }
  else {
    q->front = q->front->next; // POINTED FRONT TO NEXT NODE IN THE LINKED LIST
    q->front->pre = NULL; 
  }
  printf ("\nPriority %d value is deleted node !",node->priority_tag);
  free (node); // FREE HANDLES DELETION OF NODE AUTOMATICALLY FROM THE QUEUE
}
