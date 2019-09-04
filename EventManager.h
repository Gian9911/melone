//
// Created by gianluca on 19/08/19.
//

#ifndef MELONE_EVENTMANAGER_H
#define MELONE_EVENTMANAGER_H




#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <bits/unordered_map.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include "StateManager.h"

enum class EventType{
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased,
    MButtonDown = sf::Event::MouseButtonPressed,
    MButtonUp = sf::Event::MouseButtonReleased,
    MouseWheel = sf::Event::MouseWheelMoved,
    WindowResized = sf::Event::Resized,
    GainedFocus = sf::Event::GainedFocus,
    LostFocus = sf::Event::LostFocus,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    Closed = sf::Event::Closed,
    TextEntered = sf::Event::TextEntered,
    Keyboard = sf::Event::Count + 1, Mouse, Joystick
};

struct EventInfo{
    EventInfo(){ m_code = 0; }
    EventInfo(int l_event){ m_code = l_event; }
    union{
        int m_code;
    };
};

struct EventDetails{
    explicit EventDetails(const std::string& l_bindName)
            : m_name(l_bindName){
        Clear();
    }
    std::string m_name;
    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_mouseWheelDelta;
    int m_keyCode; // Single key code.
    void Clear(){
        m_size = sf::Vector2i(0, 0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_mouseWheelDelta = 0;
        m_keyCode = -1;
    }
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct Binding{
    explicit Binding(const std::string& l_name) : m_name(l_name), m_details(l_name), c(0){}
    ~Binding()=default;
    void BindEvent(EventType l_type, EventInfo l_info = EventInfo()){
        m_events.emplace_back(l_type, l_info);
    }

    Events m_events;
    std::string m_name;
    int c; // Count of events that are "happening".

    EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;
// Callback container.
using CallbackContainer = std::unordered_map<std::string, std::function<void(EventDetails*)>>;
// State callback container.
enum class StateType;
using Callbacks = std::unordered_map<StateType, CallbackContainer>;

class EventManager{
public:
    EventManager();
    ~EventManager();

    bool AddBinding(Binding *l_binding);
    bool RemoveBinding(std::string l_name);

    void SetCurrentState(StateType l_state);
    void SetFocus(const bool& l_focus);


    template<class T>
    bool AddCallback(StateType l_state, const std::string& l_name,
                     void(T::*l_func)(EventDetails*), T* l_instance)
    {
        auto itr = m_callbacks.emplace(l_state, CallbackContainer()).first;
        auto temp = std::bind(l_func, l_instance, std::placeholders::_1);
        return itr->second.emplace(l_name, temp).second;
    }

    bool RemoveCallback(StateType l_state, const std::string& l_name){
        auto itr = m_callbacks.find(l_state);
        if (itr == m_callbacks.end()){ return false; }
        auto itr2 = itr->second.find(l_name);
        if (itr2 == itr->second.end()){ return false; }
        itr->second.erase(l_name);
        return true;
    }

    void HandleEvent(sf::Event& l_event);
    void Update();


    sf::Vector2i GetMousePos(sf::RenderWindow* l_wind = nullptr){
        return (l_wind ? sf::Mouse::getPosition(*l_wind) : sf::Mouse::getPosition());
    }
private:
    void LoadBindings();

    StateType m_currentState;
    Bindings m_bindings;
    Callbacks m_callbacks;

    bool m_hasFocus;
};


#endif //MELONE_EVENTMANAGER_H
