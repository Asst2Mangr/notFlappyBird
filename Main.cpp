#include "raylib.h"

int main()
{
	InitWindow(800, 600, "Not Flappy Bird");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGREEN);
			DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
}