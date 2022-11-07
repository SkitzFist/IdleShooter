#include "Player.h"
#include "Log.h"

Player::Player(const Vec2<float>& _startPos){
    setPosition(_startPos);
}

Player::~Player(){
}

void Player::update(const float _dt){
    Entity::update(_dt);
}

void Player::draw() const{
    Entity::draw();
    DrawCircle(getPositon().x, getPositon().y, 15.f, RAYWHITE);
}