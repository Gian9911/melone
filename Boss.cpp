//
// Created by gianluca on 02/07/19.
//

#include "Boss.h"
Boss::Boss() :minion() {}
Boss::~Boss() = default;
void Boss::IncreseStats() {
    Dice a;
    int hp=getHp();
    int str=getStrenght();

    int result = (a.roll());

    switch (result) {

        case 1:
            hp=hp*2;
            break;
        case 2:
            str*=2;
            break;
        case 3:
            hp=hp*2;
            str*=2;

            break;
        default:
            hp*=2;
            break;

    }
}