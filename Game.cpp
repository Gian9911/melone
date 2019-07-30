//
// Created by gianluca on 30/07/19.
//

#include "Game.h"
#include "SFML/Graphics.hpp"

Game::Game():m_window("melone",sf::Vector2u(800,600)) {
m_characterTexture.loadFromFile("magic.png");
m_character.setTexture(m_characterTexture);
m_increment=sf::Vector2i(4,4);
}

Game::~Game() =default;

void Game::Update() {
    m_window.Update();
    MoveCharacter();
}

void Game::MoveCharacter() {
    sf::Vector2u windSize=m_window.GetWindowSize();
    sf::Vector2u textSize=m_characterTexture.getSize();

    if((m_character.getPosition().x>0)||(m_character.getPosition().x<0 && m_increment.x<0)){
        m_increment.x= -m_increment.x;
    }
    if((m_character.getPosition().y>0)||(m_character.getPosition().y<0 && m_increment.y<0)){
        m_increment.y= -m_increment.y;
    }

    m_character.setPosition(
            m_character.getPosition().x+m_increment.x,
            m_character.getPosition().y+m_increment.y);
}

void Game::Render() {
    m_window.BeginDrow();
    m_window.Draw(m_character);
    m_window.EndDrow();
}

