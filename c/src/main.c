#include <stdbool.h>

#include "include/evolbit.h"
#include "include/raylib.h"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTraceLogLevel(LOG_WARNING);

    TraceLog(LOG_WARNING, "[+]  SETTARGET <<");
    InitWindow(800, 600, "~evlsim by palash bauri");
    EvolBit* e = newEbit();
    EvolBit * b = newEbit();
	e->speed = 10;
    // e->coreRadius = 10.0f;
    // b->coreRadius = 5.f;

    TraceLog(LOG_WARNING, "health -> %d", e->health);

	setRadiusEbit(e , 10.f);
	setRadiusEbit(b, 20.f);
    setPosEbit(e, GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
    //e->coreRadius = 10.f;

    setPosEbit(b, GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f + 100);

    // if (!e) {
    //	TraceLog(LOG_ERROR, "Failed to alc");
    // }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        runEbit(e, true);
        runEbit(b, true);
        int winw = GetScreenWidth();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawEbit(e);
        drawEbit(b);
        DrawText(TextFormat("~evlsim: %0.f %0.f", e->corePos.x, b->corePos.x), 5,
                 5, 20, BLACK);
        DrawFPS(winw / 2, 0);

        EndDrawing();
    }

    return 0;
}
