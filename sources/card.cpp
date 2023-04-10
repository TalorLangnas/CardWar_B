#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

Card::Card()
{
    rank = TWO;
    suit = HEARTS;
}

Card::Card(int otherRank, int otherSuit){
    if((otherRank < 2) || (otherRank > 13))
    {
        throw std::runtime_error("Rank have to be between 2 to 13");
    return;
    }
    if((otherSuit < 0) || (otherSuit > 3))
    {
        throw std::runtime_error("Suit have to be between 0 to 3");
    return;
    }

    rank = Rank(otherRank);
    suit = Suit(otherSuit);
};
    

// Methods:
 Rank Card::getRank()
{
    return rank;
}

void Card::setRank(int newRank)
{
    rank = Rank(newRank);
};



Suit Card::getSuit()
{
    return suit;
}

void Card::setSuit(int newSuit)
{
    suit = Suit(newSuit);
};

int Card::compareTo(Card& other){
      
       if(this->getRank() == 2 && other.getRank() == ACE)
       {    
        return 1;
       }
       if (rank == ACE && other.getRank() == TWO)
       {
        return -1;
       }

       if ((rank == ACE && other.getRank() != TWO))
       {
        return 1;
       }

       if ((other.getRank() == ACE && rank != TWO))
       {
        return -1;
       }
       
        if(rank == other.getRank())
        {
            return 0;
        }

        if (rank > other.getRank())
        {
            return 1;
        }
        else
        {
            return -1;
        }    
       
       
       }           

    
    
void Card::print_card()
{
    std::cout << to_string() << endl;
};

string Card::to_string()
{      
    return rank_to_string(rank) + " of " + suit_to_string(suit) +". ";    
};

// enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};

string Card::suit_to_string(Suit s)
{
    switch (s)
    {
        case SPADES:
            return "Spades";
        case HEARTS:
            return "Hearts";   
        case DIAMONDS:
            return "Diamonds";
         case CLUBS:
            return "Clubs";
    }
};

// enum Rank{TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
string Card::rank_to_string(Rank r)
{
    switch (r)
    {
    case TWO:
        return "2";
    case THREE:
        return "3";    
    case FOUR:
        return "4"; 
    case FIVE:
        return "5"; 
    case SIX:
        return "6"; 
    case SEVEN:
        return "7"; 
    case EIGHT:
        return "8"; 
    case NINE:
        return "9";  
    case TEN:
        return "10";
    case JACK:
        return "Jack";
    case QUEEN:
        return "Queen"; 
    case KING:
        return "King"; 
    case ACE:
        return "Ace";                                         
    }
}; 





  
