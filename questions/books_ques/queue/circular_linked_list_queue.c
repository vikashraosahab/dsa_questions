// CREATE A QUEUE USING LINKED LIST 
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    EMPTY = 1,
    NOT_EMPTY = 0,
}MESSAGE;
MESSAGE m; // GLOBALLY DECLARATION OF THE ENUMBERATION VARIABLES
typedef struct node {
    int value;
    struct node *next;
}Node;

typedef struct queue {
  Node *front,*rear;
} Queue;

void menu  ();
void process_menu (Queue *,int);
int valid_input ();
void create_queue (Queue *);
int queue_empty (Queue *);
Node *make_node (int);
void enqueue (Queue *,int);
void dequeue (Queue *);
int peek (Queue *);
int bottom (Queue *);
void display (Queue *);

// MAIN FUNCTION 
int main (void) {
    Queue *q = (Queue *) malloc (sizeof (Queue));
    create_queue (q); // CREATE QUEUE
    int val;
    while (1) {
        menu ();
        val = valid_input ();
        if (val == 6) break;
        process_menu (q,val);
    }
    return 0;
}
void menu () { // DISPLAY MENU CART
    printf ("\n************ MENU BAR ***********");
    printf ("\nEnter : 1 for insertion : ");
    printf ("\nEnter : 2 for deletion : ");
    printf ("\nEnter : 3 front side value : ");
    printf ("\nEnter : 4 rear side value : ");
    printf ("\nEnter : 5 display : ");
    printf ("\nEnter : 6 for exit : ");
    printf ("\nEnter task according main menu : ");
}
int valid_input () { // VALID INPUT FOR INTEGER , ONLY INTEGER ARE VALID
  int value;
  while (1) {
    if (scanf ("%d",&value) != 1) {
        while (getchar () != '\n')
         printf ("\nIn-valid input. Please enter valid input : ");
        continue;
    }
    else 
     break;
  }
  return value;
}
void process_menu (Queue *q,int task) {// PERFORM TASK ACCORDING MENU 
  switch (task) {
    case 1:
      printf ("\nInsert node in the queue : ");
      int val = valid_input ();
      enqueue (q,val);
      printf ("\nvalue %d is inserted now !\nDone !");
      break;
    case 2:
      printf ("\nDeletion node from the queue : ");
      dequeue (q);
      printf ("\nDone !");
      break;
    case 3:
      queue_empty (q) == EMPTY ?
      printf ("\nQueue is empty !")
      : printf ("%d is the peek value ",peek (q));
      break;
    case 4:
        queue_empty (q) == EMPTY ?
      printf ("\nQueue is empty !")
      : printf ("%d is the bottom value ",bottom (q));
      break;
    case 5:
      queue_empty (q) == EMPTY ?
      printf ("\nQueue is empty !")
      : display (q);
      break;
  }
}
void create_queue (Queue *q) {
    q->front == NULL;
    q->rear == NULL;
}
int queue_empty (Queue *q) {
    if (q->front == NULL)
      return EMPTY;
    else 
      return NOT_EMPTY;
}
Node *make_node (int value) {// CREATE NODE 
 Node *new_node = (Node *) malloc (sizeof (Node));
 if (new_node != NULL) {
   new_node->value = value;
 }
 else {
    printf ("\nNode is not allocated !");
 }
 return new_node;
}
void enqueue (Queue *q,int val) {/// INSERTION NEW NODE IN THE QUEUE 
 Node *node = make_node (val);
 if (node != NULL) {
    if (queue_empty (q)) {
        q->front = q->rear = node;
        q->rear->next = q->front;
    }
    else {
        q->rear->next = node;
        q->rear = node;
        q->rear->next = q->front;
    }
 }
}
void dequeue (Queue *q) {
    if (queue_empty (q)) {
        printf ("\nQueue is already empty");
        return;
    }
    Node *ptr = q->front;
    if (q->front == q->rear ) {
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    free (ptr); 
}
int peek (Queue *q) {
    Node *ptr = q->rear;
    return ptr->value;
}
int bottom (Queue *q) {
    Node *ptr = q->front;
    return ptr->value;
}
void display (Queue *q) {
    Node *ptr = q->front;
    while (ptr != q->rear){
        printf ("value : %d\n",ptr->value);
        ptr = ptr->next;
    }
}