
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rotace(int& deg, char direction, int degrees) {
	if (direction == 'L') {
		deg -= degrees;
	}
	else if (direction == 'R') {
		deg += degrees;
	}
	if (deg < 0) {
		deg += 360;
	}
	if (deg >= 360) {
		deg -= 360;
	}
}

