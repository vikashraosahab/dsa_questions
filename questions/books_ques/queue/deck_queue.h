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
   deckQueue &input_restrictions (const int&);
   deckQueue &output_restrictions (const int&);
   deckQueue &menu ();
   deckQueue &process_menu (const int&);
   deckQueue &insert_end (const int &);
   deckQueue &insert_front (const int &);
   deckQueue &delete_end (const int &);
   deckQueue &delete_front (const int&);
   deckQueue &display ();
   bool isQueueEmpty ();
   bool isQueueFull ();
};