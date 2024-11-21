#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int main() {
	bool continueProgram = true;
	do {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf_s("Rectangle Selected.\n");
			Point rectangleSides[4];
			getRectanglePoints(rectangleSides);
			char* output = analyzeRectangle(rectangleSides);
			printf_s("%s\n", output);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	} while (continueProgram);
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");
	
	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Side %d: ", i +	1);
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

// gets user input for 4 points in order and stores it in array passed by reference
void getRectanglePoints(Point rectanglePoints[]) {
	printf_s("Enter the 4 points of the rectangle starting from the top left, clockwise\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Point %d (x,y): ", i + 1);
		scanf_s("%d %d", &rectanglePoints[i].x, &rectanglePoints[i].y);
	}
}
