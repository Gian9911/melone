//
// Created by gianluca on 29/08/19.
//

#ifndef MELONE_STATE_MAINMENU_H
#define MELONE_STATE_MAINMENU_H


#include "BaseState.h"
#include "EventManager.h"

struct EventDetails;
class State_MainMenu : public BaseState{
public:
    explicit  State_MainMenu(StateManager* l_stateManager);
    ~State_MainMenu() override ;

    void OnCreate() override ;
    void OnDestroy()  override;

    void Activate()  override;
    void Deactivate()  override;

    void Update(const sf::Time& l_time) override ;
    void Draw()  override;
    void MouseClick(EventDetails* l_details);

private:
    sf::Font m_font;
    sf::Text m_text;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;
    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];

};


#endif //MELONE_STATE_MAINMENU_H
