#pragma once
#ifndef _Entity
#define _Entity
#include "GameObject.h"
#include "BodyPart.h"
#include "Array.h"

/*
    Potentially this could be named spaceship
*/


class Entity : public GameObject{
public:
    Entity();
    ~Entity();
    virtual void update(const float _dt) override;
    virtual void draw() const override;
    void equip(BodyPart* _body);
    virtual const float getRadius() const override;
private:
    Array<BodyPart*> m_bodies;
};

#endif