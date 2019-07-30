//
// Created by gianluca on 30/07/19.
//

#ifndef MELONE_GAME_H
#define MELONE_GAME_H


#include "Window.h"

class Game {
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();


private:
    void MoveCharacter();
    Window m_window;
    sf::Texture m_characterTexture;
    sf::Vector2i m_increment;
    sf::Sprite m_character;


};


#endif //MELONE_GAME_H
