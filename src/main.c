#include "raylib.h"

int main(void) {
	const int swidth = 800;
	const int sheight = 600;

	InitWindow(swidth, sheight, "EvlSim by Palash Bauri");

	const Vector2 centerPos = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
	Vector2 matPos = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
	Vector2 matSize = {50.0f,50.0f};
	Vector2 matSpeed = {5, 0};
	

	SetTargetFPS(60);
	const char * a = TextFormat("!evlsim");

	while (!WindowShouldClose()) {

		matPos.x += matSpeed.x;
		matPos.y += matSpeed.y;

		if ((matPos.x >= (GetScreenWidth() - (matSize.x/2.0f))) ||
				(matPos.x <= (matSize.x/2.0f))) {
			matSpeed.x *= -1.0f;
			
		}

		a = TextFormat("~evlsim : {%f,%f}", matPos.x , matPos.y);


		
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangleV(matPos, matSize, RED);
			DrawText(a, 5, 5, 20 , BLACK);

		EndDrawing();
	}

	CloseWindow();
	
	return 0;
}
