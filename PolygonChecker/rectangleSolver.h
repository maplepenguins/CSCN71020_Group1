#pragma once
typedef struct Point {
	int x;
	int y;
} Point;

double* calculateRectangleSides(Point* rectanglePoints[]);
char* analyzeRectangle(double* sideLengths[]);
double calculateRectangleArea(double* sideLengths);
double calculateRectanglePerimeter(Point* rectanglePoints[]);


