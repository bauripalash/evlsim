#include "include/evolbit.h"

#include <stdlib.h>

#include "assets/eyeevl_png.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "include/utils.h"

EvolBit* newEbit() {
    EvolBit* e = (EvolBit*)malloc(sizeof(EvolBit));
    e->coreRadius = 100.0f;
    e->health = 100;
    e->speed = 5;
    e->corePos = Vector2Zero();
    e->rsize = (Vector2){.x = (float)e->coreRadius, .y = (float)e->coreRadius};

    e->eyeImg = ImageCopy((Image){.data = EYEEVL_PNG_DATA,
                                .width = EYEEVL_PNG_WIDTH,
                                .height = EYEEVL_PNG_HEIGHT,
                                .format = EYEEVL_PNG_FORMAT,
                                .mipmaps = 1});

    ImageResize(&e->eyeImg, e->coreRadius / 2.0f, e->coreRadius / 2.0f);

    e->eyeTexture = LoadTextureFromImage(e->eyeImg);
    //UnloadImage();

    return e;
}

void setRadiusEbit(EvolBit * e , float size) {
	e->coreRadius = size;
	e->rsize.x = size;
	e->rsize.y = size;
	ImageResize(&e->eyeImg, size / 2.0f, size / 2.0f);
	UnloadTexture(e->eyeTexture);
	e->eyeTexture = LoadTextureFromImage(e->eyeImg);
}

void setRsizeEbit(EvolBit* e, float x, float y) {
    e->rsize.x = x;
    e->rsize.y = y;
}

void setPosEbit(EvolBit* e, float x, float y) {
    e->corePos.x = x;
    e->corePos.y = y;
}

void drawEbit(EvolBit* e) {
    DrawCircle(e->corePos.x, e->corePos.y,
               e->coreRadius + (e->rsize.x / 2) + 5, BLACK);

    DrawCircleV(e->corePos, e->coreRadius, RED);
    Rectangle a =
        newRect(e->corePos.x - (e->coreRadius / 2.0f),
                e->corePos.y - e->coreRadius * 1.5, e->rsize.x, e->rsize.y);

    Rectangle b =
        newRect(e->corePos.x - e->coreRadius / 2,
                e->corePos.y + e->coreRadius / 2, e->rsize.x, e->rsize.y);

    Rectangle c =
        newRect(e->corePos.x - e->coreRadius * 1.5,
                e->corePos.y - e->rsize.y / 2, e->rsize.x, e->rsize.y);

    Rectangle d =
        newRect(e->corePos.x + e->coreRadius / 2,
                e->corePos.y - e->rsize.y / 2, e->rsize.x, e->rsize.y);

    DrawRectangleRounded(a, 0.5f, 4, GREEN);
    DrawRectangleRounded(b, 0.5f, 4, BLUE);
    DrawRectangleRounded(c, 0.5f, 4, PURPLE);
    DrawRectangleRounded(d, 0.5f, 4, GRAY);

    DrawTexture(e->eyeTexture, e->corePos.x,
                e->corePos.y - (e->eyeTexture.height / 2.0f), WHITE);
    DrawTexture(e->eyeTexture, e->corePos.x - e->eyeTexture.width,
                e->corePos.y - e->eyeTexture.height / 2.0f, WHITE);
}
void runEbit(EvolBit* e, bool bounce) {
    e->corePos.x += e->speed;

    if (bounce) {
        int _w = GetScreenWidth();

        if ((e->corePos.x >= (_w - (e->rsize.x / 2))) ||
            (e->corePos.x <= (e->rsize.x / 2))) {
            e->speed *= -1.0f;
        }
    }
}
