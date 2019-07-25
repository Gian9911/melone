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
    //gestione del combattimento
    //calcolo danni? Sicuramente no...posso sempre creare un metodo in item

    virtual bool fighting(Character &hero, Character &enemy);
    virtual bool IsLegalFight(Character &hero, Character &enemy) const;
    virtual int receiveDamage(Character &hero, int points);
};


#endif //MELONE_FIGHT_H
