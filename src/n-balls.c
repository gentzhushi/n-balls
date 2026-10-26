#include <math.h>
#include <stdlib.h>

#include "n-balls/config.h"
#include "n-balls/n-balls.h"
#include "n-balls/util.h"

Ball *createBall(Vector2 center, float radius, Vector2 velocityVector,
                 float velocity) {
  Ball *ball = malloc(sizeof(Ball));

  *ball = (Ball){.center = center,
                 .radius = radius,
                 .color = getRandomColor(),
                 .velocityV = velocityVector,
                 .velocity = velocity};

  return ball;
}
#include <math.h>
#include <stdio.h>
void regulatePositionBounds(Ball *ball) {

  // regulate x
  if (ball->center.x > SCREEN_WIDTH - ball->radius) {
    ball->center.x = SCREEN_WIDTH - ball->radius;
    ball->velocityV.x *= -1; //* fabs(ball->velocityV.x);
  } else if (ball->center.x < ball->radius) {
    ball->center.x = ball->radius;
    ball->velocityV.x *= -1; // fabs(ball->velocityV.x);
  }

  // regulate y
  if (ball->center.y > SCREEN_HEIGHT - ball->radius) {
    ball->center.y = SCREEN_HEIGHT - ball->radius;
    ball->velocityV.y *= -1;
  } else if (ball->center.y < ball->radius) {
    ball->center.y = ball->radius;
    ball->velocityV.y *= -1;
  }
}

void handleCollision(Ball *left, Ball *right) {
  Vector2 temp = left->velocityV;
  left->velocityV = right->velocityV;
  right->velocityV = temp;
}

double distance(Ball *left, Ball *right) {
  float x_sq =
      (left->center.x - right->center.x) * (left->center.x - right->center.x);
  float y_sq =
      (left->center.y - right->center.y) * (left->center.y - right->center.y);
  return sqrt(x_sq + y_sq);
}

void normalizeV(Vector2 *vec) {
  float magnitude = sqrt(vec->x * vec->x + vec->y * vec->y);

  *vec = (Vector2){vec->x / magnitude * VECTOR_SCALER,
                   vec->y / magnitude * VECTOR_SCALER};
}

void drawBall(Ball *ball) {
  DrawCircleV(ball->center, ball->radius, ball->color);

  // Vector2 velocityV = {ball->velocityV.x + ball->center.x,
  //                      ball->velocityV.y + ball->center.y};

  // DrawLineV(ball->center, velocityV, WHITE);
}
