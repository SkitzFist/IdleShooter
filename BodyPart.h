#pragma once
#ifndef _Body
#define _Body

#include "Vec2.h"
#include "Boundry.h"
#include "GameObject.h"

class Entity;

class BodyPart : public GameObject{
public:
    BodyPart(){}
    virtual ~BodyPart(){}
    virtual void onEquip(Entity* entity) = 0;
    virtual void draw() const override {/*For subclasses*/};
    virtual void update(const float _dt) override {/*For subclasses*/};
    virtual void onCollision(GameObject* _other) override {/*For subclasses*/};
    virtual const float getLargestRadius() const override {return m_boundry.radius;}
private:

};

#endif