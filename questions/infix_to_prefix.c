// PROGRAM THAT CONVERT INFIX TO PREFIX EXPRESSION
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 50
// DECLARATION OF THE ARRAY FOR STACK WITH MAXSIZE
char stack [MAXSIZE];
int top = -1; // TOP IS EQUL TO -1 
void push (char [], char); // PUSH METHOD IS USED TO INSERT DATA IN THE STACK ARRAY
int pop (char []); // POP METHOD IS USED TO REMOVE DATA FROM THE STACK OF THE ARRAY
void infix_to_prefix (char *, char *); // CONVERT INFIX TO PREFIX EXPRESSION 
void reverse (char *,char *);
int getPriority (char);

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
    char infix [MAXSIZE],postfix [MAXSIZE], reversed_exp [MAXSIZE];
    printf ("\nEnter infix expression are ");
    fgets (infix,MAXSIZE,stdin);
    infix [strcspn (infix,"\n")] = '\0';
    reverse (infix,reversed_exp);
    puts (reversed_exp);
    infix_to_prefix (reversed_exp,postfix);
    puts (postfix);
    reverse (postfix,infix);
    puts ("\nPrefix expression are : ");
    puts (infix);
    return 0;
}
void push (char stack [],char ch) // PUSH METHOD IS USED PUSH DATA ELEMENT IN THE STACK ARRAY AT THE TOP POSITION
{
    if (top >= MAXSIZE)
    {
        printf ("\nSTACK IS FULLED NOW !");
        exit (1);
    }
    stack [++top] = ch;
}
int pop (char stack []) // POP METHOD IS USED FOR POP DATA ELEMENT FROM THE TOPMOST OF THE STACK
{
    if (top <= -1)
    {
        printf ("\nSTACK IS EMPTY NOW !");
        exit (1);
    }
    return stack [top--];
}
void reverse (char *infix,char *reverse)
{
   int i,j = 0;
   i = strlen (infix) - 1;
    while (i >= 0)
    {
       if (infix [i] == '(')
        reverse [j++] = ')';
       else if (infix [i] == ')')
        reverse [j++] = '(';
       else 
        reverse [j++] = infix [i];
        i--;
    }
    reverse [j] = '\0';
}
int getPriority (char ch)
{
    if (ch == '+' || ch == '-')
     return 1;
    else if (ch == '*' || ch == '/')
     return 2;
    else 
     return 0;
}
void infix_to_prefix (char *infix,char *postfix)
{
    int i = 0, j = 0;
    while (infix [i] != '\0')
    {
        if (infix [i] == '(')
        {
            push (stack,infix[i]);
        }
        else if (infix [i] == ')')
        {
            while (top != -1 && stack [top] != '(')
            {
               postfix [j++] = pop (stack);
            }
            if (top == -1)
            {
                printf ("\nStack is empty ? ");
                exit (1);
            }
            pop (stack);
        }
        else if (isdigit (infix [i]) || isalpha (infix [i]))
        {
            postfix [j++] = infix [i];
        }
        else if (infix [i] == '+' || infix [i] == '*' || infix [i] == '-' || infix [i] == '/')
        {
            while (top != -1 && stack [top] != '(' && getPriority (stack [top]) > getPriority (infix [i]))
            {
               postfix [j++] = pop (stack);
            }
            push (stack,infix [i]);
        }
        else 
        {
            printf ("\nEXPRESSION ARE IN-VALID \n");
            exit (1);
        }
        i++;
     }
     while (top != - 1 && stack [top] != '(')
     {
            postfix [j++] = pop (stack);
     }
     postfix [j] = '\0';
}