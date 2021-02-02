#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Platform::Platform(float X, float Y, float W, float H, sf::Texture& t){

    size.x = W;
    size.y = H;

    hitbox.left = X;
    hitbox.right = X + size.x;
    hitbox.top = Y;
    hitbox.bottom = Y + size.y;

    setTexture(t);
    setPosition(X, Y);
}
