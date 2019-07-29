//
// Created by gianluca on 02/07/19.
//

#include "Dice.h"
#include <ctime> // for time
#include <cstdlib> // for rand and srand
#include <random>
#include<iostream>




Dice::Dice() {
     faces=3;
}

int Dice::smallRoll() {
    std::srand(time(nullptr));
    int result= rand()%(faces-1)+1;
    return result;
}



int  Dice::roll() {
    std::srand(time(nullptr));
    int result= rand()%(faces)+1;
    return result;
}
