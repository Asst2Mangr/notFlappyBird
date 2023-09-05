#include "raylib.h"
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

	void Draw()
	{
		DrawRectangle(x, y, width, height, GREEN);
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
	bird.speedUp = 1200;
	bird.speedDown = 300;
	bird.speedFall= 100;

	Piller piller1;
	piller1.x = (GetScreenWidth() / 4) + 200;
	piller1.y = 0;
	piller1.height = 600;
	piller1.width = 100;
	piller1.speed = 5;

	Piller piller2;
	piller2.x = ((GetScreenWidth() / 4) * 2) + 200;
	piller2.y = 0;
	piller2.height = 600;
	piller2.width = 100;

	Piller piller3;
	piller3.x = ((GetScreenWidth() / 4) * 3) + 200;
	piller3.y = 0;
	piller3.height = 600;
	piller3.width = 100;

	Piller piller4;
	piller4.x = ((GetScreenWidth() / 4) * 4) + 200;
	piller4.y = 0;
	piller4.height = 600;
	piller4.width = 100;

	while (!WindowShouldClose())
	{
		
		DrawText("Press Spacebar to start!", (GetScreenWidth() / 4), (GetScreenWidth() / 4), 25, WHITE);
		BeginDrawing();

			ClearBackground(BLACK);

			piller1.x -= piller1.speed;
			piller2.x -= piller1.speed;
			piller3.x -= piller1.speed;
			piller4.x -= piller1.speed;

			if (piller1.x < -90)
			{
				piller1.x = 790;
				piller1.speed += 1 * GetFrameTime();
			}
			if (piller2.x < -90)
			{
				piller2.x = 790;
			}
			if (piller3.x < -90)
			{
				piller3.x = 790;
			}
			if (piller4.x < -90)
			{
				piller4.x = 790;
			}
			if (piller1.speed == 0)
			{
				piller1.speed = 50;
			}

			piller1.Draw();
			piller2.Draw();
			piller3.Draw();
			piller4.Draw();

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

		EndDrawing();
	}
	
	CloseWindow();
}