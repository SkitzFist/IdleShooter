#include "Player.h"

#include "PlayerSettings.h"
#include "ValueRandom.h"
#include "ValueOverTime.h"
#include "ValueSingle.h"
#include "Value2.h"

Player::Player(const Vec2<float>& _startPos):
    m_animationThruster(this,false){
    m_boundry.radius = PlayerSettings::RADIUS;
    m_boundry.shape = Shape::circle;
    
    setPosition(_startPos);
}

Player::~Player(){
 
}

void Player::update(const float _dt){
    Entity::update(_dt);
    m_animationThruster.update(_dt);
}

void Player::render() const{
    m_animationThruster.render();
    Entity::render();
    DrawCircle(getPositon().x, getPositon().y, m_boundry.radius, BLUE);
}