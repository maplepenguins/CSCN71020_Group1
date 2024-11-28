#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
		case 1: // calculate triangle
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result); 
			//calculates only if triangle valid
			if (result != "Not a triangle") {
				//get angles as a pointer to an array
				double* angles = Anglefind(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				if (angles[0] != -1) { //checks for valid angles
					printf("Angles of the triangle:\n");
					printf("Angle A: %.2f degrees\n", angles[0]);
					printf("Angle B: %.2f degrees\n", angles[1]);
					printf("Angle C: %.2f degrees\n", angles[2]);
				}
			}
			break;
		case 2:
			printf_s("Rectangle Selected.\n");
			Point rectangleSides[4];
			getRectanglePoints(rectangleSides);
			char* output = analyzeRectangle(rectangleSides);
			printf_s("%s\n", output);
			free(output);
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

	printf_s("Please make a selection between 0-2:  ");
	
	//checks user input to see if its between one and two, if not asks the user to enter correct input
	while (scanf_s("%d", &shapeChoice) != 1 || shapeChoice < 0 || shapeChoice >2) { 
		while (getchar() != '\n'); 
		printf("Invalid input!\n Please enter selection between 0-2: ");
	}
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle (positive integers only)\n");
	for (int i = 0; i < 3; i++) {
		int valid = 0; // flag to check if the input is valid
		while (!valid) {
			printf("Side %d: ", i + 1);
			if (scanf_s("%d", &triangleSides[i]) == 1 && triangleSides[i] > 0) {
				valid = 1; 
			}
			else {
				printf("Invalid input.\n"); //if input isnt valid will reprompt
				while (getchar() != '\n'); 
			}
		}
	}
	return triangleSides;
}

// gets user input for 4 points in order and stores it in array passed by reference
void getRectanglePoints(Point rectanglePoints[]) {
	printf_s("Enter the 4 points of the rectangle starting from the top left, clockwise\n");
	printf_s("Separate the x and y with a space between the numbers\n");
	for (int i = 0; i < 4; i++)
	{
		int valid = 0;
		while (!valid) {
			printf("Point %d (x,y)", i + 1);
			if (scanf_s("%d %d", &rectanglePoints[i].x, &rectanglePoints[i].y) != 2) {
				printf("Invalid input. Please enter two integers for coordinates.\n");
				while (getchar() != '\n'); // if point isnt valid integer reprompt input
			}else{
				valid = 1;
			}
		}
		
	}
}
