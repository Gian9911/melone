//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_SPELL_H
#define ZZ_SPELL_H

#include <bits/unique_ptr.h>
#include "Item.h"
#include "Dice.h"


class Spell: public Item {
public:
Spell();
~Spell();

int calculateDamage();




};


#endif //ZZ_SPELL_H
