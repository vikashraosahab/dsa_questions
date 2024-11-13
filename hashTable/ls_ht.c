// CREATE A HASH TABLE BY USING STRUCTURE 
// HASH TABLE IS AN ASSOCIATIVE DATA STRUCTURE THAT STORE VALUE WITH RESPECTIVE KEY VALUES THAT IS AN UNIQUE INDIES 
// HASH TABLE IS STORE DATA IN ARRAY FORMAT 
#include <stdio.h>
#include <string.h>
#define MAXSIZE 50 // MACROS DEFINITION 
// DECLARATION OF THE STRUCTURE 
typedef struct {
  char *key;  // KEY VALUE (UNIQUE INDEX VALUE)
  char *data; // ACTUAL DATA 
}Hash; // DECLARATION OF THE STRUCTURE 
// FUNCTION PROTOTYPE 
Hash *linear_search (Hash*, size_t, char*); // FUNCTION THAT DEFINE LINEAR SEARCHING ALGORITHM 

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
  Hash item [] = {
    {
      "yadav", "Vikash"
    },
    {
      "sign", "Akash",
    },
    {
      "thakur", "Yuraj"
    }
  };
  size_t size = sizeof (item) / sizeof (Hash); // GET SIZEOF THE HASH TABLE 
  Hash *found = linear_search (item,size,"thakur");
  if (!found) {
    printf ("\nData isn't found in the hash table");
    return 1;
  }
  printf ("\nValue : %s",found->data);
  return 0; // IT'S TERMINATE 
}
// FUNCTION DEFINITION 
Hash *linear_search (Hash *item,size_t size, char *key) {
  for (size_t i = 0; i < size; i++) {
    if (strcmp (key,item [i].key) == 0) {
      return &item [i]; // RETURN FOUNDED DATA ADDRESS TO CALLING FUNCTION 
    }
  }
  return NULL; // WHEN DATA IS NOT FOUND 
};
