#include "TestState.h"
#include "SquareBodyPart.h"
#include "Settings.h"
#include "PlayerSettings.h"
#include "MoveSideways.h"

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
    return state;
}

GameState* TestState::update(const float _dt){
    GameState* state = this;
    player->update(_dt);
    return state;
}

void TestState::render()const{
    player->draw();
}