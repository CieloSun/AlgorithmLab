#pragma once
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
template<class T> void QuickSort(T *A, long long f, long long l)
{
	if (f >= l) return;
	int x = A[l];//select the right bound to be the pivot
	long long i = f;
	long long j = l;
	do
	{
		while (A[i] <= x)
		{
			++i;
		}
		while (i < j && A[j] >= x)
		{
			--j;
		}
		std::swap(A[i], A[j]);
	} while (i < j);
	std::swap(A[i], A[l]);//swap the middle value index and the key index
	QuickSort(A, f, j - 1);
	QuickSort(A, j + 1, l);
}

template<class T> void QuickSortTest(T* testArray)
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
		QuickSort(testArray, 0, std::pow(2, e) - 1);
		double endTime = clock();

		printf("%d %f\n", e, (endTime - startTime) / 1000);
	}
}