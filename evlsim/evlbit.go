package evlsim

import (
	"image/png"

	rl "github.com/gen2brain/raylib-go/raylib"
)

const CORE_RADIUS = 10

type EvlBit struct {
	CorePos rl.Vector2
	Health  int32
	Speed   int32
	Rsize   rl.Vector2

	eyeTexture rl.Texture2D
	originRct rl.Rectangle
	originVec rl.Vector2
}

func NewBit() *EvlBit {
	e := new(EvlBit)
	e.CorePos = rl.NewVector2(0, 0)
	e.Health = 100
	e.Speed = 5
	e.Rsize = rl.NewVector2(10, 10)
	eyeevl_png_raw, _ := evlfs.Open("assets/eyeevl.png")

	defer eyeevl_png_raw.Close()

	eyeevl_png, _ := png.Decode(eyeevl_png_raw)

	im := rl.NewImageFromImage(eyeevl_png)
	rl.ImageResize(im, int32(e.Rsize.X)/2, int32(e.Rsize.Y)/2)

	e.eyeTexture = rl.LoadTextureFromImage(im)
	rl.UnloadImage(im)
	w := e.eyeTexture.Width
	h := e.eyeTexture.Height
	e.originRct = rl.NewRectangle(0,0,float32(w),float32(h))
	e.originVec = rl.NewVector2(float32(e.eyeTexture.Width),float32(h))

	return e
}

func (e *EvlBit) GetPos() rl.Vector2 {
	return e.CorePos
}

func (e *EvlBit) GetHealth() int32 {
	return e.Health
}

func (e *EvlBit) GetSpeed() int32 {
	return e.Speed
}

func (e *EvlBit) GetRSize() rl.Vector2 {
	return e.Rsize
}

func (e *EvlBit) Draw() {
	rl.DrawCircleV(e.CorePos, CORE_RADIUS, rl.Red)
	a := rl.NewRectangle(e.CorePos.X-float32(CORE_RADIUS)/2, e.CorePos.Y-float32(CORE_RADIUS)*1.5, e.Rsize.X, e.Rsize.Y)
	rl.DrawRectangleRounded(a, 0.5, 4, rl.Green)

	b := rl.NewRectangle(e.CorePos.X-float32(CORE_RADIUS)/2, e.CorePos.Y+(float32(CORE_RADIUS)/2), e.Rsize.X, e.Rsize.Y)
	c := rl.NewRectangle(e.CorePos.X-float32(CORE_RADIUS)*1.5, e.CorePos.Y-(e.Rsize.Y/2), e.Rsize.X, e.Rsize.Y)
	d := rl.NewRectangle(e.CorePos.X+float32(CORE_RADIUS)/2, e.CorePos.Y-(e.Rsize.Y/2), e.Rsize.X, e.Rsize.Y)

	rl.DrawRectangleRounded(a, 0.5, 4, rl.Green)
	rl.DrawRectangleRounded(b, 0.5, 4, rl.Blue)
	rl.DrawRectangleRounded(c, 0.5, 4, rl.Purple)
	rl.DrawRectangleRounded(d, 0.5, 4, rl.Gray)
	rl.DrawCircleLines(int32(e.CorePos.X), int32(e.CorePos.Y), float32(CORE_RADIUS)+(e.Rsize.X/2)+5, rl.Black)

	//f := rl.NewRectangle(e.CorePos.X, e.CorePos.Y - (e.Rsize.X / 2), 32, 32)
	//rl.DrawRectangleRounded(f, 0.5,4,rl.Green)
	//g := rl.NewRectangle(e.CorePos.X - (e.Rsize.X), e.CorePos.Y - (e.Rsize.X / 2), e.Rsize.X, e.Rsize.Y)
	//rl.DrawRectangleRounded(g, 0.5,4,rl.Magenta)

	rl.DrawTexture(e.eyeTexture, int32(e.CorePos.X), int32(e.CorePos.Y) - (e.eyeTexture.Height/2),rl.White)
	rl.DrawTexture(e.eyeTexture, int32(e.CorePos.X) - e.eyeTexture.Width, int32(e.CorePos.Y) - (e.eyeTexture.Height/2),rl.White)
	//rl.DrawTexturePro(e.eyeTexture,e.originRct,f,e.originVec,0,rl.RayWhite)
	//rl.DrawTexture(e.eyeTexture, int32(e.CorePos.X)+20, int32(e.CorePos.Y), rl.RayWhite)


	// rl.DrawCircle(int32(e.CorePos.X)+20, int32(e.CorePos.Y), 15, rl.White)
	// rl.DrawCircle(int32(e.CorePos.X)-20, int32(e.CorePos.Y), 15, rl.White)
	// rl.DrawCircle(int32(e.CorePos.X)+20, int32(e.CorePos.Y), 10, rl.Black)
	// rl.DrawCircle(int32(e.CorePos.X)-20, int32(e.CorePos.Y), 10, rl.Black)
}

func (e *EvlBit) Run(bounce bool) {
	e.CorePos.X += float32(e.Speed)

	_w := float32(rl.GetScreenWidth())

	if bounce {
		if (e.CorePos.X >= (_w - (e.Rsize.X / 2))) ||
			(e.CorePos.X <= (0 - (e.Rsize.X / 2))) {
			e.Speed *= -1
		}
	}

}
