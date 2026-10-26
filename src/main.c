#include "config.h"
#include "n-balls.h"

// main
int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "N Balls");

  Ball balls[N];

  // create balls
  for (int i = 0; i < N; i++) {

    float radius = GetRandomValue(MIN_RADIUS, MAX_RADIUS);

    Vector2 center = {GetRandomValue(radius, SCREEN_WIDTH - radius),
                      GetRandomValue(radius, SCREEN_HEIGHT - radius)};

    Vector2 velocityVector = {
        GetRandomValue(-100, 100),
        GetRandomValue(-100, 100),
    };

    // normalizeV(&velocityVector);

    float velocity = GetRandomValue(MIN_VELOCITY, MAX_VELOCITY);

    balls[i] = *createBall(center, radius, velocityVector, velocity);
  }

  while (!WindowShouldClose()) {

    for (int i = 0; i < N; i++) {
      float dt = GetFrameTime();
      Vector2 vv = balls[i].velocityV;
      float velocity = balls[i].velocity;
      balls[i].center.x += dt * velocity * vv.x;
      balls[i].center.y += dt * velocity * vv.y;
      regulatePositionBounds(&balls[i]);
    }

    for (int i = 0; i < N - 1; i++)
      for (int j = i + 1; j < N; j++)
        if (balls[i].radius + balls[j].radius >= distance(&balls[i], &balls[j]))
          handleCollision(&balls[i], &balls[j]);

    BeginDrawing();
    ClearBackground(BLACK);

    for (int i = 0; i < N; i++)
      drawBall(&balls[i]);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
