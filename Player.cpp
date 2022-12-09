#include "Player.h"
#include "PlayerSettings.h"

Player::Player(const Vec2<float>& _startPos){
    m_boundry.radius = PlayerSettings::RADIUS;
    m_boundry.shape = Shape::circle;
    setPosition(_startPos);
}

Player::~Player(){
}

void Player::update(const float _dt){
    Entity::update(_dt);
}

void Player::draw() const{
    Entity::draw();
    DrawCircle(getPositon().x, getPositon().y, m_boundry.radius, RAYWHITE);
}