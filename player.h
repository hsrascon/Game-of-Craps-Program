//player.h

#ifndef _HR_PLAYER_H
#define _HR_PLAYER_H

#include <iostream>

using std::cout;

namespace HR
{

  class player
  {
    private:
    
    int player_cash,
        bet, 
        point,
        won_money,
        games_played,
        games_won;

    public:

    player();
    void place_single_bet(int);
    void place_double_bet(); 
    void reset_bet(); 
    int get_bet();
    int get_cash();
    void pay_player();
    void lose_bet();
    void set_point(int const);
    int get_point();
    int played();
    void increase_played();
    void increase_won();
    int won();

  };

}//HR

#endif

