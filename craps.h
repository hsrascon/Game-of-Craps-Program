//craps.h

#ifndef _HR_CRAPS_H
#define _HR_CRAPS_H

#include <iostream>
#include "dice.h"
#include "player.h"

using std::cout;
using std::endl;
namespace HR
{
  
  class craps
  {
  private:
  dice dices;
  player HABID;
  double first_won, first_lost; 

  public:
  craps();
  int play(int);
  int play_double(int speed); 
  int get_cash_won(); 
  double get_win_prob();
  double prob_won_1st(); 
  double prob_lost_1st();
  void print_stats(); 
  };

}//HR

#endif

