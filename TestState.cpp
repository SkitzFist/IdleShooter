#include "TestState.h"
#include "SquareBodyPart.h"
#include "Settings.h"
#include "PlayerSettings.h"
#include "MoveSideways.h"
#include "Random.h"
//debug
#include "Log.h"
#include "ValueOverTime.h"
#include "ValueRandom.h"
#include "ValueSingle.h"

Vec2<float> emitPos(Settings::WORLD_SIZE.x / 2.f, Settings::WORLD_SIZE.y / 2.f);

TestState::TestState(){
    float yPadding = static_cast<float>(Settings::WORLD_SIZE.y) * 0.05f;
    Vec2<float> playerStartPos = {
        static_cast<float>(Settings::WORLD_SIZE.x) / 2.f,
        static_cast<float>(Settings::WORLD_SIZE.y) / 2.f 
    };
    m_player = new Player(playerStartPos);

    /* ####--ParticleEmitter test--####
    ValueOverTime<int>* numberOfParticles = new ValueOverTime<int>(500, 10, duration, Lerp::linear);
    ValueOverTime<float>* speed = new ValueOverTime<float>(25.f, 5.f, duration, Lerp::smoothStep);
    float min = PI + (PI / 4.f);
    float max = min + (PI / 2.f);
    ValueRandom<float>* angle = new ValueRandom<float>(-min,  -max );
    ValueRandom<float>* particleLifeTimeInMS = new ValueRandom<float>(500.f, 2500.f);
    ValueRandom<float>* particleSize = new ValueRandom<float>(PI + (PI / 4.f), PI * 2.f);
    ValueSingle<int>* valueTest = new ValueSingle(5);
    Log::info("Value: " + std::to_string(valueTest->getValue()));
    //m_emitter = new ParticleEmitter(
        numberOfParticles,
        speed,
        angle,
        0.5f,
        particleLifeTimeInMS,
        particleSize
    );
    */
}

TestState::~TestState(){
    delete m_player;
}

GameState* TestState::handleInput(){
    GameState* state = this;
    if(IsKeyReleased(KEY_ESCAPE)){
        Log::info("Esc is released");
        delete this;
        return nullptr;
    }

    if(IsKeyPressed(KEY_SPACE)){
        m_player->equip(new SquareBodyPart());
    }
    if(IsKeyPressed(KEY_A)){
        m_player->setMovementBehaviour(new MoveSideways());
    }
    if(IsKeyPressed(KEY_S)){
    }
    return state;
}

GameState* TestState::update(const float _dt){
    GameState* state = this;
    m_player->update(_dt);
    return state;
}

void TestState::render()const{
    m_player->render();
}