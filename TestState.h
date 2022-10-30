#pragma once
#ifndef _TestState
#define _TestState

#include "GameState.h"

class TestState : public GameState{
public:
    TestState();
    ~TestState();
    virtual GameState* handleInput() override;
    virtual GameState* update(const float _dt) override;
    virtual void render() const override;
    
private:

};

#endif