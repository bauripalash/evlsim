#include <stdbool.h>

#include "include/evolbit.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "include/utils.h"

#define EPS 0.1f

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTraceLogLevel(LOG_WARNING);

    TraceLog(LOG_WARNING, "[+]  SETTARGET <<");
    InitWindow(800, 600, "~evlsim by palash bauri");
    EvolBit* e = newEbit();
    // EvolBit* b = newEbit();
    // e->speed = 10;
    //  e->coreRadius = 10.0f;
    //  b->coreRadius = 5.f;

    TraceLog(LOG_WARNING, "health -> %d", e->health);

    // setRadiusEbit(e, 10.f);
    // setRadiusEbit(b, 20.f);
    setPosEbit(e, GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
    // e->coreRadius = 10.f;

    // setPosEbit(b, GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f + 100);

    // if (!e) {
    //	TraceLog(LOG_ERROR, "Failed to alc");
    // }

    SetTargetFPS(60);
    Vector2 start = (Vector2){.x = e->corePos.x, .y = e->corePos.y};

    Vector2 target = getRandomPos(GetScreenWidth(), GetScreenHeight());
    Vector2 speed = Vector2Zero();
    Vector2 dir = Vector2Zero();
    Vector2 dist = Vector2Zero();
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_SPACE)) {
            start.x = e->corePos.x;
            start.y = e->corePos.y;
            target = getRandomPos(GetScreenWidth(), GetScreenHeight());
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            start.x = e->corePos.x;
            start.y = e->corePos.y;
            target = GetMousePosition();
        }

        dir = Vector2Subtract(target, e->corePos);
        dir = Vector2Normalize(dir);

        float xpos = e->corePos.x + dir.x * e->speed;
        float ypos = e->corePos.y + dir.y * e->speed;

        setPosEbit(e, xpos, ypos);

        if ((dir.x > 0 && e->corePos.x >= target.x) ||
            (dir.x < 0 && e->corePos.x <= target.x) ||
            (dir.y > 0 && e->corePos.y >= target.y) ||
            (dir.y < 0 && e->corePos.y <= target.y)) {
            setPosEbit(e, target.x, target.y);
        }

        int winw = GetScreenWidth();
        dist = Vector2Subtract(e->corePos, target);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLineEx(start, e->corePos, 5, RED);
        DrawLineEx(e->corePos, target, 5, GREEN);

        drawEbit(e);
        // drawEbit(b);

        DrawText(
            TextFormat("~evlsim: (%0.f:%0.f) -> (%0.f : %0.f) : [%0.f : %0.f]",
                       e->corePos.x, e->corePos.y, target.x, target.y, dist.x,
                       dist.y),
            5, 5, 20, BLACK);
        DrawFPS(winw / 2, 0);

        EndDrawing();
    }

    freeEbit(e);
    // freeEbit(b);

    CloseWindow();
    return 0;
}
