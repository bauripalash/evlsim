#include "include/utils.h"

#include "include/raylib.h"

Rectangle newRect(float x, float y, float width, float height) {
    return (Rectangle){.x = x, .y = y, .width = width, .height = height};
}
Rectangle newRectV(Vector2 pos, Vector2 size) {
    return (Rectangle){
        .x = pos.x, .y = pos.y, .width = size.x, .height = size.y};
}

Vector2 getRandomPos(int xRange, int yRange) {
    return (Vector2){.x = GetRandomValue(0, xRange),
                     .y = GetRandomValue(0, yRange)};
}
