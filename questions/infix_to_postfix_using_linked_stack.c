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
void infix_to_prefix (char *,char *);
int getPriority (char);

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char *argv[])
{
  char infix [MAXSIZE], postfix [MAXSIZE];
  printf ("\nEnter expression : ");
  scanf ("%s",infix);
  infix_to_prefix (infix,postfix);
  printf ("%c",peek(top));
  puts (postfix);
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
void infix_to_prefix (char *infix,char *postifx) // FUNCTION THAT  PERFORM CONVERSION INFIX TO PREFIX 
{ 
  int i = 0,j = 0;
  while (infix [i] != '\0')
  {
    if (infix [i] == '(')
    {
      top = push (top,infix [i]);
    }
    else if (infix [i] == ')')
    {
     while (peek (top) != '(')
     {
      postifx [j++] = peek (top);
      top = pop (top);
     }
     if (top == NULL)
     {
      printf ("\nOKay linked is empty now !");
      return;
     }
     top = pop (top); // REMOVE OTHER CHARACTERS
    }
    else if (isdigit (infix[i]) || isalpha (infix [i]))
    {
      top = push (top,infix [i]);
    }
    else if (infix [i] == '+' || infix [i] == '-' || infix [i] == '*' || infix [i] == '/')
    {
      while (peek (top) != '(' && getPriority (top->ch) > getPriority (infix[i]))
      {
        postifx [j++] = peek (top);
        top = pop (top);
      }
      top = push (top,infix[i]);
    }
    else 
    {
      printf ("\nIn-valid expression. Please enter valid expression ?  ");
      return;
    }
    i = i + 1;
  }
  while (peek (top) != '(')
  {
    postifx [j++] = peek (top);
    top = pop (top);
  }
  postifx [j] == '\0';
}
int getPriority (char ch)
{
  if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else
   return 0;
}