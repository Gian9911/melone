//
// Created by gianluca on 02/07/19.
//

#include "Dice.h"
#include <ctime> // for time
#include <cstdlib> // for rand and srand
#include <random>
#include<iostream>




Dice::Dice() {

     maxRoll=3;
     faces=3;
     numRoll=0;
}

Dice::~Dice() = default;



int  Dice::roll() {
    int result;

    std::srand(time(nullptr));
    result= rand()%3+1;

    return result;

}
