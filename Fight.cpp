//
// Created by gianluca on 24/07/19.
//

#include "Fight.h"
using namespace std;

bool Fight::fighting(Character &hero, Character &enemy) {// da sposare in hero
    isFighting=true;
    bool success = false;



    // if (sword|spell)
    //     hit = weapon->use();

    int damage=1;// todo damage è il valore calcolato con la spada

    if (damage) {
        cout << "You hit the enemy ! (HP: " << enemy.getHp() << " punti)" << endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

bool Fight::IsLegalFight(Character &hero, Character &enemy) const {
    int maxDistance = 1;
    if ((abs(hero.getPosX() - enemy.getPosX()) > maxDistance) || (abs(hero.getPosY() - enemy.getPosY()) > maxDistance))
            return false;
        return true;
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

