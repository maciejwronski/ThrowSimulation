#pragma once
#include "config.h"

using namespace std;

void submitValues() {
	cout << "Enter Throw Angle" << endl;
	cin >> throwAngle;
	cout << "Enter Intitial Speed" << endl;
	cin >> Speed;
	cout << "Enter Radius of Object" << endl;
	cin >> radiusOfObject;
	cout << "Enter Density of Object" << endl;
	cin >> densityOfObject;
	cout << "Enter Density of Air" << endl;
	cin >> densityofAir;
	cout << "Enter Aerodynamic Resistance" << endl;
	cin >> factorOfAerodynamicalResistance;
	cout << "Enter Gravitational Acceleration" << endl;
	cin >> gravitationalAcceleration;
}
void Option() {
	cout << "Which throw would you like to simulate? 1 - Horizontal, 2 - Vertical, 3 - Oblique " << endl;
	cin >> choice;
	while (choice < 1 && choice > 3) {
		cin >> choice;
		cout << "Error. Please give number once again.1 - Horizontal, 2 - Vertical, 3 - Oblique" << endl;
	}
}