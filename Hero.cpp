//
// Created by gianluca on 02/07/19.
//

#include <iostream>
#include "Hero.h"
#include "Character.h"
#include "Chest.h"

//{}TODO distruzione weapon?->avviene per mezzo di distruttore di Item...chiedere

//TODO void interact

void Hero::Growth(int & reciveedexp) {
    int a=getMaxEsp();
    int b=getExp();
     b+=reciveedexp;
     int maxL=getMaxLevel();
     int level=getLevel();

//
    if(b>=a) {
        if (level < maxL)
            level++;
            //TODO se livello dispari aumenta potenza attk weapon

            if (level % 2 == 0) {
                int hp = getHp();
                hp++;
                setHp(hp);
            }
            //else ....
            int c = a - b;
            setLevel(level);
            setExp(c);
        } else
            setExp(b);
    }




bool Hero::death() {
    bool rip=false;
    int hp=getHp();
    if(hp==0){
        rip=true;
        std::cout<<"TU MORTO"<<std::endl;
        //aggiugere sprite
        //close window;

    }
    return rip;
}


bool Hero::openChest() {//PERCHE' NON MI SEGNA CHE MANCA RETURN?
    Chest chest;
    int posx=getPosX();
    int posy=getPosY();

    chest.setOpen(true);



}