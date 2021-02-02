#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

Enemy::Enemy(float X, float Y, float W, float H, sf::Texture& t){

    size.x = W;
    size.y = H;

    hitbox.left = X;
    hitbox.right = X + size.x;
    hitbox.top = Y;
    hitbox.bottom = Y + size.y;

    idleCounter = 0;
    idleFrames = 3;
    idleSpeed = 20;

    frameSize.x = 50.f;
    frameSize.y = 50.f;

    framesAmount.x = t.getSize().x / frameSize.x;
    framesAmount.y = t.getSize().y / frameSize.y;

    for(int y = 0; y < framesAmount.y; y++){
        for(int x = 0; x < framesAmount.x; x++){
            sf::IntRect frame(x * frameSize.x, y * frameSize.y, frameSize.x, frameSize.y);
            frames.push_back(frame);
        }
    }
    setTextureRect(frames[0]);
    setTexture(t);
    setPosition(X, Y);
}
void Enemy::update(Player player){
    dist = player.getPosition().x - hitbox.left;
    if(dist >= 0){
        setScale(-1.f, 1.f);
        setOrigin(getGlobalBounds().width, 0.f);
    }
    if(dist <= 0){
        setScale(1.f, 1.f);
        setOrigin(0.f, 0.f);
    }

}
void Enemy::animate(){
    for(int i = 0; i < idleFrames; i++)
    if(idleCounter == (i + 1) * idleSpeed)
            setTextureRect(frames[i]);
    if(idleCounter == idleFrames * idleSpeed)
        idleCounter = 0;
    idleCounter++;
}
void Enemy::shoot(){

}
