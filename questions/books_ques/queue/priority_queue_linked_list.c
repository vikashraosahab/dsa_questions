// IMPLEMENTATION OF THE PRIORITY QUEUE BY USING LINKED LIST 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// ENUMERATION FOR HANDLING
typedef enum {
    EMPTY,
} VALID_MESS;
VALID_MESS ERROR_MESSAGE; // VARIABLE DECLARTION OF THE ENUMERATIONS STRUCTURE
// DECLARATION OF THE NODE STRUCTURE WITH RESPECTIVE DATA MEMBERS POINTER VARIALBES
// THIS IS DOUBLE LINKED LIST 
typedef struct node {
   int priority_tag; // PRIORITY TAG WITH HIGHTEST AND LOWEST VAUES
   char data; // ACTUALL DATA 
   struct node *next; // NEXT POINTER THAT POINTED TO NEXT NODE NULL AT THE END
   struct node *pre; // PRE POINTER THAT POINTED TO PRE NODE OR NULL AT THE BEGGINNING
} Node;
typedef struct { // LINKED LIST QUEUE
  Node *front; // FRONT POINTER VARIABLE FOR DELETION
  Node *rear; // REAR POINTER VARIALBE FOR INSERTION
}Queue;

// FUNCTION PROTOTYPES FOR MANIPULATION OF THE QUEUE DATA STRUCTURE
void create_queue (Queue *); // INITIALIZE REAR AND FRONT TO NULL 
void menu_bar (); // SHOW EACH MENU TO THE USER
void process_menu (Queue *,int); // PEROFRM EACH OPERATION ON USER INSTRUCTUIONS
int valid_int_input (); // METHOD CHECK THAT VALUE MUST RETURN IN INTEGER ONLY 
Node *make_node (); // CREATE NODE THAT STORE VALUE AND OTHER DATA MEMBERS 
void enqueue (Queue *); // PERFROM INSERTION FROM THE REAR SIDE OF THE LINKED LIST BUT PRIORITY ALSO CHECKS
void dequeue (Queue *); // PERFORM DELETION OF THE NODE FROM THE FRONT SIDE OF THE LINKED LIST
int queue_empty (Queue *); // CHECK QUEUE IS EMPTY OR NOT EMPTY
void peek (Queue *); // GET NODE FROM THE PEEK OR REAR SIDE
void bottom (Queue *); // GET NODE FROM THE BOTTOM OR FRONT SIDE 
void display (Queue *); // FOR DISPLAYING EACH CHARACTER FROM THE LINKED LIST
// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[]) {
    Queue q;
       create_queue (&q); // INITIALIZE FRONT AND REAR POINTER TO THE NULL 
       int val; // VARIABLE DECLARATIONS
       while (1) {
         menu_bar (); // METHOD THAT DISPLAY EACH MENU TO THE USER AS USER PROMPT
         val = valid_int_input (); // VALIDATE USER INPUT 
         if (val == 6) break; // EXIT THE LOOP WHEN USER ENTER 6 
         process_menu (&q,val); // CALLING FOR PERFORMMING EACH TASK ACCORDING TO THE MAIN MENU       
        }   
   
    printf ("\nProgram is ended now !"); // OUTPUT PROMPT 
    return 0; // TERMINATION
}
void menu_bar () { // DISPLAY EACH INSTRUCTION MENU TO THE USER
  printf ("\n*********** MENU BAR *************");
  printf ("\n1 : Insertion \n2 : Deletion\n3 : Peek \n4 : Bottom \n5 : Display \n6 : Exit");
  printf ("\nEnter task only in number according to the user menu : ");
}
void process_menu (Queue *q,int task) {// PROCESS TASK BASED ON THE TASK 
  switch (task){
    case 1:
     printf ("\nInsert new value in the queue : "); // OUTPUT PROMPT
     enqueue (q); // ENQUEUE METHOD IS CALLING NOW 
     printf ("\nDone !"); // OUTPUT PROMPT
     break;
    case 2:
     break;
    case 3:
     peek (q); // CALLING THE METHOD 
     break;
    case 4:
     bottom (q);
     break;
    case 5:
     break;
    default: // USER ENTER VALUE MORE THAN MENU BAR OR OUT OF SCOPE VALUES ARE IN-VALID
     printf ("\nPlease enter value that describe in the menu bar !");
     break;
  }
}
int valid_int_input () { // TAKE INPUT ONLY INTEGER 
  int value;
  while (1) {
    printf ("\nEnter input value : ");
    if (scanf ("%d",&value) != 1) {
        while (getchar () != '\n')
         printf ("\nIn-valid input value. Re-enter value : ");
        continue;
    }
    else 
      break;
  }
  return value;
}
void create_queue (Queue *q) { // METHOD INITIALIZE FRONT AND QUEUE AS NULL 
    if (q == NULL) {
        q->front = q->rear = NULL; // INITIALIZATION NULL TO THE REAR AND FRONT WHERE THERE IS NO ELEMENT IN THE QUEUE
    }
}
int queue_empty (Queue *q) { // CHECK QUEUE IS EMPTY OR NOT EMPTY
  return (q->front == NULL && q->rear == NULL) ? EMPTY : !EMPTY; // WHEN FRONT AND REAR ARE NULL THE RETURN EMPTY OTHERWISE RETURN NOT EMPTY
}
Node *make_node () {
    Node *node = (Node *) malloc (sizeof (Node)); // DYNAMIC ALLOCATION MEMORY FOR THE NODE 
    if (node != NULL) {
        int tag,value;
        printf ("\nEnter priority of the data : ");
        tag = valid_int_input (); 
        getchar ();
        printf ("\nEnter data of the node : ");
        scanf ("%c",&value); // VALUE CAN BE INTEGER OR CHARACTER
        node->priority_tag = tag; // INITIALIZE TAG IN THE PRIORITY TAG 
        node->data = value; // INITIALIZE VALUE IN THE DATA 
        node->next = NULL; // POINTING NULL FROM THE NEXT POINTER
        node->pre = NULL; // POINTTING NULL FROM THE PRE POINTER
    }
    else { // ERROR STATEMENT 
        printf ("\nError : there is no dynamic allocation memory the node !");
    }
    return node; // RETURN MULTI PARADIGAM RETURN VALUES
}
void enqueue (Queue *q) { // METHOD THAT USED FOR INSERT NEW NODE IN THE LINKED LIST 
 Node *new_node = make_node (); // CALLING MAKE_NODE METHOD HANDLING INSERTION VALUE IN THE NODE 
 // FIRST CHECK QUEUE IS EMPTY OR NOT EMPTY
 // IF NULL THEN INSERT NODE AT THE REAR AND FORNT BOTH == 0
 if (queue_empty (q) == EMPTY) {
   q->rear = q->front = new_node;
   q->rear = new_node->next = NULL;
   q->front = new_node->pre = NULL;
 }
 else {
  q->rear->next = new_node;
  new_node->pre = q->rear;
  q->rear = new_node;
  q->rear->next = NULL;
 }
}
void peek (Queue *q) { // GET PEEK OF THE VALUE FROM THE STRUCTURE 
  if (queue_empty (q) == EMPTY) {
    printf ("\nQueue is empty !");
    return;
  }
  Node *node = q->rear;
  printf ("priority tag : %d\n",node->priority_tag);
  printf ("Data of the node : %c\n",node->data);
}
void bottom (Queue *q) {
  if (queue_empty (q) == EMPTY) {
    printf ("\nQueue is empty !");
    return;
  }
  Node *node = q->front;
  printf ("%d",node->priority_tag);
}