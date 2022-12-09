#include "TestState.h"
#include "SquareBodyPart.h"
#include "Settings.h"
#include "PlayerSettings.h"
#include "MoveSideways.h"
#include "Random.h"
//debug
#include "Log.h"

TestState::TestState(){
    float yPadding = static_cast<float>(Settings::WORLD_SIZE.y) * 0.05f;
    Vec2<float> playerStartPos = {
        static_cast<float>(Settings::WORLD_SIZE.x) / 2.f - PlayerSettings::RADIUS,
        static_cast<float>(Settings::WORLD_SIZE.y) - (PlayerSettings::RADIUS + yPadding)
    };
    player = new Player(playerStartPos);
}

TestState::~TestState(){
    delete player;
    m_particles.clear();
}

GameState* TestState::handleInput(){
    GameState* state = this;
    if(IsKeyReleased(KEY_ESCAPE)){
        Log::info("Esc is released");
        delete this;
        return nullptr;
    }

    if(IsKeyPressed(KEY_SPACE)){
        player->equip(new SquareBodyPart());
    }
    if(IsKeyPressed(KEY_A)){
        player->setMovementBehaviour(new MoveSideways());
    }
    if(IsKeyPressed(KEY_S)){
        int nrOfParticles = 500;
        Vec2<float> center = {Settings::WORLD_SIZE.x  / 2.f, Settings::WORLD_SIZE.y / 2.f};
        for(int i = 0; i < nrOfParticles; ++i){
            float size = Random::FLOAT(1.f, 5.f);
            Vec2<float> direction = {Random::FLOAT(-1.f,1.f), Random::FLOAT(-1.f, 1.f)};
            float speed = Random::FLOAT(70.f, 150.f);
            m_particles.add(Particle(center, speed, direction, size));
        }
    }
    return state;
}

GameState* TestState::update(const float _dt){
    GameState* state = this;
    player->update(_dt);
    for(int i = 0; i < m_particles.size(); ++i){
        m_particles[i].update(_dt);
    }
    return state;
}

void TestState::render()const{
    player->draw();
    for(int i = 0; i < m_particles.size(); ++i){
        m_particles[i].render();
    }
}