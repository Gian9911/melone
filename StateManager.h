//
// Created by gianluca on 21/08/19.
//

#ifndef MELONE_STATEMANAGER_H
#define MELONE_STATEMANAGER_H


#include <SFML/System/Time.hpp>
#include "Window.h"
#include "SharedContext.h"
#include "BaseState.h"

enum class StateType{
        Intro = 1, MainMenu, Game, Paused, GameOver, Credits
    };

    using StateContainer = std::vector<std::pair<StateType, BaseState*>>;
    using TypeContainer = std::vector<StateType>;
    using StateFactory = std::unordered_map<StateType, std::function<BaseState*(void)>>;

class StateManager {
public:
    explicit StateManager(SharedContext* l_shared);
    ~StateManager();

    void Update(const sf::Time& l_time);
    void Draw();
    void ProcessRequests();
    SharedContext* GetContext();
    bool HasState(const StateType& l_type);
    void Remove(const StateType& l_type);
    void SwitchTo(const StateType& l_type);

private:
    void CreateState(const StateType& l_type);
    void RemoveState(const StateType& l_type);

    template<class T>
    void RegisterState(const StateType& l_type){
        m_stateFactory[l_type] = [this]() -> BaseState*
        {
            return new T(this);
        };
    }
     SharedContext* m_shared;
     StateContainer m_states;
     TypeContainer m_toRemove;
     StateFactory m_stateFactory;
};


#endif //MELONE_STATEMANAGER_H
