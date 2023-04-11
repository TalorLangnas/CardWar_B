#include "game.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2):p1(player1), p2(player2)
{
  deck = new Deck();
  deck->shuffle();
  index_p1 = 0;
  index_p2 = 51;
  p1.stacksize() = 26;
  p2.stacksize() = 26;
  players_scores = new int[2];
  players_scores[0] = 0;
  players_scores[1] = 0;
};


// playes the game untill the end
void Game::playAll()
{
  if (&this->p1 == &this->p2)
  {
    std::cout << " enter to if (&this->p1 == &this->p2) throw exception"<<endl;
    throw std::runtime_error("players must be diffrent");
  }

  while(playTurn() != false)
  {
    
  }
};

// play one turn.
bool Game::playTurn()
{ 
  if((p1.stacksize() == 0) || (p2.stacksize() == 0))
  {
    throw std::runtime_error("The Game is over, players have 0 cards");
    return false;
  }
  if(index_p1 > index_p2)
  {
    throw std::runtime_error("The Game is over, players have 0 cards");
    return false;
  }

  if (&this->p1 == &this->p2)
  {
    throw std::runtime_error("players must be diffrent");
    return false;
  }

  bool cards_flag = true;
  int draw_counter = 0;
  while ((deck->get_card(index_p1).compareTo(deck->get_card(index_p2)) == 0) && (index_p1 < index_p2))
  {                                                                        
    draw(cards_flag, draw_counter);
  }

  if ((deck->get_card(index_p1).compareTo(deck->get_card(index_p2)) == 1) && (index_p1 < index_p2))
  { 
    win(cards_flag, draw_counter);
    
    return cards_flag;
  }

  if ((deck->get_card(index_p1).compareTo(deck->get_card(index_p2)) == -1) && (index_p1 < index_p2))
  {   
    lose(cards_flag, draw_counter);
    
    return cards_flag;
  }
    return cards_flag;
};



void Game::draw(bool& cards_flag, int& draw_counter)
{ 
  p1.get_record(1) = p1.get_record(1) + 1;
  p1.set_draw_cards(deck->get_card(index_p1).to_string());
  
  p2.get_record(1) = p2.get_record(1) + 1;
  p2.set_draw_cards(deck->get_card(index_p2).to_string());

  string this_turn = get_turn();
  this_turn = this_turn + "Draw. ";
  update_last_turn(this_turn);

  index_p1++;
  index_p2--;
  update_stacks(p1, p2);  
  draw_counter = draw_counter + 2;
  
  if ((p1.stacksize() == 0) || (p2.stacksize() == 0))
  { 
    cards_flag = false;    
    players_scores[0] = (players_scores[0] + draw_counter); 
    players_scores[1] = (players_scores[1] + draw_counter);  
    update_score(p1, p2);    
  }
  
  if(cards_flag)
  {
    index_p1++;
    index_p2--;
  } 
};

void Game::win(bool &cards_flag, int draw_counter)
{ 
  p1.get_record(0) = p1.get_record(0) + 1;
  p1.set_win_cards(deck->get_card(index_p1).to_string());
  
  players_scores[0] = (2 + players_scores[0] + (draw_counter*2));  
  update_score(p1, p2);
  
  p2.get_record(2) = p2.get_record(2) + 1;
  p2.set_lose_cards(deck->get_card(index_p2).to_string());

  string this_turn = get_turn();
  this_turn = this_turn + p1.get_name()+ "Win. ";
  update_last_turn(this_turn);

  index_p1++;
  index_p2--;
  update_stacks(p1, p2); 
  
  if ((p1.stacksize() == 0) || (p2.stacksize() == 0))
  { 
    cards_flag = false;
  }
};

void Game::lose(bool &cards_flag, int draw_counter)
{ 
  p2.get_record(0) = p2.get_record(0) + 1;
  p2.set_win_cards(deck->get_card(index_p2).to_string());
  players_scores[1] = 2 + players_scores[1] + (draw_counter*2);
  update_score(p1, p2);

  p1.get_record(2) = p1.get_record(2) + 1;
  p1.set_lose_cards(deck->get_card(index_p1).to_string());

  string this_turn = get_turn();
  this_turn = this_turn + p2.get_name()+ "Win. ";
  update_last_turn(this_turn);

  index_p1++;
  index_p2--;
  update_stacks(p1, p2); 
  if ((p1.stacksize() == 0) || (p2.stacksize() == 0))
  { 
    cards_flag = false;
  }
};

// prints the name of the winning player
void Game::printWiner()
{
  int p1_score = p1.get_record(0);
  int p2_score = p2.get_record(0);

  if (p1_score == p2_score)
  {
    std::cout << "No winner, it's draw" << endl;
  }
  if (p1_score > p2_score)
  {

    std::cout << p1.get_name() << endl;
  }
  else
    std::cout << p2.get_name() << endl;
};

// update players stack size:
void Game::update_stacks(Player& player1, Player& player2)
{
    player1.stacksize() = 26 - index_p1;
    player2.stacksize() = 26 - (52-(index_p2 + 1)); 
};

// update players scores each round:
void Game::update_score(Player& player1, Player& player2)
{
    player1.get_score() = players_scores[0];
    player2.get_score() = players_scores[1];
};

// prints all the turns played one line per turn (same format as game.printLastTurn())
void Game::printLog()
{
  string log = "Log:\n" + game_log;

  std::cout << log << endl;
};

// log new data
void Game::update_game_log(string s)
{
  game_log = game_log + s + "\n";
};

void Game::printLastTurn()
{
  std::cout << last_turn << endl;
};

// this method return LastTurn()'s format string. 
string Game::get_turn()
{
  return p1.get_name() + "played " + deck->get_card(index_p1).to_string()
             + p2.get_name() + "played " + deck->get_card(index_p2).to_string();
};

/* this method updates the las_turn string and game_log string.
(when we update las_turn string the game_log string wil update autumaticlty)*/ 
void Game::update_last_turn(string s)
{
  last_turn = s;
  update_game_log(last_turn);
};

// for each player prints basic statistics:
void Game::printStats()
{ 
  std::cout << "Game state:" << endl << endl
            << "Player_1 state:" << endl 
            << "Win rate: " <<  p1.get_record(0) << " of 26 " << endl 
            << "Cards won:" << endl << p1.get_win_cards() << endl 
            << "Draw rate: " << p1.get_record(1) << " of 26 " << endl 
            << "Cards draw:" << endl << p1.get_draw_cards() << endl
            << "Lost rate: " << endl << p1.get_record(2)<< " of 26 " << endl
            << "Cards lost:" << endl << p1.get_lose_cards() << endl << endl
            << "Player_2 state:" << endl 
            << "Win rate: " <<  p2.get_record(0)<< " of 26 " << endl 
            << "Cards won:" << endl << p2.get_win_cards() << endl 
            << "Draw rate: " << p2.get_record(1)<< " of 26 " << endl 
            << "Cards draw:" << endl << p2.get_draw_cards() << endl
            << "Lost rate: " << endl << p2.get_record(2)<< " of 26 " << endl
            << "Cards lost:" << endl << p2.get_lose_cards() << endl; 
};


