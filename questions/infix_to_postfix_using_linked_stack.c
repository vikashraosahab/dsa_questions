// PROGRAM THAT CONVERT INFIX TO POSTFIX USING LINKED STACK
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 30
typedef char EXP;
typedef struct stack {
  EXP exp;            // EXPERIANCE
  struct stack *next; // POINTER THAT POINTING TO THE NEXT POINTER
} STACK;
STACK *top = NULL; // DECLARATION OF THE TOP LINKED OF THE LINKED LIST
STACK *make_node(STACK *, char);
STACK *push(STACK *, EXP); // METHOD THAT PUSH ELEMENT FROM THE STACK
STACK *pop(STACK *); // METHOD THAT POP ELEMENT FROM THE STACK
char peek (STACK *);
STACK *print(STACK *); // PRINT ELEMENT OF THE STACK
void infix_to_postfix (char *,char *); // INFIX TO POSTFIX 
int getPriority (char); // GET PRIORITY OF THE OPERATOR BASED ON THEIR PRECEDENCE 

// MAIN FUNCTION OF THE PROGRAM
int main(int argc, char *argv[]) {
  char infix_exp[MAXSIZE], postfix_exp[MAXSIZE];
  printf("\nEnter infix expression : ");
  fgets(infix_exp, MAXSIZE, stdin);
  infix_exp[strcspn(infix_exp, "\n")] = '\0'; // REPLACE NEW LINE WITH NULL
  top = push (top,'a');
  top = push (top,'b');
  top = push (top,'c');
  top = print (top);
  top = pop (top);
  printf ("\n%c",peek (top));
  top = print (top);
  printf ("\nPostfix expression are : ");
  puts (postfix_exp);
  return 0; // TERMINATION
}
STACK *push(STACK *top, EXP ch) { // PUSH ELEMENT IN THE STACK AT THE TOP OF THE STACK
  STACK *node = (STACK *)malloc(sizeof(STACK));
  node->next = NULL;
  if (top == NULL) {
    top = node;
  } else {
    node->next = top->next;
    top->next = node;
  }
  return top;
}
STACK *pop(STACK *top) { // POP ELEMENT FROM THE STACK
  char ch;
  if (top == NULL)
  {
    printf("\nStack is empty ? ");
  }
  else
  {
    STACK *ptr;
    ptr = top;
    top = top->next;
    free (ptr);
    ptr = top;
  }
  return top;
}
STACK *print(STACK *top) { // FUNCTION THAT PRINT ALL ELEMENTS OF THE STACK
  if (top == NULL) {
    printf("\nStack is empty ? ");
  } else {
    STACK *ptr = top;
    printf("\nElement of the node are : ");
    while (ptr != NULL) {
      printf("%c ", ptr->exp);
      ptr = ptr->next;
    }
  }
  return top;
}
char peek (STACK *top) // GET TOPMOST ELEMENT OR NODE OF THE LINKED LIST
{
  if (top == NULL)
  {
   printf ("\nStack is empty ? ");
   exit (1);
  }
  return top->exp;
}
void infix_to_postfix (char *infix,char *postfix) // FUNCITON THAT CONVERT INFIX EXPRESSION INTO POSTFIX EXPRESSION USING STACK
{
  int i = 0,j = 0;
  while (infix [i] != '\0')
  {
    if (infix  [i] == '(')
    {
     top = push (top,infix [i]);
    }
    else if (infix [i] == ')')
    {
      while (top != NULL && top->exp != '(' )
      {
        postfix [j++] = peek (top);
        top = pop (top); // REMOVE TOPMOST OF THE NODE
      }
      if (top == NULL)
      {
        printf ("\nStack is empty now !");
      }
      top = push (top,infix [i]);
    }
    else if (isdigit (infix [i]) || isalpha (infix [i]))
    {
      postfix [j++] = infix [i];
    }
    else if (infix [i] == '+' || infix [i] == '-' || infix [i] == '*' || infix [i] == '-')
    {
      while (top != NULL && top->exp != '(' && getPriority (top->exp) > getPriority (infix [i]))
      {
        postfix [j++] = peek (top);
        top = pop (top); // REMOVE NODE FROM THE TOP MOST LINKED LIST
      }
     top = pop (top);
    }
    else
    {
      printf ("\nIn-valid expression !");
      exit (1); // TERMINATE THAT PROGRAM HERE
    }
    i = i + 1; // INCREMENT BY 1 
  }
  while (top != NULL && top->exp != '(')
  {
     postfix [j++] = peek (top);
     top = pop (top);
  }
  postfix [j] = '\0'; // ASSIGN NULL OPERATOR AT THE END OF THE POSTFIX
}
int getPriority (char ch)
{
  if (ch == '*' || ch == '/' || ch == '%')
   return 2;
  else if (ch == '+' || ch == '-')
   return 1;
  else
   return 0;
}
