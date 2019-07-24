//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_HERO_H
#define ZZ_HERO_H
#include "Character.h"

class Hero: public Character {
public:
    //mettere choise in game o main?

    bool openChest();
    void Growth(int &mm);
    bool death();

private:
    Inventory inventory;






};


#endif //ZZ_HERO_H
