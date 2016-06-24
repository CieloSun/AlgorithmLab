#pragma once
#include <cstdio>
#include <random>
#include <ctime>

//int testArray[1000000];

//此函数接受一个从0开始的整数数组
template<class T> void insertSort(T* A, long long length)
{
	for (long long j = 1;j < length;++j)
	{
		int key = A[j];
		//Insert A[j] into the sorted sequence A[0,...j-1]
		long long i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

template<class T> void InsertSortTest(T* testArray)
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
		insertSort(testArray, std::pow(2, e));
		double endTime = clock();

		printf("%d %f\n", e, (endTime - startTime) / 1000);
	}
}