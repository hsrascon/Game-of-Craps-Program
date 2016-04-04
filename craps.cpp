#include <iostream>
#include "craps.h"
#include "dice.h"
#include "player.h"

using std::cout;
using std::endl; 

namespace HR
{
  craps::craps()
  {
  first_won = 0; 
  first_lost = 0; 
  }

  int craps::play(int speed)
  {
    if(HABID.get_cash()==0)
    {
      return 0;
    }
    int roll;

    HABID.place_single_bet(speed); 
    roll = dices.roll(); 
    HABID.increase_played();  

    if( (roll==7) || (roll==11) )
    {
    HABID.increase_won(); 
    HABID.pay_player(); 
    first_won++; 
    HABID.reset_bet(); 
    return 1;
    }

    if( (roll==2) || (roll==3) || (roll==12) )
    {
     first_lost++;
     HABID.reset_bet(); 
     return 1; 
    }

    if( (roll==4) || (roll ==5) || (roll==6) || (roll==8) || (roll==9) || (roll==10) )
    {
      HABID.set_point(roll); 
      while( (roll!=7))
      {
        HABID.place_single_bet(speed); 
        //cout<<HABID.get_bet()<<endl; 
        roll = dices.roll(); 
        if(roll == 7)
        {
         HABID.reset_bet(); 
         return 1; 
        }
        if( roll == HABID.get_point() )
        {
          HABID.increase_won(); 
          HABID.pay_player(); 
          HABID.reset_bet();
          return 1; 
        }//if
      }//while
    }//else
  HABID.reset_bet(); 
  return 1; 
  }//play()

int craps:: play_double(int speed)
{
  
  int roll;
  bool pass;
  
  HABID.increase_played(); 
	
  HABID.place_single_bet(speed); 
 
  if(HABID.get_cash() < HABID.get_bet())
  {
    return 0;
  }                        
  cout << "Bet: " <<HABID.get_bet()<< endl;
  
  roll = dices.roll();
								
  if((roll == 7) || (roll == 11))
  {
    HABID.increase_won(); 
    HABID.pay_player(); 
    first_won++; 
    HABID.reset_bet(); 
    return 1;
  }
    if( (roll==2) || (roll==3) || (roll==12) )
    {
     first_lost++;
     HABID.reset_bet(); 
     return 1; 
    }

			//Goes on to continuation rolls
			else if((roll==4) || (roll ==5) || (roll==6) || (roll==8) || (roll==9) || (roll==10) )

			{
			      HABID.set_point(roll); 				
                              pass = true;
				while(pass == true)
				{
				   HABID.place_double_bet();
					//Checks if player has enough money
					if(HABID.get_cash() < HABID.get_bet())
						break;
		                        cout << "Bet: " << HABID.get_bet()<< endl;
  					roll = dices.roll();

					//Checks if player loses and loops out
	                        	if((roll == 7))
	                        	{
						//Increments losses and games played, sets money lost
	                        	        HABID.reset_bet(); 
						pass = false;
	                        	}

					//Checks if player wins and loops out
					if(roll == HABID.get_point())
					{    
					HABID.increase_won(); 
					HABID.pay_player(); 
					HABID.reset_bet(); 
					pass = false;
                                        }
                                   }
                           }
                  
                      HABID.reset_bet(); 
                      return 1;
                  }

  int craps::get_cash_won()
  {
   return( HABID.get_cash());
  }
 
  double craps::get_win_prob()
  {
  return((HABID.won()/ (double)HABID.played())*100.0);
  }

  double craps::prob_won_1st()
  {
  return ((first_won/(double)HABID.played())*100) ; 
  }

  double craps::prob_lost_1st()
  {
  return ((first_lost/(double)HABID.played())*100) ; 
  }
  void craps::print_stats()
  {
  dices.stats(); 
  }

}//HR
