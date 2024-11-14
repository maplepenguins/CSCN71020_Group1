#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"
#define M_PI 3.14159265358979323846//added this here for the anglefind function

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) { 
		result = "Not a triangle";
		return result;
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		return result;
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
		return result;
	}
	else {
		result = "Scalene triangle";
		return result;
	}
	
}
	

void Anglefind(int side1, int side2, int side3) {
	//checks if triangle sides are valid
	if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
		printf("The sides do not form a valid triangle.\n");
		return;
	}

	//thiis find the cosine for each angle which will be used later
	double angleA_cos = (side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3);
	double angleB_cos = (side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3);
	double angleC_cos = (side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2);

	//added this here because there can be precision error messing up the calculation so with this there will be no error
	if (angleA_cos > 1.0) angleA_cos = 1.0;
	if (angleA_cos < -1.0) angleA_cos = -1.0;
	if (angleB_cos > 1.0) angleB_cos = 1.0;
	if (angleB_cos < -1.0) angleB_cos = -1.0;
	if (angleC_cos > 1.0) angleC_cos = 1.0;
	if (angleC_cos < -1.0) angleC_cos = -1.0;

	//use cosine and pie to caclulate the angle
	double angleA = acos(angleA_cos) * (180.0 / M_PI);
	double angleB = acos(angleB_cos) * (180.0 / M_PI);
	double angleC = acos(angleC_cos) * (180.0 / M_PI);

	//prints out the result
	printf("The angles of the triangle are:\n");
	printf("Angle A = %.2f degrees\n", angleA);
	printf("Angle B = %.2f degrees\n", angleB);
	printf("Angle C = %.2f degrees\n", angleC);
}
