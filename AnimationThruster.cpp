#include "AnimationThruster.h"

#include "ValueRandom.h"
#include "ValueOverTime.h"
#include "ValueSingle.h"
#include "Value2.h"
#include "ValueColorOverTime.h"

AnimationThruster::AnimationThruster(Entity* _entity, const bool& _reversed){
    m_entity = _entity;
    float duration = 350.f;
    Value<int>* nrOfParticlesPerEmit = new ValueRandom(3,10);
    Value<float>* particleSpeed = new ValueOverTime(
        100.f, 1.f, duration, Lerp::smoothStep
    );

    float xAngleMin = -0.5f;
    float xAngleMax = 0.5f;

    float yAngleMin = 0.f;
    float yAngleMax = _reversed ? -1.f : 1.f; 
    Value2<float>* direction = new Value2<float>(
        new ValueRandom<float>(xAngleMin, xAngleMax), 
        new ValueRandom<float>(yAngleMin, yAngleMax)
    );

    Value<int>* particleLifeTime = new ValueSingle(static_cast<int>(duration) + 100);

    Value<float>* particleSize = new ValueOverTime(2.5f, 0.f, duration, Lerp::smoothStart3);

    ValueColor* colorOverTime = new ValueColorOverTime(RED, YELLOW, duration - 150.f, Lerp::smoothStart2);

    m_emitter = new ParticleEmitter(
        nrOfParticlesPerEmit,
        particleSpeed,
        direction,
        0.1f,
        particleLifeTime,
        particleSize,
        colorOverTime
    );
    m_emitter->setParticleSizeValueToggle(true);
    m_emitter->setParticleSpeedValueToggle(true);
}

AnimationThruster::~AnimationThruster(){
    delete m_emitter;
}

void AnimationThruster::update(const float& _dt){
    m_emitter->update(_dt);

    if(m_emitter->canEmit()){
        m_emitter->emit(m_entity->getPositon());
    }
}

void AnimationThruster::render() const{
    m_emitter->render();
}