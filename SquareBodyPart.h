#pragma once
#ifndef _SquareBodyPart
#define _SquareBodyPart

#include "BodyPart.h"
#include "Timer.h"

class Entity;

class SquareBodyPart : public BodyPart{
public:
    SquareBodyPart();
    virtual ~SquareBodyPart() override;
    virtual void update(const float _dt) override;
    virtual void onEquip(Entity* _entity) override;
    virtual void onCollision(GameObject* _other) override;
    virtual void render() const override;

private:
    Entity* m_entity;
    Timer m_timer;
    Rectangle rec;
    float m_angleStart;
    float m_angleTarget;
    float m_sizeFactor;
    float m_sizeStart;
    float m_sizeTarget;
    float m_baseRadius;
};

#endif