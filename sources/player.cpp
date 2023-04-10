#include "player.hpp"

using namespace std;
using namespace ariel;


 //Constructor
    Player::Player(string new_name)
    {
        name = new_name;
        record = new int[3];
        record[0] = 0;
        record[1] = 0;
        record[2] = 0;
        stack_size = 0;
        score = 0;
        win_cards = "";
        draw_cards = "";
        lose_cards = "";
    }
    
    Player::Player()
    {
        name = "Israel Israeli";
        record = new int[3];
        record[0] = 0;
        record[1] = 0;
        record[2] = 0;
        stack_size = 0;
        score = 0;
        win_cards = "";
        draw_cards = "";
        lose_cards = "";
    }
    
// Methods

int& Player::stacksize()
{
    return stack_size;
};

int Player:: cardesTaken(){
        
    return score;
};

int& Player::get_score()
{   
    return score;
};
    
    void Player::set_log(string s)
    {
        player_log = player_log + s +"\n";
    };

    string Player::get_log()
    {
        return player_log;
    };

    void Player::set_state(string s)
    {
         player_state = player_state + s +"\n";
    };
    string Player::get_state()
    {
        return player_state;
    };

    void Player::win(const Card& card)
    {
       this->get_record(0) = this->get_record(0) + 1;
       Card c = card;
       set_win_cards(c.to_string());


    };

    int& Player::get_record(size_t i)
    {
        return record[i];
    };
    
     string Player::get_win_cards()
     {
        return win_cards;
     };

    void Player::set_win_cards(string s)
    {
        win_cards = win_cards + s+"\n"; 
    };
    
    string Player::get_draw_cards()
    {
        return draw_cards;
    };
    
    void Player::set_draw_cards(string s)
    {
        draw_cards = draw_cards + s + "\n";  
    };
    
    string Player::get_lose_cards()
    {
        return lose_cards;
    };

    void Player::set_lose_cards(string s)
    {
         lose_cards =  lose_cards + s + "\n";  
    };
    

string Player::get_name()
{
    return name + " ";
};

    


   

