//
// Created by gianluca on 02/09/19.
//

#ifndef MELONE_TEXTUREMANAGER_H
#define MELONE_TEXTUREMANAGER_H


#include <SFML/Graphics/Texture.hpp>
#include "ResourceManager.h"

class TextureManager: public ResourceManager<TextureManager, sf::Texture> {
public:
    TextureManager():ResourceManager("../Resources/textures.cfg"){}
    sf::Texture* Load1(const std::string& l_path)  {//TODO controlla nome
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(Utils::GetWorkingDirectory() + l_path)){
            delete texture;
            texture = nullptr;
            std::cerr << "!Failed to load texture: " << l_path << std::endl;
        }
        return texture;
    }
};


#endif //MELONE_TEXTUREMANAGER_H
