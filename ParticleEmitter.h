#pragma once
#ifndef _ParticleEmitter
#define _ParticleEmitter

#include "Particle.h"
#include "Timer.h"
#include "Array.h"
#include "Value.h"

class ParticleEmitter{
public:
    ParticleEmitter(Value<int>* _numberOfParticles, Value<float>* _speed,
    Value<float>* _direction, float _timeBetweenEmits, Value<int>* _particleLifeTimeInMS,
    Value<float>* _particleSize);
    ~ParticleEmitter();
    void emit(const Vec2<float>& _startPos);
    const bool canEmit() const;
    void reset();
    void update(const float _dt);
    void render() const;

    void setParticleSpeedValueTogge(const bool& _value);
    void setParticleSizeValueTogge(const bool& _value);

private:
    Timer m_timeBetweenEmits;
    Array<Particle*> m_particles;
    Value<int>* m_numberOfParticles;
    Value<float>* m_speed;
    bool m_particleSpeedValueToggle;
    Value<float>* m_angle;
    Value<int>* m_particleLifeTimeInMs;
    Value<float>* m_particleSize;
    bool m_particleSizeValueToggle;
};

#endif