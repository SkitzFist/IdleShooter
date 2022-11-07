#pragma once
#ifndef _GameObject
#define _GameObject
#include "Vec2.h"

class GameObject{
public:
    virtual ~GameObject(){}
    virtual void setPosition(const Vec2<float>& _newPos);
    const Vec2<float>& getPositon() const;
    virtual void update(const float _dt) = 0;
    virtual void draw() const = 0;
protected:
    GameObject(){};

private:
    Vec2<float> m_position;
};

#endif