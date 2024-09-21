<<<<<<< HEAD
// PROGRAM THAT CONVERT INFIX EXPRESSION INTO POSTIFX EXPRESSION
=======
// PROGRAM THAT CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
<<<<<<< HEAD
#include <malloc.h>
=======
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1

// MAXIMUM SIZE OF THE ARRAY
#define MAXSIZE 30
typedef char EXP;
<<<<<<< HEAD
typedef struct listnode
{
  EXP ch;
  struct listnode *next; // NEXT POINTER THAT POINTED TO THE NEXT NODE
} STACK;
STACK *top = NULL; // ASSIGN NULL TO THE TOP OF THE listnode
=======
typedef struct stack
{
 EXP ch; // 
 struct stack *next; // NEXT POINTER 
}STACK;

STACK *top = NULL; // ASSING NULL TO TOP OF STACK
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1
STACK *make_node (char);
STACK *push (STACK *,char);
STACK *pop (STACK *);
char peek (STACK *);

<<<<<<< HEAD
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
=======
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
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1
  }
  else 
  {
<<<<<<< HEAD
   new_node->next = top;
   top = new_node;
   
  }
  return top;
}
STACK *pop (STACK *top) // REMOVE TOPMOST ELEMENT FROM THE STACK
=======
   STACK *ptr = top;
    ptr = top->next;
    free (top);
    top = ptr;
  }
  return top;
}
char peek (STACK *top)
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1
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
<<<<<<< HEAD
  return top->ch;
=======
  else 
    return top->ch;
>>>>>>> f51b51ffa268b3c048e812e8451ea7a992a091e1
}
