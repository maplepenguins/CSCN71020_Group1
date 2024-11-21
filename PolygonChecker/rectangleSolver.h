#pragma once
typedef struct Point {
	int x;
	int y;
} Point;

float calculateDistance(Point p1, Point p2);
bool isRectangle(Point rectanglePoints[4]);
char* analyzeRectangle(Point rectanglePoints[4]);
double* calculateRectangleSides(Point* rectanglePoints[]);
char* analyzeRectangle(double* sideLengths[]);
double calculateRectangleArea(double* sideLengths);
double calculateRectanglePerimeter(Point* rectanglePoints[]);


