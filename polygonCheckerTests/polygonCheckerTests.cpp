#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	char* analyzeTriangle(int side1, int side2, int side3);
	int* getTriangleSides(int* triangleSides);
	double* Anglefind(int side1, int side2, int side3);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace polygonCheckerTests
{
	const double TOLERANCE = 0.1;

	bool compare_double(double a, double b, double tolerance = TOLERANCE) {
		return fabs(a - b) < tolerance;
	}
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
			Assert::AreEqual(angles[0], 27.37, 0.01);  
			Assert::AreEqual(angles[1], 39.99, 0.01);  
			Assert::AreEqual(angles[2], 112.64, 0.01);}
	};

	TEST_CLASS(fourpoints)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
}
