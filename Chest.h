//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_CHEST_H
#define ZZ_CHEST_H


#include <bits/unique_ptr.h>
#include"Item.h"


class Chest {
public:

    Chest();
    ~Chest();
    int OpenChest();

    bool isOpen() const;

    void setOpen(bool open);


Item giveElement();


private:
    bool open;


};


#endif //ZZ_CHEST_H
