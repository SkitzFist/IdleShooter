#include "Particle.h"
#include "Settings.h"
#include "ValueSingle.h"
//debug
#include "Log.h"

Particle::Particle(const Vec2<float>& _pos, Value<float>* _speed, 
            const Vec2<float>& _direction, Value<float>* _size, 
            const int& _lifeTimeInMS, Color _color):
    m_position(_pos), m_direction(_direction), 
    m_lifeTimeInMS(_lifeTimeInMS),m_color(_color){
    m_speed = _speed->copy();
    m_size = _speed->copy();
    m_startTimeStamp = std::chrono::steady_clock::now();
}

Particle::Particle(const Vec2<float>& _pos):
    m_color(RAYWHITE), m_position(_pos){
    m_direction = {1.f,1.f};
    m_lifeTimeInMS = 1000;
    m_speed = nullptr;
    m_size = nullptr;
}

Particle::~Particle(){
    delete m_speed;
    delete m_size;
}

void Particle::update(const float _dt){
    if(m_speed){
        m_position = m_position + (m_direction * m_speed->getValue()) * _dt;
    }else{
        Log::info("speed not initiated");
    }
}

const bool Particle::canRemove() const{
    std::chrono::steady_clock::time_point curentTimeStamp = std::chrono::steady_clock::now();
    float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curentTimeStamp - m_startTimeStamp).count();
    bool lifeTimeReachedDuration = elapsed >= m_lifeTimeInMS;
    bool particleIsOutOfBounds = m_position.x > Settings::WORLD_SIZE.x || m_position.x < 0.f ||
                                m_position.y > Settings::WORLD_SIZE.y || m_position.y < 0.f;
 
    if(lifeTimeReachedDuration || particleIsOutOfBounds){
        return true;
    }
    return false;
}

void Particle::render()const{
    if(m_size){
        DrawCircle(m_position.x, m_position.y, m_size->getValue(), m_color.toColor());
    }else{
        Log::info("Size not initiated");
    }
    
}

void Particle::setColor(const Color& _color){
    m_color = _color;
}
void Particle::setPosition(const Vec2<float>& _pos){
    m_position = _pos;
}
void Particle::setDirection(const float& _angle){
    if(m_speed){
        float speed = m_speed->getValue();
        Vec2<float> direction = {
            speed * cosf(_angle),
            speed * sinf(_angle)
        };
        m_direction = direction.normalize(); //might need to move it
    }
}
void Particle::setDirection(const Vec2<float>& _dir){
    m_direction = _dir;
}
void Particle::setSpeed(Value<float>* _speed){
    m_speed = _speed->copy();
    m_speed->reset();
}
void Particle::setSpeed(const float& _speed){
    m_speed = new ValueSingle(_speed);
}
void Particle::setSize(Value<float>* _size){
    m_size = _size->copy();
    m_size->reset();
}
void Particle::setSize(const float& _size){
    m_size = new ValueSingle(_size);
}
void Particle::setLifeTime(const float _lifeTimeInMS){
    m_lifeTimeInMS = _lifeTimeInMS;
}