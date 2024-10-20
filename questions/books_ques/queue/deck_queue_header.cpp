// CLASS DEFINITIONS
#include "deck_queue.h"
#include <iostream>
#define TASK 1 // SYMBOLIC CONSTANT 
// CLASS CONSTRUCTOR DEFINITION
DeckQueue::DeckQueue ():
  left_insert (-1),
  right_insert (-1),
  right_delete (-1),
  left_delete (-1) {
    while (1) {
      menu (TASK); // SHOW EACH USER PROMPT 
      int task = valid_input (); // TAKE VALD INPUT
      if (task == 3) break; // STOP THE LOOP 
      process_menu (task); // PERFORM TASK ACCORDING TO THE USER INPUT
    }
}
// CLASS PSEUDO MEMBER FUNCTIONS
DeckQueue& DeckQueue::display () {
    std::cout << "Hello,World by Vikash Yadav\n" << std::endl; // OUTPUT

    return *this;
}
DeckQueue& DeckQueue::input_restrict () {
  while (1) {
   int value;
   std::cout << "Enter value : " << std::endl;
   value = valid_input ();
  switch (value) {
    case 1:
      break;
    case 2:
      break;
  
   }
  } 
  return *this;
}
DeckQueue& DeckQueue::output_restrict () {

  return *this;
}
// FUNCTION THAT DISPLAY ALL MENU PROMPT TO THE USER
void DeckQueue::menu (const int& task){
  switch (task) {
    case 1:
       std::cout << "Menu : \n";
       std::cout << "\n1 : Input restriction queue : \n";
       std::cout << "\n2 : Output restirction queue : \n";
       std::cout << "\n3 : EXIT \n";
       std::cout << "\nPlease enter valid input according to the main menu : ";
      break;
    case 2:
       std::cout << "Menu : \n";
       std::cout << "\n1 :  : \n";
       std::cout << "\n2 :  : \n";
       std::cout << "\n3 : EXIT \n";
       std::cout << "\nPlease enter valid input according to the main menu : ";
      break;
  }
}
// PROCESS MENU FUNCTION ACTUALLY TAKES INPUT AS PARAMENTER AND PERFORM ACCORDING TASK
void DeckQueue::process_menu (const int& task) {
   switch (task) {
     case 1:
       std::cout << "Input Restriction queue menu open : \n";
         
       std::cout << "\nExisted Now !";
       break;
     case 2:
       std::cout << "\nOutput Restriction queue menu open : \n";
       
       std::cout << "\nExisted Now !";
       break;
   }
}
DeckQueue& DeckQueue::insert_end (DeckQueue& queue) {
  
  return *this;
}
DeckQueue& DeckQueue::insert_front (DeckQueue& queue) {

  return *this;
}
DeckQueue& DeckQueue::deletion_end (DeckQueue& queue) {

  return *this;
}
DeckQueue& DeckQueue::deletion_front (DeckQueue& queue) {
  
  return *this;
}
int DeckQueue::valid_input () {
  int val;
  while (1) {
   // PERFROM EXCEPTION HANDLING BETTER 
  start:std::cout << "\nPlease enter value : ";
   try { // TRY BLOCK FIND OUT CACHE EXPRESSION
     if (scanf ("%d",&val) != 1) { // WHEN VAL IS NOT AN INTEGER VALUE
      while (getchar () != '\n')
       throw val; // THEN THROW IT AS THE ERROR 
      continue;
    }
    else // OTHERWISE BREAK THE LOOP
      break;
   } // CATCH METHOD SOLVED THE EXECEPTIONS 
   catch (...) {
     std::cout << "Error ! Input is in-valid\n Please enter valid input ? " << std::endl; // STATEMENT
     goto start;
   }
  }
  return val; // RETURN VAL 
}
// CLASS MEMBER DESTRUCTOR DEFINITION 
DeckQueue::~DeckQueue () {
    std::cout << "Program is ended now !" << std::endl; // OUTPUT 
}
