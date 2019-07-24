//
// Created by gianluca on 02/07/19.
//

#include <bits/unique_ptr.h>
#include "inventory.h"
#include"Item.h"
#include "Chest.h"
#include "Hero.h"
#include <vector>

inventory::inventory() {




    empty=true;
    numSlot = 3;
    palletico.resize(numSlot);

}
inventory::~inventory()=default;


void  inventory::GetElement(Item &a) {
    Chest chest;
    int i=0;
    for(i=0;i<numSlot;i++){
        if( palletico[i].getType()==0)
            palletico[i]=a;
    }
}





void inventory::UseElement(int i){

    if(palletico[i].getType()==3){}
        //metodo che fa aumentare ps
     if(palletico[i].getType()==2){
         //clacola danno che fa la magia
     }
      if(palletico[i].getType()==1) {}
      //metodo che calcola il dqnno con la spada

}

void inventory::eraseItem(int i){
    Item a;
    a.setType(0);
     palletico[i]=a;
}