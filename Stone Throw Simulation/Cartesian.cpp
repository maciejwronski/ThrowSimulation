#include "cartesian.h"

Cartesian::Cartesian(float Height, float Range) {
	maxHeight = Height;
	maxRange = Range;

	font = al_load_font("fonts/times.ttf", 18, 0);
}
Cartesian::~Cartesian() {
	al_destroy_font(font);
};

void Cartesian::drawCoordinateSystem(){
	drawHorizontalLine();
	drawVerticalLine();
	drawHeightMarks();
	drawRangeMarks();
	calculateScale();
	al_flip_display();
}
void Cartesian::calculateScale() {
	scale[0] = (horizontalLineEnd[0] - horizontalLineStart[0]) / maxRange;
	scale[1] = (VerticalLineEnd[1] - VerticalLineStart[1]) / maxHeight;
}
void Cartesian::drawHorizontalLine() {
	al_draw_line(horizontalLineStart[0], horizontalLineStart[1], horizontalLineEnd[0], horizontalLineEnd[1], al_map_rgb(255, 255, 255), 5);
}
void Cartesian::drawVerticalLine() {
	al_draw_line(VerticalLineStart[0], VerticalLineStart[1], VerticalLineEnd[0], VerticalLineEnd[1], al_map_rgb(255, 255, 255), 5);
}

void Cartesian::drawHeightMarks() {
	al_draw_line(VerticalLineEnd[0] - 10, VerticalLineEnd[1], VerticalLineEnd[0] + 10, VerticalLineEnd[1], al_map_rgb(255, 255, 255), 5); // MAX HEIGHT
	al_draw_textf(font, al_map_rgb(255, 255, 0), VerticalLineEnd[0] - 50, VerticalLineEnd[1], 0, "%.3f", maxHeight);
	al_draw_line(VerticalLineEnd[0] - 10, (VerticalLineStart[1]+VerticalLineEnd[1])/2, VerticalLineEnd[0] + 10, (VerticalLineStart[1] + VerticalLineEnd[1]) /2, al_map_rgb(255, 255, 255), 5); // HALF OF MAX HEIGHT
	al_draw_textf(font, al_map_rgb(255, 255, 0), VerticalLineEnd[0] - 50, (VerticalLineStart[1] + VerticalLineEnd[1]) / 2, 0, "%.3f", maxHeight/2);
}
void Cartesian::drawRangeMarks() {
	al_draw_line(horizontalLineEnd[0], horizontalLineEnd[1]-10, horizontalLineEnd[0], horizontalLineEnd[1] + 10, al_map_rgb(255, 255, 255), 5); // MAX RANGE
    al_draw_textf(font, al_map_rgb(255, 255, 0), horizontalLineEnd[0]-50, horizontalLineEnd[1]+20, 0, "%.3f", maxRange);
	al_draw_line((horizontalLineStart[0]+horizontalLineEnd[0])/2, horizontalLineEnd[1] - 10, (horizontalLineStart[0] + horizontalLineEnd[0]) / 2, horizontalLineEnd[1] + 10, al_map_rgb(255, 255, 255), 5); // HALF OF MAX RANGE
	al_draw_textf(font, al_map_rgb(255, 255, 0), (horizontalLineStart[0] + horizontalLineEnd[0]) / 2, horizontalLineEnd[1] +10, 0, "%.3f", maxRange/2);
}

void Cartesian::drawPoints(std::vector <std::pair<double, double> > &coords){
	for (int i = 0; i < coords.size(); i++) {
		al_draw_circle(horizontalLineStart[0]+coords[i].first*scale[0], horizontalLineStart[1]+coords[i].second*scale[1], 3, al_map_rgb(255, 0, 0), 2);
	}
}
void Cartesian::drawThrowTrack(std::vector <std::pair<double, double> > &coords) {
	drawCoordinateSystem();
	drawPoints(coords);
}