#pragma once
#ifndef _MoveSideways
#define _MoveSideways

#include "AiMovement.h"
#include "Vec2.h"
#include "Timer.h"

class MoveSideways : public AiMovement{
public:
    MoveSideways();
    virtual void update(const float _dt) override;
    virtual void onSetMovement(Entity* _entity) override;
private:
    Timer m_timer;
    float m_target;
    float m_next;
};

#endif