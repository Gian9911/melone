//
// Created by gianluca on 25/07/19.
//

#include "Enemy.h"
Enemy::Enemy() :Character(){
    Dice a;
    ItemFactory factory;
    Item weapon;
    if(a.smallRoll()==1)
     weapon=factory.GenerateSword();
    else
        weapon=factory.GenerateSpell();
}

//Cosi facendo anche enemy può gestire il combattimento esattamente come una normale classe di combattimento