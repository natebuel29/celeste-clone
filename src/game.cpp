#include "game.h"

// #############################################################################
//                           Game Globals
// #############################################################################

constexpr int WORLD_WIDTH = 320;
constexpr int WORLD_HEIGHT = 180;
constexpr int TILESIZE = 8;

EXPORT_FN void update_game(GameState *gameStateIn, RenderData *renderDataIn, Input *inputIn)
{
    if (renderData != renderDataIn)
    {
        renderData = renderDataIn;
        gameState = gameStateIn;
        input = inputIn;
    }

    if (!gameState->initialized)
    {
        renderData->gameCamera.dimensions = {WORLD_WIDTH, WORLD_HEIGHT};
        gameState->initialized = true;
    }

    renderData->gameCamera.position.x = 160;
    renderData->gameCamera.position.y = 90;

    draw_sprite(SPRITE_DICE, {0.0f, 0.0f});
}