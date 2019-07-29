//
// Created by gianluca on 29/07/19.
//

#ifndef MELONE_USEPOTION_H
#define MELONE_USEPOTION_H


#include "Fight.h"

class UsePotion : public Fight{
public:
    int calculateHeal(Item &a);
};


#endif //MELONE_USEPOTION_H
