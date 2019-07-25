//
// Created by gianluca on 02/07/19.
//


#ifndef CHARACTER_H_
#define CHARACTER_H_

//#include "Weapon.h"
#include<SFML/Graphics.hpp>
#include "Inventory.h"

class Character {
public:


   Character();//sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

    virtual ~Character();

    Character(const Character&);
    // TODO add assignment operator ?
    Character& operator=(const Character& other);

    virtual void move(int x, int y);

    // TODO check...void move(int distance);

    virtual int getHp() const;

    virtual void setHp(int hp);

   // Weapon* getWeapon();

   // void setWeapon(Weapon* weapon);


    virtual bool fight(Character &enemy);

    virtual bool isLegalFight(const Character &enemy) const;

    virtual int receiveDamage(int points);

    virtual int getCritic() const;

    virtual  void setCritic(int critic);

    virtual int getExp() const;

    virtual void setExp(int exp);

    virtual int getMaxEsp() const;

    virtual void setMaxEsp(int maxEsp);

    virtual int getLevel() const;

    virtual void setLevel(int level);

    virtual int move();

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getMaxLevel() const;

    void setMaxLevel(int maxLevel);

    bool isFighting() const;

    void setIsFighting(bool isFighting);





    //animation




    //sf::IntRect uvRect;

   // void Update(int row, float deltaTime)

private:
    int HP;
    int armor;//
    int posX;
    int posY;
  //  Weapon* weapon;
    int critic;
    int exp;
    int MaxEsp;
    int level;
    int MaxLevel;
    bool fighting;




    //animation




   // sf::Vector2u imageCount;
   // sf::Vector2u currentImage;
    //float totalTime;
    //float switchime;

};

#endif // CHARACTER_H_
