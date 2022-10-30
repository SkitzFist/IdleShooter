#include "TestState.h"
#include "Log.h"

TestState::TestState(){
    Log::info("TestState Created");
}

TestState::~TestState(){
    Log::info("TestState destroyed");
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

}