//
// Created by gianluca on 28/07/19.
//

#ifndef MELONE_ITEMFACTORY_H
#define MELONE_ITEMFACTORY_H

#include "Item.h"


class ItemFactory {
public:
   virtual  Item GenerateSword();
   virtual  Item GenerateSpell();
   virtual void GiveStrenght(Item a, int i);


};


#endif //MELONE_ITEMFACTORY_H
