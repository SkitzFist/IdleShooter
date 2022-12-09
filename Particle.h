#pragma once
#ifndef _Particle
#define _Particle

#include "Vec2.h"
#include "ColorStruct.h"

class Particle{
public:
    Particle(const Vec2<float>& _pos, const float& _speed, 
    const Vec2<float>& _direction, const float& _size, Color _color = RAYWHITE);
    void update(const float _dt);
    void render() const;
private:
    Vec2<float> m_position;
    float m_speed;
    Vec2<float> m_direction;
    float m_size;
    ColorStruct m_color;
};

#endif