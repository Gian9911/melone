//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_WARRIOR_H
#define ZZ_WARRIOR_H


#include "Hero.h"
#include "Warrior.h"
#include "Inventory.h"
class Fight;

class Warrior : public Hero {
public:
    Warrior();
    virtual void setFight(Fight* fightt);
Item* f(int i);

protected:
    Fight* fight;
};


#endif //ZZ_WARRIOR_H
