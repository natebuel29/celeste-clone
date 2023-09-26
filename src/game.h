#pragma once

#include "nb_lib.h"
#include "render_interface.h"
#include "input.h"
#include "assets.h"

// #############################################################################
//                           Game Structs
// #############################################################################
struct GameState
{
    bool initialized = false;
    IVec2 playerPos;
};
static GameState *gameState;

// #############################################################################
//                           Game Globals
// #############################################################################
constexpr int tset = 5;

// #############################################################################
//                           Game Functions (Exposed)
// #############################################################################
extern "C"
{
    EXPORT_FN void update_game(GameState *gameStateIn, RenderData *renderDataIn, Input *inputIn);
}