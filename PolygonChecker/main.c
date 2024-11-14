#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1: // calculate triangle
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			printf_s(" %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result); 
			Anglefind(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;
		case 0:// exits program
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
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
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Please make a selection between 0-2:  ");
	
	//checks user input to see if its between one and two, if not asks the user to enter correct input
	while (scanf_s("%d", &shapeChoice) != 1 || shapeChoice < 0 || shapeChoice >2) { 
		while (getchar() != '\n'); 
		printf("Invalid input! Please enter selection between 0-2: ");
	}
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf("Enter the three sides of the triangle.\n "); 
	for (int i = 0; i < 3; i++) {// asks for the three sides in a loop
		int valid = 0;

		while (!valid) {
			printf("Side %d: ", i + 1);
			if (scanf_s("%d", &triangleSides[i]) != 1 || triangleSides[i] <= 0) {
				// if not a valid input user is asked again to enter a valid input
				while (getchar() != '\n'); 
				printf("Please enter a valid positive integer.\n");
			}  
			else {
				valid = 1;
			}

		
		}
	
	}
	
	if (triangleSides[0] + triangleSides[1] <= triangleSides[2] ||//Sum of S1 and S2 should be greater than S3
		triangleSides[0] + triangleSides[2] <= triangleSides[1] ||//Sum of S1 and S3 should be greater than S2
		triangleSides[1] + triangleSides[2] <= triangleSides[0]) {//Sum of S2 and S3 should be greater than S1

		// if any condition is true the sides do not form a triangle
		printf("The sides do not form a triangle.\n");
		return NULL;
	}
	return triangleSides;
}
	
	