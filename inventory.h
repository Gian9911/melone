//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_INVENTORY_H
#define ZZ_INVENTORY_H


#include "Item.h"
#include <vector>


class inventory {
public:

    inventory();
    ~inventory();
    void GetElement(Item &a);
    void UseElement(int i);
    void eraseItem(int i);



private:
    std::vector<Item> palletico;
    int numSlot;
    bool empty;

};


#endif //ZZ_INVENTORY_H
