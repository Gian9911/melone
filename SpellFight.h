//
// Created by gianluca on 25/07/19.
//

#ifndef MELONE_SPELLFIGHT_H
#define MELONE_SPELLFIGHT_H

#include "Fight.h"
#include "Item.h"

class SpellFight:public Fight,public Item {
public:
    SpellFight();
    int fighting(Item &spell) override ;
};


#endif //MELONE_SPELLFIGHT_H
