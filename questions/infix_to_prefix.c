// PROGRAM CONVERT INFIX TO POSTFIX EXPRESSION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>

#define SIZE 20 // SYMBOLIC CONSTANT 
typedef int TOP;
typedef int OPERATOR;
typedef struct 
{
    TOP top;
    OPERATOR operator[SIZE];
} STACK;

int isEmpty (STACK);
int isFull (STACK);
int isOperator (char);
int stack_top (STACK);
char pop (STACK);
char push (STACK);
int precedence (char );
char *infix_to_postfix (char *);

// MAIN FUNCTION OF THE PROGRAM
void main (int argc, char *argv[])
{

}