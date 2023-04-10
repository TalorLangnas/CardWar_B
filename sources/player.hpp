#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;
using namespace ariel;

class Player{
    
    string name;
    int* record;
    string player_log;
    string player_state;
    string win_cards;
    string draw_cards;
    string lose_cards;
    int stack_size;
    int score;   
    

    public:

    //Constructor
    Player();
    Player(string name);
    //~Player();
    
    //Demo methods   
    
    //string stacksize(); // return the amount of cards left.
    int& stacksize(); // return the amount of cards left.
    int cardesTaken();
    void set_log(string);
    string get_log();
    void set_state(string);
    string get_state();
    void win(const Card&);
    int& get_record(size_t);
    string get_win_cards();
    void set_win_cards(string);
    string get_draw_cards();
    void  set_draw_cards(string);
    string get_lose_cards();
    void set_lose_cards(string);
    string get_name();
    int& get_score();
    
    
};


#endif