#pragma once
#include <iostream>
#include <vector>


using namespace std;
class ThrowObject {
	std::vector <std::pair<double, double> > coords;
	float velocity[2];
	float totalTime;
	float acceleration;
	float step;
	float startHeight;

	void calculateCoords(int whichThrow);
public:
	ThrowObject(float velX, float velY, float totalT, float gravAcceleration, float stepp, int whichThrow, float intitialHeight);
	~ThrowObject();

	vector<pair<double, double>> & GetMyVector();
};