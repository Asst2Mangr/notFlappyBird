#include "raylib.h"

int main()
{
	InitWindow(800, 600, "Not Flappy Bird");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(DARKGREEN);

			DrawRectangle(700, 0, 100, 600, BLACK);
			DrawRectangle(550, 0, 100, 600, BLUE);
			DrawRectangle(400, 0, 100, 600, BLACK);
			DrawRectangle(250, 0, 100, 600, BLUE);
			DrawCircle(GetScreenWidth() / 4, GetScreenHeight() / 2, 25, BLACK);

			DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
}