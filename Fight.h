//
// Created by gianluca on 24/07/19.
//

#ifndef MELONE_FIGHT_H
#define MELONE_FIGHT_H

#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include <iostream>
class Fight {
public:
    virtual int fighting(Item& a)=0;
    virtual bool IsLegalFight(Character &hero, Character &enemy) const;
    virtual int receiveDamage(Character &hero, int points);
};


#endif //MELONE_FIGHT_H
