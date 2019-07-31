//
// Created by gianluca on 31/07/19.
//

#ifndef MELONE_EVENTTYPE_H
#define MELONE_EVENTTYPE_H

#include <vector>
#include <SFML/Window/Event.hpp>
#include <bits/unordered_map.h>
#include <functional>

enum class EventType {
KeyDown=sf::Event::KeyPressed,
KeyUp=sf::Event::KeyReleased,
MButton=sf::Event::MouseButtonPressed,
MButtonUp=sf::Event::MouseButtonReleased,
MouseWheel=sf::Event::MouseWheelMoved,
WindowResize=sf::Event::Resized,
GainedFocus=sf::Event::GainedFocus,
LostFocus=sf::Event::LostFocus,
MouseEntered=sf::Event::MouseEntered,
MouseLeft=sf::Event::MouseLeft,
Closed=sf::Event::Closed,
TextEntered=sf::Event::TextEntered,
Keyboard=sf::Event::Count+1, Mouse, Joystic

};

struct EventInfo{
    EventInfo(){m_code=0;}
    EventInfo(int l_event){m_code=l_event;}
    union{
        int m_code;
    };

    using Events=std::vector<std::pair<EventType, EventInfo>>;

    struct EventDetails{
        EventDetails(const std::string& l_bindName):m_name(l_bindName){
            Clear();
        }
        std::string m_name;
        sf::Vector2i m_size;
        sf::Uint32 m_TextEntered;
        sf::Vector2i m_mouse;
        int m_mouseWheelDelta;
        int m_keyCode;

        void Clear(){
            m_size=sf::Vector2i(0, 0);
            m_TextEntered=0;
            m_mouse=sf::Vector2i(0,0);
            m_mouseWheelDelta=0;
            m_keyCode=-1;

        }
    };


    struct Binding{
        Binding(const std::string& l_name):m_name(l_name),m_details(l_name),c(0){}
        void BindEvent(EventType l_type,EventInfo l_info=EventInfo()){
            m_events.emplace_back(l_type, l_info);
        }
        Events  m_events;
        std::string m_name;
        int c;//Count of events hapening
        EventDetails m_details;
    };

    using Bindings=std::unordered_map<std::string, Binding*>;//unordered map garantisce  he ci sia un binding per azion.

using Callbacks=std::unordered_map<std::string, std::function<void(EventDetails*)>>;


};

#endif //MELONE_EVENTTYPE_H
