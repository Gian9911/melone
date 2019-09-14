//
// Created by gianluca on 30/07/19.
//

#include "Window.h"
#include "EventManager.h"


Window::Window() {
    SetUp("window",sf::Vector2u(640,480));
}

Window::Window(const std::string &title, const sf::Vector2u& size) {
    SetUp(title,size);
}

Window::~Window() {
    Destroy();
}

void Window::SetUp(const std::string& title, const sf::Vector2u& size) {
    m_windowTitle=title;
    m_windowSize=size;
    m_IsFullScreen=false;
    m_IsDone=false;
    Create();

    m_isFocused = true;
    m_eventManager->AddCallback( StateType(0),"Fullscreen_toggle", &Window::ToggleFullScreen, this);
    m_eventManager->AddCallback(StateType (0), "Window_close", &Window::Close, this);
}

void Window::Create() {
    auto Style(m_IsFullScreen ? sf::Style::Fullscreen: sf::Style::Default);
    m_window.create({m_windowSize.x,m_windowSize.y,32},m_windowTitle,Style);
}

void Window::Destroy() {
    m_window.close();
}

//modifica 2

void Window::Update() {
    sf::Event event;
    while(m_window.pollEvent(event)){
        if(event.type==sf::Event::LostFocus){
            m_isFocused = false;
            m_eventManager->SetFocus(false);
        }
        else if(event.type==sf::Event::GainedFocus){
            m_isFocused = true;
            m_eventManager->SetFocus(true);
        }
        m_eventManager->HandleEvent(event);
    }
    m_eventManager->Update();
}

void Window::ToggleFullScreen(EventDetails* l_details) {//non ho idea di cosa faccia
    m_IsFullScreen = !m_IsFullScreen;
    m_window.close();
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

bool Window::IsFocused() {
    return m_isFocused;
}

EventManager* Window::GetEventManager() {
    return m_eventManager;
}

sf::RenderWindow* Window::GetRenderWindow() {
    return &m_window;
}

sf::FloatRect Window::GetViewSpace() {
    sf::Vector2f viewCentre = m_window.getView().getCenter();
    sf::Vector2f viewSize = m_window.getView().getSize();
    sf::Vector2f viewSizeHalf(viewSize.x /2, viewSize.y/2);
    sf::FloatRect viewSpace (viewCentre - viewSizeHalf, viewSize);
    return viewSpace;
}