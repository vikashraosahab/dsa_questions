// CLASS DEFINITION 
// DEFINE A CLASS WITH PRIVATE DATA MEMBERS AND MEMBER FUNCTIONS 
class deckQueue {
  private:
   int queue [20];
   int front;
   int rear;
  public:
   deckQueue (); // CONSTRUCTOR 
   ~deckQueue (); // DESTRUCTOR
   deckQueue &run ();
   int valid_input ();
   deckQueue &input_restrictions ();
   deckQueue &output_restrictions ();
   deckQueue &menu (const int task);
   deckQueue &process_menu (const int&);
   deckQueue &insert_end (const int &); // FOR THE INSERTION ELEMEN
   deckQueue &insert_front (const int &); // FOR THE INSERT ELEMENT AT THE FRONT OF THE QUEUE
   deckQueue &delete_end (const int &); // FOR DELETIO OF THE ELEMENT FROM THE END OF THE QUEUE 
   deckQueue &delete_front (const int&); // FOR DELETE ELEMENT FROM THE FRONT OF THE QUEUE
   deckQueue &display (); // FOR DISPLAYING 
   bool isQueueEmpty (); // FOR CHECKING QUEUE IS EMPTY OR NOT EMPTY 
   bool isQueueFull (); // FOR CHECKING THAT QUEUE IS FULLED OR NOT FULLED
};