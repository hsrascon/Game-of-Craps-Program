#include <iostream>
#include "craps.h"
#include <stdlib.h>
#include <stdio.h>
using namespace HR;

using std::cout;
using std::endl;

int main(void)
{
  craps game, game2; 
  int st; 
  FILE *out_file, *fp ;
  fp = fopen("double.csv", "w");
  out_file= fopen("single.csv", "w");
  srand(time(0));

  for(int i = 0; i<10000; i++)
  {
    st =game.play(1); 
    fprintf(out_file, "%d, ", game.get_cash_won()); 
    if(st == 0)
    {
    break ; 
    }
  }
  cout<<"Probability of winning craps is : "<<game.get_win_prob()<< endl;
  cout<<"Probability of winning craps on first roll is: "<<game.prob_won_1st()<<endl;
  cout<<"Probability of losing craps on first roll is: "<<game.prob_lost_1st()<<endl;
 
  for(int i = 0; i<10000; i++)
  {
    st =game2.play(2); 
    fprintf(fp, "%d, ", game2.get_cash_won()); 
    if(st == 0)
    {
    break ; 
    }
  }

  fclose(out_file);
  fclose(fp);
return (0);
}                
