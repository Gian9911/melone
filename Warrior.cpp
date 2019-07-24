//
// Created by gianluca on 02/07/19.
//

#include "Warrior.h"
#include "Character.h"
#include "inventory.h"
#include "Chest.h"
#include "Item.h"



Warrior::Warrior() :Hero(){}
//TODO
Warrior::~Warrior() = default;//TODO


bool Warrior::openChest() {
    Chest chest;
    int tipo=chest.OpenChest();

    // TODO usre strategy pattern per impostare una strategia di combattimento nulla.



    



}

//puntatore + array