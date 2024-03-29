//
// Created by gianluca on 30/08/19.
//

#ifndef MELONE_SHAREDCONTEXT_H
#define MELONE_SHAREDCONTEXT_H

#include "Window.h"
#include "EventManager.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "DebugOverlay.h"

class Map;
class Window;
class EventManager;
class EntityManager;
class TextureManager;
struct SharedContext{
    SharedContext():
            m_wind(nullptr),
            m_eventManager(nullptr),
            m_textureManager(nullptr),
            m_entityManager(nullptr),
            m_gameMap(nullptr){}

    Window* m_wind;
    EventManager* m_eventManager;
    TextureManager* m_textureManager;
    EntityManager* m_entityManager;
    Map* m_gameMap;
    DebugOverlay m_debugOverlay;
};

#endif //MELONE_SHAREDCONTEXT_H
