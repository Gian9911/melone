//
// Created by gianluca on 30/07/19.
//

#ifndef MELONE_WINDOW_H
#define MELONE_WINDOW_H

#include <SFML/Graphics.hpp>


class Window {
public:
    Window();
    Window(const std::string& title,const sf::Vector2u size);
    ~Window();
    void BeginDrow();
    void EndDrow();
    void Update();
    bool IsDone();
    bool IsFullScreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullScreen();
    void Draw(sf::Drawable& drowable);

private:
    void SetUp(const std::string& title, const sf::Vector2u& size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_IsDone;
    bool m_IsFullScreen;
};


#endif //MELONE_WINDOW_H
