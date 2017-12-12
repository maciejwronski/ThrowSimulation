#include "ThrowObject.h"

ThrowObject::ThrowObject(float velX, float velY, float totalT, float gravAcceleration, float stepp, int whichThrow, float intitialHeight) {
	velocity[0] = velX;
	velocity[1] = velY;
	totalTime = totalT;
	acceleration = gravAcceleration;
	step = stepp;
	startHeight = intitialHeight;
	calculateCoords(whichThrow);
}

ThrowObject::~ThrowObject(){}

void ThrowObject::calculateCoords(int whichThrow) {
	float tempX, tempY;
	float t = 0;
	if (whichThrow == 1) {
		while(t < totalTime){
			tempX = velocity[0] * t;
			tempY = startHeight - acceleration*t*t / 2;
			t += step;
			coords.push_back(make_pair(tempX, tempY));
			printf("[%f][%f]\n", tempX, tempY);
		}
	}
	else if (whichThrow == 2) {
		while (t < totalTime) {
			tempX = 20;
			tempY = velocity[1] * t - acceleration*t*t / 2;
			t += step;
			coords.push_back(make_pair(tempX, tempY));
			printf("[%f][%f]\n", tempX, tempY);
		}
	}
	else if (whichThrow == 3) {
		while (t < totalTime) {
			tempX = velocity[0] * t;
			tempY = velocity[1] * t - (acceleration / 2)*t*t;
			t += step;
			coords.push_back(make_pair(tempX, tempY));
			printf("[%f][%f]\n", tempX, tempY);
		}
	}
}

vector<pair<double, double>> & ThrowObject::GetMyVector(){
	return coords;
};