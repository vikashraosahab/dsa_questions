#include <iostream>
#include "deck_queue.h"
// CLASS MEMBER FUNCTIONS DEFINITION SECTION 
DeckQueue::DeckQueue ():front (-1),rear (-1){} // CONSTRUCTOR DEFITIION 
DeckQueue::~DeckQueue () {
  std::cout << "\nOkay program is ended now !";
} // DESTRUCTOR DEFINITION 
void DeckQueue::run () { // DEFINITION OF THE CLASS RUN MEMBER FUNCTION 
  int val;
  while (true) {
    menu (1);
    val = valid_input (); 
    if (val == 4) break;
    process_menu (val);
  }
} 
void DeckQueue::menu (const int value) { // DEFINITION OF THE CLASS MENU MEMBER FUNCTION 
 std::cout << "\n*************** Main Menu *****************";
 switch (value) {
   case 1:
     std::cout << "\n1 : Input Restriction";
     std::cout << "\n2 : Output Restriction";
     std::cout << "\n3 : Display";
     std::cout << "\n4 : End";
     break;
   case 2:
     std::cout << "\n1 : Insert Data From End";
     std::cout << "\n2 : Insert Data From Front";
     std::cout << "\n3 : Delete Data From End";
     std::cout << "\n4 : Exit";
     break;
   case 3:
     std::cout << "\n1 : Insert Data From End";
     std::cout << "\n2 : Delete Data From End";
     std::cout << "\n3 : Delete Data From Front";
     std::cout << "\n4 : Exit";
     break;
 }
}
void DeckQueue::process_menu (const int& task) { // DEFINITION OF THE CLASS PROCESS MENU MEMBER FUNCTION 
    switch (task) {
      case 1:
        std::cout << "\n********** Input Restriction Activated **********";
        input_restriction (); // CALLING INPUT RESTRICTION METHOD
        break;
      case 2:
        std::cout << "\n*********** Output Restriction Activated *********";
        menu (2);
        break;
      case 3:
       std::cout << "\n************ DISPLAY DATA OF THE QUEUE *************";
       display ();
       break;
  }
}
int DeckQueue::valid_input () { // DEFINITION OF THE CLASS VALID_INPUT MEMBER FUNCTION 
  int val;
  while (true) {
    try {
      std::cout << "\nEnter value : ";
      if (std::cin >> val)
        return val;
      std::cin.clear (); // CLEAR BLOCKAGE INPUT METHOD 
      std::cin.ignore (10,'\n'); // NEW CHARACTER NOT SHOW ANY TYPE OF ERROR 
      throw "In-valid input";
    }
    catch (const char *) {
      std::cerr << "\nInput-invalid. Please enter valid input : ";
    }
  }
  return 10;
}
void DeckQueue::display () const { // DEFINITION OF THE CLASS DISPLAY MEMBER FUNCTION 
  size_t i = front;
  for (i; i <= rear; i++) {
    if (i == MAX_SIZE - 1 && rear < i) 
     i = 0;
    std::cout << "\nQueue value : " << queue [i] << std::endl;
  }
}
inline bool DeckQueue::isQueueEmpty () const { // DEFINTIION OF THE ISQUEUEEMPTY MEMBER FUNCTION 
  return front == -1 && rear == -1;
}
inline bool DeckQueue::isQueueFulled () const { // DEFINITION OF THE QUEUE FULLED MEMBBER FUNCTION 
 return (front == 0 && rear == MAX_SIZE -1) || (rear == front -1);
}
DeckQueue& DeckQueue::insert_end (const int& value) { // DEFINITION OF THE INSERT END MEMBER FUNCTION 
  try {
    if (isQueueFulled())
      throw "Queue is fulled";
    if (isQueueEmpty())
      rear = 0, front = 0;
    else if (rear == MAX_SIZE - 1 && front != 0)
      rear = 0;
    queue [rear] = value;
  } 
  catch (const char *) {
   std::cerr << "\nQueue is fulled";
  }
  return *this;
};
DeckQueue& DeckQueue::insert_front (const int& val) { // DEFINITION OF THE INSERT FRONT MEMBER FUNCTION 
 
  return *this;
};
DeckQueue& DeckQueue::delete_end () {

  return *this;
};
DeckQueue& DeckQueue::delete_front () {

  return *this;
};
DeckQueue& DeckQueue::input_restriction () {
  int value;
  while (true){
    menu (2);
    value = valid_input ();
    if (value == 4) break;
    switch (value) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
    }
  }
  return *this;
}
DeckQueue& DeckQueue::output_restriction () {
  int value;
  while (true) {
    menu (3);
    value = valid_input ();
    if (value == 4) break;
    switch (value) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
    }
  }
  return *this;
}
