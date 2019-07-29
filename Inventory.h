//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_INVENTORY_H
#define ZZ_INVENTORY_H


#include "Item.h"
#include <vector>


class Inventory {
public:

    Inventory();
    ~Inventory();
    void GetElement(Item &a);
    void UseElement(int i);
    void eraseItem(int i);
    Item showElement(int i);
    void setElement(Item &a, int i);

    const std::vector<Item> &getVectorInv() const;

    void setVectorInv(const std::vector<Item> &vectorInv);

    int getNumSlot() const;

    void setNumSlot(int numSlot);

    bool isEmpty() const;

    void setEmpty(bool empty);


private:
    std::vector<Item> vectorInv;
    int numSlot;
    bool empty;

};


#endif //ZZ_INVENTORY_H
