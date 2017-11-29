#pragma once

class rzutUkosny {
	float velocity[2];
	float totalTime;
	float acceleration;
	float step;

public:
	rzutUkosny(float velX, float velY, float totalT, float gravAcceleration, float stepp);
	~rzutUkosny();

	void drawTrack();
};