package main

import (
	"evlsim/evlsim"
	"fmt"

	rl "github.com/gen2brain/raylib-go/raylib"
)

func main() {
	rl.SetConfigFlags(rl.FlagWindowResizable)

	rl.InitWindow(800, 600, "EvlSim by Palash Bauri")

	e := evlsim.NewBit()
	d := evlsim.NewBit()
	winw := rl.GetScreenWidth()
	e.CorePos = rl.NewVector2(float32(rl.GetScreenWidth())/2 , float32(rl.GetScreenHeight())/2)
	d.CorePos = rl.NewVector2(e.CorePos.X, e.CorePos.Y - evlsim.CORE_RADIUS*20)
	d.Speed = 10
	rl.SetTargetFPS(60)

	for !rl.WindowShouldClose() {
		winw = rl.GetScreenWidth()

		e.Run(true)
		d.Run(true)
		rl.BeginDrawing()
		rl.ClearBackground(rl.RayWhite)
		e.Draw()
		d.Draw()

		rl.DrawText(fmt.Sprintf("~evlsim : %0.f %0.f}", e.CorePos.X, d.CorePos.X), 5, 5, 20, rl.Black)
		rl.DrawFPS(int32(winw)/2, 0)

		rl.EndDrawing()

	}

	rl.CloseWindow()

}
