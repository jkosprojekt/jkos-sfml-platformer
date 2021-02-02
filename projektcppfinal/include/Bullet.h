#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Enemy.h"
#include "Platform.h"
#include "Player.h"
#include "Entity.h"

class Bullet : public Entity{

private:
    float speed;
    bool active;

public:
    bool collisionPlatform;
    bool collisionEnemy;
    Bullet(float X, float Y, float W, float H, sf::Texture& t);
    void update(Player player, std::vector<Platform>& level, std::vector<Enemy>& enemies, float time);
    void collidePlatform(std::vector<Platform>& level);
    void collideEnemy(std::vector<Enemy>& enemies);

};
