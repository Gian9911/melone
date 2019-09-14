//
// Created by gianluca on 30/08/19.
//

#ifndef MELONE_STATE_PAUSED_H
#define MELONE_STATE_PAUSED_H


#include "BaseState.h"
#include "EventManager.h"

class State_Paused : public BaseState {
public:
    explicit State_Paused(StateManager* l_stateManager);
    ~State_Paused() override;

    void OnCreate() override;
    void OnDestroy()override ;

    void Activate() override ;
    void Deactivate() override;

    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void Unpause(EventDetails* l_details);
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::RectangleShape m_rect;
};

#endif //MELONE_STATE_PAUSED_H
