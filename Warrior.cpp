//
// Created by gianluca on 02/07/19.
//

#include "Warrior.h"
#include "Character.h"
#include "Inventory.h"
#include "Chest.h"
#include "Item.h"



void Warrior::fight1(int i, Character &enemy) {
    //pressed a value i by game of main and address enemy
    Item a;
    a = inventory.showElement(i);
    if (a.getType() % 1 == 0) {
        Warrior::fight(enemy);
        //calculate damage with sword
    }
}

    // TODO usre strategy pattern per impostare una strategia di combattimento nulla....check







