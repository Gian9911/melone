//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_BOSS_H
#define ZZ_BOSS_H

#include <iostream>
#include "minion.h"
#include "Dice.h"


class Boss :public minion{
Boss();
~Boss();
void IncreseStats();
};


#endif //ZZ_BOSS_H
