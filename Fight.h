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
    virtual ~Fight();
    virtual bool IsLegalFight(Character &hero, Character &enemy) const = 0;
    virtual int receiveDamage(Character &hero, int points)=0;
};


#endif //MELONE_FIGHT_H
