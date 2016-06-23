#pragma once
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<random>

int testArray[1000000];

void BubbleSort(int *A, long long n)
{
	for (long long i = 0;i < n;++i)
	{
		for (long long j = n - 1;j > i;--j)
		{
			if (A[j - 1] > A[j]) std::swap(A[j], A[j - 1]);
		}
	}
}

void BubbleSortTest()
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
		BubbleSort(testArray, std::pow(2, e));
		double endTime = clock();

		printf("%d %f\n", e, (endTime - startTime) / 1000);
	}
}

