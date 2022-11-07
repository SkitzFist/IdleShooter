#pragma once
#ifndef _Player
#define _Player

#include "Entity.h"

class Player : public Entity{
public:
    Player(const Vec2<float>& _startPos);
    ~Player();
    virtual void update(const float _dt) override;
    virtual void draw() const override;
    
private:

};
#endif