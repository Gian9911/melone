//
// Created by gianluca on 30/08/19.
//

#ifndef MELONE_STATE_GAME_H
#define MELONE_STATE_GAME_H

#include "BaseState.h"
#include "Map.h"
#include "EventManager.h"
class Map;
class State_Game : public BaseState{
public:
    State_Game(StateManager* l_stateManager);
    ~State_Game() override ;//added override

    void OnCreate() override;
    void OnDestroy() override;

    void Activate() override;
    void Deactivate() override;

    void Update(const sf::Time& l_time) override;
    void Draw();

    void MainMenu(EventDetails* l_details) override;
    void Pause(EventDetails* l_details) override;
   // ????????void PlayerMove(EventDetails* l_details);

    // Debug:
    void ToggleOverlay(EventDetails* l_details);
private:
    void UpdateCamera();

    Map* m_gameMap;
    int m_player;
};


#endif //MELONE_STATE_GAME_H
