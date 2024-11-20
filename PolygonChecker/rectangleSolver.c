#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

// returns array of side lengths for rectangle
double* calculateRectangleSides(Point* rectanglePoints[]) {
	// array of side lengths and diagonals (diagonals stored in last 2 elements)
	double sideLengths[6];
	int x1, x2, y1, y2;
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
	// calculates distance of diagonals
	x2 = rectanglePoints[0]->x;
	y2 = rectanglePoints[0]->y;
	x2 = rectanglePoints[2]->x;
	y2 = rectanglePoints[2]->y;
	sideLengths[4] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	x2 = rectanglePoints[1]->x;
	y2 = rectanglePoints[1]->y;
	x2 = rectanglePoints[3]->x;
	y2 = rectanglePoints[3]->y;
	sideLengths[5] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return sideLengths;
}



char* analyzeRectangle(double* sideLengths[]) {
	
}


double calculateRectanglePerimeter(Point* rectanglePoints[]) { //calculate perimeter

	double* sideLengths = calculateRectangleSides(rectanglePoints);

	double perimeter = sideLengths[0] + sideLengths[1] + sideLengths[2] + sideLengths[3];

	return perimeter;
}

double calculateRectangleArea(double* sideLengths) { //calculate area

	double area = sideLengths[0] * sideLengths[1];

	return area;

}