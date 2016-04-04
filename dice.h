//dice.h

#ifndef _HR_DICE_H
#define _HR_DICE_H

#include <iostream>

using std::cout;

namespace HR
{

  class dice
  {
    private:
    
    int dice_a, 
        dice_b,
        count[12]; 
    public:

    dice();
    int roll();
    void stats(); 
  };

}//HR

#endif