#pragma once

#include "nb_lib.h"
#include "render_interface.h"
#include "input.h"
#include "assets.h"

// #############################################################################
//                           Game Globals
// #############################################################################
constexpr int tset = 5;

// #############################################################################
//                           Game Structs
// #############################################################################
struct GameState
{
    IVec2 playerPos;
};

// #############################################################################
//                           Game Functions (Exposed)
// #############################################################################
extern "C"
{
    EXPORT_FN void update_game(RenderData *renderDataIn, Input *inputIn);
}