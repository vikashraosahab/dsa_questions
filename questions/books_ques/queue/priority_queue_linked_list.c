// IMPLEMENTATION OF THE PRIORITY QUEUE USING LINKED LIST 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// DEFINITION OF THE ENUMERATION FOR HANDLING ERRORS
typedef enum {
  EMPTY, // DATA MEMBER OF THE ENUMERATION DATA TYPE
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
void enqueu (Queue *); // METHOD THAT INSERT NEW ELEMENT FROM THE REAR SIDE
void dequeu (Queue *); // METHOD THAT REMOVE OR DELETE NODE FROM THE FRONT SIDE 
void peek (Queue *); // GET VALUE OF THE QUEUE FROM THE REAR SIDE
void bottom (Queue *); // GET VALUE OF THE QUEUE FROM THE FRONT SIDE
bool queue_empty (Queue *); // METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY
void display_queue (Queue *); // METHOD THAT DISPLAY ALL DATA OF THE LINKED LIST
// MAIN FUNCTION OF THE PROGRAM 
// ENTRY POINT OF THE PROGRAM
int main (int argc, char * argv[]) {
  Queue *q;  // STRUCTURE POINTER VARIABLE DECLARATIONS
  int val;
  while (1) {
    menu (); // CALLING MENU METHOD FOR DISPLAYING EACH INSTRUCTIONS TO THE USER EVERY TIME
    val = input_int (); // INPUT PROMPT
    if (val == 6) break; // WHEN USER INPUT VALUE 6 THEN ACCORDING TO THE MENU TERMINATE THE LOOP
    process_menu (q); // 
  }
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
  rturn value;
}
void process_menu (Queue *q,int task) { // METHOD THAT PERFORM USER INSTRUCTED OPERATIONS BASED ON MENU INSTRUCTION 
 switch (task) {
    case 1:
     printf ("\nInsert new node in the linked list : ");

     printf ("\nDone !");
    break;
    case 2:
     printf ("\nDeletion of node is in process .........");
     break;
    case 3:
     break;
    case 4:
     break;
    case 5:
     break;
    default:
     printf ("\nValue %d is not associated with any task in menu instructions !");
     break;
  }
}
