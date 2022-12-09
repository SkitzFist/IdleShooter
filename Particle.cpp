#include "Particle.h"

Particle::Particle(const Vec2<float>& _pos, const float& _speed, 
const Vec2<float>& _direction, const float& _size, Color _color)
: m_position(_pos), m_speed(_speed), m_direction(_direction), m_size(_size),
m_color(_color){

}

void Particle::update(const float _dt){
    m_position = m_position + m_direction * m_speed * _dt;
}

void Particle::render()const{
    DrawCircle(m_position.x, m_position.y, m_size, m_color.toColor());
}