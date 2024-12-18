// PRAGMA ONCE IS WRAPPER DEFINITION PREPROCESSOR 
#pragma once // IT'S C++ PROVIDE WRAPPER PREPROCESSOR THAT USE FOR PREVENTION OF THE DECLARATION OF CLASS DEFINITION MULTIPLE TIMES
// CLASS DECLARATION SECTION
#include <iostream>
#include <ctype.h>
// CREATION OF THE PARTICULAR NODE 
#include <iostream>
#include <memory> // FOR DECLARATION OF THE SMART POINTER THAT ALLOCATE AND DE-ALLOCATE DYNAMIC MEMORY EFFICEINTLY
                  //
class Node {
   public: // ACCESS-MODIFIERS 
  /* DATA MEMBERS OF THE CLASS (NODE) */
    int data;
    std::shared_ptr <Node> pre; // PRE IS A SMART POINTER THAT USED TO POINTING PRE NODE  OF THE CURRENT NODE 
    std::shared_ptr <Node> next; //  NEXT IS A SMART POINTER THAT USED TO POINTING NEXT NODE OF THE CURRENT NODE
    Node (int); // CONSTRUCTOR 
};

// CLASS PROTOTYPE 
class DeckQueue {
  /* TRADITIONAL POINTER */
  //Node *queue; // PRIVATE DATA MEMBER OF ANOTHER CLASS 
  /* SMART POINTER THAT PROVIDE BY MEMORY HEADER FILE OF STANDARD TEMPLATE LIBRARY */
  std::shared_ptr <Node> queue; // SMART POINTER
  int size; // FOR TOTAL NUMBER OF DATA IN THE DECKQUEUE 
  int task; // PRIVATE DATA MEMBER
  public: // ACCESS - MODIFIER 
  DeckQueue (); // CONSTRUCTOR 
  // ~DeckQueue (); // DESTRUCTOR 
  void run (); // MEMBER METHOD FOR EXECUTE ALL THE FILE 
  void menu (int); // MEMBER METHOD FOR SHOWING EACH INSTRUCTION TO THE USER
  void process_menu (const int&); // MEMBER METHOD FOR HANDLE PROCESS OF EACH INSTRUCTIONS
  void display () const; // MEMBER METHOD FOR DISPLAY DATA
  DeckQueue& input_restriction (); // MEMBER METHOD THAT HANDLES INPUT RESTRICTIONS OPERATIONS
  DeckQueue& output_restriction (); // MEMBER METHOD THAT HANDLES OUTPUT RESTRICTIONS OPERATIONS
  void insert_end (int); // MEMBER METHOD THAT INSERT NEW NODE IN THE LIST AT END 
  void insert_front (int); // MEMBER METHOD THAT INSERT NEW NODE IN THE LIST AT FRONT
  void delete_front (); // MEMBER METHOD THAT DELETE NODE FROM THE FRONT OF THE LIST
  void delete_end (); // MEMBER METHOD THAT DLETE NODE FROM THE END OF THE LIST
  int valid_input (); // MEMBER METHOD THAT VALIDATE INTEGER VALUES
};
