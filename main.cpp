#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include"gtest/gtest.h"
#include "Character.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(512,512),"Melone",sf::Style::Close|sf::Style::Resize);
   sf::Texture textureWarrior;
   textureWarrior.loadFromFile("magic.png");
   sf::Sprite warrior(textureWarrior);
   sf::Vector2u size=textureWarrior.getSize();
   warrior.setOrigin(size.x/2,size.y/2);
   sf::Vector2f increment(0.4f,0.4f);


    Character melone;
    sf::RectangleShape meloneShape=melone.getBase();
    meloneShape.setPosition(100,100);
    sf::Texture texture;
    texture.loadFromFile("magic.png");

    while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if(event.text.unicode<128)
                    std::cout<<event.text.unicode<<std::endl;
        }
    }
    if((warrior.getPosition().x+(size.x/2)>window.getSize().x && increment.x>0)||(warrior.getPosition().x-(size.x/2)<0 && increment.x<0)){
        increment.x=-increment.x;
    }
    if((warrior.getPosition().y+(size.y/2)>window.getSize().y && increment.y>0) || (warrior.getPosition().y-(size.y/2)<0 && increment.y<0)){
        increment.y=-increment.y;
    }
    warrior.setPosition(warrior.getPosition()+increment);
    window.clear(sf::Color(16,16,16,255));
    window.draw(warrior);
    window.display();

}
return 0;
}
