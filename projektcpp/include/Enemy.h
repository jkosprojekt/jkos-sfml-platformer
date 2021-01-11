#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Entity.h"

class Enemy : public Entity{

private:
    int idleCounter, idleFrames, idleSpeed;
    sf::Clock animationTimer;
    sf::IntRect frame;

public:
    Enemy(float X, float Y, float W, float H, sf::Texture& t);
    void update();
    void animate();
    void shoot();
};
