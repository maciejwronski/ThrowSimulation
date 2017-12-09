#pragma once
#include <iostream>
#include "variables.h"
#include "rzut.h"
#include "allegro.h"
#include "cartesian.h"

using namespace std;

void submitValues();
void calculateNewQuantities();
void printMaxValues();

int main(){
	submitValues();
	calculateNewQuantities();
	printMaxValues();

	rzutUkosny rzut(velocity[0], velocity[1], totalTime, gravitationalAcceleration, Step);
	Allegro allegro;
	Cartesian cartesian(hMax, range);

	while (exitSimulation == false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exitSimulation = true;
		cartesian.drawThrowTrack(rzut.GetMyVector());
	}
	system("PAUSE");
	return 0;
}

void printMaxValues() {
	cout << "------------------------------" << endl;
	cout << "X-Velocity: " << velocity[0] << " [m]"<< endl;
	cout << "Y-Velocity: " << velocity[1] << " [m]"<<endl;
	cout << "Rise Time: " << riseTime << " [s]" <<endl;
	cout << "Total time: " << totalTime << " [s]" <<endl;
	cout << "Max Height: " << hMax << " [m]" << endl;
	cout << "Throw Range: " << range << " [m]" << endl;
	cout << "------------------------------" << endl;
}

void calculateNewQuantities() {
	angleInRadiants = (((22 / 7)*throwAngle) / 180.0);
	velocity[0] = Speed*cos(angleInRadiants);
	velocity[1] = Speed*sin(angleInRadiants);
	riseTime = velocity[1] / gravitationalAcceleration;
	totalTime = 2 * riseTime;
	hMax = gravitationalAcceleration*pow(riseTime, 2) / 2;
	range = velocity[0] * totalTime;
}

void submitValues() {
	cout << "Enter Throw Angle [in Degree]" << endl;
	cin >> throwAngle;
	cout << "Enter Intitial Speed [in metr/second]" << endl;
	cin >> Speed;
	cout << "Enter Gravitational Acceleration [in metr/second^2]" << endl;
	cin >> gravitationalAcceleration;
	cout << "Enter step [As the value is lower, it shows more results, for example 0.01. It's related with maximum time.]" << endl;
	cin >> Step;
}