#pragma once
#ifndef _GameObject
#define _GameObject
#include "Vec2.h"
#include "Boundry.h"

class GameObject{
public:
    virtual ~GameObject(){}
    virtual void setPosition(const Vec2<float>& _newPos);
    const Vec2<float>& getPositon() const;
    virtual void update(const float _dt) = 0;
    virtual void draw() const = 0;
    virtual void onCollision(GameObject* _other) = 0;
    virtual const float getLargestRadius() const = 0;
    const Boundry& getBoundry() const { return m_boundry; }
protected:
    GameObject():m_boundry(){};
    Boundry m_boundry;
private:
    Vec2<float> m_position;
};

#endif