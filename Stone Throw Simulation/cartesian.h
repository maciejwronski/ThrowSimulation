#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>

static const float horizontalLineStart[2] = { 100,500 };
static const float horizontalLineEnd[2] = { 1000,500 };
static const float VerticalLineStart[2] = { 100,500 };
static const float VerticalLineEnd[2] = { 100, 50 };
class Cartesian {
	ALLEGRO_FONT* font = NULL;
	float maxHeight;
	float maxRange;
	
	void drawHorizontalLine();
	void drawVerticalLine();
	void drawHeightMarks();
	void drawRangeMarks();
public:
	Cartesian(float Height, float Range);
	~Cartesian();

	void drawCoordinateSystem();
};