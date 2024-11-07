#pragma once
typedef struct Point {
	int x;
	int y;
} Point;

double* calculateRectangleSides(Point* rectanglePoints[]);
char* analyzeRectangle(int side1, int side2, int side3, int side4);

