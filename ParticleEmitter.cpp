#include "ParticleEmitter.h"

//debug
#include "Log.h"

ParticleEmitter::ParticleEmitter(Value<int>* _numberOfParticles, Value<float>* _speed,
Value<float>* _angle, float _timeBetweenEmits, Value<int>* _particleLifeTimeInMS,
Value<float>* _particleSize):
    m_timeBetweenEmits(_timeBetweenEmits), m_particles(50), m_particleSizeValueToggle(true),
    m_particleSpeedValueToggle(true){
    
    m_numberOfParticles = _numberOfParticles;
    m_speed = _speed;
    m_angle = _angle;
    m_particleLifeTimeInMs = _particleLifeTimeInMS;
    m_particleSize = _particleSize;
}

ParticleEmitter::~ParticleEmitter(){
    m_particles.clear();
    delete m_numberOfParticles;
    delete m_speed;
    delete m_angle;
    delete m_particleLifeTimeInMs;
    delete m_particleSize;
}

/*
void ParticleEmitter::emit(const Vec2<float>& _startPos){
    
    for(int i = 0; i < m_numberOfParticles->getValue(); ++i){
        Particle* particle = new Particle(_startPos);

        float angle = m_angle->getValue();
        Vec2<float> direction = {
            cosf(angle),
            sinf(angle)
        };
        particle->setDirection(direction);

        if(m_particleSpeedValueToggle){
            particle->setSpeed(m_speed);
        }else{
            particle->setSpeed(std::move(m_speed->getValue()));
        }

        if(m_particleSizeValueToggle){
            particle->setSize(m_particleSize);
        }else{
            particle->setSize(std::move(m_particleSize->getValue()));
        }

        particle->setLifeTime(std::move(m_particleLifeTimeInMs->getValue()));

        m_particles.add(particle);
    }

    m_timeBetweenEmits.reset();
}
*/


//TODO:: needs to overload emit, delay between shots.
void ParticleEmitter::emit(const Vec2<float>& _startPos){
    for(int i = 0; i < m_numberOfParticles->getValue(); ++i){
        float speed = m_speed->getValue();
        float x = speed * cosf(m_angle->getValue());
        float y = speed * sinf(m_angle->getValue());
        int lifeTime = m_particleLifeTimeInMs->getValue();
        Vec2<float> direction(x,y);
        Vec2<float> normalizedDirection = direction.normalize();
        Particle* p = new Particle(
            _startPos, m_speed, direction,
            m_particleSize, lifeTime
        );
        m_particles.add(p);
    }
    m_timeBetweenEmits.reset();
}


const bool ParticleEmitter::canEmit() const{
    return m_timeBetweenEmits.isFinished();
}

void ParticleEmitter::reset(){
    m_angle->reset();
    m_speed->reset();
    m_numberOfParticles->reset();
    m_particleLifeTimeInMs->reset();
    m_particleSize->reset();
}

void ParticleEmitter::update(const float _dt){
    m_timeBetweenEmits.update(_dt);

    for(int i = 0; i < m_particles.size(); ++i){
        m_particles[i]->update(_dt);
       
        if(m_particles[i]->canRemove()){
            m_particles.remove(i);
        }
    }

    Particle* p = m_particles[0];

    //Log::vector("Pos", p->m_position);
    //Log::info("Speed: " + std::to_string(p->m_speed->getValue()));
    //Log::vector("dir", p->m_direction);
    //Log::info("Lifetime: " + std::to_string(p->m_lifeTimeInMS));
    //Log::info("size: " + std::to_string(p->m_size->getValue()));

    if(m_angle->shouldReset()){
        m_angle->reset();
    }
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

void ParticleEmitter::setParticleSizeValueTogge(const bool& _value){
    m_particleSizeValueToggle = _value;
}
void ParticleEmitter::setParticleSpeedValueTogge(const bool& _value){
    m_particleSpeedValueToggle = _value;
}