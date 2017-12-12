#include "cartesian.h"

Cartesian::Cartesian(float Height, float Range) {
	maxHeight = Height;
	maxRange = Range;
	calculateScale();
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
}
void Cartesian::calculateScale() {
	maxRange != 0 ? scale[0] = (horizontalLineEnd[0] - horizontalLineStart[0]) / maxRange : scale[0] = 1;
	scale[1] = (VerticalLineEnd[1] - VerticalLineStart[1]) / maxHeight;
	printf("%f %f\n", scale[0], scale[1]);
}
void Cartesian::drawHorizontalLine() {
	al_draw_line(horizontalLineStart[0], horizontalLineStart[1], horizontalLineEnd[0], horizontalLineEnd[1], al_map_rgb(255, 255, 255), 5);
}
void Cartesian::drawVerticalLine() {
	al_draw_line(VerticalLineStart[0], VerticalLineStart[1], VerticalLineEnd[0], VerticalLineEnd[1], al_map_rgb(255, 255, 255), 5);
}

void Cartesian::drawHeightMarks() {
	al_draw_line(VerticalLineEnd[0] - 10, VerticalLineEnd[1], VerticalLineEnd[0] + 10, VerticalLineEnd[1], al_map_rgb(255, 255, 255), 5); // MAX HEIGHT
	al_draw_textf(font, al_map_rgb(255, 255, 0), VerticalLineEnd[0] - 100, VerticalLineEnd[1], 0, "%.3f[m]", maxHeight);
	al_draw_line(VerticalLineEnd[0] - 10, (VerticalLineStart[1]+VerticalLineEnd[1])/2, VerticalLineEnd[0] + 10, (VerticalLineStart[1] + VerticalLineEnd[1]) /2, al_map_rgb(255, 255, 255), 5); // HALF OF MAX HEIGHT
	al_draw_textf(font, al_map_rgb(255, 255, 0), VerticalLineEnd[0] - 100, (VerticalLineStart[1] + VerticalLineEnd[1]) / 2, 0, "%.3f[m]", maxHeight/2);
}
void Cartesian::drawRangeMarks() {
	al_draw_line(horizontalLineEnd[0], horizontalLineEnd[1]-10, horizontalLineEnd[0], horizontalLineEnd[1] + 10, al_map_rgb(255, 255, 255), 5); // MAX RANGE
    al_draw_textf(font, al_map_rgb(255, 255, 0), horizontalLineEnd[0]-100, horizontalLineEnd[1]+20, 0, "%.3f[m]", maxRange);
	al_draw_line((horizontalLineStart[0]+horizontalLineEnd[0])/2, horizontalLineEnd[1] - 10, (horizontalLineStart[0] + horizontalLineEnd[0]) / 2, horizontalLineEnd[1] + 10, al_map_rgb(255, 255, 255), 5); // HALF OF MAX RANGE
	al_draw_textf(font, al_map_rgb(255, 255, 0), (horizontalLineStart[0] + horizontalLineEnd[0]) / 2 -30, horizontalLineEnd[1] +10, 0, "%.3f[m]", maxRange/2);
}

void Cartesian::drawPoints(std::vector <std::pair<double, double> > &coords){
	al_draw_circle(horizontalLineStart[0] + coords[0].first*scale[0], horizontalLineStart[1] + coords[0].second*scale[1], 3, al_map_rgb(0, 255, 0), 5);
	for (int i = 1; i < coords.size(); i++) {
		al_draw_circle(horizontalLineStart[0]+coords[i].first*scale[0], horizontalLineStart[1]+coords[i].second*scale[1], 3, al_map_rgb(0, 0, 255), 2);
		al_rest(drawDelay);
		al_flip_display();
	}
	al_draw_circle(horizontalLineStart[0] + coords[coords.size()-1].first*scale[0], horizontalLineStart[1] + coords[coords.size()-1].second*scale[1], 3, al_map_rgb(255, 0, 0), 5);
	al_flip_display();
	everythingHasBeenDrawn = true;
}
void Cartesian::drawThrowTrack(std::vector <std::pair<double, double> > &coords) {
	while (!everythingHasBeenDrawn) {
		drawCoordinateSystem();
		drawPoints(coords);
	}
}