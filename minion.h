//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_MINION_H
#define ZZ_MINION_H


#include "Character.h"

class minion : public Character {
public:
    minion();

    ~minion();

    int enemydeath();


    void randomMove();

    int fight();

    int getStrenght() const;

    void setStrenght(int strenght);

    bool isFighting() const;

    void setIsFighting(bool isFighting);


private:
    int strenght;
    bool IsFighting;

};


#endif //ZZ_MINION_H
