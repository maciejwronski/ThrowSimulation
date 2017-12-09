#include "rzut.h"

rzutUkosny::rzutUkosny(float velX, float velY, float totalT, float gravAcceleration, float stepp) {
	velocity[0] = velX;
	velocity[1] = velY;
	totalTime = totalT;
	acceleration = gravAcceleration;
	step = stepp;
	calculateCoords();
}

rzutUkosny::~rzutUkosny(){}

void rzutUkosny::calculateCoords() {
	float tempX, tempY;
	for (float t = 0; t < totalTime; t += step) {
		tempX = velocity[0] * t;
		tempY = velocity[1] * t - (acceleration / 2)*t*t;
		coords.push_back(make_pair(tempX, tempY));
		printf("[%f][%f]\n", tempX, tempY);
	}
}

vector<pair<double, double>> & rzutUkosny::GetMyVector(){
	return coords;
};