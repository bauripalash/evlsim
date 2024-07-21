#include "include/evolbit.h"
#include "include/raylib.h"


int main(void) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTraceLogLevel(LOG_WARNING);

	TraceLog(LOG_WARNING, "[+]  SETTARGET <<");
	InitWindow(800, 600, "~evlsim by palash bauri");
	EvolBit * e = newEbit();
	TraceLog(LOG_WARNING, "health -> %d", e->health);
	e->corePos = (Vector2){ .x = GetScreenWidth()/2.0f , .y = GetScreenHeight()/2.0f };

	//if (!e) {
	//	TraceLog(LOG_ERROR, "Failed to alc");
	//}

	
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		runEbit(e, true);
		int winw = GetScreenWidth();

		BeginDrawing();
			ClearBackground(RAYWHITE);
			drawEbit(e);
		DrawText(TextFormat("~evlsim: %f %f" , e->corePos.x, e->corePos.y),5, 5, 20, BLACK);
		DrawFPS(winw/2,0 );
			
		EndDrawing();
	}

	return 0;
}
