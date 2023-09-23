#pragma once

#include "nb_lib.h"
#include "assets.h"

// #############################################################################
//                           Renderer Constants
// #############################################################################
constexpr int MAX_TRANSFORMS = 1000;

// #############################################################################
//                           Renderer Structs
// #############################################################################

struct Transform
{
    IVec2 atlasOffset;
    IVec2 spriteSize;
    Vec2 pos;
    Vec2 size;
};

struct RenderData
{
    int transformCount;
    Transform transforms[MAX_TRANSFORMS];
};

// #############################################################################
//                           Renderer Globals
// #############################################################################
static RenderData renderData;

// #############################################################################
//                           Renderer Functions
// #############################################################################
void draw_sprite(SpriteID spriteID, Vec2 pos, Vec2 size)
{
    Sprite sprite = get_sprite(spriteID);

    Transform transform = {};
    transform.atlasOffset = sprite.atlasOffset;
    transform.spriteSize = sprite.spriteSize;
    transform.pos = pos;
    transform.size = size;

    renderData.transforms[renderData.transformCount++] = transform;
}