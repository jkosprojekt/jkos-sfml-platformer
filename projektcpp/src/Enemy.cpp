#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy(float X, float Y, float W, float H, sf::Texture& t){

    size.x = W;
    size.y = H;

    hitbox.left = X;
    hitbox.right = X + size.x;
    hitbox.top = Y;
    hitbox.bottom = Y + size.y;

    frame = sf::IntRect(0, 0, 50, 50);
    setTexture(t);
    setTextureRect(frame);
    setPosition(X, Y);
    animationTimer.restart();
}
void Enemy::update(){

    animate();
}
void Enemy::animate(){
    if(animationTimer.getElapsedTime().asSeconds() >= 0.3f){
        frame.left += 50.f;
        if(frame.left >= 100.f)
            frame.left = 0;
        animationTimer.restart();
        setTextureRect(frame);
    }
}
void Enemy::shoot(){

}
