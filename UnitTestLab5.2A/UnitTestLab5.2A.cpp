#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2A/Lab5.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab52A
{
	TEST_CLASS(UnitTestLab52A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			int t = goodMathPhys(f);
			Assert::AreEqual(t, 0);
		}
	};
}


