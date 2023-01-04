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
    m_thrustEmitter->render();
    Entity::render();
    DrawCircle(getPositon().x, getPositon().y, m_boundry.radius, BLUE);
}

void Player::initThrustEmitter(){

    float duration = 450.f;
    Value<int>* nrOfParticlesPerEmit = new ValueRandom(3,10);
    Value<float>* particleSpeed = new ValueOverTime(
        100.f, 1.f, duration, Lerp::smoothStep
    );

    float angleMin =PI + (PI/2.f); //Debug
    float angleMax = PI*2.f; //Debug

    Value<float>* angle = new ValueRandom(-angleMin,-angleMax);
    Value<int>* particleLifeTime = new ValueSingle(static_cast<int>(duration) + 200);
    Value<float>* particleSize = new ValueOverTime(
        2.5f, 0.f, duration, Lerp::smoothStart3
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