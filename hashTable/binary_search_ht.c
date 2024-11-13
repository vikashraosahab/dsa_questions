// CREATE HASH TABLE USING STRUCTURE 
// PERFORM BINARY SEARCH OVER THE HASH TABLE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// DECLARATIONS OF THE STRUCTURE 
typedef struct {
  int key; // FOR HASH KEY VALUE
  char *data; // FOR HASH ACTUAL DATA
} Hash;

Hash *binary_search (Hash*,size_t,size_t,size_t,int);
// HEADING OF THE MAIN FUNCTION 
int main (int argc, char * argv[]) {
  // INITIALIZATION OF THE HASH TABLE 
  Hash item [] = {
    {
     1,"Vikash"
    },
    {
     2, "Akash"
    },
    {
     3, "Arun"
    }
  };
  size_t low = 0;
  size_t size = sizeof (item) / sizeof (Hash);
  size_t high = size - 1;
  Hash *found = binary_search (item,low,high,size,5);
  !found ? printf ("\nVAlue not found !") : printf ("\nValue is : %s",found->data);
  return 0;
}
Hash *binary_search (Hash *item,size_t low,size_t high,size_t size, int value) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (item [mid].key == value) 
      return &item [mid];
    else if (item [mid].key > value)
      high = high - 1;
    else 
      low = low + 1;
  }

  return NULL;
}
