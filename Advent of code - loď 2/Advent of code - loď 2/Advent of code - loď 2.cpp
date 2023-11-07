
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rotaceWaypointu(int& x, int& y, int stupen) {
	int pomX = x;
	int pomY = y;

	if (stupen == 90) {
		x = -pomY;
		y = pomX;
	}

	else if (stupen == 180) {
		x = -pomX;
		y = -pomY;
	}

	else if (stupen == 270) {
		x = pomY;
		y = -pomX;
	}
}

void pohybWaypointu(int& x, int& y, int hodnota, char smer) {
	if (smer == 'N') {
		y += hodnota;
	}

	else if (smer == 'S') {
		y -= hodnota;
	}

	else if (smer == 'E') {
		x += hodnota;
	}

	else if (smer == 'W') {
		x -= hodnota;
	}
}

int main()
{
	ifstream infile("input.txt");
	string line;

	int x = 0;
	int y = 0;
	int xWaypoint = 10;
	int yWaypoint = 1;
	int stupen = 0;

	while (getline(infile, line)) {
		char prikaz = line[0];
		int hodnota = stoi(line.substr(1));

		if (prikaz == 'L') {
			stupen = hodnota;
			rotaceWaypointu(xWaypoint, yWaypoint, stupen);
		}

		else if (prikaz == 'R') {
			stupen = 360 - hodnota;
			rotaceWaypointu(xWaypoint, yWaypoint, stupen);
		}

		else if (prikaz == 'N' || prikaz == 'S' || prikaz == 'E' || prikaz == 'W') {
			pohybWaypointu(xWaypoint, yWaypoint, hodnota, prikaz);
		}

		else if (prikaz == 'F') {
			x += hodnota * xWaypoint;
			y += hodnota * yWaypoint;
		}

		else {
			cout << "Chyba" << endl;
		}	
	}

	cout << "xWaypoint: " << xWaypoint << " yWaypoint: " << yWaypoint << endl;
	cout << "x: " << x << " y: " << y << endl;
	cout << "Manhattan distance: " << abs(x) + abs(y) << endl;

	return 0;
}