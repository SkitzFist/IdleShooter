#include "include/emscripten.h"

#include "Settings.h"
#include "Log.h"

//States
#include "TestState.h"
GameState* state = nullptr;


//Functions
void init();
void destroy();
void run();
void handleInput();
void update();
void render();


int main(void){
    init();
    emscripten_set_main_loop(run, 0, 1);
    return 0; //this code won't execute due to emscripten.
}

void init(){
    InitWindow(Settings::WORLD_SIZE.x, Settings::WORLD_SIZE.y, "Idle Shooter");
    state = new TestState();
}

void destroy(){
    emscripten_cancel_main_loop();
    Log::info("Main loop canceled");
    CloseWindow();
    Log::info("Window closed");
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
        DrawFPS(10,10);
    EndDrawing();
}