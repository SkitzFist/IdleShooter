#pragma once
#ifndef _Entity
#define _Entity

#include "Array.h"
#include "GameObject.h"
#include "BodyPart.h"
#include "AiMovement.h"

/*
    Potentially this could be named spaceship
*/


class Entity : public GameObject{
public:
    Entity();
    ~Entity();
    virtual void update(const float _dt) override;
    virtual void draw() const override;
    virtual void onCollision(GameObject* _ohter) override {/*For subclasses*/};
    void equip(BodyPart* _body);
    virtual void setMovementBehaviour(AiMovement* _movement);
    virtual const float getLargestRadius() const override;
private:
    Array<BodyPart*> m_bodies;
    AiMovement* m_movement;
};

#endif