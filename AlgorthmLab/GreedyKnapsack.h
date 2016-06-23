#pragma once
#include <cstdio>
#include <algorithm>

struct Object
{
	int v, w;
};

namespace GK
{
	const int MAX_N = 10000;
	int n, M;
	Object object[GK::MAX_N];
	int amount;
}

bool cmp(Object a, Object b)
{
	if (a.v*b.w > b.v*a.w) return true;
	return false;
}

int greedy_knapsack(Object object[], int n)
{
	int V = 0;
	std::sort(object, object + n, cmp);
	for (int i = 0;i < n;++i)
	{
		int cnt = 0;
		while (GK::M >= object[i].w&&cnt < GK::amount)
		{
			V += object[i].v;
			GK::M -= object[i].w;
			cnt++;
		}
	}
	return V;
}

void EXP2_GREEDY()
{
	printf("̰�ķ�:\n");
	printf("����ÿ����Ʒ������:\n");
	scanf_s("%d", &GK::amount);
	int i;
	printf("�����뱳���������:\n");
	scanf_s("%d", &GK::M);
	printf("��������Ʒ����:\n");
	scanf_s("%d", &GK::n);
	printf("������������Ʒ������:\n");
	for (i = 0;i < GK::n;i++)
		scanf_s("%d", &GK::object[i].w);
	printf("������������Ʒ�ļ�ֵ:\n");
	for (i = 0;i < GK::n;i++)
		scanf_s("%d", &GK::object[i].v);
	int P = greedy_knapsack(GK::object, GK::n);
	printf("����ֵΪ:\n");
	printf("%d\n", P);
	printf("\n");
}