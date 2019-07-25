//
// Created by gianluca on 25/07/19.
//

#ifndef MELONE_SWORDFIGHT_H
#define MELONE_SWORDFIGHT_H

#include "Fight.h"
#include "Item.h"


class SwordFight :public Fight{
public:
    int calculateDamage(Item &sword);


};


#endif //MELONE_SWORDFIGHT_H
