#include <cstdlib>
#include <ctime>
#include <random>
#include "QuickSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"//最终没有使用
#include "SelectionSort.h"//最终没有使用

int intarray[1000000];
int intarray2[1000000];
double doublearray[1000000];
double doublearray2[1000000];


template<class T> void test(T* testArray, T* testArrayCopy)
{
	std::default_random_engine engine((unsigned int)time(NULL));
	std::uniform_real_distribution<double> distribution(0, 100000);
	for (int e = 1;e <= 16;e++)
	{
		long long length = std::pow(2, e);
		for (long long i = 0;i < length;++i)
		{
			testArrayCopy[i] = testArray[i] = static_cast<T>(distribution(engine));
		}
		double startTime = clock();
		insertSort(testArray, length);
		double endTime = clock();
		printf("%lld\t%s%f\t", length, "Insert Sort:", (endTime - startTime) / 1000);
		startTime = clock();
		QuickSort(testArrayCopy, 0, length);
		endTime = clock();
		printf("%s%f\n", "Quick Sort:", (endTime - startTime) / 1000);
	}
}

void EXP1()
{
	printf("%s\n", "Test the integer array:");
	test(intarray, intarray2);
	printf("%s\n", "Test the float array:");
	test(doublearray, doublearray2);
}

