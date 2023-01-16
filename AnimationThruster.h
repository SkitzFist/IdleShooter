#ifndef _AnimationThruster
#define _AnimationThruster

#include "Animation.h"
#include "ParticleEmitter.h"
#include "Entity.h"

class AnimationThruster : public Animation{
public:
    AnimationThruster( Entity* _entity, const bool& _reversed = false);
    ~AnimationThruster();
    virtual void update(const float& _dt) override;
    virtual void render() const override;
private:
    ParticleEmitter* m_emitter;
    Entity* m_entity;
};

#endif