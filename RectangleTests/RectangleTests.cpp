#include "pch.h"
#include "CppUnitTest.h"

extern "C" { typedef struct Point {
	int x;
	int y;
} Point;
float calculateDistance(Point p1, Point p2);
bool isRectangle(Point rectanglePoints[4]);
char* analyzeRectangle(Point rectanglePoints[4]);

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		
		
		// This is testing the four points functionality using points that does not create a rectangle: P1(2,2), P2(3,4), P3(5,2), P4(2,1)
		TEST_METHOD(Four_Points_FunctionalityTwo)
		{


		}
	};
}
