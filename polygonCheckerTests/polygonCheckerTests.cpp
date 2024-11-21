#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	char* analyzeTriangle(int side1, int side2, int side3);
	int* getTriangleSides(int* triangleSides);
	void Anglefind(int side1, int side2, int side3);
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

		TEST_METHOD(TestMethod1)
		{
	


		}

	};

	TEST_CLASS(fourpoints)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
}
