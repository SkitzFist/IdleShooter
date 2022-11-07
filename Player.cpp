#include "Player.h"
#include "Log.h"

Player::Player(const Vec2<float>& _startPos){
    setPosition(_startPos);
}

Player::~Player(){

}

void Player::draw() const{
    DrawCircle(getPositon().x, getPositon().y, 15.f, RAYWHITE);
    Entity::draw();
}