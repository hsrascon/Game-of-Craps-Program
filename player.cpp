#include <iostream>
#include "player.h"

namespace HR
{
  using namespace std;
  player::player()
  {
    player_cash = 10000;
    bet = 0; 
    point = 0;
    won_money = 0;
    games_played = 0;
    games_won = 0;
  }

  void player::place_single_bet(int speed)
  {
   if( player_cash == 0)
   {
      return; 
   }
   if(bet == 0 && (speed > 1))
   {
   bet = 1; 
   player_cash -= bet; 
   return; 
   }
   if(speed == 1)
   {
   bet++;
   player_cash -= 1 ;
   }
   if(speed > 1)
   {
     if( player_cash < (bet * 2))
     {
     bet = bet + player_cash ; 
     player_cash = 0; 
     }
     else
     {
     bet *= 2; 
     player_cash -= bet ; 
     }
    }
  }

void player::place_double_bet()
{
  bet = bet * 2;
 
  player_cash -= bet;
}  

void player::reset_bet()
  {
  bet = 0; 
  }
  
  int player::get_bet()
  {
    return bet; 
  }
  
  int player::get_cash()
  {
      return (player_cash );    
  }

  void player::pay_player()
  {
   // cout<<"Player gets paid: "<<2*bet<<endl; 
    player_cash = player_cash + (2* bet);
  }
  
  void player::set_point(int const _point)
  {
      point = _point;   
  }

  int player::get_point()
  {
     return (point);
  }

  int player::played()
  {
      return games_played;
  }

  void player::increase_played()
  {
      games_played++;
      //cout<<games_played<<endl; 
  }
  
  void player::increase_won()
  {
      games_won++;
  }
  
  int player::won()
  {
     return (games_won);
  } 

}// HR
