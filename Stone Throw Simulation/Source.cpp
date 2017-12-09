#pragma once
#include <iostream>
#include "variables.h"
#include "ThrowObject.h"
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

	ThrowObject throwObject(velocity[0], velocity[1], totalTime, gravitationalAcceleration, Step, whichOption, intitialHeight);

	Allegro allegro;
	Cartesian cartesian(hMax, range);
	while (exitSimulation == false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exitSimulation = true;
		cartesian.drawThrowTrack(throwObject.GetMyVector());
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
	whichOption == 2 ? velocity[0] = 0.0 : velocity[0] = Speed*cos(angleInRadiants);
	velocity[1] = Speed*sin(angleInRadiants);
	riseTime = velocity[1] / gravitationalAcceleration;
	whichOption != 1 ? totalTime = 2 * riseTime : totalTime = sqrt(2 * intitialHeight / gravitationalAcceleration);
	whichOption != 1 ? hMax = gravitationalAcceleration*pow(riseTime, 2) / 2 :hMax = intitialHeight;
	range = velocity[0] * totalTime;
}

void submitValues() {
	while (whichOption < 1 || whichOption > 3) {
		cout << "[Which Throw: 1 - Horizontal / 2 - Vertical / 3 - Oblique] Throw" << endl;
		cin >> whichOption;
	}
	if (whichOption == 1) {
		cout << "Enter Intitial Height [m]" << endl;
		cin >> intitialHeight;
		throwAngle = 0;
	}
	else if (whichOption == 2) {
		throwAngle = 90;
	}
	else if (whichOption == 3) {
		cout << "Enter Throw Angle [in Degree]" << endl;
		cin >> throwAngle;
	}
	cout << "Enter Intitial Speed [in metr/second]" << endl;
	cin >> Speed;
	cout << "Enter Gravitational Acceleration [in metr/second^2]" << endl;
	cin >> gravitationalAcceleration;
	cout << "Enter step [As the value is lower, it shows more results, for example 0.01. It's related with maximum time.]" << endl;
	cin >> Step;
}