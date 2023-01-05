#include "ParticleEmitter.h"

//debug
#include "Log.h"
#include "Random.h"

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

Array<Particle*> tracedParticles(10);
Timer tracedTimer(0.1f);
void printTraced(){
    for(int i = 0; i < tracedParticles.size(); ++i){
        Particle* p = tracedParticles[i];
        if(p->canRemove()){
            tracedParticles[i] = nullptr;
        }
        if(p){
            Log::info("P["+std::to_string(i)+"]: ");
            Log::vector("\tPos", p->m_position);
            Log::vector("\tdir", p->m_direction);
            Log::info("\tlifetime: " + std::to_string(p->m_lifeTimeInMS));
            if(p->m_speed){
                Log::info("\tSpeed: " + std::to_string(p->m_speed->getValue()));
            }else{
                Log::info("\tspeed not init");
            }
            if(p->m_size){
                Log::info("\tSize: " + std::to_string(p->m_size->getValue()));
            }else{
                Log::info("\tSize not init");
            }
            Log::info("timestamp: " + std::to_string(p->m_startTimeStamp.time_since_epoch().count()));
        }        
    }
}


void ParticleEmitter::emit(const Vec2<float>& _startPos){
    for(int i = 0; i < m_numberOfParticles->getValue(); ++i){
        Particle* particle = new Particle(_startPos);

        //need to get this value from outside
        Vec2<float> direction = {Random::FLOAT(-1.f, 1.f), Random::FLOAT(0, 1)};
        particle->setDirection(direction);

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
        static int max = 1;
        static int counter = 0;
        if(i == 0 && counter < max){
            ++counter;
            tracedParticles.add(particle);
        }
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
    tracedTimer.update(_dt);

    if(tracedTimer.isFinished()){
        if(tracedParticles.size() > 0){
            printTraced();
        }
        tracedTimer.reset();
    }

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