//
// Created by gianluca on 30/07/19.
//

#ifndef MELONE_GAME_H
#define MELONE_GAME_H

#include "StateManager.h"
#include "Window.h"

class Game {
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
    void MoveSprite(EventDetails* l_details);
    void LateUpdate();

private:
    void MoveCharacter();
    Window m_window;
    sf::Texture m_characterTexture;
    sf::Vector2i m_increment;
    sf::Sprite m_character;
    sf::Clock m_clock;
    sf::Time m_elpsed;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    StateManager m_stateManager;
    SharedContext m_context;
};


#endif //MELONE_GAME_H
