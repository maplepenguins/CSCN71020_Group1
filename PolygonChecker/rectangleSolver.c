#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "rectangleSolver.h"

// returns distance between 2 points
float calculateDistance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// checks if the points form a valid rectangle based on side lengths and diagonals between points
bool isRectangle(Point rectanglePoints[4]) {
	float sides[4], diagonals[2];
	sides[0] = calculateDistance(rectanglePoints[0], rectanglePoints[1]);
	sides[1] = calculateDistance(rectanglePoints[1], rectanglePoints[2]);
	sides[2] = calculateDistance(rectanglePoints[2], rectanglePoints[3]);
	sides[3] = calculateDistance(rectanglePoints[3], rectanglePoints[0]);

	diagonals[0] = calculateDistance(rectanglePoints[0], rectanglePoints[2]);
	diagonals[1] = calculateDistance(rectanglePoints[1], rectanglePoints[3]);

	// is rectangle if opposite sides and diagonals are equal to each other
	return (sides[0] == sides[2] && sides[1] == sides[3] && diagonals[0] == diagonals[1]);
}

// returns perimeter and area string if the points form a valid rectangle
char* analyzeRectangle(Point rectanglePoints[4]) {
	// Allocate memory for the result string dynamically
	char* result = (char*)malloc(512 * sizeof(char));
	if (!result) {
		return NULL; // Handle memory allocation failure
	}

	// only need to get 2 adjacent sides to calculate area and perimeter
	float sides[2];
	sides[0] = calculateDistance(rectanglePoints[0], rectanglePoints[1]);
	sides[1] = calculateDistance(rectanglePoints[1], rectanglePoints[2]);

	float perimeter = 2 * (sides[0] + sides[1]);
	// if points do not form a rectangle only print perimeter
	if (!isRectangle(rectanglePoints)) {
		sprintf_s(result, 512, "The points do not form a rectangle where Perimeter: %.2f", perimeter);
		return result;
	}
	// if points do form a rectangle, print both area and perimeter
	float area = sides[0] * sides[1];
	sprintf_s(result, 512, "The points form a rectangle where Perimeter: %.2f and Area: %.2f", perimeter, area);
	return result;
}