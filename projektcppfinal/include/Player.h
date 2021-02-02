#pragma once

#include <vector>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Platform.h"
#include "Entity.h"

class Player : public Entity{

private:

    bool collision;
    bool onGround;
    float speed;
    float jumpHeight;

    int walkCounter, idleCounter, walkFrames, idleFrames, walkSpeed, idleSpeed;
public:
    bool faceLeft;
    Player(float X, float Y, float W, float H, sf::Texture& t);
    void update(bool &W, bool &A, bool &D, std::vector<Platform>& level);
    void collide(float xvel, float yvel, std::vector<Platform>& level);
    void animate();
    void walk();
    void idle();
    void shoot();
};
