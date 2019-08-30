#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include"gtest/gtest.h"
#include "Character.h"
#include "Game.h"


int  main() {
    Game game;
    while (!game.GetWindow()->IsDone()) {
        game.Update();
        game.Render();
        game.LateUpdate();
    }
}








































