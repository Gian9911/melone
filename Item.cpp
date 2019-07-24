//
// Created by gianluca on 02/07/19.
//

#include "Item.h"
#include<iostream>
#include <bits/unique_ptr.h>
#include "Dice.h"
#include "Hero.h"
#include "inventory.h"

Item::Item(){
    Dice a;
    Type = a.roll();
    strenght=a.roll();
    actived=false;
    std::string b=Item::give1Name();
    std::string c=Item::give2name();
    firstName=b;
    secondName=c;


}

Item::~Item()=default;


std::string Item::give1Name() {
    if (Type % 3 == 0)
        firstName = "Spada";

    if(Type%2==0)
        firstName="Incantesimo";

    if(Type%1==0)
        firstName="Pozione";

}

std::string Item::give2name() {
    if (Type % 3 == 0)
        firstName = "invincibile";

    if(Type%2==0)
        firstName="forte";

    if(Type%1==0)
        firstName="debole";

}


bool Item::isActived() {//o nelle specifici file delle classi weapon spell e potion????
    actived=true;

}

int Item::getType() const {
    return Type;
}

void Item::setType(int type) {
    Type = type;
}

int Item::getStrenght() const {
    return strenght;
}

void Item::setStrenght(int strenght) {
    Item::strenght = strenght;
}

const std::string &Item::getFirstName() const {
    return firstName;
}

void Item::setFirstName(const std::string &firstName) {
    Item::firstName = firstName;
}

void Item::setActived(bool actived) {
    Item::actived = actived;
}

const std::string &Item::getSecondName() const {
    return secondName;
}

void Item::setSecondName(const std::string &secondName) {
    Item::secondName = secondName;
}
