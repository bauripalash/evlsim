#include "include/raylib.h"
#include "include/raymath.h"
#include "include/evolbit.h"
#include "include/utils.h"
#include <stdlib.h>

EvolBit * newEbit(){
	EvolBit * e = (EvolBit*)malloc(sizeof(EvolBit));
	e->coreRadius = 50.0f;
	e->health = 100;
	e->speed = 5;
	e->corePos = Vector2Zero();
	e->rsize = (Vector2){.x = e->coreRadius, .y = e->coreRadius };
	return e;
}
void drawEbit(EvolBit * e){
	DrawCircle(e->corePos.x, e->corePos.y, e->coreRadius + (e->rsize.x/2)+5, BLACK);

	DrawCircleV(e->corePos, e->coreRadius, RED);
	Rectangle a = newRect(e->corePos.x - (e->coreRadius/2.0f), e->corePos.y-e->coreRadius*1.5, e->rsize.x, e->rsize.y);

	Rectangle b = newRect(e->corePos.x - e->coreRadius/2, e->corePos.y+e->coreRadius/2, e->rsize.x, e->rsize.y);

	Rectangle c = newRect(e->corePos.x-e->coreRadius*1.5, e->corePos.y - e->rsize.y/2, e->rsize.x, e->rsize.y);

	Rectangle d = newRect(e->corePos.x + e->coreRadius / 2 , e->corePos.y - e->rsize.y/2, e->rsize.x , e->rsize.y);

	DrawRectangleRounded(a, 0.5f, 4, GREEN);
	DrawRectangleRounded(b, 0.5f, 4, BLUE);
	DrawRectangleRounded(c, 0.5f, 4, PURPLE);
	DrawRectangleRounded(d, 0.5f, 4, GRAY);
}
void runEbit(EvolBit * e, bool bounce){
	e->corePos.x += e->speed;

	if (bounce) {
		int _w = GetScreenWidth();

		if ((e->corePos.x >= (_w - (e->rsize.x/2))) ||
		(e->corePos.x <= (e->rsize.x/2))) {
			e->speed *= -1.0f;
		}
	}
}
