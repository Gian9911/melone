//
// Created by gianluca on 02/07/19.
//

#include <iostream>
#include "minion.h"
#include "Dice.h"
#include <random>

minion::minion() {
    Dice a;
    int hp=(a.roll())*7;
    setHp(hp);

    int c=((a.roll())+3);//modifica
    setPosX(c);

    int d=((a.roll())+1);
    setPosY(d);


    int z=0;
    setExp(z);
    setMaxEsp(z);

   strenght=(a.roll()*5);
   IsFighting=false;


}

minion::~minion() =default;


int minion::enemydeath() {
   // bool rip=false;//mantenere?
    int hp=getHp();
    if(hp==0){
       // rip=true;

        //aggiugere sprite


    }
    int exp=hp/2;
    return exp;
}

void minion::randomMove() {
    if(!IsFighting) {
        int a = getPosX();
        int b = getPosY();


        int result;
        std::srand(time(nullptr));
        result = rand() % 5 + 1;
        switch (result) {//aggiungere if per dimensione massima mappa

            case 1:
                minion::move(a++, b);
                break;
            case 2:
                minion::move(a, b++);
                break;
            case 3:
                minion::move(a--, b);
                break;
            case 4:
                minion::move(a, b--);
                break;
            default:
                minion::move(a, b);
                break;

        }
    }
}



int minion::fight() {//TODO  modificare gestione combattimento IsFighting
    IsFighting=true;

//add animation...
    int damage=strenght;
    return damage;
}

int minion::getStrenght() const {
    return strenght;
}

void minion::setStrenght(int strenght) {
    minion::strenght = strenght;
}

bool minion::isFighting() const {
    return IsFighting;
}

void minion::setIsFighting(bool isFighting) {
    IsFighting = isFighting;
}
