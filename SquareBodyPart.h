#pragma once
#ifndef _SquareBodyPart
#define _SquareBodyPart

#include "Body.h"
#include "Log.h"

class SquareBodyPart : public Body{
public:
    SquareBodyPart(){}
    ~SquareBodyPart(){Log::info("SquareBodyPart destroyed");}
    virtual void onEquip(Entity* _entity) override {}
    virtual void draw(const Vec2<float>& _pos, int _radius){
        Vec2<float> pos = {
            _pos.x - _radius,
            _pos.y - _radius
        };

        DrawRectangle(pos.x, pos.y, _radius * 2, _radius * 2, GREEN);
    }
private:

};

#endif