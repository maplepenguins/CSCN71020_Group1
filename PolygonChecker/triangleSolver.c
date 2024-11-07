#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}
	return result;

}
	

void Anglefind(int side1, int side2, int side3) {
	float s, area, radius, A1, B2, C3;
	float pie = 3.14;

	s = (side1 + side2 + side3) / 2;
	if (side1 > s || side2 > s || side3 > s) {

		printf("The three sides do not form a triangle");
	}
	else {
		area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
		radius = (side1 * side2 * side3) / (4 * area);

		A1 = (180 / pie) * asin(side1 / (2 * radius));
		B2 = (180 / pie) * asin(side2 / (2 * radius));
		C3 = (180 / pie) * asin(side3 / (2 * radius));

		printf("The Angles are:\n%.2f\n%.2f\n%.2f", A1, B2, C3);
	}
}



