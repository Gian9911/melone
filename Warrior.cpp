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

Warrior::Warrior():Hero(){
    fight=nullptr;
}

void Warrior::setFight(Fight* fightt) {
    fight=fightt;

}





