// CLASS DEFINITIONS
#include "deck_queue.h"
#include <iostream>

// CLASS CONSTRUCTOR DEFINITION
DeckQueue::DeckQueue () {
    std::cout << "Hello,World\n" << std::endl;
}
// CLASS PSEUDO MEMBER FUNCTIONS
DeckQueue& DeckQueue::display () {
    std::cout << "Hello,World by Vikash Yadav\n" << std::endl;

    return *this;
}
DeckQueue::~DeckQueue () {
    std::cout << "Destructor of the class" << std::endl;
}