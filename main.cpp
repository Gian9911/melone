#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include"gtest/gtest.h"
#include "Character.h"
#include "Game.h"


int main() {
    Game game;
    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        sf::sleep(sf::seconds(0.2));
        game.RestartClock();
    }
}








































