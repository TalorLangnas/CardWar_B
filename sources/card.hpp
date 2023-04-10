#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel {


    enum Rank{TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

    enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};
    
    class Card
    {
       
    private:    
    Rank rank;
    Suit suit;     

    public:
    //Constructors:
    Card(int, int);
    Card();
   
    //Methods:
    int compareTo(Card&);
    void print_card();
    Rank getRank();
    Suit getSuit();
    string to_string();
    void setRank(int);
    void setSuit(int);
    string suit_to_string(Suit);
    string rank_to_string(Rank);        
};

}

#endif

