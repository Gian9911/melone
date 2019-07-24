
//
// Created by gianluca on 02/07/19.
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <bits/unique_ptr.h>
#include "Character.h"
#include <ctime>
#include <iostream>
#include "Inventory.h"



using namespace std;

// FIXME use initializer list
Character::Character() {
    HP = 10;
    armor = 0;
    posX = 0;
    posY = 0;
    //  weapon = nullptr;
    critic = 0;
    exp = 0;
    MaxLevel = 20;
    MaxEsp=10;
    level=1;
    isFighting=false;

}

Character::~Character() = default;

Character& Character:: operator=(const Character &other){
   if(this!= &other){
       //if(Inventory!=nullptr)
       //delete Inventory;
       HP=other.HP;
       posX=other.posX;
       posY=other.posY;
       critic=other.critic;
       exp=other.exp;
       MaxEsp=other.MaxEsp;
       level=other.level;
       MaxLevel=other.MaxLevel;
       armor=other.armor;
       //TODO crea un metodo privato che richiama sia operatore sia costruttotre copia SE NECESSARIO
       return *this;

   }
}

//Character::Character(const Character&){}

void Character::move(int x, int y) {
    posX += x;
    posY += y;
}

//void Character::move(int distance) {
 //   posX += distance;
 //   posY += distance;
//}




bool Character::fight(Character &enemy) {// da sposare in hero
    isFighting=true;
    bool success = false;



   // if (sword|spell)
   //     hit = weapon->use();

 int damage=1;// todo damage è il valore calcolato con la spada

    if (damage) {
        cout << "You hit the enemy ! (HP: " << enemy.getHp() << " punti)" << endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}




int Character::receiveDamage(int points) {
    if (level > 4)
        points -= 3;
    else if (level > 2)
        points -= 2;
    else if (level >= 1)
        points -= 2;



    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        critic+=3;
    else
        critic++;
    //
    return points;
}



bool Character::isLegalFight(const Character &enemy) const {
    int maxDistance = 1;
    if ((abs(posX - enemy.posX) > maxDistance) || (abs(posY - enemy.posY) > maxDistance))
        return false;
    return true;
}

//TODO ci sono 3 move

int Character::move(){//dda aggiungere texture
    //da modificare con key pressed
    sf::Keyboard::Key A;
    sf::Keyboard::Key W;
    sf::Keyboard::Key S;
    sf::Keyboard::Key D;
    sf::Keyboard::Key key;



    if(sf::Keyboard::isKeyPressed(A)){
        posX--;
    }
    else
        if(sf::Keyboard::isKeyPressed(W)){
            posY++;
        }
        else
            if(sf::Keyboard::isKeyPressed(S)){
                posY--;
            }
            else
                if(sf::Keyboard::isKeyPressed(D)){
                    posX++;
                }


    return (posX+posY);
}


//


int Character::getHp() const {
    return HP;
}

void Character::setHp(int hp) {
    HP = hp;
}

int Character::getCritic() const {
    return critic;
}

void Character::setCritic(int s) {
    Character::critic = s;
}

int Character::getExp() const {
    return exp;
}

void Character::setExp(int s) {
    Character::exp = s;
}

int Character::getMaxEsp() const {
    return MaxEsp;
}

void Character::setMaxEsp(int maxEsp) {
    MaxEsp = maxEsp;
}


int Character::getLevel() const {
    return level;
}

void Character::setLevel(int s) {
    Character::level = s;
}

int Character::getPosX() const {
    return posX;
}

void Character::setPosX(int s) {
    Character::posX = s;
}

int Character::getPosY() const {
    return posY;
}

void Character::setPosY(int s) {
    Character::posY = s;
}

int Character::getMaxLevel() const {
    return MaxLevel;
}

void Character::setMaxLevel(int maxLevel) {
    MaxLevel = maxLevel;
}
