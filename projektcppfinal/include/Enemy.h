#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity{

private:
    float dist;
    int idleCounter, idleFrames, idleSpeed;
    sf::Clock animationTimer;
    sf::IntRect frame;

public:
    Enemy(float X, float Y, float W, float H, sf::Texture& t);
    void update(Player player);
    void animate();
    void shoot();
};
