// FIND OUT THE GCD AND LCM BY USING RECURSION
// GCD GREATEST COMMON DIVISIOR AND LCM LEAST COMMON MULTIPLAY
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int gcd (int,int);

// MAIN FUNCTION OF THE PROGRAM
int main (int argc, char * argv[])
{
   int a,b;
   printf ("\nEnter value a and b");
   scanf ("%d %d",&a,&b);
   int result = gcd (a,b);
   printf ("\nGcd is %d",result);
    return 0;
}
int gcd (int a, int b)
{
    if (a == 0 || a == 1)
     return 1;
    else 
     return gcd (a, b %a);
}