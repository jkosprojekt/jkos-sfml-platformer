#include "Player.h"
#include "Entity.h"

extern float accelGravity;
extern float maxGravity;

Player::Player(float X, float Y, float W, float H, sf::Texture& t){
    faceLeft = false;
    speed = 4.f;
    jumpHeight = 7.f;

    size.x = W;
    size.y = H;

    walkCounter = 0;
    walkFrames = 3;
    walkSpeed = 20;

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
void Player::update(bool &W, bool &A, bool &D, std::vector<Platform>& level){
    if(W && onGround) velocity.y = jumpHeight * -1;

    if(onGround == false){
        velocity.y += accelGravity;
        if(velocity.y > maxGravity) velocity.y = maxGravity;
    }

    if(A){
        faceLeft = true;
        velocity.x = -1.f;
        setScale(-1.f, 1.f);
        setOrigin(getGlobalBounds().width, 0.f);
    }
    if(D){
        faceLeft = false;
        velocity.x = 1.f;
        setScale(1.f, 1.f);
        setOrigin(0.f, 0.f);
    }
    if(!(A || D)) velocity.x = 0.f;

    move(velocity.x * speed, 0);
    collide(velocity.x, 0, level);

    onGround = false;
    move(0, velocity.y);
    collide(0, velocity.y, level);

    animate();
}
void Player::collide(float xvel, float yvel, std::vector<Platform>& level){
    for(Platform& p : level){
        if(getPosition().x < p.hitbox.right &&
           getPosition().x + size.x > p.hitbox.left &&
           getPosition().y < p.hitbox.bottom &&
           getPosition().y + size.y > p.hitbox.top)
            collision = true;
        else
            collision = false;
        if (collision){
            if(xvel > 0){
                setPosition(p.hitbox.left - size.x, getPosition().y);
                velocity.x = 0.f;
            }
            if(xvel < 0){
                setPosition(p.hitbox.right, getPosition().y);
                velocity.x = 0.f;

            }
            if(yvel > 0){
                setPosition(getPosition().x, p.hitbox.top - size.y);
                velocity.y = 0.f;
                onGround = true;
            }
            if(yvel < 0){
                setPosition(getPosition().x, p.hitbox.bottom);
                velocity.y = 0.f;
            }
        }
        if(getPosition().y < 0)
        {
            setPosition(getPosition().x, 1);
            velocity.y = 0.f;
        }
    }
}
void Player::animate(){
    if(velocity.x != 0)
        walk();
    else
        idle();
}

void Player::walk(){
    for(int i = 0; i < walkFrames; i++)
        if(walkCounter == (i + 1) * walkSpeed)
            setTextureRect(frames[i+ idleFrames]);
    if(walkCounter == walkFrames * walkSpeed)
        walkCounter = 0;

    walkCounter++;
}

void Player::idle(){
    for(int i = 0; i < idleFrames; i++)
        if(idleCounter == (i + 1) * idleSpeed)
            setTextureRect(frames[i]);
    if(idleCounter == idleFrames * idleSpeed)
        idleCounter = 0;

    idleCounter++;
}

void Player::shoot(){

}

