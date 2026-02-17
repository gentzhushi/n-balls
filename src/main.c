#include "config.h"
#include "n-balls.h"

// main
int main(void){

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "N Balls");

	Ball balls[N];

	// create balls
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

		// update all balls with deltaframe * velocity with respect
		// to it's velocity vector.

		// compare every ball to all other balls with 2 for-loops
		// for all balls which have a difference lte the sum of their
		// radiuses, swap velocities, with an impact reduction.
		
		// update all positions respectfully

		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < N; i++)
			drawBall(&balls[i]);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
