#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Platform.h"

Bullet::Bullet(float X, float Y, float W, float H, sf::Texture& t){

    speed = 4.f;
    velocity.x = 1.f;
    size.x = W;
    size.y = H;

    hitbox.left = X;
    hitbox.right = X + size.x;
    hitbox.top = Y;
    hitbox.bottom = Y + size.y;

    setTexture(t);
    setPosition(X, Y);

    collisionPlatform = false;
    collisionEnemy = false;
    active = true;

}

void Bullet::update(Player player, std::vector<Platform>& level, std::vector<Enemy>& enemies, float time){
    if(player.faceLeft == true){
        velocity.x = -1.f;
        setScale(-1.f, 1.f);
    }
    if(player.faceLeft == false){
        velocity.x = 1.f;
        setScale(1.f, 1.f);
    }
    collideEnemy(enemies);
    collidePlatform(level);
    if(collisionEnemy == false && collisionPlatform == false)
        move(velocity.x * speed * time, 0);

}

void Bullet::collidePlatform(std::vector<Platform>& level){

    for(Platform& p : level){
        if(getPosition().x < p.hitbox.right &&
           getPosition().x + size.x > p.hitbox.left &&
           getPosition().y < p.hitbox.bottom &&
           getPosition().y + size.y > p.hitbox.top)
            collisionPlatform = true;
        else
            collisionPlatform = false;
    }
}

void Bullet::collideEnemy(std::vector<Enemy>& enemies){

    for(Enemy& en : enemies){
        if(getPosition().x < en.hitbox.right &&
           getPosition().x + size.x > en.hitbox.left &&
           getPosition().y < en.hitbox.bottom &&
           getPosition().y + size.y > en.hitbox.top)
            collisionEnemy = true;
        else
            collisionEnemy = false;
    }

}
