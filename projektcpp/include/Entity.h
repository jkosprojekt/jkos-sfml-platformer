#pragma once
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Hitbox.h"


class Entity : public sf::Sprite{
public:
    sf::Vector2f velocity, size, frameSize, framesAmount;
    std::vector<sf::IntRect> frames;

    Hitbox hitbox;
};

