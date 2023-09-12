#include "raylib.h"
#include<iostream>
#include<cstdlib>
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
	bool deadbird = false;

	Color dead = DARKGREEN;
	Color alive = RED;

	Color use = RED;

	void ChangeColor()
	{
		if (deadbird == false)
		{
			use = alive;
		}
		else
		{
			use = dead;
		}
	}

	void Draw()
	{
		DrawCircle(x, y, radius, use);
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

	//used to generate top and bottom of pillers
	Rectangle getRec1()
	{
		return Rectangle{ x, y - ranMain, width, height};
	}
	Rectangle getRec2()
	{
		return Rectangle{ x, y - ranMine, width, height };
	}

	void Draw()
	{
		DrawRectangleRec(getRec1(), GREEN);
		DrawRectangleRec(getRec2(), GREEN);
	}
};

int main()
{
	//starting window
	InitWindow(800, 600, "Not Flappy Bird");
	SetWindowState(FLAG_VSYNC_HINT);

	//generation of bird
	Bird bird;
	bird.x = GetScreenWidth() / 4;
	bird.y = GetScreenHeight() / 2;
	bird.radius = 25;
	bird.speedUp = 2100;
	bird.speedDown = 200;
	bird.speedFall= 250;

	//generation of pillers
	Piller piller1;
	piller1.x = (GetScreenWidth() / 4) + 200;
	piller1.y = 0;
	piller1.height = 600;
	piller1.width = 100;
	piller1.speed = 5;
	piller1.ranMain = GetRandomValue(600, 200);
	piller1.ranMine = piller1.ranMain - piller1.height - 200;

	Piller piller2;
	piller2.x = (piller1.x + 500);
	piller2.y = 0;
	piller2.height = 600;
	piller2.width = 100;
	piller2.ranMain = GetRandomValue(600, 200);
	piller2.ranMine = piller2.ranMain - piller2.height - 200;

	bool start = false;
	int score = 0;

		while (!WindowShouldClose())
		{

			if (IsKeyPressed(KEY_ENTER) && start == false)
			{
				start = true;
				score = 0;

				//movement of bird
				bird.x = GetScreenWidth() / 4;
				bird.y = GetScreenHeight() / 2;
				bird.radius = 25;
				bird.speedUp = 2100;
				bird.speedDown = 200;
				bird.speedFall = 250;

				//movement of pillers
				piller1.x = (GetScreenWidth() / 4) + 200;
				piller1.y = 0;
				piller1.height = 600;
				piller1.width = 100;
				piller1.speed = 5;
				piller1.ranMain = GetRandomValue(600, 200);
				piller1.ranMine = piller1.ranMain - piller1.height - 200;

				piller2.x = (piller1.x + 500);
				piller2.y = 0;
				piller2.height = 600;
				piller2.width = 100;
				piller2.ranMain = GetRandomValue(600, 200);
				piller2.ranMine = piller2.ranMain - piller2.height - 200;

				bird.deadbird = false;
				bird.ChangeColor();
			}
			if (start == true)
			{
				//generation of birds
				piller1.x -= piller1.speed;
				piller2.x -= piller1.speed;
				if (piller1.x < -90)
				{
					piller1.x = (piller2.x + 500);
					piller1.speed += 5 * GetFrameTime();
					piller1.ranMain = GetRandomValue(600, 200);
					piller1.ranMine = piller1.ranMain - piller1.height - 200;
					score++;
				}
				if (piller2.x < -90)
				{
					piller2.x = (piller1.x + 500);
					piller2.ranMain = GetRandomValue(600, 200);
					piller2.ranMine = piller2.ranMain - piller2.height - 200;
					score++;
				}

				//control of bird
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


				//Checking for bird collision with each part of pillars
				if (CheckCollisionCircleRec(Vector2{ bird.x, bird.y }, bird.radius, piller1.getRec1()))
				{
					bird.speedFall = 0;
					bird.speedDown = 0;
					bird.speedUp = 0;
					piller1.speed = 0;
					piller2.speed = 0;
					bird.deadbird = true;
					bird.ChangeColor();
				}
				if (CheckCollisionCircleRec(Vector2{ bird.x, bird.y }, bird.radius, piller1.getRec2()))
				{
					bird.speedFall = 0;
					bird.speedDown = 0;
					bird.speedUp = 0;
					piller1.speed = 0;
					piller2.speed = 0;
					bird.deadbird = true;
					bird.ChangeColor();
				}
				if (CheckCollisionCircleRec(Vector2{ bird.x, bird.y }, bird.radius, piller2.getRec1()))
				{
					bird.speedFall = 0;
					bird.speedDown = 0;
					bird.speedUp = 0;
					piller1.speed = 0;
					piller2.speed = 0;
					bird.deadbird = true;
					bird.ChangeColor();
				}
				if (CheckCollisionCircleRec(Vector2{ bird.x, bird.y }, bird.radius, piller2.getRec2()))
				{
					bird.speedFall = 0;
					bird.speedDown = 0;
					bird.speedUp = 0;
					piller1.speed = 0;
					piller2.speed = 0;
					bird.deadbird = true;
					bird.ChangeColor();
				}
				BeginDrawing();

				ClearBackground(BLACK);

				//draws Pillers
				piller1.Draw();
				piller2.Draw();

				//draws bird
				bird.Draw();

				DrawFPS(10, 10);
				EndDrawing();

			}
			else
			{

				//start screen
				ClearBackground(BLACK);
				DrawText("Press Enter to start!", (GetScreenWidth() / 4), (GetScreenWidth() / 4), 25, WHITE);
				DrawText(TextFormat("Score: %i", score), (GetScreenWidth()  / 4), (GetScreenWidth() - 400), 40, WHITE);
				EndDrawing();
			}

			if (IsKeyPressed(KEY_R))
			{
				start = false;
			}
		}
	
	CloseWindow();
}