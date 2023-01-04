#include "Player.h"

#include "PlayerSettings.h"
#include "ValueRandom.h"
#include "ValueOverTime.h"
#include "ValueSingle.h"
//debug
#include "Log.h"

Player::Player(const Vec2<float>& _startPos){
    m_boundry.radius = PlayerSettings::RADIUS;
    m_boundry.shape = Shape::circle;
    setPosition(_startPos);

    initThrustEmitter();
}

Player::~Player(){
    delete m_thrustEmitter;
}

void Player::update(const float _dt){
    Entity::update(_dt);
    m_thrustEmitter->update(_dt);
    if(m_thrustEmitter->canEmit()){
        m_thrustEmitter->emit(getPositon());
    }
}

void Player::render() const{
    Entity::render();
    m_thrustEmitter->render();
    DrawCircle(getPositon().x, getPositon().y, m_boundry.radius, RAYWHITE);
}

void Player::initThrustEmitter(){

    float duration = 500.f;
    ValueRandom<int>* nrOfParticlesPerEmit = new ValueRandom(2,5);
    ValueOverTime<float>* particleSpeed = new ValueOverTime(
        4.f, 1.f, duration, Lerp::smoothStart3
    );

    float angleMin =PI + (PI / 2.f);
    float angleMax = angleMin + (PI);

    ValueRandom<float>* angle = new ValueRandom(-angleMin,-angleMax);
    ValueSingle<int>* particleLifeTime = new ValueSingle(static_cast<int>(duration) + 200);
    ValueOverTime<float>* particleSize = new ValueOverTime(
        3.5f, 0.f, duration, Lerp::smoothStart
    );
    m_thrustEmitter = new ParticleEmitter(
        nrOfParticlesPerEmit,
        particleSpeed,
        angle,
        0.1f,
        particleLifeTime,
        particleSize
    );
    m_thrustEmitter->setParticleSizeValueTogge(true);
    m_thrustEmitter->setParticleSpeedValueTogge(true);
}