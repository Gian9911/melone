//
// Created by gianluca on 30/08/19.
//

#ifndef MELONE_STATE_GAME_H
#define MELONE_STATE_GAME_H


#include "BaseState.h"
#include "EventManager.h"

class State_Game : public BaseState{
public:
    State_Game(StateManager* l_stateManager);
    ~State_Game() override ;

    void OnCreate() override;
    void OnDestroy() override;

    void Activate() override ;
    void Deactivate() override ;

    void Update(const sf::Time& l_time) override ;
    void Draw() override ;

    void MainMenu(EventDetails* l_details);
    void Pause(EventDetails* l_details);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_increment;
};



#endif //MELONE_STATE_GAME_H
