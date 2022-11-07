#pragma once
#ifndef _Body
#define _Body

#include "Vec2.h"

class Entity;

class BodyPart{
public:
    virtual ~BodyPart(){}
    virtual void onEquip(Entity* entity) = 0;
    virtual void draw(const Vec2<float>& _pos, int _radius) const = 0;
    virtual void update(const float _dt) = 0;
private:
};

#endif