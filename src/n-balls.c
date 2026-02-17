#include <stdlib.h>
#include <math.h>

#include "config.h"
#include "n-balls.h"
#include "util.h"

Ball* createBall(Vector2 center, float radius, Vector2 velocityVector, float velocity){
	Ball *ball = malloc(sizeof(Ball));
	
	*ball = (Ball) {
		.center = center,
		.radius = radius,
		.color = getRandomColor(),
		.velocityV= velocityVector,
		.velocity = velocity
	};

	return ball;
}

void regulatePositionBounds(Ball *ball){
	// regulate x
	if (ball->center.x > SCREEN_WIDTH - ball->radius) 
		ball->center.x = SCREEN_WIDTH - ball->radius;
	else if (ball->center.x < ball->radius) 
		ball->center.x = ball->radius;

	// regulate y
	if (ball->center.y > SCREEN_HEIGHT - ball->radius) 
		ball->center.y = SCREEN_HEIGHT - ball->radius;
	else if (ball->center.y < ball->radius) 
		ball->center.y = ball->radius;
}

void normalizeV(Vector2 *vec){
	float magnitude = sqrt(vec->x * vec->x + vec->y * vec->y);
	vec->x = vec->x/magnitude;
	vec->y = vec->y/magnitude;
}

void drawBall(Ball *ball){
	DrawCircleV(ball->center, ball->radius, ball->color);
	DrawLineV(ball->center, ball->velocityV, WHITE);
}
