#include "GreedyKnapsack.h"
#include "BacktrackKnapsack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void EXP2()
{
	EXP2_GREEDY();
	EXP2_TREE();
}

void dataproduct(bool model)
{
	srand(time(0));

	int amount, knapM, knapN;
	if (model) amount = 1;
	else amount = 1 + rand() % 100;
	knapM = 1 + rand() % 1000;
	knapN = 1 + rand() % 100;
	cout << amount << " " << knapM << " " << knapN << endl;
	for (int i = 0;i < knapN;++i)
	{
		cout << 1 + rand() % 100 << " ";
	}
	cout << endl;
	for (int i = 0;i < knapN;++i)
	{
		cout << 1 + rand() % 100 << " ";
	}
}


/*某次随机生成的数据
1 893 28
96 39 25 47 93 8 34 66 77 87 84 25 62 1 49 37 88 71 66 54 53 23 50 64 82 58 25 15
98 49 76 87 40 49 51 32 10 36 27 58 15 83 13 41 88 81 94 17 19 9 12 64 16 59 90 66
请按任意键继续. . .*/