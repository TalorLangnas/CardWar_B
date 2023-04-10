#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"

using namespace std;
using namespace ariel;


class Deck
{
private:

   Card *cards_deck; 
   
public:
    Deck();

    void print_deck();
    void shuffle();
    Card& get_card(size_t);   
};


#endif