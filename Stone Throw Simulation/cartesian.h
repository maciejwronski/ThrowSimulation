#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>
#include <vector>
#include <iostream>

static const float horizontalLineStart[2] = { 100,500 };
static const float horizontalLineEnd[2] = { 1000,500 };
static const float VerticalLineStart[2] = { 100,500 };
static const float VerticalLineEnd[2] = { 100, 50 };


class Cartesian {
	ALLEGRO_FONT* font = NULL;
	bool horizontalThrow;
	float maxHeight;
	float maxRange;
	float intitialHeight;
	float scale[2];
	void drawHorizontalLine();
	void drawVerticalLine();
	void drawHeightMarks();
	void drawRangeMarks();
	void drawCoordinateSystem();
	void calculateScale();
	void drawPoints(std::vector <std::pair<double, double> > &coords);
public:
	Cartesian(float Height, float Range);
	~Cartesian();

	void drawThrowTrack(std::vector <std::pair<double, double> > &coords);
};