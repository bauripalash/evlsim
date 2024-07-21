#include <stdbool.h>

#include "raylib.h"

typedef struct EvolBit {
	float coreRadius;
	Vector2 corePos;
	int health;
	int speed;
	Vector2 rsize;

	Rectangle * originRect;
	Vector2 originVec;
	Texture2D * eyeTexture;

	Vector2 targetPos;

}EvolBit;

EvolBit * newEbit();
void drawEbit(EvolBit * e);
void runEbit(EvolBit * e, bool bounce);
