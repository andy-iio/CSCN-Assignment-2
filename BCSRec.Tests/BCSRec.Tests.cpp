#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int*, int*);
extern "C" int getArea(int*, int*);
extern "C" int setLength(int, int*);
extern "C" int setWidth(int, int*);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTests
{
	TEST_CLASS(BCSRecTests)
	{
	public:

	//--------------- getPerimeter Tests--------------------//
		TEST_METHOD(TestGetPerimeter_ValidInput_CalculatesPermeterCorrectly)
		{
			//This is testing the getPerimeter function using a 4 by 2 rectangle
			int length = 4;
			int width = 2;
			int Result;
			Result = getPerimeter(&length, &width);
			Assert::AreEqual(12, Result);
		}

	//--------------- getArea Tests--------------------//

		TEST_METHOD(TestGetArea_ValidInput_CalculatesAreaCorrectly)
		{
			//This is testing the getArea function using a 3 by 4 rectangle
			int length = 3;
			int width = 4;
			int Result;
			Result = getArea(&length, &width);
			Assert::AreEqual(12, Result);
		}

	//--------------- setLength Tests--------------------//

		TEST_METHOD(TestSetLength_ValidInput_SetsLengthCorrectly)
		{
			//valid input into setLength function, should set length correctly
			int input = 25;
			int length = 0;
			setLength(input, &length);
			Assert::AreEqual(25, length );
		}

		TEST_METHOD(TestSetLength_InvalidInputOutOfRange_LengthDoesNotChange)
		{
			//invalid input into setLength function, should not change length
			int input = 100;
			int length = 30;
			setLength(input, &length);
			Assert::AreEqual(30, length);
		}
		TEST_METHOD(TestSetLength_InvalidInputNegativeNumber_LengthDoesNotChange)
		{
			//invalid input into setLength function, should not change length
			int input = -2;
			int length = 30;
			setLength(input, &length);
			Assert::AreEqual(30, length);
		}

	//--------------- setWidth Tests--------------------//

		TEST_METHOD(TestSetWidth_ValidInput_SetsWidthCorrectly)
		{
			//valid input into setWidth function, should change width correctly
			int input = 28;
			int width = 80;
			setWidth(input, &width);
			Assert::AreEqual(28, width);
		}

		TEST_METHOD(TestSetWidth_InvalidInputNegativeNumber_WidthDoesNotChange)
		{
			//invalid input of -2 into setWidth function, width should not change
			int input = -2;
			int width = 80;
			setWidth(input, &width);
			Assert::AreEqual(80, width);
		}

		TEST_METHOD(TestSetWidth_InvalidInputZero_WidthDoesNotChange)
		{
			//invalid input of 0 into setWidth function, width should not change
			int input = 0;
			int width = 80;
			setWidth(input, &width);
			Assert::AreEqual(80, width);
		}

	};
}
