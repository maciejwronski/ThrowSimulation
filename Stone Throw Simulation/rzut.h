#pragma once
#include <iostream>
#include <vector>


using namespace std;
class rzutUkosny {
	std::vector <std::pair<double, double> > coords;
	float velocity[2];
	float totalTime;
	float acceleration;
	float step;

	void calculateCoords();
public:
	rzutUkosny(float velX, float velY, float totalT, float gravAcceleration, float stepp);
	~rzutUkosny();

	vector<pair<double, double>> & GetMyVector();
};