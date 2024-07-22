#include <stdbool.h>

#include "raylib.h"

typedef struct EvolBit {
    float coreRadius;
    Vector2 corePos;
    int health;
    int speed;
    Vector2 rsize;

    Rectangle originRect;
    Vector2 originVec;
    Image eyeImg;
    Texture2D eyeTexture;

    Vector2 targetPos;

} EvolBit;

EvolBit* newEbit();
void freeEbit(EvolBit* e);
void drawEbit(EvolBit* e);
void runEbit(EvolBit* e, bool bounce);

void setRsizeEbit(EvolBit* e, float x, float y);
void setPosEbit(EvolBit* e, float x, float y);
void setRadiusEbit(EvolBit* e, float size);
