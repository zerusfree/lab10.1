#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101
{
	TEST_CLASS(UnitTest101)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            string filename = "test.txt";
            ofstream fout(filename);
            fout << "ATCGAGA" << endl;
            fout << "GCTATGC" << endl;
            fout.close();

            bool result = AvailiableElements(filename);

            Assert::IsTrue(result);
			remove(filename.c_str());
		}
	};
}
