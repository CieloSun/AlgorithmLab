#pragma once
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
void SelectionSort(int *A, long long n)
{
	for (long long i = 0;i < n - 1;++i)
	{
		long long lowindex = i;
		for (long long j = n - 1;j > i;--j)
		{
			if (A[j] < A[lowindex]) lowindex = j;
			std::swap(A[i], A[lowindex]);
		}
	}
}

void SelectionSortTest()
{
	std::default_random_engine engine((unsigned int)time(NULL));
	std::uniform_int_distribution<int> distribution(0, 100000);


	for (int e = 1;e <= 19;e++)
	{
		for (long long i = 0;i < 1000000;++i)
		{
			testArray[i] = distribution(engine);
		}

		double startTime = clock();
		SelectionSort(testArray, std::pow(2, e));
		double endTime = clock();

		printf("%d %f\n", e, (endTime - startTime) / 1000);
	}
}