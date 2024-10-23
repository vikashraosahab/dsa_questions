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
    menu (1);
    task = valid_input ();
    if (task == 4) break;
    process_menu (task);
   }
   std::cout << "\nProgram is ended now !";
}
deckQueue& deckQueue::input_restrictions () {
  int task; // VARIABLE DECLARATIONS
  while (1) {
    menu (2);
    task = valid_input (); // TAKE VALID INPUT ONLY FOR INTEGER VALUES
    if (task == 4) break;
    switch (task) {
      case 1:
        std::cout << "\nDeletion from the front is in processing : "; 

        break;
      case 2:
        std::cout << "\nDeletion from the end is in processing : ";

        break;
      case 3:
         std::cout << "\nInsertion at the end is in porcessing : ";
         int value;
         std::cout << "\nEnter value : ";
         std::cin >> value;
         insert_front (value);
         std::cout << "\nProcess completed now !";
        break;
      case 5:
        menu (1);
        process_menu (1);
        break;
    }
  }
  return *this;
}
deckQueue& deckQueue::output_restrictions () {
   int task; // VARIABLE DECLARATIONS
  while (1) {
    menu (3);
    task = valid_input (); // TAKE VALID INPUT ONLY FOR INTEGER VALUES
    if (task == 4) break;
    switch (task) {
      case 1:
        std::cout << "\nInsertion at  front is in processing : "; 
 
        break;
      case 2:
         std::cout << "\nInsertion at the end is in processing : ";
         int value;
         std::cout << "\nEnter value : ";
         std::cin >> value;
         insert_end (value);
         std::cout << "\nProcess completed now !";
        break;
      case 3:
         std::cout << "\nDeletion from end is in processing : ";

        break; 
      case 5:
         menu (1);
         process_menu (1);
         break;
    }
  }
  return *this;
}
deckQueue& deckQueue::menu (const int task) {
  reStart:std::cout << "\n****************** MAIN MENU *******************";
  switch (task) {
    case 1:
      std::cout << "\n1 : INPUT RESTRICTIONS : ";
      std::cout << "\n2 : OUTPUT RESTRICTIONS : ";
      std::cout << "\n3 : DISPLAY : ";
      break;
    case 2:
      std::cout << "\n1 : Deletion from front : ";
      std::cout << "\n2 : Deletion from end : ";
      std::cout << "\n3 : Insertion from end : ";
      std::cout << "\n5 : Goto to main page : ";
      break;
    case 3:
      std::cout << "\n1 : Insertion from front : ";
      std::cout << "\n2 : Insertion from end : ";
      std::cout << "\n3 : Deletion from end : ";
      std::cout << "\n5 : Goto to main page : ";
      break;
    default:
      goto reStart; // DEFINING LABLE 
      break;
      
  }
  std::cout << "\n4 : Exit !";
  std::cout << "\nEnter input according to the main menu : ";
}
deckQueue& deckQueue::process_menu (const int& task) {
  switch (task) {
    case 1:
      std::cout << "\nINPUT RESTRICTIONS OPENED NOW !" << std::endl;
      input_restrictions ();
      break;
    case 2:
      std::cout << "\nOUTPUT RESTRICTIONS OPENED NOW !" << std::endl;
      output_restrictions ();
      break;
    case 3:
      std::cout << "\nDISPLAY !" << std::endl;
      display ();
      break;
  }
}
deckQueue& deckQueue::insert_end (const int& val) {
   if (isQueueEmpty ()) 
    rear = front = 0;
   else if (isQueueFull ()) 
     std::cout << "Queueu is fulled so there is space left to insert element";
   else if (rear == MAX_SIZE - 1 && front != 0)
    rear = (rear + 1) % MAX_SIZE;
   queue [rear] = val;
   return *this;
}
deckQueue& deckQueue::insert_front (const int&) {}
deckQueue& deckQueue::delete_end (const int&) {}
deckQueue& deckQueue::delete_front (const int&) {}
deckQueue& deckQueue::display () {
  if (isQueueEmpty ()) 
    std::cout << "Queue is empty !";
  else {
   int i = front;
   while (i <= rear) {
    printf ("%d ",queue[i]);
    i = (rear + 1) % MAX_SIZE;
   }
  }
  return *this;
}
bool deckQueue::isQueueEmpty () { // CHECK THAT IS QUEUE IS EMPTY OR NOT EMPTY
  return rear == - 1 && front == -1;
}
bool deckQueue::isQueueFull () { // CHECK THAT IS QUEUE IS FULLED OR NOT FULLED
  return (rear == MAX_SIZE - 1 && front == 0) || (rear == front - 1);
}