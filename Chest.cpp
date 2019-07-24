//
// Created by gianluca on 02/07/19.
//

#include "Chest.h"
#include "Item.h"
#include <memory>
#include "inventory.h"



Chest::Chest() {
    open=false;



}

Chest::~Chest()=default;

int Chest::OpenChest() {
    open=true;
    Item a;
    int tipo=a.getType();
    return tipo;

}

bool Chest::isOpen() const {
    return open;
}

void Chest::setOpen(bool open) {
    Chest::open = open;
}

Item Chest::giveElement() {
    Item a;
    return a;
}