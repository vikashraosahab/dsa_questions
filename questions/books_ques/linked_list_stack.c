// WRITE A PROGRAM TO IMPLEMENT A STACK USING A LINKED LIST
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// USER TYPE DATA TYPE 
typedef int NODE;
typedef struct listNode // STRUCTURE DECLARATIONS 
{
 NODE val;
 struct listNode *next;
}ListNode;

// FUNCTION PROTOTYPE
ListNode *top = NULL;
bool isStackEmpty (ListNode *);
ListNode *make_node (int);
ListNode *createList (ListNode *,int);
ListNode *push (ListNode *,int);
ListNode *pop (ListNode *);
int peek (ListNode *);
void print (ListNode *);
int input ();
// MAIN FUNCTIO OF THE PROGRAM 
int main (int argc, char * argv[])
{
    int task,value;
    while (1)
    {
        /*
         MENU INFORMATION THAT HELP USER TO USE THE APPLICATION EFFICIENTLY
        */
        printf ("\n*************** MAIN MENU *******************");
        printf ("\nEnter : 1 for creation linked list ");
        printf ("\nEnter : 2 for print the linked list elements");
        printf ("\nEnter : 3 for push new element in the stack at the topmost  of the linked ");
        printf ("\nEnter : 4 for remove element from the topmost of the stack");
        printf ("\nEnter : 5 for get element of the top of the stack");
        printf ("\nEnter : 6 for exit.......");
        printf ("\nEnter task according to the main menu : ");
       task = input ();
      switch (task) // PERFORM TASK ACCORDING TO THEIR RESPECTIVE NUMBER
      {
        case 1:
         printf ("\nCreate linked using stack : ");
         while (1)
         {
             printf ("\nEnter value that you want to insert in the linked list  (-1 for exit) : ");
            if (scanf ("%d",&value) != 1)
            {
                while (getchar () != '\n')
                 printf ("\nIn-valid input. Please enter valid ");
                continue;
            }
            if (value == -1)
             break;
            top = createList (top,value);
         }
         printf ("\nLinked list is create now !");
         break;
        case 2:
         printf ("\nLinked list element are displaying now : \n");
         isStackEmpty (top) == true ? printf ("\nStack is empty ? ")
         :print (top);
         break;
        case 3:
          printf ("\nPush node in the linked list ? ");
          printf ("\nEnter value that you want to insert in the linked list ? ");
          if (scanf ("%d",&value) != 1)
          {
            while (getchar () != '\n')
             printf ("\nIn-valid input. PLease enter valid input.");
            continue;
          }
          top = push (top,value);
          printf ("\nNode is inserted now !");
          break;
        case 4:
         isStackEmpty (top) == true ? printf ("") : printf ("\nNode is popped out from the linked list ? ");
         top = pop (top);
         printf ("\nProcess is done !");
         break;
        case 5:
         isStackEmpty (top) == true ? printf ("\nStack is empty ? ")
         : printf ("\nTop most element of the stack is : %d ",peek (top));
         break;
      }
      if (task == 6)
       break; // STOP THE LOOP
    }
    return 0;
}
int input () // FUNCTION THAT TAKE INTEGER INPUT BY FULL VALIDATION METHOD
{
  int val;
  printf ("\nEnter value : ");
  while (1)
  {
    if (scanf ("%d",&val) != 1) // IF INPUT ISN'T INTEGER 
    {
    while (getchar () != '\n')
     printf ("\nIn-valid input. Please enter valid input : ");
     continue;
    }
    else 
     break;
  }
  return val;
}
bool isStackEmpty (ListNode *top)
{
    if (top == NULL)
     return true;
    else 
     return false;
}
ListNode *make_node (int value) // CREATE A NODE THAT CAN STORE A VALUE AND JOINED IN THE LINKED LIST 
{
   ListNode *node = (ListNode *) malloc (sizeof (ListNode));
   if (node != NULL)
   {
    node->val = value;
    node->next = NULL;
   }
   else 
    printf ("\nThere is space allocated for the node");
   return node;
}
ListNode *createList (ListNode *top,int val) // CREATION OF THE LINKED LIST 
{
   ListNode *new_node = make_node (val);
   if (top == NULL)
   {
    top = new_node; // INSERT NODE IN THE NULL LINKED LIST AT THE TOP
    new_node->next = NULL;
   }
   else
   {
    new_node->next = top; // INSERT NEW ELEMENT AT THE TOP OF THE STACK OR LINKED LIST 
    top = new_node;
   }
   return top;
}
void print (ListNode *top) // dISPLAY THE LINKED LIST ELEMENTS BY USING RECURSION 
{
  if (top != NULL) // BASE CASE OF THE FUNCTION
   {
    printf ("Node element is : %d\n",top->val);
    print (top->next); // FUNCTION RECURSIVE CALLING 
   }
}
int peek (ListNode *top)
{
    if (!isStackEmpty (top))
    {
      return top->val;
    }
    else 
     printf ("\nStack is empty ?");
}
ListNode *push (ListNode *top,int value) // PUSH NEW NODE AT THE TOP OF THE STACK
{
   ListNode *node = make_node (value); // ALLOCATE MAKE NODE 
   if (top == NULL)
   { 
      top = node; // PUSH NODE WHEN STACK IS EMPTY 
   }
   else 
   {
      node->next = top;
      top = node; // PUSH NODE WHEN STACK IS NOT EMPTY
   }

   return top;
}
ListNode *pop (ListNode *top) // POP NODE FROM THE LINKED LIST
{
  if (!isStackEmpty (top))
  {
    ListNode *ptr = top->next;
    free (top);
    top = ptr;
    printf ("\nNode is remove or pop out from the linked list ? ");
  } 
  else 
   printf ("\nStack is empty ? ");
  return top;
}