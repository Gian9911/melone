//
// Created by gianluca on 02/07/19.
//

#include <bits/unique_ptr.h>
#include "Inventory.h"
#include"Item.h"
#include "Chest.h"
#include "Hero.h"
#include <vector>

Inventory::Inventory() {
    Item a;
    a=a.getElementNull();
    empty=true;
    numSlot = 3;
    vectorInv.resize(numSlot);
    for (int i=0;i<numSlot;i++)
        vectorInv[i]=a;

}
Inventory::~Inventory()=default;


void  Inventory::GetElement(Item &a) {
    Chest chest;
    int i=0;
    for(i=0;i<numSlot;i++){
        if( vectorInv[i].getType()==0)
            vectorInv[i]=a;
    }
}

void Inventory::UseElement(int i){

    if(vectorInv[i].getType()==3){}
        //metodo che fa aumentare ps
     if(vectorInv[i].getType()==2){
         //clacola danno che fa la magia
     }
      if(vectorInv[i].getType()==1) {}
      //metodo che calcola il dqnno con la spada

}

void Inventory::eraseItem(int i){
    Item a;
    a.getElementNull();
     vectorInv[i]=a;
}

Item Inventory::showElement(int i){//TODO per riferimento?
    Item a;
    a= vectorInv[i];
    return a;
}



