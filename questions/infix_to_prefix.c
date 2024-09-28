// CONVERT INFIX EXPRESSION TO PREFIX EXPRESSION
// REVERSE EXPRESSION
// FIRST CONVERT INFIX EXPRESSION INTO POSTFIX EXPRESSION
// SECOND REVERSE POSTIFX AND IT BECOME PREFIX EXPRESSION
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 50 // MACROS DEFINITION FOR MAXIMUM LENGTH
typedef struct 
{
 char stack [MAXSIZE];
 int top;
}STACK;

void initialized (STACK *);
int isStackFull (STACK *);
int isStackEmpty (STACK *);
void reverse (char *,char *);
void infix_to_postfix (STACK *,char *, char *);
STACK push (STACK *,char);
STACK pop (STACK *);
int peek (STACK *);
int getPriority (char);

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char *argv[])
{
    STACK stack;
    STACK *stackPtr = &stack; // STACK VARIABLE DECLARATIONS
    char infix [MAXSIZE], postfix [MAXSIZE],reversed_exp [MAXSIZE];
    printf ("\nEnter your expression are : ");
    fgets (infix,MAXSIZE,stdin); // TAKE INPUT USER AND STORE INFIX EXPRESSION VARIABLE
    infix [strcspn (infix,"\n")] = '\0'; // REMOVE NEWLINE CHARACTER BY USING NULL
    int length = sizeof (infix) / sizeof (infix [0]); // GET TOTAL NUMBER OF CHARACTER IN THE STRING 
    initialized (stackPtr); // INITIALIZED STACK TOP AS - 1
    reverse (infix,reversed_exp); // REVERSE THE INFIX EXPRESSION
    infix_to_postfix (stackPtr,infix,postfix);
    reverse (postfix,infix);
    printf ("\nPrefix expression are : %s",infix);
    return 0;
}
void initialized (STACK *top) // INITIALIZATION OF THE STACK AS TOP IS -1
{
    top->top = -1;
}
int isStackFull (STACK *s) // FUNCTION COMPONENT THAT CHECK STACK IS FULLLED
{
   return s->top;
}
int isStackEmpty (STACK *s) // FUNCTION COMPONENT THAT CHECK STACK IS EMPTY OR NOT EMPTY
{
    return s->top;
}
void reverse (char *infix , char *reversed_exp) // FUNCTION COMPONENT THAT REVERSE INFIX EXPRESSION
{
   int i = strlen (infix) -1, j = 0;
   for (i; i >= 0; i--)
   {
     if (infix [i] == '(') // FIX OPEN CURLY DURING REVERSE THE STRING
     {
        reversed_exp [j++] = ')'; 
     }
     else if (infix [i] == ')') // FIXING CLOSE CURLY DURING REVERSE THE STRING
     {
        reversed_exp [j++] = '(';
     }
     else 
     {
        reversed_exp [j++] = infix [i];
     }
   }
   reversed_exp [j] = '\0';
}
STACK push (STACK *S,char ch) // PUSH DATA ELEMENT AT THE TOP OF THE STACK
{
    if (isStackFull(S))
    {
        printf ("\nStack is empty ? ");
        exit (1); // TERMINATE
    }
    else 
     S->stack[++S->top] = ch;
}
STACK pop (STACK *S) // REMOVE ELEMNT FROM THE STACK
{
    if (isStackEmpty (S))
    {
        printf ("\nStack is fulled now !");
        exit (1);
    }
    S->stack[S->top--];
}
int peek (STACK *S) // GET TOPMOST ELEMENT FROM THE STACK
{
    if (isStackEmpty (S))
    {
        printf ("\nStack is fulled now !");
        exit (1);
    }
    return S->stack[S->top]; // GETTING TOP MOST ELEMENT FROM THE STACK
}
void infix_to_postfix (STACK *s,char *infix,char *postfix) // CONVERSION OF THE INFIX TO POSTFIX EXPRESSION
{
    int i = 0, j = 0;
    while (infix [i] != '(')
    {
        if (infix [i] == '(')
         push (s,infix[i]);
        else if (infix [i] == ')')
        {
         while (s->top != -1 && s->stack [s->top] != '(')
         {
            postfix [j++] = peek (s); // INSERT TOPMOST ELEMENT FROM THE STACK 
            pop (s); // REMOVE TOPMOST ELEMENT FROM THE STACK
         }
         if (s->top == -1)
         {
            printf ("\nStakc is empty !");
            exit (1);
         }
         pop (s); // REMOVE OTHER ELEMENTS FROM THE STACK
        }
       else if (isdigit (infix [i]) && isalpha (infix [i]))
       {
        postfix [j++] = infix [i];
       }
      else if (infix [i] == '+' || infix [i] == '*' || infix [i] == '/' || infix [i] == '-')
      {
        while (s->top != -1 && s->stack [s->top] != '(' && getPriority (s->stack[s->top]) > getPriority (infix [i]))
        {
           postfix [j++] = peek (s);
           pop (s);
        }
        push (s,infix [i]);
      }
      else 
      {
        printf ("\nExpression is in-valid\nPlease enter valid input ? ");
        exit (1);
      }
    }
    while (s->top != -1 && s->stack [s->top] != '(')
    {
        postfix [j++] = peek (s);
        pop (s);
    }
    postfix [j] = '\0';
}
int getPriority (char ch) // GET PRIORITY OF THE OF OPERATOR ACCORDING THEIR PRECEDENCE 
{
    if (ch == '*' || ch == '/')
     return 2;
    else if (ch == '+' || ch == '-')
     return 1;
    else 
     return 0;
}