//
// Created by gianluca on 25/07/19.
//

#ifndef MELONE_SPELLFIGHT_H
#define MELONE_SPELLFIGHT_H

#include "Fight.h"
#include "Item.h"

class SpellFight:public Fight {
public:
    int claculateDamage(Item &spell);
};


#endif //MELONE_SPELLFIGHT_H
