// PROGRAM THAT CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// MAXIMUM SIZE OF THE ARRAY
#define MAXSIZE 30
typedef char EXP;
typedef struct stack
{
 EXP ch; // 
 struct stack *next; // NEXT POINTER 
}STACK;

STACK *top = NULL; // ASSING NULL TO TOP OF STACK
STACK *make_node (char);
STACK *push (STACK *,char);
STACK *pop (STACK *);
char peek (STACK *);

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char *argv[])
{
  top = push (top,'a');
  top = push (top,'b');
  top = push (top,'c');
  top = push (top,'d');
  top = pop (top);
  printf ("%c",peek (top));
  return 0;
}
STACK *make_node (char ch) // CREATE MAKE NODE 
{
  STACK *node = (STACK *) malloc (sizeof (STACK));
  if (node != NULL)
  {
    node->ch = ch; // PASS THE VALUE IN THE NODE CH BASE
  }
  else 
    printf ("\nThere is no memory allocated ");

  return node;
}
STACK *push (STACK *top,char value) // THIS IS FUNCTION METHOD IS USED FOR PUSH ELEMENT TO THE HEAD OF THE LINKED 
{
   STACK *new_node = make_node (value);
   if (top == NULL)
  {
      top = new_node;
  }
  else 
  {
      new_node->next = top;
      top = new_node;
  }

  return top;
}
STACK *pop (STACK *top) // POP REMOVE  ELEMENT FROM THE TOP OF THE STACK
{
  if (top == NULL)
  {
   printf ("\nStack is empty ? ");
   exit (1); 
  }
  else
  {
   STACK *ptr = top;
    ptr = top->next;
    free (top);
    top = ptr;
  }
  return top;
}
char peek (STACK *top)
{
  if (top == NULL)
  {
   printf ("\nStack is empty ? ");
  }
  else 
    return top->ch;
}
