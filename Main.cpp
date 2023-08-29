#include "raylib.h"

int main()
{
	InitWindow(800, 600, "notFlappyBirds");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLUE);

			DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
}