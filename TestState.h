#pragma once
#ifndef _TestState
#define _TestState

#include "GameState.h"
#include "Player.h"
#include "Array.h"
#include "Particle.h"

class TestState : public GameState{
public:
    TestState();
    ~TestState();
    virtual GameState* handleInput() override;
    virtual GameState* update(const float _dt) override;
    virtual void render() const override;
    
private:
    Entity* player;
    Array<Particle> m_particles;
};

#endif