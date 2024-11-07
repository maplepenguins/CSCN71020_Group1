#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
		return;
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		return;
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
		return;
	}
	else {
		result = "Scalene triangle";
		return;
	}

	return result;
}