// CREATION OF THE HASH TABLE 
/*
* HASH TABLE IS ASSOCIATED DATA STRUCTURE THAT STORE DATA WITH A UNIQUE KEY PAIR 
* HASH TABLE IS STORE DATA IN THE ARRAY FORMAT, AND IT'S VERY FAST FOR ACCESSING DATA WHEN INDEX OR UNIQUE ID IS GIVEN
*/
#include <stdio.h>
#include <ctype.h>
// DECLARATION OF THE STRUCTURE 
// STRUCTURE USED FOR CREATION HASH TABLE IN MEMORY
typedef struct {
  char *key;
  int data;
} HashTable;
// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
  HashTable item [] = {
    {"Vikash",20},
    {"Akash",44},
    {"Arun",52},
    {"Vikram",52}
  };
  size_t size = sizeof (item) / sizeof (1);
  printf ("%d",size);
  for (size_t i = 0; i < size; i++)
    printf ("\nValue : %d\t Key : %s",item[i].data,item[i].key);
  return 0;
}
