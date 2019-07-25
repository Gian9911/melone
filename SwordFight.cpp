//
// Created by gianluca on 25/07/19.
//

#include "SwordFight.h"


int SwordFight::calculateDamage(Item &sword) {
    int strenght=sword.getStrenght();
    strenght=strenght*3-2;
    return strenght;

}