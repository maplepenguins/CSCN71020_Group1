#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

// returns array of side lengths for rectangle
double* calculateRectangleSides(Point* rectanglePoints[]) {
	double sideLengths[4];
	int x1;
	int y1;
	int x2;
	int y2;
	for (int i = 0; i < 4; i++) {
		x1 = rectanglePoints[i]->x;
		y1 = rectanglePoints[i]->y;
		if (i == 3) {
			x2 = rectanglePoints[0]->x;
			y2 = rectanglePoints[0]->y;
		}
		else {
			x2 = rectanglePoints[i + 1]->x;
			y2 = rectanglePoints[i + 1]->y;
		}
		sideLengths[i] = sqrt( pow(x2-x1, 2) + pow(y2 - y1, 2) );
	}
	return sideLengths;
}

char* analyzeRectangle(int side1, int side2, int side3, int side4) {

}
