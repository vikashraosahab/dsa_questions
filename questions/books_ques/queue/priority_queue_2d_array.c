// PRIORITY QUEUE WITH THE HELP OF 2 -DIMENSIONAL ARRAY
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// ENUMERATIONS DECLARATIONS FOR EFFECTIVE VALIDATIONS
typedef enum {
    EMPTY,
    FULLED,
    MAXIMUM = 10,
} MESSAGE; // ENUMERATIONS NAME
MESSAGE M; // ENUMERATIONS VARIABLES DECLARATIONS
// STRUCTURE BY TYPEDEFINE 
typedef struct {
    int queue [MAXIMUM][MAXIMUM]; // 2-DIMENSIONAL ARRAY THERE IS ONLY TWO ROWS AND MAXIUM COLUMS ROW 0 FOR PRIORITY TAG AND ROW 1 FOR DATA VALE
    int front;
    int rear;
} Queue; // STRUCTURE NAME 
// FUNCTIONS PROTOTYPE
void menu_bar (); // FOR SHOWING MENU BAR THAT HELPS USER TO PERFORM THEIR OPERATIONS WITH MENU
void process_menu (Queue *,int); // FOR PERFORMING TASK ACCORDING TO THE MENU BAR
int valid_input (); // FOR VALIDATION ONLY INTEGER VALUE 
int queue_empty (Queue *); // METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY
void create_queue (Queue *); // METHOD THAT CREATE QUEUE DATA STRUCTURE IN THE MEMORY
int queue_fulled (Queue *); // METHOD THAT CHECK QUEUE IS FULLLED OR NOT FULLED
void enqueue (Queue *,int); // METHOD THAT USED TO INSERT NEW VALUE IN THE QUEUE 
void dequeue (Queue *); // METHOD THAT USER TO DELETE VALUE FROM THE QUEUE
int peek (Queue *); // GET VALUE FROM THE PEEK OR FROM THE REAR OF THE QUEUE
int bottom (Queue *); // GET VALUE FROM THE BOTTOM OR FROM THE FRONT OF THE QUEUE
void display (Queue *); // PRINTING EACH DATA VALUE FROM THE QUEUE 

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char *argv[]) {
Queue q; // STRUCTURE VARIABLES DECLARATIOSN 
create_queue (&q); // ENABLE QUEUE DATA STRUCUTRE IN THE MEMORY 
int task;
while (1) {
    menu_bar (); // CALLING MENU BAR FUNCTION THAT SHOWS USER PROMPTS FOR INSTRUCTIONS
    task = valid_input (); // TAKING VALIDATED INTEGER VALUE
    if (task == 6) break; // TERMINATE THE PROGRAM WHEN TASK GOES EQUAL TO 6
    process_menu (&q,task);
  }
  return 0; // TERMIANTE SUCCESSFULLY
}
// FUNCTION DEFINTIONS 
void menu_bar () {// SHOW MENU FOR HELP USER  AS PROMPT THAT HELP WHAT TASK NEED TO PERFORM 
  printf ("\n************** MENU BAR ******************");
  printf ("\n1 : INSERTION\n2 : DELETION\n3 : DISPLAY\n4 : PEEK VALUE \n5 : BOTTOM VALUE \n6 : EXIT\n");
  printf ("\nEnter task according to the main menu : ");
}
int valid_input () { // VALIDATE USER INPUT ONLY INTEGER IS APPLICABLE 
 int val; 
 printf ("\nEnter value (only integer is allow 0 - 9) : ");
 while (1) {
    if (scanf ("%d",&val) != 1) { // CHECK THAT VAL IS ONLY INTEGER  
      while (getchar () != '\n')   // TAKE VLAUE UNTIL IT NOT ENCOUNTER WITH THE NEWLINE
        printf ("\nIn-valid input. Please re-enter value : "); // OUTPUT PROMPT
      continue;
    }
    else 
      break;
  }
  return val; // RETURN INTEGER VALUE;
}
void process_menu (Queue *q, int task) {
  switch (task) {
    case 1:
      printf ("\nInsertion of new data is in process ............ ");
        
      printf ("\nDone!");
      break;
    case 2:
    case 3:
      printf ("\nMethod that checks queue empty : %d ",queue_fulled (q));
      break;
    case 4:
      printf ("\nMethod that checks queue fulled : %d",queue_fulled (q));
      break;
    case 5:

      break;
    default:
    printf ("\nPlease enter value that related to the menu bar \n");
    break;
  }
}
void create_queue (Queue *q) {// METHOD THAT CREATE QUEUE BY INITIALIZATIO OF REAR AND FRONT AS - 1
  q->rear = q->front == -1; // INITIALIZE FRONT REAR AS -1 
}
int queue_empty (Queue *q) {// METHOD THAT CHECKS GIVEN QUEUE IS EMPTY OR NOT EMPTY
  return (q->rear == -1 && q->front == -1) ? EMPTY : !EMPTY; // WHEN REAR AND FRONT BECOME -1 THEN QUEUE IS EMPTY OTHERWISE THERE IS AT LEASE ONE ELEMENT IN THE QUEUE
}
int queue_fulled (Queue *q) { // METHOD THAT CHECK QUEUE IS FULLED OR NOT FULLED
  return (q->rear == MAXIMUM - 1) ? FULLED : !FULLED; // WHEN REAR IS EQUL TO MAXIUM THEN QUEUE BECOE FULLED QUEUE 
}
