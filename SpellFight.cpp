//
// Created by gianluca on 25/07/19.
//

#include "SpellFight.h"
SpellFight::SpellFight() :Item(){}

int SpellFight::fighting(Item& spell) {
int strenght=spell.getStrenght();
strenght=strenght*3-3;
return strenght;
}
