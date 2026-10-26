#ifndef NBALLS_H
#define NBALLS_H

#include <raylib.h>

typedef struct {
  Vector2 center;
  float radius;
  Color color;
  Vector2 velocityV;
  float velocity;
} Ball;

Ball *createBall(Vector2 center, float radius, Vector2 velocityVector,
                 float velocity);

void regulatePositionBounds(Ball *ball);

void normalizeV(Vector2 *vec);

void drawBall(Ball *ball);

double distance(Ball *ball1, Ball *ball2);

void handleCollision(Ball *ball1, Ball *ball2);
#endif
