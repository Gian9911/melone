//
// Created by gianluca on 02/07/19.
//
#ifndef DICE_H
#define DICE_H
class Dice {
public:

    Dice();
    ~Dice();
    int roll();

private:

    int maxRoll;
    int numRoll;
    int faces;

};


#endif
