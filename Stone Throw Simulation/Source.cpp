#pragma once
#include <iostream>
#include "variables.h"
#include "ukosny.h"
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
	rzut.drawTrack();
	Allegro allegro;
	Cartesian cartesian(hMax, range);


	while (exitSimulation == false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exitSimulation = true;
		cartesian.drawCoordinateSystem();
	}


	return 0;
}

void printMaxValues() {
	cout << "------------------------------" << endl;
	cout << "X-Velocity: " << velocity[0] << endl;
	cout << "Y-Velocity: " << velocity[1] << endl;
	cout << "Rise Time: " << riseTime << endl;
	cout << "Total time: " << totalTime << endl;
	cout << "Max Height: " << hMax << endl;
	cout << "Throw Range: " << range << endl;
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
	cout << "Enter Throw Angle" << endl;
	cin >> throwAngle;
	cout << "Enter Intitial Speed" << endl;
	cin >> Speed;
	cout << "Enter Gravitational Acceleration" << endl;
	cin >> gravitationalAcceleration;
	cout << "Enter step" << endl;
	cin >> Step;
}