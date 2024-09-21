// PROGRAM THAT CONVERT INFIX EXPRESSION INTO POSTIFX EXPRESSION
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define MAXSIZE 30
typedef char EXP;
typedef struct listnode
{
  EXP ch;
  struct listnode *next; // NEXT POINTER THAT POINTED TO THE NEXT NODE
} STACK;
STACK *top = NULL; // ASSIGN NULL TO THE TOP OF THE listnode
STACK *make_node (char);
STACK *push (STACK *,char);
STACK *pop (STACK *);
char peek (STACK *);

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char *argv[]) 
{
  top = push (top,'a');
  top = push (top,'b');
  top = push (top,'e');
  top = push (top,'c');
  top = pop (top);
  printf ("%c",top->ch); 
  return 0;
}
STACK *make_node (char ch)
{
  STACK *node = (STACK *) malloc (sizeof (STACK));
  if (node == NULL)
  {
    printf ("\nThere is no memory allocated for the ");
  }
  else 
    node->ch = ch;

  return node;
}
STACK *push (STACK *top,char ch) // METHOD OF PUSHING NEW NODE IN THE LINKED LIST
{
  STACK *new_node = make_node (ch); 
  if (top == NULL)
  {
    top = new_node;
    new_node->next = NULL;
  }
  else 
  {
   new_node->next = top;
   top = new_node;
   
  }
  return top;
}
STACK *pop (STACK *top) // REMOVE TOPMOST ELEMENT FROM THE STACK
{
  if (top != NULL)
  {
   STACK *ptr = top->next;
   free (top);
   top = ptr;
  }
  else 
    printf ("\nStack is empty ? ");
 
  return top;
}
char peek (STACK *top) // GET TOPMOST ELEMENT FROM THE STACK
 {
  if (top == NULL)
  {
   printf ("\nStack is empty !");
    exit (1); // TERMINATE
  }
  return top->ch;
}
