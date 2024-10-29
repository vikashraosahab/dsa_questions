// CLASS DEFINITION SECTION 
#include <iostream>
#include <stdio.h>
#include "deck_queue.h"

// CLASS DEFINITION SECTION 
DeckQueue::DeckQueue ():front (-1),rear (-1) {}; // CLASS CONSTRUCTOR DEFINITION HANDLES INITIALIZATION OF FRON AND REAR LABEL OF THE QUEUE
DeckQueue::~DeckQueue () {
   std::cout << "\nProgram is ended now !";
}
void DeckQueue::run () { // METHOD THAT WORK AS ROOT METHOD OF THE PROGRAM , WHERE EACH USER-DEFINE METHOD OR FUNCTIONALITY STARTS EXECUTION
  int val; 
  while (true) {
    menu (1);
    val = valid_input (); // ONLY INTEGER VALUE IS ACCEPTABLE
    if (val == 4) break;
    process_menu (val);
  }
}
void DeckQueue::menu (const int task) { // MEHTOD THAT DISPLAY MENU INSTRUCTION THAT HELP USER TO MANIPULATE QUEUE DATA STRUCTURE 
   /* INSTRUCTION THAT HELP USER TO TAKE ACTION AND MANIPULATE THE QUEUE */
   std::cout << "\n************** Main Menu *********************";
   switch (task) {
     case 1: // FOR BASIC INSTRUCTION
       std::cout << "\n1 : Input Restrictions";
       std::cout << "\n2 : Output Restrictions";
       std::cout << "\n3 : Display";
       break;
     case 2: // FOR INPUT RESTRICTIONS 
       std::cout << "\n1 : Insert value in the queue at the end of the queue";
       std::cout << "\n2 : Delete value from the queue from the end of the queue";
       std::cout << "\n3 : Delete value from the queue from the front of the queue";
       break;
     case 3: // FOR OUTPUT RESTRICTIONS 
       std::cout << "\n1 : Insert value in the queue at the end of the queue";
       std::cout << "\n2 : Insert value in the queue at the front of the queue";
       std::cout << "\n3 : Delete value from the queue from the end of the queue";
       break;

   }
   std::cout << "\n4 : Exit";
   std::cout << "\nEnter value according to the main menu : ";
}
void DeckQueue::process_menu (const int& task) { // MEMBER METHOD THAT EXECUTE TASK ACCORDING USER INPUT 
   switch (task) {
     case 1:
       std::cout << "\n************** Input Restriction Mode ****************";
       input_restriction (); // CALLING THE INPUT RESTRICTION MEMBER METHOD 
       break;
     case 2:
       std::cout << "\n************** Output Restriction Mode ***************";
       output_restriction (); // CALLING THE OUTPUT RESTRICTIONS MEMBER METHOD
       break;
     case 3:
       std::cout << "\n******************** Display Mode ********************";
       display (); // DISPLAY METHOD IS CALLING 
       break;
  }                  
}
int DeckQueue::valid_input () const { // MEMBER METHOD THAT VALIDATE INPUT VALUE , IF VALUE IS INTEGER THEN RETURN TO THE CALLING FUNCTION 
  int value;
  while (true) {
    re_start:std::cout << "\nEnter value : ";
    try {
     if (scanf ("%d",&value) != 1) { // CHECK THAT USER INPUT INTEGER OR NOT 
       while (getchar () != '\n') // NON NEW LINE CHARACTER
         throw value; // WHEN EXCEPTION OCCUR THROW TO THE CATACH PART TO RE-SOLVE IT 
       continue;
     }
     else  // WHEN USER INPUT RIGHT INPUT THEN BREAK THE LOOP AND PASS VALUE TO CALLING SECTION 
       break;
    } 
    catch (int) {
      std::cout << "\nIn-valid input. Please enter valid input : ";
      goto re_start;
    }
  }
  return value;
}
bool DeckQueue::isQueueEmpty () const { // METHOD THAT CHECK QUEUE IS EMPTY OR NOT EMPTY
  return (rear == -1 && front == -1);                                      
}
bool DeckQueue::isQueueFulled () const { // METHOD THAT CHECK QUEUE IS FULLED OR NOT FULLED
  return (front != 0 && rear == front - 1) && (front == 0 && rear == MAX_SIZE - 1);
}
void DeckQueue::display () const { // MEMBER METHOD THAT Display 
  if (isQueueEmpty ()) 
    std::cout << "\nQueue is empty,so there is no left to display !";
  else {
    int i = front;
    std::cout << "\nQueue data are : \n";
    for (i; i <= rear; i = (i + 1) % MAX_SIZE) {
      std::cout << "Value : " << queue [i] << std::endl;
    }
  }
}
DeckQueue& DeckQueue::input_restriction () { // MEMBER METHOD THAT HANDLES INPUT RESTRICTIONS 
  while (true) {
    menu (2);
    task = valid_input ();
    if (task == 4) break;
    switch (task) {
      case 1:
        std::cout << "\nInsert value from the end of the queue";
        insert_end (); // INSERTION FROM END FUNCTION IS CALLING 
        break;
      case 2:
        std::cout << "\nDelete value from the front of the queue";
        delete_front (); 
        break;
      case 3:
        std::cout << "\nDelete value from the end of the queue";
        delete_end();
        break;
    }
  }
  return *this;
}
DeckQueue& DeckQueue::output_restriction () { // MEMBER METHOD THAT HANDLES OUTPUT RESTRICTIONS FUNCTIONALITIES
  while (true) {
    menu (3);
    task = valid_input ();
    if (task == 4) break;
    switch (task) {
      case 1:
        std::cout << "\nInsert value from the rear of the queue";
        insert_end ();
        break;
      case 2:
        std::cout << "\nInsert value from the front of the queue";
        insert_front ();
        break;
      case 3:
        std::cout << "\nDelete value from the end of the queue";
        delete_end ();
        break;
    }
  }
  return *this;
}
DeckQueue& DeckQueue::insert_end () { // INSERT VALUE IN THE QUEUE FROM THE END OF THE QUEUE
  if (isQueueFulled ()) // CHECK QUEUE IS FULLED OR NOT 
     std::cout << "\nQueue is fulled, so there is no space left to insert new value";
  else if (isQueueEmpty ())
     rear = 0,front = 0;
  else 
    rear = (rear + 1) % MAX_SIZE;
  task = valid_input ();
  queue [rear] = task; // INSERT VALUE IN THE QUEUE 
  return *this;
}
DeckQueue& DeckQueue::insert_front () { // INSERT VALUE IN THE QUEUE FROM THE FRONT SIDE OF QUEUE
 if (isQueueFulled ())
   std::cout << "\nQueue is fulled, so there is no space left to insert new value";
 else if (isQueueEmpty ())
   rear = 0, front = 0;
 else {
   rear = MAX_SIZE - 1;
 }
 rear = (rear - 1) % MAX_SIZE;
 task = valid_input();
 queue [rear] = task; 
 return *this;
}
DeckQueue& DeckQueue::delete_end () { // METHOD THAT HELP TO DELETE VALUE FROM THE QUEUE FROM THE END OF THE QUEUE
  if (isQueueEmpty ())
    std::cout << "\nQueue is empty,so there is no value left to delete";
  else if (rear == 0 && front == 0) {
    task = queue [front];
    rear = front = -1;
  }
  else if (front == 0 && rear > front) {
     task = queue [front];
     front = rear;
     front = (front - 1) % MAX_SIZE;
  }
  std::cout << "\n" << task << "Deleted now !" << std::endl;
  return *this;
}
DeckQueue& DeckQueue::delete_front () { // METHOD THAT HANDLES DELETION FROM THE FRONT OF THE QUEUE 
  if (isQueueEmpty ()) 
    std::cout << "\nQueue is empty, so there is space left in the queue for deletion";
  else if (front == MAX_SIZE - 1 && rear <= front)
    front = 0;
  task = queue [front];
  front = (front + 1) % MAX_SIZE;
  std::cout << "Value is deleted : " << task << std::endl;
  return *this;
}
