#ifndef DECK_QUEUE_HEADER
#define DECK_QUEUE_HEADER
// CLASS PROTOTYPES DECLARATIONS
class DeckQueue {
  public: // PUBLIC MODIFIER FOR PUBLIC MEMBER FUNCTIONS 
   //const int max_size = 20;
   DeckQueue (); // CONSTRUCTOR METHOD OF THE CLASS
   ~DeckQueue (); // DESTRUCTOR METHOD OF THE CLASS 
  void process_menu (const int&);
  int valid_input ();
  void menu (const int&);
  DeckQueue &output_restrict ();
  DeckQueue &input_restrict ();
  DeckQueue &insert_end (DeckQueue &);
  DeckQueue &insert_front (DeckQueue &);
  DeckQueue &deletion_end (DeckQueue &);
  DeckQueue &deletion_front (DeckQueue &);
  bool isQueueFull (DeckQueue &);
  bool isQueueEmpty (DeckQueue &);
  DeckQueue &display ();
  // PRIVATE MODIFIERS MEMBERS ARE HIGHLY SECURED OR PROTECTED MEMBERS THAT NO OTHER PART OF THE CODE CAN ACCESS EXCEPT IT'S CLASS PUBLIC MEMBERS FUNCTIONS 
  // PRIVATE IS A MODIFIER THAT USED FOR DECLARATIONS OF THE PRIVATE DATA MEMBERS 
  private:
  int array [50];
  int rear;
  int front;
}; // SEMI-COLON IS VERY IMPORTANT TO INSERT WHEN CLASS DECLARATIONS IS ENED AFTER CLOSED CURLY BRACKETS 

#endif 
