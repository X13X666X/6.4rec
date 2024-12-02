#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountZeroElements)
        {
            double array[] = { 1.0, 0.0, -3.5, 0.0, 2.1 };
            int size = 5;
            int expectedZeroCount = 2;

            int actualZeroCount = CountZeroElements(array, size);

            Assert::AreEqual(expectedZeroCount, actualZeroCount);
        }

        TEST_METHOD(TestFindMinIndex)
        {
            double array[] = { 3.0, -1.5, 2.7, -5.0, 1.2 };
            int size = 5;
            int expectedMinIndex = 3;

            int actualMinIndex = FindMinIndex(array, size);

            Assert::AreEqual(expectedMinIndex, actualMinIndex);
        }

        TEST_METHOD(TestSumAfterMin)
        {
            double array[] = { 3.0, -1.5, 2.7, -5.0, 1.2, 4.3 };
            int size = 6;
            int minIndex = FindMinIndex(array, size);
            double expectedSum = 5.5; // 1.2 + 4.3

            double actualSum = SumAfterMin(array, size, minIndex);

            Assert::AreEqual(expectedSum, actualSum, 0.001);
        }

        void SortOddIndicesByAbs(double* array, const int size, int i = 1, int j = 1) {
            if (i >= size) {
                return;
            }
            if (j >= size) {
                SortOddIndicesByAbs(array, size, i + 2, i + 2);
                return;
            }
            if (j > i && j % 2 == 1 && abs(array[j]) < abs(array[i])) {
                // Переставляємо значення без swap
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            SortOddIndicesByAbs(array, size, i, j + 2);
        }
   
    };
}
