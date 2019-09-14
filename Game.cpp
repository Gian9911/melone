//
// Created by gianluca on 30/07/19.
//

#include <iostream>
#include "Game.h"
#include "SFML/Graphics.hpp"

Game::Game(): m_window("melone", sf::Vector2u(800, 600)),m_stateManager(&m_context){
m_clock.restart();
srand(time(nullptr));
m_context.m_wind = &m_window;
m_context.m_eventManager = m_window.GetEventManager();//controla modifica abbastana importante
//m_characterTexture.loadFromFile("magic.png");
//m_character.setTexture(m_characterTexture);
//m_increment=sf::Vector2i(4,4);
//m_window.GetEventManager().AddCallback(StateType (0),"Move", &Game::MoveSprite,this);//aggiunto statetype(0)
//m_context.m_wind = &m_window;
//m_context.m_eventManager = m_window.GetEventManager();
m_stateManager.SwitchTo(StateType::Intro);
}

Game::~Game() =default;

void Game::Update() {
    m_window.Update();
    m_stateManager.Update(m_elpsed);
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
    m_stateManager.Draw();
    m_window.EndDrow();
}


Window* Game::GetWindow() {
    Window* window=&m_window;
    return window;
}

sf::Time Game::GetElapsed() {
    return m_elpsed;
}

void Game::RestartClock() {
    float frametime =1.0f/60.0f;
    if(m_elpsed.asSeconds()>=frametime){
        m_elpsed-=sf::seconds(frametime);
    }
    else
        m_elpsed+=m_clock.restart();

}

void Game::MoveSprite(EventDetails *l_details) {
    sf::Vector2i mousepos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
    m_sprite.setPosition(mousepos.x, mousepos.y);
    std::cout<<"Moving sprite to:"<<mousepos.x<<":"<<mousepos.y<<std::endl;
}

void Game::LateUpdate() {
    m_stateManager.ProcessRequests();
    RestartClock();
}