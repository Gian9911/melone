//
// Created by gianluca on 02/07/19.
//

#include "Warrior.h"
#include "Character.h"
#include "Inventory.h"
#include "Chest.h"
#include "Item.h"
#include "Fight.h"
#include "SwordFight.h"

// TODO usre strategy pattern per impostare una strategia di combattimento nulla....check

Fight* Warrior::f(int i) {
    Item a=inventory.showElement(i);
    int b=a.getType();
    Fight* fightt=new SwordFight();
    if(b==2|b==1)
       fightt=nullptr;
    return fightt;
}




