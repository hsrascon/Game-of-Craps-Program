#include <iostream>
#include <stdlib.h>
#include "dice.h"

using namespace std;
namespace HR
{
  dice::dice()   //constructor
  {
    dice_a = 0; 
    dice_b = 0;
    for(int i=0; i<12; i++)
    {
    count[i] = 0 ; 
    }
  }

  int dice::roll()
  {
  int target; 
  dice_a = (rand()%6) +1 ; 
  dice_b = (rand()%6) +1 ;
  //cout<<"dice rolled : "<<dice_a+dice_b<<endl; 
  target = dice_a + dice_b -1 ; //subtract 1 to assign to correct array element
  count[target] += 1 ; 
  return(dice_a + dice_b);
  }

  void dice::stats()
  {
    FILE *stats;
    stats = fopen("dice_stats.csv", "w");   
   
    for(int d=1; d<12 ; d++)
    {
    fprintf(stats, "%d, ", d+1); 
    }
    fprintf(stats, "\n"); 
    for(int a=1; a<12; a++)
    {
    fprintf(stats, "%d, ", count[a]);  
    }
   fclose(stats); 
  }
}//HR
