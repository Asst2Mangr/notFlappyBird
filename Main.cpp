#include "raylib.h"
#include<iostream>
#include<cstdlib>
using namespace std;
//Reaenn, Zoey, Jordan
// 9/1/2023
// This is our not flappy bird game!

//bird class
struct Bird
{
	float x, y;
	float radius;
	float speedUp;
	float speedDown;
	float speedFall;

	void Draw()
	{
		DrawCircle(x, y, radius, RED);
	}
};

//pillar class
struct Piller
{
	float x, y;
	float height, width;
	float speed;

	float ranMain;
	float ranMine;

	void Draw()
	{
		DrawRectangle(x, y - ranMain, width, height, GREEN);
		DrawRectangle(x, y - ranMine, width, height, GREEN);
	}
};

int main()
{
	InitWindow(800, 600, "Not Flappy Bird");
	SetWindowState(FLAG_VSYNC_HINT);

	Bird bird;
	bird.x = GetScreenWidth() / 4;
	bird.y = GetScreenHeight() / 2;
	bird.radius = 25;
	bird.speedUp = 2100;
	bird.speedDown = 200;
	bird.speedFall= 250;

	Piller piller1;
	piller1.x = (GetScreenWidth() / 4) + 200;
	piller1.y = 0;
	piller1.height = 600;
	piller1.width = 100;
	piller1.speed = 5;
	piller1.ranMain = GetRandomValue(600, 200);
	piller1.ranMine = piller1.ranMain - piller1.height - 150;

	Piller piller2;
	piller2.x = (piller1.x + 500);
	piller2.y = 0;
	piller2.height = 600;
	piller2.width = 100;
	piller2.ranMain = GetRandomValue(600, 200);
	piller2.ranMine = piller2.ranMain - piller2.height - 150;

	bool start = false;

		while (!WindowShouldClose())
		{

			BeginDrawing();

			ClearBackground(BLACK);

			if (IsKeyPressed(KEY_ENTER))
			{
				start = true;
			}
			if (start == true)
			{

				piller1.x -= piller1.speed;
				piller2.x -= piller1.speed;
				if (piller1.x < -90)
				{
					piller1.x = (piller2.x + 500);
					piller1.speed += 5 * GetFrameTime();
					piller1.ranMain = GetRandomValue(600, 200);
					piller1.ranMine = piller1.ranMain - piller1.height - 150;
				}
				if (piller2.x < -90)
				{
					piller2.x = (piller1.x + 500);
					piller2.ranMain = GetRandomValue(600, 200);
					piller2.ranMine = piller2.ranMain - piller2.height - 150;
				}
				if (piller1.speed == 0)
				{
					piller1.speed = 50;
				}

				piller1.Draw();
				piller2.Draw();

				//draws bird
				bird.Draw();

				if (IsKeyPressed(KEY_SPACE))
				{
					bird.y -= bird.speedUp * GetFrameTime();
				}
				else if (IsKeyReleased(KEY_SPACE))
				{
					bird.y += bird.speedDown * GetFrameTime();
				}
				else if (IsKeyUp(KEY_SPACE))
				{
					bird.y += bird.speedFall * GetFrameTime();
				}
				else if (IsKeyDown(KEY_SPACE))
				{
					bird.y += bird.speedFall * GetFrameTime();
				}

				//start of resetting the game
				if (bird.y > 0 && IsKeyPressed(KEY_ENTER))
				{
					bird.x = GetScreenWidth() / 4;
					bird.y = GetScreenHeight() / 2;
				}

				DrawFPS(10, 10);

			}
			else
			{
				DrawText("Press Enter to start!", (GetScreenWidth() / 4), (GetScreenWidth() / 4), 25, WHITE);
			}

			EndDrawing();
		}
	
	CloseWindow();
}