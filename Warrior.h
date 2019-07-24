//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_WARRIOR_H
#define ZZ_WARRIOR_H


#include "Hero.h"
#include "Warrior.h"
#include "inventory.h"

class Warrior : public Hero {
public:
    inventory Inventory;

    ~Warrior();

    bool openChest();

    Warrior();

private:


};


#endif //ZZ_WARRIOR_H
