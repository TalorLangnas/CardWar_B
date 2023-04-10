#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"


using namespace std;
using namespace ariel;

class Game
{
    Player& p1;
    Player& p2;
    string game_log;
    Deck* deck;
    size_t index_p1;
    size_t index_p2;
    string last_turn;
    int p1_score;
    int p2_score;
    int* players_scores;    

public:

    Game(Player&, Player&);

    void playAll();      // playes the game untill the end
    void printWiner(); // prints the name of the winning player
    void printLog();   // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    bool playTurn();
    void printLastTurn();
    void draw(bool&, int&);
    void win(bool&, int);
    void lose(bool&, int);
    string get_turn();
    void update_last_turn(string);
    void update_game_log(string);
    void update_stacks(Player&, Player&);
    void update_score(Player&, Player&);

      
};

#endif