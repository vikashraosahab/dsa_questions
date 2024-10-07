// CREATE CIRCULAR LINKED LIST QUEUE 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ENUMERATION FOR VALIDATION MESSAGE
typedef enum {
    EMPTY = 1,
    NOT_EMPTY = 0,
} MESSAGE;

MESSAGE M; // VARIABLE DECLARATION FOR THE ENUMBERATION STRUCTURE NAME
typedef struct node { // STRUCTURE FOR CREATING A PARTICULAR NODE 
    int value;
    struct node *next; // NEXT POINTER 
}Node;
typedef struct queue { // STRUCTURE THAT DEFINE QUEUE ADT
    Node *front,*rear;
}Queue; 
// FUNCTION PROTOTYPE
Queue *queue = NULL; // DECLARATION AND DEFINITION A NULL QUEUE ADT
void initialized_queue (Queue *); // INITIALIZED QUEUE ADT IN THE MEMORY
void menu_bar ();  // DISPLAY MENU BAR
void process_menu (Queue *,int); // DISPLAY PROCESS BAR 
int valid_input (); // VALID INPUT THAT ENTER BY USER
int empty (Queue *); // CHECK THAT QUEUE IS EMPTY OR NOT
int peek (Queue *); // GET VALUE OF THE TOP OF THE QUEUE
int bottom (Queue *); // GET VALUE OF THE BOTTOM OF THE QUEUE
Node *make_node (int); // CREATE A NODE THAT STORE PARTICULAR INFORMATION 
Queue *enqueue (Queue *,int); // INSERTION PERFORM FROM THE REAR SIDE OF THE QUEUE
Queue *dequeue (Queue *); // DELETION FROM FRONT SIDE OF THE QUEUE
void display (Queue *q); // DISPLAY EACH VALUE OF THE QUEUE

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
    
   // initialized_queue (queue); // FUNCTION THAT INITIALIZED QUEUE 
    int value;
    while (1) {
        menu_bar (); // MENU BAR
        value = valid_input (); // CALLING VALID_INPUT FUNCTION FOR VALIDATION INTEGER ONLY
        if (value == 6) break;  // BREAK THE LOOP 
        process_menu (queue,value); // PROCESS CALLING EXECUTE EACH TASK ACCORDING 
    }
    printf ("\nExit the program !");
    return 0;
}
void initialized_queue (Queue *q) {
  if (queue == NULL) {
    q->front = q->front = NULL;
  }
}
void menu_bar () { // FOR DISPLAY MENU OUTPUT PROMPT
    printf ("\n************** MENU BAR ****************");
    printf ("\n1 : Insertion\n2 : Deletion\n3 : Peek\n4 : Bottom \n5 : Display\n6 : EXIT");
    printf ("\nEnter task according to the menu bar : ");
}
int valid_input () {// THIS FUNCTION ALLOW ONLY INTEGER VALUE OTHERWISE ASK RE-ENTER VALUE TO USER
  int val;
  while (1) {
    if (scanf ("%d",&val) != 1) {  // CHECK INPUT IS INTEGER OR OTHER DATA TYPE
        while (getchar () != '\n'); // NEW_LINE CHARACTER ISN'T CONSIDER AS RIGTH OR WRONG NOT SHOW ERROR PROMPT WHEN ENCOUTNER WITH NEWLIEN
         printf ("\nEntered input is valid. Re-enter input : ");
        continue; 
    } 
    else  // IF INPUT IS ALREADY INTEGER THEN BREAK THE REPEATION AND RETRUN VALUE 
      break;
  }
  return val;
}
void process_menu (Queue *queue,int task) {// EXECUTE THE PROGRAM ACCORDING TO THE USER ENTER
  switch (task) {
    case 1:
     printf ("\nInsertion is in process.........");
     printf ("\nEnter value that you want to be inserted : ");
     int value = valid_input ();
    
     printf ("\nDone !");
     break;
    case 2:
     printf ("%d",empty (queue));
     break;
    case 3:
    case 4:
    case 5:
  }
}
int empty (Queue *q) { // FUNCTION THAT CHECK THAT EMPTY 
  if (q == NULL)
    return EMPTY;
  else 
    return NOT_EMPTY;
}
