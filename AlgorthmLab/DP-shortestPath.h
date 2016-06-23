#pragma once
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX_V = 50;
const int INF = 100000;

int forwardDP(int cost[][MAX_V], int V, int s, int e)
{
	queue<int> q;
	for (int i = 0;i < V;++i)
	{
		if (cost[s][i] != INF)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int temp = q.front();q.pop();
		for (int i = 0;i < V;++i)
		{
			if (cost[temp][i] != INF&&cost[s][i] > cost[s][temp] + cost[temp][i])
			{
				cost[s][i] = cost[s][temp] + cost[temp][i];
				q.push(i);
			}
		}
	}
	return cost[s][e];
}

int backwardDP(int cost[][MAX_V], int V, int s, int e)
{
	queue<int> q;
	for (int i = 0;i < V;++i)
	{
		if (cost[i][e] != INF)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int temp = q.front();q.pop();
		for (int i = 0;i < V;++i)
		{
			if (cost[i][temp] != INF&&cost[i][e] > cost[temp][e] + cost[i][temp])
			{
				cost[i][e] = cost[temp][e] + cost[i][temp];
				q.push(i);
			}
		}
	}
	return cost[s][e];
}