#include "raylib.h"

int main()
{
	InitWindow(800, 600, "Pong");
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