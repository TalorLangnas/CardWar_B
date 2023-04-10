#include "deck.hpp"
#include "card.hpp"
#include <vector>
#include <cstdlib>
# include <bits/stdc++.h>

using namespace std;
//using namespace ariel;



Deck::Deck()
{   
    size_t index = 0;
    cards_deck = new Card[52];
    for(int suit = 0; suit < 4; suit++)
    {
        for(int rank = 2; rank < 14; rank++)
        {     
            cards_deck[index].setRank(Rank(rank));
            cards_deck[index].setSuit(Suit(suit));
            index++;            
        }
    }
}

Card& Deck::get_card(size_t i)
{   
    return cards_deck[i];
};


void Deck::print_deck()
{
    for(int i = 0; i < 52; i++)
    {
        cards_deck[i].print_card();
    }
}



void Deck::shuffle()
{
    srand(time(0));

    for(int i=0; i < 52; i++)
    {
        int r = i + (rand() % (52-i));
        swap(this->cards_deck[i], this->cards_deck[r]);
    }
};



