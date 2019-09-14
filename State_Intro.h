//
// Created by gianluca on 27/08/19.
//

#ifndef MELONE_STATE_INTRO_H
#define MELONE_STATE_INTRO_H


#include "BaseState.h"
#include "EventManager.h"

struct EventDetails;

class State_Intro : public BaseState{
public:
    explicit State_Intro(StateManager* l_stateManager) ;
    ~State_Intro() override;
    void OnCreate()  override;
    void OnDestroy()  override;
    void Activate()  override;
    void Deactivate()  override;
    void Update(const sf::Time& l_time) override;
    void Draw()  override;
    void Continue(EventDetails* l_details) ;

private:
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Text m_text;
    float m_timePassed;
    sf::Font m_font;
};


#endif //MELONE_STATE_INTRO_H
