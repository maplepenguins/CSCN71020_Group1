#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	char* analyzeTriangle(int side1, int side2, int side3);
	int* getTriangleSides(int* triangleSides);
	double* Anglefind(int side1, int side2, int side3);
	typedef struct Point {
		int x;
		int y;
	} Point;
	float calculateDistance(Point p1, Point p2);
	bool isRectangle(Point rectanglePoints[4]);
	char* analyzeRectangle(Point rectanglePoints[4]);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace polygonCheckerTests
{
	TEST_CLASS(analyzeTriangleTests)
	{
	public:
		
		TEST_METHOD(isoscelesTriangleTest)
		{	//tests function with isoscles sides
			int side1 = 5;
			int side2 = 5;
			int side3 = 7;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);


		}

		TEST_METHOD(equilateralTriangleTest) {
			//tests function with equilateral sides
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(scaleneTriangleTest) {
			//test function with scalene sides
			int side1 = 5;
			int side2 = 6;
			int side3 = 7;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);


		}

		TEST_METHOD(neagtiveNumbersTriangleTest) {
			// tests function with a negative number as one of the sides
			int side1 = 4;
			int side2 = 5;
			int side3 = -6;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);

		}

		TEST_METHOD(zeroSideTriangleTest) {
			//tests function with 0 as one of the sides
			int side1 = 0;
			int side2 = 6;
			int side3 = 7;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}
			

	};

	TEST_CLASS(triangleAngleTests)
	{
	public:
		//unit test for valid triangle
		TEST_METHOD(TestValidTriangle)
		{
			double* angles = Anglefind(3, 4, 5);
			
			Assert::AreEqual(angles[0], 36.87, 0.01);  
			Assert::AreEqual(angles[1], 53.13, 0.01); 
			Assert::AreEqual(angles[2], 90.0, 0.01);   
		}
		//unit test for invalid triangle
		TEST_METHOD(TestInvalidTriangle)
		{
			double* angles = Anglefind(1, 1, 3);
			
			Assert::AreEqual(angles[0], -1.0);
			Assert::AreEqual(angles[1], -1.0);
			Assert::AreEqual(angles[2], -1.0);
		}

		//unit test for triangle with all sides the same
		TEST_METHOD(TestEquilateralTriangle)
		{
			double* angles = Anglefind(5, 5, 5);
			Assert::AreEqual(angles[0], 60.0, 0.01);
			Assert::AreEqual(angles[1], 60.0, 0.01);
			Assert::AreEqual(angles[2], 60.0, 0.01);
		}
		//unit test for large triangle
		TEST_METHOD(TestLargeTriangle)
		{
			double* angles = Anglefind(100, 200, 250);
			Assert::AreEqual(angles[0], 22.33, 0.01);  
			Assert::AreEqual(angles[1], 49.45, 0.01);  
			Assert::AreEqual(angles[2], 108.21, 0.01);
		}
	};

	TEST_CLASS(fourpoints)
	{
	public:

		TEST_METHOD(CalculateXDistanceTest)
		{
			// points with distance of 5 in X axis
			Point p1 = { 0, 0 };
			Point p2 = { 5, 0 };
			float result = calculateDistance(p1, p2);
			float expected = 5.0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(CalculateYDistanceTest)
		{
			// points with distance of 5 in Y axis
			Point p1 = { 0, 0 };
			Point p2 = { 0, 5 };
			float result = calculateDistance(p1, p2);
			float expected = 5.0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ValidRectangleTest)
		{
			// 3 X 2 rectangle
			Point rectanglePoints[] = {
				{0, 0},
				{3, 0},
				{3, 2},
				{0, 2}
			};
			float result = isRectangle(rectanglePoints);
			Assert::IsTrue(result);
		}

		TEST_METHOD(ValidSquareTest)
		{
			// 3 X 3 Square
			Point rectanglePoints[] = {
				{0, 0},
				{3, 0},
				{3, 3},
				{0, 3}
			};
			float result = isRectangle(rectanglePoints);
			Assert::IsTrue(result);
		}

		TEST_METHOD(InvalidDiagonalsTest)
		{
			// Parallelogram has opposite sides equal but not equal diagonals
			Point rectanglePoints[] = {
				{1, 0},
				{4, 0},
				{3, 2},
				{0, 2}
			};
			bool result = isRectangle(rectanglePoints);
			Assert::IsFalse(result);
		}

		TEST_METHOD(InvalidTrapezoidTest)
		{
			// Trapezoid has equal diagonals but one pair of opposite sides not equal 
			Point rectanglePoints[] = {
				{1, 0},
				{3, 0},
				{4, 2},
				{0, 2}
			};
			bool result = isRectangle(rectanglePoints);
			Assert::IsFalse(result);
		}

		TEST_METHOD(InvalidRectanglePrintPerimeterTest)
		{
			// Parallelogram with side lengths 3, 2.236, 3, 2.236
			Point rectanglePoints[] = {
				{1, 0},
				{4, 0},
				{3, 2},
				{0, 2}
			};
			char* result = analyzeRectangle(rectanglePoints);
			Assert::AreEqual("The points do not form a rectangle where Perimeter: 10.47", result);
			free(result);
		}

		TEST_METHOD(PrintValidAreaAndPerimeterTest)
		{
			// 3 X 2 rectangle
			Point rectanglePoints[] = {
				{0, 0},
				{3, 0},
				{3, 2},
				{0, 2}
			};
			char* result = analyzeRectangle(rectanglePoints);
			Assert::AreEqual("The points form a rectangle where Perimeter: 10.00 and Area: 6.00", result);
			free(result);
		}

	};
}
