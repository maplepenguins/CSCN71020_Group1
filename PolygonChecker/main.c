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
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result); 
			Anglefind(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;
		case 0:
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

	printf_s("Enter number: ");

	scanf_s "%d", &shapeChoice) != 1 || shapeChoice < 0 || shapeChoice >3) {
	printf("Invalid input! Please enter a number between 0 and 3.\n");
	

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf("Enter the three sides of the triangle ");
	for (int i = 0; i < 3; i++) {
		int valid = 0;

		while (!valid) {
			printf("Side %d: ", i + 1);
			if (scanf_s("%d", &triangleSides[i]) != 1 || triangleSides[i] <= 0) {
				
				while (getchar() != '\n');
				printf("Please enter a valid positive integer.\n");
			}
			else {
				valid = 1;
			}

		
		}
	
	}
	if (triangleSides[0] + triangleSides[1] <= triangleSides[2] ||
		triangleSides[0] + triangleSides[2] <= triangleSides[1] ||
		triangleSides[1] + triangleSides[2] <= triangleSides[0]) {
		printf("The sides do not form a triangle.\n");
		return NULL;
	}
	return triangleSides;
}
	
	