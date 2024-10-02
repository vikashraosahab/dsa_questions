// PROGRAM THAT CONVERT INFIX EXPRESSION INTO POSTFIX EXPRESSION 
/*
** FIRST REVERSE INFIX EXPRESSION ***
** SECOND CONVERT REVERSED EXPRESSION INTO POSTIFX **
** THIRD  REVERSE POSTIFX EXPRESSI AND YOU GET THE PREFIX EXPRESSION **
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 50 // DEFINE MACROSS DEFINITION FOR THE SIZE OF THE ARRAY
typedef struct node // STRUCTURE DEFINITION 
{
    char ch;
    int count; // COUNT GENERALLY USED FOR SET LIMITATIONS
    struct node *next; // POINTED TO THE NEXT NODE 
} STACK;
STACK *top = NULL; // TOP MEANS TOP POINTER OF THE STACK 
STACK *make_node (char); // MAKE A NODE 
STACK *push (STACK *,char ); // PUSH METHOD IS USED FOR INSERT NEW NODE AT THE TOP OF THE STACK
STACK *pop (STACK *); // POP METHOD IS USED FOR REMOVE NODE FROM THE TOP OF THE STACK
char peek (STACK *); // PEEK METHOD IS USED FOR GET TOPMOST ELEMENT OF THE STACK WITHOUT REMOVING IT
// CONVERSION RELATED FUNCTION 
void reverse (char *,char *); // REVERSE STRING FROM END TO FIRST CHARACTER
void infix_to_prefix (STACK *,char *,char *); // CONVERT INFIX CHARACTER INTO PREFIX CHARACTER
int getPriority (char *); // RETURN VALUE BASED ON THE PRIORITY OF THE OPERATOR ACCORDING THEIR PRECEDENCE 
//void print (char *);

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[])
{
    
    char infix [MAXSIZE], prefix [MAXSIZE], reversed [MAXSIZE]; // VARIABLE DECLARATIONS
    printf ("\nEnter your infix expression : ");
    fgets (infix,MAXSIZE,stdin); // TAKE INPUT UNTIL MAXSIZE
    infix [strcspn (infix,"\n")] = '\0'; // REPLACE NEWLINE CHARACTER WITH THE NULL CHARACTER
    reverse (infix,reversed); // FUNCTION CALLING FOR REVERSE INFIX EXPRESSION
    puts (reversed);
    return 0;
}
STACK *make_node (char ch) // MAKE A NODE 
{
  STACK *node = (STACK *) malloc (sizeof (STACK)); // DYNAMIC ALLOCATION OF THE MEMORY
  if (node != NULL)
  {
    node->ch = ch;
    node->next = NULL;
  }
  return node;
}
STACK *push (STACK *top,char ch) // PUSHING NEW ELEMENT AT THE TOP OF THE STACK
{
  STACK *node = make_node (ch);
  if (top == NULL)
  {
    top = node;
    top->count = 1;
  }
  else if (top->count >= MAXSIZE) // WHEN STACK IS CROSS LIMIT OF THE MAXSIZE 
  {
    printf ("\nSTACK IS FULLED NOW !");
    exit (1); // TERMINATE THE PROGRAM HERE
  }
  else 
  {
   node->next = top;
   top = node;
  }

  return top;
}
STACK *pop (STACK *top) // POP METHOD IS REMOVING NODE FROM THE TOPMOST OF THE STACK
{
  if (top == NULL)
  {
    printf ("\nStack is empty now !");
    exit (1);
  }
  else 
  {
    STACK *ptr = top->next; // INCREMENT TOP BY 1 FOR SET NEXT VALUE AT THE TOP OF THE STACK
    free (top); // DELETE ALL THE STACK 
    top = ptr; // COPY ALL STACK AFTER DELETION OF THE TOPMOST VLAUE AGAIN IN TOP
    top->count -= 1;
  }
  return top;
}
char peek (STACK *top) // GET TOPMOST CHARACTER OF THE STACK
{
  if (top == NULL)
  {
    printf ("\nStack is empty now !");
    exit (1);
  }
  else 
   return top->ch;
}
void reverse (char *str,char *str2) // REVERSE INFIX EXPRESSION
{
  int length = strlen (str) - 1, i = 0; // GET THE TOTAL LENGTH OF THE STRING
  while (length >= 0)
  {
    if (str [length] == '(')
      str2 [i++] = ')';
    else if (str [length] == ')')
      str2 [i++] = '(';
    else 
      str2 [i++] = str [length]; // PASS CHARACTER OF THE STRING FROM THE END TO FIRST IN SECOND 
    length = length - 1; // DECREMENT LENGTH BY 1
  }
  str2 [i] = '\0'; // INSERT NULL CHARACTER AT THE END OF THE STRING 2
}
