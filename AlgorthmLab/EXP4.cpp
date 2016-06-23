#include "EightNumber.h"
#include <ctime>
#include <cstdlib>
void EXP4()
{
	int temp[3][3];
	int cnt = 0;
	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < 3;++j)
		{
			temp[i][j] = cnt++;
		}
	}
	
	srand(time(0));
	for (int t = 0;t < 100;++t)
	{
		int i = rand() % 3;
		int j = rand() % 3;
		int k = rand() % 3;
		int h = rand() % 3;
		swap(temp[i][j], temp[k][h]);
	}
	
	cout << "³õÊ¼×´Ì¬£º" << endl;
	Maze maze(temp);
	maze.print();
	cout << bestFirst(maze) << endl;
	//cout << bfs(temp) << endl;
	//cout << dfs(maze) << endl;
}