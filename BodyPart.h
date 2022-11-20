#pragma once
#ifndef _Body
#define _Body

#include "Vec2.h"
#include "Boundry.h"

class Entity;

class BodyPart{
public:
    BodyPart(){}
    virtual ~BodyPart(){}
    virtual void onEquip(Entity* entity) = 0;
    virtual void draw() const = 0;
    virtual void update(const float _dt, const Vec2<float>& _pos) = 0;
    virtual void onCollision(Entity* _other) = 0;
    const Boundry& getBoundry() const { return m_boundry; }
protected:
    Boundry m_boundry;
private:
};

#endif