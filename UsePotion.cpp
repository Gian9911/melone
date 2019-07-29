//
// Created by gianluca on 29/07/19.
//

#include "UsePotion.h"
int UsePotion::calculateHeal(Item &a) {
    int heal=a.getStrenght()*4;
    return heal;
}