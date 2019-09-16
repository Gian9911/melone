//
// Created by gianluca on 16/09/19.
//

#ifndef MELONE_PLAYER_H
#define MELONE_PLAYER_H


#include "Character.h"

class Player: public Character {
public:
   explicit Player(EntityManager* l_entityMgr);
    ~Player() override;
    void OnEntityCollision(EntityBase* l_collider, bool l_attack) override;
    void React(EventDetails* l_details);
};


#endif //MELONE_PLAYER_H
