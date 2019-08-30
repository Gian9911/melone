//
// Created by gianluca on 30/08/19.
//

#ifndef MELONE_SHAREDCONTEXT_H
#define MELONE_SHAREDCONTEXT_H


#include "Window.h"
#include "EventManager.h"


struct SharedContext{
        SharedContext(){
            m_wind= nullptr;
            m_eventManager= nullptr;
        }

        Window* m_wind;
        EventManager* m_eventManager;
    };



#endif //MELONE_SHAREDCONTEXT_H
