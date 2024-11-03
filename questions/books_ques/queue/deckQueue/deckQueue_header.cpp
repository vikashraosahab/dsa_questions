// CLASS DEFINITION SECTION a
#include "deckQueue_header.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>

using std::cin;  // FOR INPUT
using std::cout; // FOR OUTPUT 
using std::cerr; // FRO DISPLAY ERROR 
using std::shared_ptr; // STANDARD TEMPLATE LIBRARY POINTER THAT EFFIECIENTLY ALLOCATED AND DE-ALLOCATE DYNAMIC MEMORY
// CLASS MEMBER METHODS ARE DEFINE HERE --
Node::Node(int value) : data(value), next(nullptr), pre(nullptr) {}
// ASSIGN QUEUE USING MEMBER : INITIALIZATION METHOD BY CONSTRUCTOR
DeckQueue::DeckQueue() : queue(nullptr),size (0) { /* CLASS CONSTRUCT DEFINITION */ }
/*
DeckQueue::~DeckQueue () { // CLASS DESTRUCTOR DEFINITION
  cout << "\nProgram is ended now !";
} */
void DeckQueue::run() { // MEMBER METHOD THAT ACTS AS A ROOT OF THE APPLICATION
  while (true) {
    menu(1); // CALLING METHOD THAT DISPLAY MENU TO USER
    task = valid_input();
    if (task == 4) break;            // WHEN USER ENTER 4 THAT MEANS TERMIANTE THE LOOP
    process_menu(task); // CALLING PROCESS_MENU METHOD FOR HANDLING INPUT AND                // OUTPUT RESTRICTION
  }
  cerr << "\nProgram is ended !";
}
void DeckQueue::menu(
    int task) { // MEMBER METHOD THAT ACTS AS A METHOD WHERE PROGRAMMER HAVE
                // DESCRIBE ALL THE INSRUCTIONS THAT USER NEED
  switch (task) {
  case 1:
    cout << "\n**************** Main Menu *******************";
    cout << "\n1 : Input Restriction";
    cout << "\n2 : Output Restriction";
    cout << "\n3 : Display";
    cout << "\n4 : Exit";
    break;
  case 2: // USE IT FOR DISPLAY INSTRUCTION TO THE USER WHEN THEY PERFORM INPUT
          // RESTRICTION OPERATIONS BY PASS 2 AS ARGUEMENT TO METHOD
    cout << "\n************ Input Resctriction **************";
    cout << "\n1 : Insert End";
    cout << "\n2 : Delete End";
    cout << "\n3 : Delete Front";
    cout << "\n4 : Exit";
    break;
  case 3: // USE WHEN YOU WANT DISPLAY OUTPUT RESTRICTION TO USER BY PASS 3 AS
          // ARGUEMENT TO METHOD
    cout << "\n************ Output Restriction **************";
    cout << "\n1 : Insert Front";
    cout << "\n2 : Insert End";
    cout << "\n3 : Delete End";
    cout << "\n4 : Exit";
    break;
  }
}
void DeckQueue::process_menu(
    const int &
        value) { // METHOD THAT HANDLES INPUT AND OUTPUT RESTRICTIONS OPERATIONS
  switch (value) {
  case 1:
    input_restriction(); // FOR INPUT RESTRICTION PROGRAM 
    break;
  case 2:
    output_restriction(); // FOR OUTPUT RESTRICTION PROGRAM 
    break;
  case 3:
    display(); // FOR DISPLAY RESTULLT 
    break;
  }
}
int DeckQueue::valid_input() { // METHOD THAT VALIDATE INPUT VALUE ONLY INTEGER
                               // RETURN AS true
  int value;
  while (true) {
    cout << "\nEnter value : ";
    try {
      if (cin >> value) {
        return value;
      }
      else 
        throw "throw in-valid input"; // THROW STRINGS CACHES OR EXCEPTION FOR HANDLING 
    }
    catch (const char *) {
      std::cerr << "\nIn-valid input. Please enter valid input";
      // IN C++ IS INPUT IN-VALID THEN NEW INPUT IS BLOCK SO WE NEED TO CLEAR THIS FAIL STATE FOR THAT WE USED CIN.CLEAR () METHOD TO CLEAR ALL THE FAILS STATE SO WE INPUT NEW VALUES 
      cin.clear(); // CLEAR FIAL STATE AND RE-SET FOR INPUT 
      cin.ignore (1000,'\n'); // IGNORE UNTIL WHEN INPUT IS NEWLINE 
    }
  }
}
DeckQueue &
DeckQueue::input_restriction() { // HANDLES INPUT RESTRICTION OPERATIONS
  while (true) {
    menu(2);              // DISPLAY MENU OF INPUT RESTRICTION
    task = valid_input(); // INPUT VALUE
    if (task == 4)
      break; // TERMINATE LOOP
    switch (task) {
    case 1:
      cout << "\nInsert node in the linked list at the end is in processing :  ";
      cout << "\nEnter value of the node : ";
      cin >> task;
      insert_end(task);
      break;
    case 2:
      cout << "\nDeletion of node from the linked list is in processing : ";
      delete_end();
      break;
    case 3:
      cout << "\nDeletion of the node from the linked list is in processing : ";
      delete_front();
      break;
    }
  }
  return *this;
}
DeckQueue & DeckQueue::output_restriction() { // HANDLES OUTPUT RESTRICTION OPERATIONS
  while (true) {
    menu(3);              // DISPLAY OUTPUT RESTRICTION TO THE USER
    task = valid_input(); // INPUT VALUE
    if (task == 4)
      break; // BREAK THE LOOP
    switch (task) {
    case 1:
      cout << "\nInsert node in the linked list at the front is in processing : ";
      cout << "\nEnter value of the node : ";
      cin >> task;
      insert_front(task);
      break;
    case 2:
      cout << "\nInsert node in the linked list at the end is in processing : ";
      cout << "\nEnter value of the node : ";
      cin >> task;
      insert_end(task);
      break;
    case 3:
      cout << "\nDeletion of the node from the linked list from the end is in "
              "processing : ";
      delete_end();
      break;
    }
  }
  return *this;
}
void DeckQueue::insert_end(int value) { // INSERT NODE IN THE CIRCULAR LINKED
  // MAKE SHARE ALLOCATED DYNMAIC MEMORY MORE EFFIECIENTLY WHEN THERE ALREADY A LAYER OF SHARED_PTR WITHOUT CREATING EXTRA LAYER OF POINTER IT'S JUST ASSIGN MEMORY OF SAME OBJECT OF THE NODE 
  std::shared_ptr <Node> node = std::make_shared<Node> (value); // MAKE SAHRED IS MORE EFFIECIENT THAN NEW OPERATOR BECAUSE IT'S CREATE OBJECT AND ALLOCATED IT TO THE SHARE POINTER MANAME IT without create extra layer
  try {
    if (node == nullptr) // DYNAMIC MEMORY NOT ALLOCATED FOR THE PARTICULAR NODE 
      throw "Dynamic memory not allocated "; // THEN THROW THIS EXCEPTION TO THE CATCH BLOCK SO IT CAN RE-SOLVE IT EFFIECIENTLY
    else {
      if (queue == nullptr) {
        queue = node;
        queue->pre = queue;
        queue->next = queue;
      }
      else {
        std::shared_ptr <Node> ptr = queue->pre; // LAST NODE OF THE CIRCULAR DOUBLY LINKED LIST 
        ptr->next = node; // LAST NODE NEXT POINTER POINTING TO THE NEXT NODE 
        node->pre = ptr; // NEW NODE PRE POINTER POINTING TO THE LAST NODE 
        node->next = queue; // NEW NODE NEXT POINTER POINTING TO THE QUEUE OR FIRST FOR CREATION THE CIRCULAR LINKED LIST
        queue->pre = node; // FIRST NODE PRE POINTER POINTING TO THE LAST NODE FOR CREATION OF CIRCULAR LINKED LIST
      }
      size++;
    }
  }
  catch (const char *) {
    cerr << "\nError : Dynamic memory not allocated for node";
  }
}
void DeckQueue::insert_front(int value) { // INSERT NODE IN THE CIRCULAR LINKED
  shared_ptr <Node> node = std::make_shared <Node> (value); // SHAREDPTR CREATE A POINTER THAT EFFIECIENTLY ALLOCATED AND DE-ALLOCATED DYNAMIC MEMORY FOR RESOURCE AND MAKE_SHARED TEMPLATED 
  try {
    if (node == nullptr) 
      throw "Dynamic memory not allocated";
    else {
      if (queue == nullptr) {
        queue = node;
        queue->pre = queue;
        queue->next = queue;
      }
      else {
       shared_ptr <Node> tail = queue->pre;
       node->next = queue;
       queue->pre = node;
       queue = node;
       node->pre = tail;
       tail->next = node;
      }
      size += 1;
    }
  }
  catch (const char *) {
    cerr << "\nError : Dynamic memory not allocated for the particular node";
  }
}
void DeckQueue::delete_front() { // DELETE NODE FROM THE LINKED LIST AT FRONT OF
  // USE STANDARD TEMPLATE LIBRARY SMART POINTER FOR EFFIECIENTLY ALLOCATION AND DE-ALLOCATION DYNAMIC MEMORY ALLOCATION 
  try {
   if (queue == nullptr)  // WHEN QUEUE IS ALREADY EMPTY
     throw "Queue is empty !";
   if (size == 1 && (queue->pre == queue && queue->next == queue))  // WHEN ONLY ELEMENT IN THE QUEUE IS LEFT 
     queue = nullptr; // ASSIGN QUEUE NULL WHEN THERE IS NOT ELEMENT LEFT
   else {
      shared_ptr <Node> ptr = queue; // SMART TEMPLATE LIBRARY POINTER METHOD
      shared_ptr <Node> tail = queue->pre; // SMART TEMPLATE LIBRARY POINTER METHOD
      queue = queue->next;
      queue->pre = tail;
      tail->next = queue;
     //  ptr.reset (); // reset () method is used to reset or assing null to pointer // DELETION OF THE FIRST NODE FROM THE CIRCULAR DOUBLEY LINKED LIST
     try {
       ptr.reset (); // reset method is STL shared_ptr  method that reset shared_ptr pointer to the null 
       if (ptr != nullptr) 
        throw "Pointer is not null"; 
     }
     catch (...) {
        cerr << "\nPointer not reset yet , and it's not release all data!";
     }
   }
   size -= 1; // DECREMENT TOTAL NUMBER OF ELEMENTS FROM THE QUEUE 
  } 
  catch (const char *) { // HANDLES EXCEPTION SMARTLY
   cerr << "\nQueue is already empty !";
  }// THE LIST
}
void DeckQueue::delete_end() { // DELETE NODE FROM THE LINKED LSIT AT END OF THE
  try {
    if (queue == nullptr) 
      throw "Queue is already empty";
    if (size == 1 && (queue->pre == queue && queue->next == queue)) 
      queue = nullptr;
    else {
      shared_ptr <Node> tail = queue->pre;
      shared_ptr <Node> second_last = tail->pre;
      queue->pre = second_last;
      second_last->next = queue;
      try {
       tail.reset (); // DELETE LAST NODE FROM THE LINKED LSIT 
       if (tail != nullptr) 
         throw tail;
      }
      catch (Node) {
       cerr << "\nNode is not deleted from the queue !";
      }
      size -= 1;
    }
  } 
  catch (const char *) {
    cerr << "\nQueue is already empty";
  } // LINKED LIST
}
void DeckQueue::display() const { // DISPLAY DATA OF THE DECKQueue 
 try {
   if (queue == nullptr)
     throw "Empty";
     std::shared_ptr <Node> ptr = queue;
   cout << "\nDisplay value of deck queue are : ";
   do {
    cout << "\nQueue data are : " << ptr->data;
    ptr = ptr->next;
   }
   while (ptr != queue);
 }
 catch (const char *) {
   cerr << "\nQueue is already empty !";
 }
 cout << "\nDone !";
}
