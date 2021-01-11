#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Entity.h"

class Platform : public Entity{

public:
    Platform(float X, float Y, float W, float H, sf::Texture& t);
};
