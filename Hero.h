//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_HERO_H
#define ZZ_HERO_H
#include "Character.h"

class Hero: public Character {
public:
    Item item;
    Hero();
    ~Hero();
    //mettere choise in game o main?

    bool openChest();
    void Growth(int &mm);
    bool death();

private:
    //weapon






};


#endif //ZZ_HERO_H
