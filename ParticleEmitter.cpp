#include "ParticleEmitter.h"

//debug
#include "Log.h"
#include "Random.h"

ParticleEmitter::ParticleEmitter(Value<int>* _numberOfParticles, Value<float>* _speed,
Value2<float>* _direction, const float& _timeBetweenEmits, Value<int>* _particleLifeTimeInMS,
Value<float>* _particleSize):
    m_timeBetweenEmits(_timeBetweenEmits), m_particles(25), m_particleSizeValueToggle(true),
    m_particleSpeedValueToggle(true){
    
    m_numberOfParticles = _numberOfParticles;
    m_speed = _speed;
    m_direction = _direction;
    m_particleLifeTimeInMs = _particleLifeTimeInMS;
    m_particleSize = _particleSize;
}

ParticleEmitter::~ParticleEmitter(){
    m_particles.clear();
    delete m_numberOfParticles;
    delete m_speed;
    delete m_direction;
    delete m_particleLifeTimeInMs;
    delete m_particleSize;
}

void ParticleEmitter::emit(const Vec2<float>& _startPos){
    for(int i = 0; i < m_numberOfParticles->getValue(); ++i){
        Particle* particle = new Particle(_startPos);
        
        particle->setDirection(m_direction->getValue());

        if(m_particleSpeedValueToggle){
            particle->setSpeed(m_speed);
        }else{
            float speed = m_speed->getValue();
            particle->setSpeed(speed);
        }

        if(m_particleSizeValueToggle){
            particle->setSize(m_particleSize);
        }else{
            float size = m_particleSize->getValue();
            particle->setSize(size);
        }

        int lifeTime = m_particleLifeTimeInMs->getValue();
        particle->setLifeTime(lifeTime);

        m_particles.add(particle);
    }

    m_timeBetweenEmits.reset();
}

const bool ParticleEmitter::canEmit() const{
    return m_timeBetweenEmits.isFinished();
}

void ParticleEmitter::reset(){
    m_direction->reset();
    m_speed->reset();
    m_numberOfParticles->reset();
    m_particleLifeTimeInMs->reset();
    m_particleSize->reset();
}

void ParticleEmitter::update(const float _dt){
    m_timeBetweenEmits.update(_dt);

    for(int i = 0; i < m_particles.size(); ++i){

        if(m_particles[i]->canRemove()){
            m_particles.remove(i);
        }else{
            m_particles[i]->update(_dt);
        }
    }

    m_direction->shouldReset(); //Value2 handles reset checks inside method

    if(m_speed->shouldReset()){
        m_speed->reset();
    }

    if(m_numberOfParticles->shouldReset()){
        m_numberOfParticles->reset();
    }

    if(m_particleLifeTimeInMs->shouldReset()){
        m_particleLifeTimeInMs->reset();
    }
}

void ParticleEmitter::render() const{
    for(int i = 0; i < m_particles.size(); ++i){
        m_particles[i]->render();
    }
}

void ParticleEmitter::setParticleSizeValueToggle(const bool& _value){
    m_particleSizeValueToggle = _value;
}
void ParticleEmitter::setParticleSpeedValueToggle(const bool& _value){
    m_particleSpeedValueToggle = _value;
}