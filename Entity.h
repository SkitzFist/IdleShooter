#pragma once
#ifndef _Entity
#define _Entity
#include "GameObject.h"
#include "Body.h"
#include "Array.h"

/*
    Potentially this could be named spaceship
*/


class Entity : public GameObject{
public:
    Entity();
    ~Entity();
    virtual void draw() const override;
    void equip(Body* _body);

private:
    Array<Body*> m_bodies;
};

#endif