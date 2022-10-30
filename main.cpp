#include "include/emscripten.h"

//Settings
#include "Settings.h"

//States
#include "TestState.h"

//Globals
GameState* state = nullptr;

void init();
void destroy();
void run();
void handleInput();
void update();
void render();

//Debug
#include <string>

int main(void){
    init();
    emscripten_set_main_loop(run, 0,1);
}

void init(){
    InitWindow(Settings::WORLD_SIZE.x, Settings::WORLD_SIZE.y, "Idle Shooter");
    state = new TestState();
}

void destroy(){
    emscripten_cancel_main_loop();
    std::string str = "Main loop cancelled";
    TraceLog(LOG_INFO, str.c_str());
}

void run(){
    if(!state){
        destroy();
    }
    handleInput();
    update();
    render();
}

void handleInput(){
    if(state){
        state = state->handleInput();
    }
}

void update(){
    if(state){
        state = state->update(GetFrameTime());
    }
}

void render(){
    BeginDrawing();
        ClearBackground(BLACK);
        if(state){
            state->render();
        }
    EndDrawing();
}