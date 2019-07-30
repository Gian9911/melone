//
// Created by gianluca on 30/07/19.
//

#include "Window.h"

Window::Window() {
    SetUp("window",sf::Vector2u(640,480));
}

Window::Window(const std::string &title, const sf::Vector2u size) {
    SetUp(title,size);
}

Window::~Window() {
    Destroy();
}

void Window::SetUp(const std::string &title, const sf::Vector2u &size) {
    m_windowTitle=title;
    m_windowSize=size;
    m_IsFullScreen=false;
    m_IsDone=false;
    Create();
}

void Window::Create() {
    auto Style(m_IsFullScreen?sf::Style::Fullscreen:sf::Style::Default);
    m_window.create({m_windowSize.x,m_windowSize.y,32},m_windowTitle,Style);
}

void Window::Destroy() {
    m_window.close();
}

void Window::Update() {
    sf::Event event;
    while(m_window.pollEvent(event)){
        if(event.type==sf::Event::Closed){
            m_IsDone=true;
        }
        else if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::F5){
            ToggleFullScreen();
        }
    }
}

void Window::ToggleFullScreen() {
    m_IsFullScreen=!m_IsFullScreen;
    Destroy();
    Create();
}


void Window::BeginDrow() {
    m_window.clear(sf::Color::Black);
}

void Window::EndDrow() {
    m_window.display();
}

bool Window::IsDone() {
    return m_IsDone;
}

bool Window::IsFullScreen() {
    return m_IsFullScreen;
}

sf::Vector2u Window::GetWindowSize() {
    return m_windowSize;
}

void Window::Draw(sf::Drawable &drowable) {
    m_window.draw(drowable);
}
