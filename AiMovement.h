#pragma once
#ifndef _AiMovement
#define _AiMovement

class Entity;

class AiMovement{
public:
    virtual ~AiMovement() {}
    virtual void update(const float _dt) = 0;
    virtual void onSetMovement(Entity* _entity){p_entity = _entity;}
protected:
    Entity* p_entity;
};

#endif