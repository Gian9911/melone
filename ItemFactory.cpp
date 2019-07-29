//
// Created by gianluca on 28/07/19.
//

#include "ItemFactory.h"

Item ItemFactory::GenerateSpell() {
    Item a;
    a.setType(2);
    return a;
}

Item ItemFactory::GenerateSword() {
    Item a;
    a.setType(3);
    return a;
}

void ItemFactory::GiveStrenght(Item a, int i) {
    a.setStrenght(i);
}