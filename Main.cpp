#include "raylib.h"

struct Bird
{

};

struct Piller
{
	float x, y;
	float height, width;
	float speed;

	void Draw()
	{
		DrawRectangle(x, y, width, height, RED);
	}
};

int main()
{
	InitWindow(800, 600, "Not Flappy Bird");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(DARKGREEN);

			Piller piller1;
			piller1.x = 700;
			piller1.y = 0;
			piller1.height = 600;
			piller1.width = 100;

			Piller piller2;
			piller1.x = 550;
			piller1.y = 0;
			piller1.height = 600;
			piller1.width = 100;

			Piller piller3;
			piller1.x = 400;
			piller1.y = 0;
			piller1.height = 600;
			piller1.width = 100;

			Piller piller4;
			piller1.x = 250;
			piller1.y = 0;
			piller1.height = 600;
			piller1.width = 100;

			piller1.Draw();
			piller2.Draw();
			piller3.Draw();
			piller4.Draw();


			DrawCircle(GetScreenWidth() / 4, GetScreenHeight() / 2, 25, BLACK);

			DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
}