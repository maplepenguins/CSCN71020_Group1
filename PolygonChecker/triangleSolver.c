#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"
#define M_PI 3.14159265358979323846//added this here for the anglefind function


char* analyzeTriangle(int side1, int side2, int side3) {
	//anaylyzes whether inputs are triangle
	char* result = "";
	// if any sides equal to 0 its not a triangle
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) { 
		result = "Not a triangle";
		return result;
	}
	//if all sides are equal it is equilateral triangle
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		return result;
	}
	//if 2 sides are equal and the 3rd is not its isosceles
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
		return result;
	}
	// if none of the sides equal anything above its scalene
	else {
		result = "Scalene triangle";
		return result;
	}
	
}
	

double* Anglefind(int side1, int side2, int side3) {
	static double angles[3];  //static memory to return angles

	//check if trianle is valid
	if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
		printf("The sides do not form a valid triangle.\n");
		angles[0] = angles[1] = angles[2] = -1;  //invalid
		return angles;
	}

	//calculate cosine
	double angleA_cos = (side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3);
	double angleB_cos = (side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3);
	double angleC_cos = (side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2);

	//correct and inaccuracies 
	if (angleA_cos > 1.0) angleA_cos = 1.0;
	if (angleA_cos < -1.0) angleA_cos = -1.0;
	if (angleB_cos > 1.0) angleB_cos = 1.0;
	if (angleB_cos < -1.0) angleB_cos = -1.0;
	if (angleC_cos > 1.0) angleC_cos = 1.0;
	if (angleC_cos < -1.0) angleC_cos = -1.0;

	//use acos to find angle in radians then covert to degrees
	angles[0] = acos(angleA_cos) * (180.0 / M_PI);
	angles[1] = acos(angleB_cos) * (180.0 / M_PI);
	angles[2] = acos(angleC_cos) * (180.0 / M_PI);

	return angles;
}