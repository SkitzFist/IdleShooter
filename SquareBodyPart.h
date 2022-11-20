#pragma once
#ifndef _SquareBodyPart
#define _SquareBodyPart

#include "BodyPart.h"
#include "Timer.h"

class SquareBodyPart : public BodyPart{
public:
    SquareBodyPart();
    virtual ~SquareBodyPart() override;
    virtual void update(const float _dt, const Vec2<float>& _pos) override;
    virtual void onEquip(Entity* _entity) override;
    virtual void onCollision(Entity* _other) override;
    virtual void draw() const override;

private:
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