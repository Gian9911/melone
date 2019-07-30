
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
    Item a;
    a.getElementNull();
    int i=0;
    int b=inventory.getNumSlot();

    for(i=0;i<b;i++)
        inventory.setElement(a,i);


    HP = 10;
    armor = 0;
    posX = 0;
    posY = 0;
    critic = 0;
    exp = 0;
    MaxLevel = 20;
    MaxEsp=10;
    level=1;
    fighting=false;
    sf::RectangleShape d(sf::Vector2f(100.0f,100.0f));
    this->base=d;



}

sf::RectangleShape Character::realizeElement() {
    sf::RectangleShape a(sf::Vector2f(100.0f,100.0f));
return a;
}

Character::~Character() = default;

Character& Character:: operator=(const Character &other) {
    if (this != &other) {
        //if(Inventory!=nullptr)
        //delete Inventory;
        HP = other.HP;
        posX = other.posX;
        posY = other.posY;
        critic = other.critic;
        exp = other.exp;
        MaxEsp = other.MaxEsp;
        level = other.level;
        MaxLevel = other.MaxLevel;
        armor = other.armor;
        inventory=other.inventory;
        //TODO crea un metodo privato che richiama sia operatore sia costruttotre copia SE NECESSARIO
    }
    return *this;
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

//TODO rifare move

bool Character::move(){//dda aggiungere texture
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            posX--;
            base.move(-0.1f,0.0f);
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            posY++;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                posY--;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    posX++;
        bool moved=true;
    return moved;
}

bool Character::move2(sf::Keyboard::Key){//dda aggiungere texture
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        posX--;
        base.move(-0.1f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        posX--;
        base.move(0.0f,-0.1f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        posX--;
        base.move(0.0f,0.1f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        posX--;
        base.move(0.1f,0.0f);
    }


    bool moved=true;
    return moved;
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

bool Character::isFighting() const {
    return fighting;
}

void Character::setIsFighting(bool isFighting) {
    Character::fighting = isFighting;
}

void Character::setFighting(bool j) {
    Character::fighting = j;
}

const Inventory &Character::getInventory() const {
    return inventory;
}

void Character::setInventory(const Inventory &u) {
    Character::inventory = u;
}

const sf::RectangleShape &Character::getBase() const {
    return base;
}

void Character::setBase(const sf::RectangleShape &u) {
    Character::base = u;
}



