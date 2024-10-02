// CONVERT INFIX EXPRESSION INTO POSTFIX EXPRESSION 
// PROGRAM THAT CONVERT A+B INTO AB+ (INFIX INTO POSTIFX)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 40 // MACROS DEFINITION FOR THE MAXIMUM LENGTH OF THE ARRAY
// DECLARATION OF THE STRUCTURE 
// CREATION OF THE STACK USING LINKED LIST
typedef struct listnode 
{
 char value;
 struct listnode *next; // NEXT POINTER THAT POINT TO THE NEXT NODE 
}ListNode;
// FUNCTION PROTOTYPES
ListNode *top = NULL;
ListNode *make_node (char);
ListNode *push (ListNode *,char); // PUSH METHOD IS USED FOR PUSH NEW NODE IN THE LINKED LIST AT THE TOP OF THE STACK
ListNode *pop (ListNode *); // POP METHOD IS USED FOR REMOVE OR DELETE NODE FROM THE LINKED LIST AT THE TOP OF THE STACK
char peek (ListNode *); // GET THE CHARACTER THAT IS TOPMOST OF THE STACK
bool isStackEmpty (ListNode *); // CHECK THE STACK IS EMPTY OF NOT (UNDERFLOW CONDITION VALIDATION)
// bool isStackFull (ListNode *); // CHECK THE STACK IS FULLED OR NOT (OVERFLOW CONDITION VALIDATION)
void infix_to_postfix (ListNode *,char *,char *); // CONVERT INFIX EXPRESSION INTO POSTFIX EXPRESION 
int getPriority (char); // THIS METHOD CHECK EACH CHARACTER AND RETURN VALUES ACCORDING TO THEIR PRIORITY 
void print (ListNode *); // PRINT THE EXPRESSION THAT PASSED AS ARGUMENTS
// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
   // ListNode s // STRUCTURE VARIABLE DECLARATIONS
    char infix_exp [MAXSIZE],postfix_exp [MAXSIZE]; // ARRAY DECLARATIONS
    printf ("\nEnter infix expression : ");
    fgets (infix_exp,MAXSIZE,stdin); // FOR GETTING INPUT UNITL MAXSIZE
    infix_exp [strcspn (infix_exp,"\n")] = '\0'; // REMOVE NEWLINE WITH NULL OPERATOR
    infix_to_postfix (top,infix_exp,postfix_exp);
    puts (postfix_exp); // PRINT THE POSTFIX EXPRESSION 
   // printf ("%c",peek (top));
    return 0; // TERMINATE THE WHOLE FUNCTION SUCCESSFULLY
}
// FUNCTION DEFINTIONS
bool isStackEmpty (ListNode *top) // CHECKING STACK IS EMPTY OR NOT 
{
    if (top == NULL)
     return true; // RETURN TRUE WHEN STACK IS EMPTY
    else  
     return false; 
}
ListNode *make_node (char ch) // CREATE A NODE THAT STORE VALUE AT THE HEAP MEMORY (DYNAMICALLLY)
{
    ListNode *node = (ListNode *) malloc (sizeof (ListNode)); // ALLOCATION OF THE DYNAMIC MEORY 
    if (node != NULL)
    {
        node->value = ch;
        node->next = NULL;
    }
    else 
     printf ("\nThere is no dynamic memory allocated !");
    return node;
}
ListNode *push (ListNode *top,char value) // PUSH METHOD IS USED FOR INSERT ELEMENT AT THE TOP OF THE STACk
{
    ListNode *node = make_node (value);
   if (isStackEmpty (top) == true)
     top = node; // WHEN TOP IS NULL INSERT NODE AT THE TOP OF THE STACK 
   else  // WHEN STACK IS NOT NULL THEN INSERT NEW ELEMENT NODE AT THE TOP OF THE STACK AND MOVE OTHER LINKED LIST NODE FROM THE TOP
   {
    node->next = top;
    top = node;
   }
   return top;
}
ListNode *pop (ListNode *top) // POP METHOD IS USED FOR REMOVE ELEMENT FROM THE TOP OF THE STACK
{
    if (isStackEmpty(top))
    {
        printf ("\nStack is empty !");
    }
    else 
    {
        ListNode *ptr = top->next;
        free (top); // REMOVE OR DELETE ALL THE LINKED LIST
        top = ptr; // COPY LINKED LIST NODE INTO TOP AGAIN
    }
    return top;
}
char peek (ListNode *top) // GET TOPMOST CHARACTER 
{
  if (top == NULL)
  {
    printf ("\nStack is empty !");
    exit (1);
  }
  else 
   return top->value;
}
void infix_to_postfix (ListNode *top,char *infix,char *postfix) // CONVERT INFIX I INTO POSTIFX P EXPRESSION
{
    int i = 0, j = 0;
    while (infix [i] != '\0')
    {
        if (infix [i] == '(')
        {
            top = push (top,infix [i]); // PUSH INTO THE STACK 
        }
        else if (infix [i] == ')')
        {
            while (top != NULL && top->value != '(')
            {
                postfix [j++] = peek (top);
                top = pop (top); // REMOVE CHARACTER FROM THE LINKED LIST 
            }
            top = pop (top);
        }
        else if (isdigit (infix [i]) || isalpha (infix [i]))
        {
            postfix [j++] = infix [i];
        }
        else if (infix [i] == '+' || infix [i] == '*' || infix [i] == '/' || infix [i] == '-')
        {
            while (top != NULL && top->value != '(' && getPriority (top->value) > getPriority (infix [i]))
            {
                postfix [j++] = peek (top);
                top = pop (top); // REMOVE TOPMOST ELEMENT FROM THE STACK
            }
            if (top == NULL)
            {
                printf ("\nStack is empty ? ");
                exit (1);
            }
            top = push (top,infix [i]); // REMOVE OTHER CHARACTERS FROM THE STACK
        }
        else 
        {
            printf ("\nIn-valid expression");
            exit (1);
        }
        i = i + 1; // INCREMENT I BY 1
    }
    // REMOVE OTHER ALL CHARACTER FROM THE STACK
    while (top != NULL && top->value != '(')
    {
        postfix [j++] = peek (top);
        top = pop (top);
    }
    postfix [j] = '\0'; // INITIALIZE NULL CHARACTER IN THE POSTFIX EXPRESSION AFTER THE OVERALL 
}
int getPriority (char ch) // METHOD THAT CHECK THE PRIORITY OF THE OPERATOR BASED ON THE PRECEDENCE OF THE PARTICULAR CHARACTER
{
    if (ch == '*' || ch == '/')
     return 2; // HIGHER PRECEDENCE 
    else if (ch == '+' || ch == '-')
     return 1; // LOWER PRECEDENCE 
    else 
     return 0; // LEAST PRECEDENCE 
}
void print (ListNode *top)
{
    ListNode *ptr;
    ptr = top;
    while (ptr != NULL)
    {
        printf ("\n%c",ptr->value);
        ptr = ptr->next;
    }
}