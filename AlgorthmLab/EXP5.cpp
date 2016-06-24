#include "DP-shortestPath.h"
void EXP5()
{
	int cost[MAX_V][MAX_V];
	int costcopy[MAX_V][MAX_V];
	for (int i = 0;i < MAX_V;++i)
	{
		for (int j = 0;j < MAX_V;++j)
		{
			cost[i][j] = INF;
			costcopy[i][j] = INF;
		}
	}
	int V, s, e;
	cin >> V >> s >> e;
	for (int i = 0;i < V;++i)
	{
		for (int j = 0;j < V;++j)
		{
			cin >> cost[i][j];
			costcopy[i][j] = cost[i][j];
		}
	}
	cout << "forward " << forwardDP(cost, V, s, e) << endl;
	cout << "backward " << backwardDP(costcopy, V, s, e) << endl;
}
/*
9 0 8
0 3 1 5 7 100000 100000 100000 100000
100000 100000 100000 100000 100000 2 3 100000 100000
100000 100000 100000 100000 100000 9 16 100000 100000
100000 100000 100000 100000 100000 5 100000 7 100000
100000 100000 100000 100000 100000 10 2 4 100000
100000 100000 100000 100000 100000 100000 100000 100000 13
100000 100000 100000 100000 100000 100000 100000 100000 1
100000 100000 100000 100000 100000 100000 100000 100000 2
100000 100000 100000 100000 100000 100000 100000 100000 100000
forward 7
backward 7
请按任意键继续. . .
*/

