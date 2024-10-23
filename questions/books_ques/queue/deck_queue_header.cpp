// CLASS DEFINITION SECTION 
#include "deck_queue.h"
#include <iostream>
#include <stdio.h>
#define MAX_SIZE 20
// CLASS MEMBER FUNCTION DEFINITIONS
// CONSTRUCTOR INITIALIZE 
deckQueue::deckQueue ():rear (-1),front (-1){}; // DEFINITION OF THE CONSTRUCTOR
deckQueue::~deckQueue () {};
int deckQueue::valid_input () {
  int value;
  while (1) {
   std::cout << "\nEnter value : " << std::endl;
   if (scanf ("%d",&value) != 1) {
     while (getchar () != '\n')
      std::cout << "In-valid input. Please enter valid input !";
     continue;
   }
   else 
    break;
  }
  return value;
}
deckQueue& deckQueue::run () {
   int task;
   while (1) {
    menu ();
    task = valid_input ();
    if (task == 3) break;
    std::cout << "Empty : " << isQueueEmpty () << std::endl;
    std::cout << "Fulled : " << isQueueFull () << std::endl;
   }
   std::cout << "\nProgram is ended now !";
}
deckQueue& deckQueue::input_restrictions (const int& task) {}
deckQueue& deckQueue::output_restrictions (const int& task) {}
deckQueue& deckQueue::menu () {
  std::cout << "****************** MAIN MENU *******************";
  std::cout << "\n1 : INPUT RESTRICTIONS : ";
  std::cout << "\n2 : OUTPUT RESTRICTIONS : ";
  std::cout << "\n3 : Exit !";
  std::cout << "\nEnter input according to the main menu : ";
}
deckQueue& deckQueue::process_menu (const int& task) {
  switch (task) {
    case 1:
      std::cout << "\nINPUT RESTRICTIONS OPENED NOW !" << std::endl;

      break;
    case 2:
      std::cout << "\nOUTPUT RESTRICTIONS OPENED NOW !" << std::endl;

      break;
  }
}
deckQueue& deckQueue::insert_end (const int&) {}
deckQueue& deckQueue::insert_front (const int&) {}
deckQueue& deckQueue::delete_end (const int&) {}
deckQueue& deckQueue::delete_front (const int&) {}
deckQueue& deckQueue::display () {}
bool deckQueue::isQueueEmpty () { // CHECK THAT IS QUEUE IS EMPTY OR NOT EMPTY
  return rear == - 1 && front == -1;
}
bool deckQueue::isQueueFull () { // CHECK THAT IS QUEUE IS FULLED OR NOT FULLED
  return (rear == MAX_SIZE - 1 && front == 0) || (rear == front - 1);
}