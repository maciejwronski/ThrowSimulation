#include "ukosny.h"
#include <iostream>

rzutUkosny::rzutUkosny(float velX, float velY, float totalT, float gravAcceleration, float stepp) {
	velocity[0] = velX;
	velocity[1] = velY;
	totalTime = totalT;
	acceleration = gravAcceleration;
	step = stepp;
}

rzutUkosny::~rzutUkosny(){}

void rzutUkosny::drawTrack() {
	float tempX, tempY;
	for (float t = 0; t < totalTime; t += step) {
		tempX = velocity[0] * t;
		tempY = velocity[1] * t - (acceleration / 2)*t*t;
		printf("COORDS: [%f][%f]\n", tempX, tempY);
	}
}