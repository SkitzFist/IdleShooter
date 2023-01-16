#pragma once
#ifndef _Particle
#define _Particle

#include <chrono>

#include "Vec2.h"
#include "ValueColor.h"
#include "Value.h"

class Particle{
public:
    Particle(const Vec2<float>& _pos);
    ~Particle();
    void update(const float _dt);
    const bool canRemove() const;
    void render() const;
    
    void setColor(ValueColor* _color);
    void setPosition(const Vec2<float>& _pos);
    void setDirection(const float& _angle);
    void setDirection(const Vec2<float>& _dir);
    void setSpeed(Value<float>* _speed);
    void setSpeed(const float& _speed);
    void setSize(Value<float>* _size);
    void setSize(const float& _size);
    void setLifeTime(const float _lifeTimeInMS);
    
private:
    ValueColor* m_color;
    Vec2<float> m_position;
    Vec2<float> m_direction;
    Value<float>* m_speed;
    Value<float>* m_size;
    int m_lifeTimeInMS;
    std::chrono::steady_clock::time_point m_startTimeStamp;
};

#endif