#include "TestState.h"
#include "Log.h"

TestState::TestState(){
    player = new Player({200,100});
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
    return state;
}

GameState* TestState::update(const float _dt){
    GameState* state = this;

    return state;
}

void TestState::render()const{
    player->draw();
}