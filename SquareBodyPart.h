#pragma once
#ifndef _SquareBodyPart
#define _SquareBodyPart

#include "BodyPart.h"

class SquareBodyPart : public BodyPart{
public:
    SquareBodyPart();
    virtual ~SquareBodyPart() override;
    virtual void update(const float _dt) override;
    virtual void onEquip(Entity* _entity) override;
    virtual void draw(const Vec2<float>& _pos, int _radius) const override;

private:
    float m_angle;
};

#endif