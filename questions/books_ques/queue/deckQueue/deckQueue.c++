/*
 ************************* DECKQUEUE **************************
 ******** USING CIRCULAR DOUBLY LINKED LIST *******************
 **************** WITH USING OOPS APPROACH ********************
*/
#include <iostream>
#include <stdio.h>
#include "deckQueue_header.h"

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char *argv[]) {
  try {
    DeckQueue *ptr = new DeckQueue (); // ALLOCATION OF THE DYNAMIC MEMORY
    if (ptr == nullptr) // CHECK FOR CLASS POINTER OBJECT IS NULLPTR OR NOT 
      throw ptr; // IF POINTER IS NOT ALLOCATED THEN THROW IT TO THE CATCH BLOCK FOR RE-SOLVE EXCEPTION 
    ptr->run ();
    delete [] ptr; // DE-ALLOCATION OF THE DYNAMIC MEMORY 
  }
  catch (...) { // RE-SOLVING EXCEPTION OF THE PROGRAM 
    std::cout << "\nThere is object is of class found now !";
  }
  return 0;
}
