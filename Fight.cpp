//
// Created by gianluca on 24/07/19.
//

#include "Fight.h"
using namespace std;


int Fight::fighting(Item &a) {
    int points=0;
    return points;
}

bool Fight::IsLegalFight(Character &hero, Character &enemy) const {
    hero.setIsFighting(true);
    enemy.setIsFighting(true);
    int maxDistance = 1;
    bool distanceIscorrect;
    if ((abs(hero.getPosX() - enemy.getPosX()) > maxDistance) || (abs(hero.getPosY() - enemy.getPosY()) > maxDistance))
            distanceIscorrect= false;
    else
        distanceIscorrect=true;
    return distanceIscorrect;
}



int Fight::receiveDamage(Character &hero, int points) {
    int level=hero.getLevel();
    int HP=hero.getHp();
    int critic=hero.getCritic();

    if (level > 4)
        points -= 3;
    else if (level > 2)
        points -= 2;
    else if (level >= 1)
        points -= 2;
    if (points <= 0)
        points = 1;
    HP -= points;
    hero.setHp(HP);
    if (points > 10)
        critic+=3;
    else
        critic++;
    hero.setCritic(critic);
    return points;
}

