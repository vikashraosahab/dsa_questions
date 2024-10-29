// CLASS DECLARATIONS SECTION 
#include <array>

class DeckQueue {
  /* DATA MEMBER FOR THE CLASS */
  int front,rear;
  static const size_t MAX_SIZE = 20; // CONSTANT AS WELL AS STATIC MAXIMUM SIZE 
  std::array <int,MAX_SIZE> queue; // STANDARD TEMPLATE LIBRARY ARRAY WITH A CONSTANT SIZE DECLARATION
  public: /* PUBLIC MEMBER FUNCTION */
  int task; // PUBLIC DATA MEMBER
   DeckQueue (); // CLASS CONSTRUCTOR
   ~DeckQueue (); // CLASS DESTRUCTOR 
   void run ();  // MEMBER FUNCTION THAT EXECUTE ALL PROGRAM
   void menu (const int); // MEMBER FUNCTION THAT SHOW OR DISPLAY MENU
   void process_menu (const int&); // MEMBER FUNCTION THAT PROCESS TASK ACCORDING TO THE MENU 
   int valid_input () const; // MEMBER FUNCTION THAT VALIDATE INPUT VALUE 
   void display () const; // MEMBER FUNCTIONT THAT DISPLAY DECKQUEUE 
   DeckQueue& insert_end (); // MEMBER FUNCTION THAT INSER VALUE AT THE END OF THE QUEUE
   DeckQueue& insert_front (); // MEMBER FUNCTION THAT INSERT VALUE AT THE FRONT OF THE QUEUE
   DeckQueue& delete_end (); // MEMBER FUNCTION THAT DELETE VALUE FROM THE END SIDE OF THE QUEUE 
   DeckQueue& delete_front (); // MEMBER FUNCTION THAT DELETE VALUE FROM THE FRONT SIDE OF THE QUEUE
   DeckQueue& input_restriction (); // MEMBER FUNCTION THAT HANDLE INPUT RESTRICTION METHOD OF FUNCTIONALITIES 
   DeckQueue& output_restriction (); // MEMBER FUNCTION THAT HANDLE OUTPUT RESTRICTION METHOD OR FUNCTIONALITIES
   bool isQueueEmpty () const; // MEMBER METHOD THAT CHECKS QUEUE IS EMPTY OR NOT
   bool isQueueFulled () const; // MEMBER METHOD THAT CHECKS QUEUE IS FULLED OR NOT 
}; // END OF THE CLASS 