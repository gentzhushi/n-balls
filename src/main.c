#include "config.h"
#include "n-balls/n-balls.h"

// main
int main(void){

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "N Balls");

	Ball balls[N];

	for (int i = 0; i < N; i++){

		Vector2 center = {
			GetRandomValue(0, SCREEN_WIDTH),
			GetRandomValue(0, SCREEN_HEIGHT)
		};

		float radius = GetRandomValue(MIN_RADIUS, MAX_RADIUS);

		Vector2 velocityVector = {
			GetRandomValue(1, 100),
			GetRandomValue(1, 100),
		};

		normalizeV(&velocityVector);

		float velocity = GetRandomValue(1,100);
		
		balls[i] = *createBall(center, radius, velocityVector, velocity);
	}

	while(!WindowShouldClose()){

		//moveBalls();
		//regulateBallPositions();

		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < N; i++)
			drawBall(&balls[i]);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
