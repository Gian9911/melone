//0
// Created by gianluca on 30/07/19.
//

#ifndef MELONE_WINDOW_H
#define MELONE_WINDOW_H

#include <SFML/Graphics.hpp>
#include "EventManager.h"

class Window {
public:
    Window();
    Window(const std::string& title,const sf::Vector2u& size);
    ~Window();
    void BeginDrow();
    void EndDrow();
    void Update();
    bool IsDone();
    bool IsFullScreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullScreen();
    void Draw(sf::Drawable& drowable);
    bool IsFocused();
    EventManager GetEventManager();//elimino il puntatore dal tipo della funzione
    void ToggleFullScreen(EventDetails* l_details);//non inserisco il puntatore nell' argonemtno da far passere
    sf::RenderWindow* GetRenderindow();


    void Close(EventDetails* l_details = nullptr){
        m_IsDone = true;
    };

private:
    void SetUp(const std::string& title, const sf::Vector2u& size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_IsDone;
    bool m_IsFullScreen;
    EventManager m_eventManager;
    bool m_isFocused;
};


#endif //MELONE_WINDOW_H
